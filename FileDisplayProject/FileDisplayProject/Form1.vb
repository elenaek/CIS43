Imports System.IO
Public Class frmFileDisplay

    Dim fileArray() As String
    Dim backUpFileArray() As String
    Dim saveFileName As String



    Private Sub btnRead_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnRead.Click
        OpenFile()

    End Sub
    Public Sub OpenFile()

        Dim inputFile As StreamReader
        Dim lineOfText As String
        Dim arrayCounter As Integer = 0
        Dim fileArraySize As Integer = 0
        With ofdPhony411
            .Filter = "Text files (*.txt)|*.txt"
            .Title = "Select a File to Open"
            Try
                .InitialDirectory = "C:\Desktop"
            Catch
            End Try

            If .ShowDialog() = Windows.Forms.DialogResult.OK Then
                inputFile = File.OpenText(.FileName)
                lbTextFile.Items.Clear()
                ' put file contents into the listbox
                While inputFile.Peek <> -1 ' not end of file
                    lineOfText = inputFile.ReadLine()
                    lbTextFile.Items.Add(lineOfText)
                    ReDim Preserve fileArray(fileArraySize)
                    fileArray(arrayCounter) = lineOfText

                    fileArraySize += 1
                    arrayCounter += 1

                End While
                inputFile.Close()
            End If
        End With
        btnBack.Enabled = True

    End Sub

    Public Sub SaveAsFile()
        Dim outputFile As StreamWriter


        With sfdSave
            .Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*"
            .Title = "Save File As"
            .InitialDirectory = "C:\Desktop"

            If .ShowDialog() = Windows.Forms.DialogResult.OK Then
                Try
                    outputFile = File.CreateText(.FileName)
                    saveFileName = .FileName
                    For Each item As String In lbTextFile.Items
                        outputFile.WriteLine(item)
                    Next
                    outputFile.Close()
                Catch
                End Try


            End If
        End With
    End Sub

    Public Sub SaveFile()
        Dim outputFile As StreamWriter = New StreamWriter(saveFileName, False)
        Try
            For Each item As String In lbTextFile.Items
                outputFile.WriteLine(item)
            Next
        Catch

        End Try
        outputFile.Close()
    End Sub

    Private Sub btnSearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSearch.Click
        Dim searchFor As String = tbSearchString.Text.ToLower()
        Dim backUpArraySize As Integer = 0
        lbTextFile.Items.Clear()

        For Each item As String In fileArray
            If item <> "" Then
                Dim compareString As String = item.ToLower()
                If InStr(compareString, searchFor) > 0 Then
                    lbTextFile.Items.Add(item)
                    ReDim Preserve backUpFileArray(backUpArraySize)

                    backUpFileArray(backUpArraySize) = item
                    backUpArraySize += 1
                End If
            End If
        Next
        btnForward.Enabled = True
    End Sub

    Private Sub lbTextFile_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lbTextFile.SelectedIndexChanged

    End Sub

    Private Sub btnBack_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnBack.Click
        lbTextFile.Items.Clear()
        Dim numb As Integer = 0
        For Each item As String In fileArray
            If item = "" Then
                Exit For
            Else
                lbTextFile.Items.Add(item)
            End If
        Next
    End Sub

    Private Sub btnForward_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnForward.Click
        lbTextFile.Items.Clear()
        Try
            For Each item As String In backUpFileArray
                If item <> "" Then
                    lbTextFile.Items.Add(item)
                End If
            Next
        Catch
        End Try

    End Sub

    Private Sub btnLinearSearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnLinearSearch.Click
        Dim chosenFile As StreamReader
        Dim parseText As String
        Dim searchWord As String = tbSearchString.Text.ToLower()


        With ofdPhony411
            .Filter = "Text Files (*.txt) | *.txt"
            .Title = "Choose a file to parse through"
            Try
                .InitialDirectory = "C:\Desktop"
            Catch
            End Try

            If .ShowDialog() = Windows.Forms.DialogResult.OK Then
                chosenFile = File.OpenText(.FileName)
                lbTextFile.Items.Clear()
                While chosenFile.Peek <> -1
                    parseText = chosenFile.ReadLine()
                    If InStr(parseText.ToLower(), searchWord) > 0 Then
                        lbTextFile.Items.Add(parseText)

                    End If
                End While
            End If

        End With
    End Sub


    Private Sub OpenToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OpenToolStripMenuItem.Click
        OpenFile()
    End Sub

    Private Sub SaveToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveToolStripMenuItem.Click
        SaveFile()
    End Sub

    Private Sub SaveAsToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveAsToolStripMenuItem.Click
        SaveAsFile()
        SaveToolStripMenuItem.Enabled = True
    End Sub
End Class
