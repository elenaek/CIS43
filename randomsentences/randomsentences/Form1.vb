Public Class frmRandomSentences
    Dim strNoun = New String() {"fang", "ninja", "train", "dog", "man", "woman", "quicksand", "army", "ferret", "magnet", "firefighter"}
    Dim strAdj = New String() {"demure", "banal", "quaint", "unsightly", "beautiful", "zealous", "witty", "young", "swift", "abundant", "tasteless", "modern", "lively", "gentle", "happily"}
    Dim strVerb() = New String() {"scared", "jumped", "dropped", "ran", "fought", "attracted", "blinked", "flipped", "fell", "tripped"}
    Dim strPrep() = New String() {"for", "from", "as", "down", "in", "into", "over", "under", "between", "behind", "off", "of", "on", "above", "about", "across", "after", "against", "along", "behind"}
    Dim strArt() = New String() {"the", "one", "a", "some", "another"}

    Private Sub btnExit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub

    Private Sub btnNext_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnNext.Click
        Dim strResult As String = StrConv(getWord("article"), VbStrConv.ProperCase) & " " & getWord("adjective") & " " & getWord("noun") & " " & getWord("verb") & " " & getWord("preposition") & " " & getWord("article") & " " & getWord("adjective") & " " & getWord("noun") & "."
        lbSentences.Items.Add(strResult)
    End Sub

    Function getWord(ByVal type As String)
        Randomize()
        Select Case type.ToLower()
            Case "noun"
                Dim rand As Integer = CInt(Int((UBound(strNoun) * Rnd()) + 0))
                Return strNoun(rand)
            Case "verb"
                Dim rand As Integer = CInt(Int((UBound(strVerb) * Rnd()) + 0))
                Return strVerb(rand)
            Case "preposition"
                Dim rand As Integer = CInt(Int((UBound(strPrep) * Rnd()) + 0))
                Return strPrep(rand)
            Case "article"
                Dim rand As Integer = CInt(Int((UBound(strArt) * Rnd()) + 0))
                Return strArt(rand)
            Case "adjective"
                Dim rand As Integer = CInt(Int((UBound(strAdj) * Rnd()) + 0))
                Return strAdj(rand)
            Case Else
                Return "No such type of word."
        End Select
        'Return "No such type of word."
    End Function


    Private Sub btnClear_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnClear.Click
        lbSentences.Items.Clear()
    End Sub
End Class
