object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW6 by109705002'#26446#22825#23527
  ClientHeight = 423
  ClientWidth = 682
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 682
    Height = 423
    Align = alClient
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 680
      Height = 193
      ActivePage = TabSheet1
      Align = alTop
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Singly Linked List'
        object Label1: TLabel
          Left = 16
          Top = 24
          Width = 42
          Height = 13
          Caption = 'Element:'
        end
        object Label2: TLabel
          Left = 22
          Top = 56
          Width = 36
          Height = 13
          Caption = 'Target:'
        end
        object Label3: TLabel
          Left = 48
          Top = 88
          Width = 10
          Height = 13
          Caption = 'n:'
        end
        object Label4: TLabel
          Left = 151
          Top = 87
          Width = 35
          Height = 13
          Caption = 'Range:'
        end
        object Edit1: TEdit
          Left = 64
          Top = 21
          Width = 57
          Height = 21
          TabOrder = 0
          Text = '50'
        end
        object Edit2: TEdit
          Left = 64
          Top = 53
          Width = 57
          Height = 21
          TabOrder = 1
          Text = '50'
        end
        object Button1: TButton
          Left = 160
          Top = 20
          Width = 89
          Height = 25
          Caption = 'Insert First'
          TabOrder = 2
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 255
          Top = 20
          Width = 89
          Height = 25
          Caption = 'Insert Last'
          TabOrder = 3
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 160
          Top = 51
          Width = 89
          Height = 25
          Caption = 'Search Target'
          TabOrder = 4
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 255
          Top = 51
          Width = 121
          Height = 25
          Caption = 'Insert Target Before'
          TabOrder = 5
          OnClick = Button4Click
        end
        object Button5: TButton
          Left = 382
          Top = 51
          Width = 121
          Height = 25
          Caption = 'Insert Target After'
          TabOrder = 6
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 509
          Top = 51
          Width = 89
          Height = 25
          Caption = 'Target Delete'
          TabOrder = 7
          OnClick = Button6Click
        end
        object Edit3: TEdit
          Left = 64
          Top = 84
          Width = 57
          Height = 21
          TabOrder = 8
          Text = '5'
        end
        object Button7: TButton
          Left = 255
          Top = 82
          Width = 248
          Height = 25
          Caption = 'Insert n Random Numbers'
          TabOrder = 9
          OnClick = Button7Click
        end
        object Button8: TButton
          Left = 509
          Top = 82
          Width = 89
          Height = 25
          Caption = 'Clear List'
          TabOrder = 10
          OnClick = Button8Click
        end
        object Edit4: TEdit
          Left = 192
          Top = 84
          Width = 57
          Height = 21
          TabOrder = 11
          Text = '100'
        end
        object Button13: TButton
          Left = 509
          Top = 113
          Width = 89
          Height = 25
          Caption = 'Reverse List'
          TabOrder = 12
          OnClick = Button13Click
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Linked Stack'
        ImageIndex = 1
        object Label5: TLabel
          Left = 16
          Top = 24
          Width = 42
          Height = 13
          Caption = 'Element:'
        end
        object Label6: TLabel
          Left = 16
          Top = 64
          Width = 207
          Height = 48
          Caption = 'POP Result:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -40
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Edit5: TEdit
          Left = 80
          Top = 21
          Width = 49
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Button9: TButton
          Left = 184
          Top = 19
          Width = 75
          Height = 25
          Caption = 'Push'
          TabOrder = 1
          OnClick = Button9Click
        end
        object Button10: TButton
          Left = 288
          Top = 19
          Width = 75
          Height = 25
          Caption = 'Pop'
          TabOrder = 2
          OnClick = Button10Click
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'Linked Queue'
        ImageIndex = 2
        object Label8: TLabel
          Left = 16
          Top = 24
          Width = 42
          Height = 13
          Caption = 'Element:'
        end
        object Label7: TLabel
          Left = 16
          Top = 64
          Width = 148
          Height = 48
          Caption = 'Deleted:'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -40
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Edit6: TEdit
          Left = 80
          Top = 21
          Width = 49
          Height = 21
          TabOrder = 0
          Text = '10'
        end
        object Button11: TButton
          Left = 176
          Top = 19
          Width = 75
          Height = 25
          Caption = 'InsertQ'
          TabOrder = 1
          OnClick = Button11Click
        end
        object Button12: TButton
          Left = 288
          Top = 19
          Width = 75
          Height = 25
          Caption = 'DeleteQ'
          TabOrder = 2
          OnClick = Button12Click
        end
      end
    end
    object PageControl2: TPageControl
      Left = 1
      Top = 194
      Width = 680
      Height = 228
      ActivePage = TabSheet4
      Align = alClient
      TabOrder = 1
      object TabSheet4: TTabSheet
        Caption = 'Singly Linked List Output'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 672
          Height = 200
          Align = alClient
          TabOrder = 0
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Linked Stack Output'
        ImageIndex = 1
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 672
          Height = 200
          Align = alClient
          TabOrder = 0
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'Linked Queue Output'
        ImageIndex = 2
        object Memo3: TMemo
          Left = 0
          Top = 0
          Width = 672
          Height = 200
          Align = alClient
          TabOrder = 0
        end
      end
    end
  end
end
