Set wsshell = WScript.CreateObject("wscript.shell")

'Get server name (not UNC)
serverName=InputBox("Enter the target server name. (Must be host name)", "Server Name")
postConcat="\\"& serverName &"\"
currDir = wsshell.CurrentDirectory

If serverName ="" then
WScript.Quit
End if



'Main sub
On Error Resume Next
createDir()
If Err.Number <> 0 Then
	WScript.Echo("Invalid characters in Server Name. Please try again.")
	Err.Clear()
	WScript.Sleep(2)
	WScript.Quit()
End if
parsePrinterNames(serverName)
createVBS()


'Create Directories
Public Sub createDir()
		Set fso = CreateObject("Scripting.FileSystemObject")
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		If Not fso.FolderExists(currDir & "\PrinterScriptsFolder") Then
		newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder")
		End If
		
		If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName) Then
		newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&serverName)
		End If
			
			If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\PrintLogs") Then
			newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&serverName&"\PrintLogs")
			End If
			
				If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS") Then
				newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS")
				End If
				
						If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer EXE") Then
						newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&serverName&"\Printer EXE")
						End If
						
								If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer SED") Then
								newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&serverName&"\Printer SED")
								End If		
End Sub


'Pipe net view and parse printer names put them in a list
Public Sub parsePrinterNames(serverName)
		'Output net view to text file
		wsshell.Run "cmd /Q /C CD C:\windows\system32 & net view \\" & serverName & " > "&""""&currDir&"\PrinterScriptsFolder\"&serverName&"\PrintLogs\083191.txt"&""""
		'WScript.Echo(currDir)
		'Set user and current dir env var
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		'currDir = wsshell.CurrentDirectory
		
		'Allows time for text pipe completion
		WScript.Sleep(1000)
		
		'Parse for printer names and write to new text file
		Set fso = CreateObject("Scripting.FileSystemObject")
		Set txtFile = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&serverName&"\PrintLogs\083191.txt")
		Set wrtFile = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&serverName&"\PrintLogs\083191mod.txt",2,True)
		Do While Not txtFile.AtEndOfStream
			txtLine = txtFile.ReadLine()
			If InStr(1,txtLine,"print",1) > 0 Then
			txtLine=Split(txtLine,"  ")
			'postLine=Left(txtLine(0),Len(txtLine(0))-1) may need later
			'WScript.Echo(txtLine(0))
			wrtFile.Write(txtLine(0) & ";")
			Else
			End if	
		Loop
End Sub

'Cleans up left over directories not EXE
Public Sub deleteDir()
			Set fso = CreateObject("Scripting.FileSystemObject")
				If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS") Then
				fso.DeleteFolder(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS")
				End If
						
						If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer SED") Then
						fso.DeleteFolder (currDir & "\PrinterScriptsFolder\"&serverName&"\Printer SED")
						End If	

End Sub

'Cleans up directories if error is caught
Public Sub deleteDirErr()
			Set fso = CreateObject("Scripting.FileSystemObject")
				If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&serverName) Then
				fso.DeleteFolder(currDir & "\PrinterScriptsFolder\"&serverName)
				End If
End Sub

'Create VBS
Public Sub createVBS()
		'Const FORREADING = 1          REMINDER
		'Const FORWRITING = 2
		'Const FORAPPENDING = 8
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		Set fso = CreateObject("Scripting.FileSystemObject")
		'WScript.Echo(userProfile)
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		'On Error Resume next
		Set txtFile = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&serverName&"\PrintLogs\083191mod.txt")
		On Error Resume next
		thefile=txtFile.ReadAll
		If Err.Number <> 0 Then
			WScript.Echo("Error"&Err.Number&": "& Err.Description&vbCrLf&vbcrlf&"Description: This error typically occurs due to an invalid server name or not enough permissions to access the SMB share.")
			Err.Clear
			txtFile.Close()
			deleteDirErr()
			WScript.Sleep(2)
			WScript.Quit
		End If
		
		printerArray = Split(theFile,";")
		
		For i = 0 To UBound(printerArray)
			  If printerArray(i) <> "" then
				Set wrtFile = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS\"& printerArray(i)&".vbs",2,True)
				wrtFile.WriteLine("dim printerPath"& vbcrlf)
				wrtFile.WriteLine("printerPath ="&""""&postConcat&printerArray(i)&""""&vbCrLf)
				'wrtFile.WriteLine("usrConfirm=Msgbox(""Do you want to install this printer: "&""&printerArray(i)&""""&",vbYesNo,""Printer Installation Confirmation"")"&vbcrlf)
				'wrtFile.WriteLine("if usrConfirm = 6 then"& vbcrlf)
				wrtFile.WriteLine("set wsN = wscript.createobject(""Wscript.Network"")"& vbcrlf)
				wrtFile.WriteLine("Set wsO = WScript.CreateObject(""Wscript.shell"")" & vbCrLf & vbCrLf & vbCrLf)
				wrtFile.WriteLine("On error resume next"&vbCrLf)
				wrtFile.WriteLine("wsN.AddWindowsPrinterConnection(printerPath)"&vbCrLf&vbcrlf&vbcrlf&vbCrLf)
				wrtFile.WriteLine("If err.number <> 0 Then"&vbCrLf)
				wrtFile.WriteLine("err.clear"&vbCrLf)
				wrtFile.WriteLine("wscript.quit"&vbCrLf)
				wrtFile.WriteLine("end if"&vbCrLf)
				wrtFile.WriteLine("WScript.Sleep(1000)"&vbcrlf)
				wrtFile.WriteLine("dChoice=Msgbox(""Do you want to set this printer as your default printer?"",vbYesNo,""Set Default Printer"")"&vbCrLf&vbCrLf)
				wrtFile.WriteLine("if dChoice = 6 then"&vbCrLf)
				wrtFile.WriteLine("wsN.SetDefaultPrinter(printerPath)"&vbCrLf)
				wrtFile.WriteLine("else"&vbCrLf)
				wrtFile.WriteLine("end if"&vbCrLf&vbCrLf)
				wrtFile.WriteLine("wscript.echo(""Your printer has been installed!"")"&vbCrLf&vbCrLf&vbCrLf)
				'wrtFile.WriteLine("else"&vbCrLf)
				'wrtFile.WriteLine("end if"&vbCrLf)
				
				createSED(printerArray(i))
				WScript.Sleep(500)
				createEXE(Replace(printerArray(i)," ","",1,-1,1))
				'WScript.Echo printerArray(i)
			 End If

		Next

End Sub


'Creates a SED
Public Sub createSED(printName)
				Set fso = CreateObject("Scripting.FileSystemObject")
				trPrintName=Replace(printName," ","",1,-1,1)
				'WScript.Echo(trPrintName)
				Set wrtSed = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&serverName&"\Printer SED\"& trPrintName&".SED",2,True)
				wrtSed.WriteLine("[Version]"&vbcrLF)
				wrtSed.WriteLine("Class=IEXPRESS"&vbCrLf)
				wrtSed.WriteLine("SEDVersion=3"&vbcrlf)
				wrtSed.WriteLine("[Options]"&vbCrLf)
				wrtSed.WriteLine("PackagePurpose=InstallApp"&vbCrLf)
				wrtSed.WriteLine("ShowInstallProgramWindow=1"&vbCrLf)
				wrtSed.WriteLine("HideExtractAnimation=1"&vbCrLf)
				wrtSed.WriteLine("UseLongFileName=1"&vbCrLf)
				wrtSed.WriteLine("InsideCompressed=0"&vbCrLf)
				wrtSed.WriteLine("CAB_FixedSize=0"&vbCrLf)
				wrtSed.WriteLine("CAB_ResvCodeSigning=0"&vbCrLf)
				wrtSed.WriteLine("RebootMode=N"&vbCrLf)
				wrtSed.WriteLine("InstallPrompt=%InstallPrompt%"&vbCrLf)
				wrtSed.WriteLine("DisplayLicense=%DisplayLicense%"&vbCrLf)
				wrtSed.WriteLine("FinishMessage=%FinishMessage%"&vbCrLf)
				wrtSed.WriteLine("TargetName=%TargetName%"&vbCrLf)
				wrtSed.WriteLine("FriendlyName=%FriendlyName%"&vbCrLf)
				wrtSed.WriteLine("AppLaunched=%AppLaunched%"&vbCrLf)
				wrtSed.WriteLine("PostInstallCmd=%PostInstallCmd%"&vbCrLf)
				wrtSed.WriteLine("AdminQuietInstCmd=%AdminQuietInstCmd%"&vbCrLf)
				wrtSed.WriteLine("UserQuietInstCmd=%UserQuietInstCmd%"&vbCrLf)
				wrtSed.WriteLine("SourceFiles=SourceFiles"&vbCrLf)
				wrtSed.WriteLine("[Strings]"&vbCrLf)
				wrtSed.WriteLine("InstallPrompt="&vbCrLf)
				wrtSed.WriteLine("DisplayLicense="&vbCrLf)
				wrtSed.WriteLine("FinishMessage="&vbCrLf)
				wrtSed.WriteLine("TargetName="&currDir & "\PrinterScriptsFolder\"&serverName&"\Printer EXE\"& printName&".EXE"&vbCrLf)
				wrtSed.WriteLine("FriendlyName="&printName&" Install"&vbcrlf)
				wrtSed.WriteLine("AppLaunched=C:\Windows\system32\wscript.exe "&""""&printName&".vbs"&""""&vbcrlf)
				wrtSed.WriteLine("PostInstallCmd=<None>"&vbcrlf)
				wrtSed.WriteLine("AdminQuietInstCmd="&vbcrlf)
				wrtSed.WriteLine("UserQuietInstCmd="&vbcrlf)
				wrtSed.WriteLine("FILE0="&""""&printName&".vbs"&""""&vbcrlf)
				wrtSed.WriteLine("[SourceFiles]"&vbcrlf)
				wrtSed.WriteLine("SourceFiles0="&currDir & "\PrinterScriptsFolder\"&serverName&"\Printer VBS\"&vbcrlf)
				wrtSed.WriteLine("[SourceFiles0]"&vbCrLf)
				wrtSed.WriteLine("%FILE0%="&vbcrlf)
End Sub

Public Sub createEXE(printName)
				'wsshell.Run "cmd /Q /C CD C:\windows\sysWOW64 & iexpress /N "&""""& currDir & "\PrinterScriptsFolder\Printer SED\"& printName & ".SED"&""""
				driveLtr = Split(currDir,":")
				
				'WScript.Echo(driveLtr(0))
				'Wscript.echo(printName)
				On Error Resume Next
				wsshell.Run "cmd /Q /C "&driveLtr(0)&":"&"&CD "&currDir&"\PrinterScriptsFolder\"&serverName&"\Printer SED\ &"& "C:\Windows\SysWOW64\iexpress.exe "&printName&".SED " & "/N"
				If Err.Number <> 0 Then
					WScript.Echo("Error ("&Err.Number&"): "&Err.Description&vbCrLf&vbCrLf&"Description: This error typically occurs when iexpress is not reachable or you are using an imcompatible OS (x86 or not above Windows XP)")
					Err.Clear
					WScript.Quit
				End if
				'wsshell.Run "cmd /q /c cd c:\windows\syswow64 & iexpress "&currDir&"\PrinterScriptsFolder\"&serverName&"\Printer SED\"&printName&".sed "& "/N"
End Sub 

WScript.Sleep(2000)
deleteDir()
WScript.Sleep(700)
WScript.Echo("Printer enumeration complete!")