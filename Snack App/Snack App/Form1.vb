Public Class frmSnackChooser

    Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lblInfo.Click

    End Sub

    Private Sub btnAdd_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnAdd.Click
        Dim stringPass As String = txtSnackInput.Text
        lstSnacks.Items.Add(stringPass)
        txtSnackInput.Text = ""
    End Sub

    Private Sub frmSnackChooser_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Randomize()
    End Sub

    Private Sub btnRandomize_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnRandomize.Click
        Dim randomValue As Integer = CInt(Int((lstSnacks.Items.Count() * Rnd()) + 0))
        Dim chosenItem As String = CStr(lstSnacks.Items(randomValue))
        lstOutput.Items.Clear()
        lstOutput.Items.Add(chosenItem)
    End Sub

    Private Sub btnResetSnacks_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnResetSnacks.Click
        lstSnacks.Items.Clear()
    End Sub

    Private Sub btnResetAll_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnResetAll.Click
        lstSnacks.Items.Clear()
        lstOutput.Items.Clear()
        txtSnackInput.Text = ""
    End Sub

    Private Sub btnDelete_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDelete.Click
        lstSnacks.Items.RemoveAt(lstSnacks.SelectedIndex)

    End Sub
End Class
