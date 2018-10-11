Set wsshell = WScript.CreateObject("wscript.shell")

'Get server name (not UNC)
serverName=InputBox("Enter the UNC to the printer.(ex. \\servername\printername)", "UNC to Printer")
postConcat="\\"& serverName &"\"
printerName=Split(serverName,"\",-1,1)
'WScript.Echo(printerName(3))
'WScript.Quit
'printerName(2) is the Server Name
'printerName(3) is the Printer's Name
currDir = wsshell.CurrentDirectory

If serverName ="" then
WScript.Quit
End if



'Main sub
On Error Resume Next
createDir()
If Err.Number <> 0 Then
	WScript.Echo("Invalid UNC Path. Please use this format: "&vbCrLf&vbcrlf&"\\ServerName\PrinterName")
	Err.Clear()
	WScript.Sleep(2)
	WScript.Quit()
End if
createVBS()


'Create Directories
Public Sub createDir()
		Set fso = CreateObject("Scripting.FileSystemObject")
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		If Not fso.FolderExists(currDir & "\PrinterScriptsFolder") Then
		newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder")
		End If
		
		If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)) Then
		newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&printerName(2))
		End if
		
			If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\PrintLogs") Then
			newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&printerName(2)&"\PrintLogs")
			End If
			
				If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS") Then
				newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS")
				End If
				
						If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer EXE") Then
						newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer EXE")
						End If
						
								If Not fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer SED") Then
								newFolder = fso.CreateFolder (currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer SED")
								End If
				
End Sub

'Cleans up directories
Public Sub deleteDir()
			Set fso = CreateObject("Scripting.FileSystemObject")
				If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS") Then
				fso.DeleteFolder(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS")
				End If
						
						If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer SED") Then
						fso.DeleteFolder (currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer SED")
						End If	

End Sub

'Cleans up directories if error is caught
Public Sub deleteDirErr()
			Set fso = CreateObject("Scripting.FileSystemObject")
				If fso.FolderExists(currDir & "\PrinterScriptsFolder\"&printerName(2)) Then
				fso.DeleteFolder(currDir & "\PrinterScriptsFolder\"&printerName(2))
				End If
End Sub

'Create VBS
Public Sub createVBS()
		'Const FORREADING = 1          REMINDER
		'Const FORWRITING = 2
		'Const FORAPPENDING = 8
		'userProfile = wsshell.ExpandEnvironmentStrings("%UserProfile%")
		Set fso = CreateObject("Scripting.FileSystemObject")
				On Error Resume next
				Set wrtFile = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS\"& printerName(3)&".vbs",2,True)
				If Err.Number <> 0 Then
					WScript.Echo("Error("&Err.number&"): "& Err.description&vbCrLf&vbCrLf&"Description: This error typically occurs due to a bad UNC path or not having enough permissions to access the SMB share.")
					'WScript.Echo("lalala")
					Err.Clear
					wrtFile.Close()
					deleteDirErr(printerName(2))
					WScript.Sleep(2)
					WScript.Quit
				End If
				
				wrtFile.WriteLine("dim printerPath"& vbcrlf)
				wrtFile.WriteLine("printerPath ="&""""&serverName&""""&vbCrLf)
				wrtFile.WriteLine("usrConfirm=Msgbox(""Do you want to install this printer: "&""&printerName(3)&""""&",vbYesNo,""Printer Installation Confirmation"")"&vbcrlf)
				wrtFile.WriteLine("if usrConfirm = 6 then"& vbcrlf)
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
				wrtFile.WriteLine("else"&vbCrLf)
				wrtFile.WriteLine("end if"&vbCrLf)

				createSED(printerName(3))
				'WScript.Echo(printerName(2))
				WScript.Sleep(500)
				createEXE(Replace(printerName(3)," ","",1,-1,1))
				'WScript.Echo printerArray(i)

End Sub


'Creates a SED
Public Sub createSED(printName)
				Set fso = CreateObject("Scripting.FileSystemObject")
				trPrintName=Replace(printName," ","",1,-1,1)
				'WScript.Echo(trPrintName)
				Set wrtSed = fso.OpenTextFile(currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer SED\"& trPrintName&".SED",2,True)
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
				wrtSed.WriteLine("TargetName="&currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer EXE\"& printName&".EXE"&vbCrLf)
				wrtSed.WriteLine("FriendlyName="&printName&" Install"&vbcrlf)
				wrtSed.WriteLine("AppLaunched=C:\Windows\system32\wscript.exe "&""""&printName&".vbs"&""""&vbcrlf)
				wrtSed.WriteLine("PostInstallCmd=<None>"&vbcrlf)
				wrtSed.WriteLine("AdminQuietInstCmd="&vbcrlf)
				wrtSed.WriteLine("UserQuietInstCmd="&vbcrlf)
				wrtSed.WriteLine("FILE0="&""""&printName&".vbs"&""""&vbcrlf)
				wrtSed.WriteLine("[SourceFiles]"&vbcrlf)
				wrtSed.WriteLine("SourceFiles0="&currDir & "\PrinterScriptsFolder\"&printerName(2)&"\Printer VBS\"&vbcrlf)
				wrtSed.WriteLine("[SourceFiles0]"&vbCrLf)
				wrtSed.WriteLine("%FILE0%="&vbcrlf)
End Sub

Public Sub createEXE(printName)
				'wsshell.Run "cmd /Q /C CD C:\windows\sysWOW64 & iexpress /N "&""""& currDir & "\PrinterScriptsFolder\Printer SED\"& printName & ".SED"&""""
				driveLtr = Split(currDir,":")
				
				'WScript.Echo(driveLtr(0))
				'Wscript.echo(printName)
				'WScript.Quit
				On Error Resume next
				wsshell.Run "cmd /Q /C "&driveLtr(0)&":"&"&CD "&currDir&"\PrinterScriptsFolder\"&printerName(2)&"\Printer SED\ &"& "C:\Windows\SysWOW64\iexpress.exe "&printName&".SED " & "/N"
					If Err.Number <> 0 Then
						WScript.Echo("Error ("&Err.Number&"): "&Err.Description&vbCrLf&vbCrLf&"Description: This error typically occurs when iexpress is not reachable or you are using an imcompatible OS (x86 or not above Windows XP)")
						Err.Clear
						WScript.Quit
					End if
End Sub 

WScript.Sleep(3000)
deleteDir()
WScript.Sleep(700)
WScript.Echo("Printer enumeration complete!")