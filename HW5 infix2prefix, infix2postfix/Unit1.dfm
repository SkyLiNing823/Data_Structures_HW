object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW5 infix2prefix&postfix by 109705002 '#26446#22825#23527
  ClientHeight = 459
  ClientWidth = 661
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 661
    Height = 161
    ActivePage = TabSheet1
    Align = alTop
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Infix'
      object Label1: TLabel
        Left = 330
        Top = 0
        Width = 289
        Height = 13
        Caption = 'Only Binary Operands in {+,-,*,/,^} are considered.'
        Color = clRed
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 112
        Top = 29
        Width = 520
        Height = 21
        TabOrder = 0
        Text = '(A+B)*C^(D+E*F-G*(H+J))'
      end
      object Edit2: TEdit
        Left = 112
        Top = 56
        Width = 520
        Height = 21
        TabOrder = 1
      end
      object Edit3: TEdit
        Left = 112
        Top = 83
        Width = 520
        Height = 21
        TabOrder = 2
      end
      object Button1: TButton
        Left = 16
        Top = 56
        Width = 90
        Height = 21
        Caption = 'Infix => Prefix'
        TabOrder = 3
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 16
        Top = 83
        Width = 90
        Height = 21
        Caption = 'Infix => Postfix'
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prefix'
      ImageIndex = 1
      object Label2: TLabel
        Left = 330
        Top = 0
        Width = 289
        Height = 13
        Caption = 'Only Binary Operands in {+,-,*,/,^} are considered.'
        Color = clRed
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object Button3: TButton
        Left = 16
        Top = 83
        Width = 90
        Height = 21
        Caption = 'Prefix => Postfix'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 16
        Top = 56
        Width = 90
        Height = 21
        Caption = 'Prefix => Infix'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Edit4: TEdit
        Left = 112
        Top = 29
        Width = 520
        Height = 21
        TabOrder = 2
        Text = '*+AB^C-+D*EF*G+HJ'
      end
      object Edit5: TEdit
        Left = 112
        Top = 56
        Width = 520
        Height = 21
        TabOrder = 3
      end
      object Edit6: TEdit
        Left = 112
        Top = 83
        Width = 520
        Height = 21
        TabOrder = 4
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Postfix'
      ImageIndex = 2
      object Label3: TLabel
        Left = 330
        Top = 0
        Width = 289
        Height = 13
        Caption = 'Only Binary Operands in {+,-,*,/,^} are considered.'
        Color = clRed
        Font.Charset = EASTEUROPE_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
      end
      object Edit7: TEdit
        Left = 112
        Top = 29
        Width = 520
        Height = 21
        TabOrder = 0
        Text = 'AB+CDEF*+GHJ+*-^*'
      end
      object Edit8: TEdit
        Left = 112
        Top = 56
        Width = 520
        Height = 21
        TabOrder = 1
      end
      object Edit9: TEdit
        Left = 112
        Top = 83
        Width = 520
        Height = 21
        TabOrder = 2
      end
      object Button5: TButton
        Left = 16
        Top = 83
        Width = 90
        Height = 21
        Caption = 'Postfix => Prefix'
        TabOrder = 3
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 16
        Top = 56
        Width = 90
        Height = 21
        Caption = 'Postfix => Infix'
        TabOrder = 4
        OnClick = Button6Click
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 161
    Width = 661
    Height = 298
    Align = alClient
    TabOrder = 1
    object Memo1: TMemo
      Left = 1
      Top = 1
      Width = 659
      Height = 296
      Align = alClient
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
end
