<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmSnackChooser
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.grpFoods = New System.Windows.Forms.GroupBox()
        Me.lstSnacks = New System.Windows.Forms.ListBox()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.btnRandomize = New System.Windows.Forms.Button()
        Me.txtSnackInput = New System.Windows.Forms.TextBox()
        Me.lblInfo = New System.Windows.Forms.Label()
        Me.grpOutput = New System.Windows.Forms.GroupBox()
        Me.lstOutput = New System.Windows.Forms.ListBox()
        Me.btnResetSnacks = New System.Windows.Forms.Button()
        Me.btnResetAll = New System.Windows.Forms.Button()
        Me.btnDelete = New System.Windows.Forms.Button()
        Me.grpFoods.SuspendLayout()
        Me.grpOutput.SuspendLayout()
        Me.SuspendLayout()
        '
        'grpFoods
        '
        Me.grpFoods.Controls.Add(Me.lstSnacks)
        Me.grpFoods.Location = New System.Drawing.Point(197, 12)
        Me.grpFoods.Name = "grpFoods"
        Me.grpFoods.Size = New System.Drawing.Size(292, 289)
        Me.grpFoods.TabIndex = 0
        Me.grpFoods.TabStop = False
        Me.grpFoods.Text = "Snack List"
        '
        'lstSnacks
        '
        Me.lstSnacks.FormattingEnabled = True
        Me.lstSnacks.Location = New System.Drawing.Point(19, 22)
        Me.lstSnacks.Name = "lstSnacks"
        Me.lstSnacks.Size = New System.Drawing.Size(254, 251)
        Me.lstSnacks.TabIndex = 0
        '
        'btnAdd
        '
        Me.btnAdd.Location = New System.Drawing.Point(268, 452)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(173, 38)
        Me.btnAdd.TabIndex = 1
        Me.btnAdd.Text = "Add"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'btnExit
        '
        Me.btnExit.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnExit.Location = New System.Drawing.Point(507, 452)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(173, 38)
        Me.btnExit.TabIndex = 2
        Me.btnExit.Text = "Exit"
        Me.btnExit.UseVisualStyleBackColor = True
        '
        'btnRandomize
        '
        Me.btnRandomize.Location = New System.Drawing.Point(506, 230)
        Me.btnRandomize.Name = "btnRandomize"
        Me.btnRandomize.Size = New System.Drawing.Size(173, 38)
        Me.btnRandomize.TabIndex = 4
        Me.btnRandomize.Text = "Randomize"
        Me.btnRandomize.UseVisualStyleBackColor = True
        '
        'txtSnackInput
        '
        Me.txtSnackInput.Location = New System.Drawing.Point(215, 397)
        Me.txtSnackInput.Name = "txtSnackInput"
        Me.txtSnackInput.Size = New System.Drawing.Size(255, 20)
        Me.txtSnackInput.TabIndex = 5
        '
        'lblInfo
        '
        Me.lblInfo.Location = New System.Drawing.Point(292, 375)
        Me.lblInfo.Name = "lblInfo"
        Me.lblInfo.Size = New System.Drawing.Size(107, 19)
        Me.lblInfo.TabIndex = 6
        Me.lblInfo.Text = "Type your food here:" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        '
        'grpOutput
        '
        Me.grpOutput.Controls.Add(Me.lstOutput)
        Me.grpOutput.Location = New System.Drawing.Point(507, 65)
        Me.grpOutput.Name = "grpOutput"
        Me.grpOutput.Size = New System.Drawing.Size(172, 159)
        Me.grpOutput.TabIndex = 7
        Me.grpOutput.TabStop = False
        Me.grpOutput.Text = "Output List"
        '
        'lstOutput
        '
        Me.lstOutput.FormattingEnabled = True
        Me.lstOutput.Location = New System.Drawing.Point(14, 21)
        Me.lstOutput.Name = "lstOutput"
        Me.lstOutput.Size = New System.Drawing.Size(148, 121)
        Me.lstOutput.TabIndex = 0
        '
        'btnResetSnacks
        '
        Me.btnResetSnacks.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnResetSnacks.Location = New System.Drawing.Point(215, 301)
        Me.btnResetSnacks.Name = "btnResetSnacks"
        Me.btnResetSnacks.Size = New System.Drawing.Size(90, 20)
        Me.btnResetSnacks.TabIndex = 8
        Me.btnResetSnacks.Text = "Reset Snacks"
        Me.btnResetSnacks.UseVisualStyleBackColor = True
        '
        'btnResetAll
        '
        Me.btnResetAll.Location = New System.Drawing.Point(506, 301)
        Me.btnResetAll.Name = "btnResetAll"
        Me.btnResetAll.Size = New System.Drawing.Size(173, 38)
        Me.btnResetAll.TabIndex = 9
        Me.btnResetAll.Text = "Reset All"
        Me.btnResetAll.UseVisualStyleBackColor = True
        '
        'btnDelete
        '
        Me.btnDelete.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnDelete.Location = New System.Drawing.Point(311, 301)
        Me.btnDelete.Name = "btnDelete"
        Me.btnDelete.Size = New System.Drawing.Size(68, 20)
        Me.btnDelete.TabIndex = 10
        Me.btnDelete.Text = "Delete"
        Me.btnDelete.UseVisualStyleBackColor = True
        '
        'frmSnackChooser
        '
        Me.AcceptButton = Me.btnAdd
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnExit
        Me.ClientSize = New System.Drawing.Size(697, 512)
        Me.Controls.Add(Me.btnDelete)
        Me.Controls.Add(Me.btnResetAll)
        Me.Controls.Add(Me.btnResetSnacks)
        Me.Controls.Add(Me.grpOutput)
        Me.Controls.Add(Me.lblInfo)
        Me.Controls.Add(Me.txtSnackInput)
        Me.Controls.Add(Me.btnRandomize)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.btnAdd)
        Me.Controls.Add(Me.grpFoods)
        Me.Name = "frmSnackChooser"
        Me.Text = "Snack Chooser"
        Me.grpFoods.ResumeLayout(False)
        Me.grpOutput.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents grpFoods As System.Windows.Forms.GroupBox
    Friend WithEvents lstSnacks As System.Windows.Forms.ListBox
    Friend WithEvents btnAdd As System.Windows.Forms.Button
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents btnRandomize As System.Windows.Forms.Button
    Friend WithEvents txtSnackInput As System.Windows.Forms.TextBox
    Friend WithEvents lblInfo As System.Windows.Forms.Label
    Friend WithEvents grpOutput As System.Windows.Forms.GroupBox
    Friend WithEvents lstOutput As System.Windows.Forms.ListBox
    Friend WithEvents btnResetSnacks As System.Windows.Forms.Button
    Friend WithEvents btnResetAll As System.Windows.Forms.Button
    Friend WithEvents btnDelete As System.Windows.Forms.Button

End Class
