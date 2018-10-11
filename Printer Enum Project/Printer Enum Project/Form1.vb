Public Class printerEnumForm

    Private Sub autoEnumBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles autoEnumBtn.Click

        Dim stmRdr As New System.IO.StreamReader(System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream("Printer_Enum_Project.autoEnumNew.vbs"))

        Dim script1Code As String = stmRdr.ReadToEnd
        stmRdr.Close()

        Dim script1GUID As Guid = Guid.NewGuid()
        Dim script1FileName As String = script1GUID.ToString() & ".vbs"
        script1FileName = Application.StartupPath & "\" & script1FileName

        Dim stmWrite As New System.IO.StreamWriter(script1FileName)
        stmWrite.Write(script1Code)
        stmWrite.Close()
        Process.Start(script1FileName)
        System.Threading.Thread.Sleep(1000)

        For Each p As Process In Process.GetProcesses
            If p.ProcessName.ToLower = "wscript.exe".ToLower Then
                p.Kill()
            End If
        Next

        Dim Script1fileInfo As New System.IO.FileInfo(script1FileName)
        Try
            Script1fileInfo.Delete()
        Catch ex As Exception
            MessageBox.Show(ex.ToString)
        End Try

    End Sub

    Private Sub manualInputBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles manualInputBtn.Click

        Dim stmRdr As New System.IO.StreamReader(System.Reflection.Assembly.GetExecutingAssembly().GetManifestResourceStream("Printer_Enum_Project.manualInputNew.vbs"))

        Dim script1Code As String = stmRdr.ReadToEnd
        stmRdr.Close()

        Dim script1GUID As Guid = Guid.NewGuid()
        Dim script1FileName As String = script1GUID.ToString() & ".vbs"
        script1FileName = Application.StartupPath & "\" & script1FileName

        Dim stmWrite As New System.IO.StreamWriter(script1FileName)
        stmWrite.Write(script1Code)
        stmWrite.Close()
        Process.Start(script1FileName)
        System.Threading.Thread.Sleep(1000)

        For Each p As Process In Process.GetProcesses
            If p.ProcessName.ToLower = "wscript.exe".ToLower Then
                p.Kill()
            End If
        Next

        Dim Script1fileInfo As New System.IO.FileInfo(script1FileName)
        Try
            Script1fileInfo.Delete()
        Catch ex As Exception
            MessageBox.Show(ex.ToString)
        End Try

    End Sub

    Private Sub HelpToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles HelpToolStripMenuItem.Click
        Dim helpFrm As New Form2
        helpFrm.Show()

    End Sub
End Class
