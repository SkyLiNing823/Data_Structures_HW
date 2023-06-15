object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Permutations and Hanoi Towers  by '#26446#22825#23527
  ClientHeight = 457
  ClientWidth = 660
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 185
    Top = 0
    Height = 457
    ExplicitLeft = 288
    ExplicitTop = 104
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 457
    Align = alLeft
    TabOrder = 0
    object PageControl2: TPageControl
      Left = 1
      Top = 1
      Width = 183
      Height = 240
      ActivePage = TabSheet4
      Align = alTop
      TabOrder = 0
      object TabSheet4: TTabSheet
        Caption = 'Permute"ABC..."'
        object Label1: TLabel
          Left = 21
          Top = 33
          Width = 19
          Height = 16
          Caption = 'k ='
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 21
          Top = 68
          Width = 20
          Height = 16
          Caption = 'n ='
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 105
          Top = 106
          Width = 50
          Height = 16
          Caption = '(n <= 9)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Button1: TButton
          Left = 21
          Top = 144
          Width = 134
          Height = 33
          Caption = 'Permutations'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Edit1: TEdit
          Left = 46
          Top = 32
          Width = 109
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Edit2: TEdit
          Left = 47
          Top = 67
          Width = 108
          Height = 21
          TabOrder = 2
          Text = '4'
        end
        object CheckBox1: TCheckBox
          Left = 21
          Top = 107
          Width = 52
          Height = 17
          Caption = 'Tracing'
          Checked = True
          State = cbChecked
          TabOrder = 3
        end
      end
      object TabSheet5: TTabSheet
        Caption = 'Arbitrary Input'
        ImageIndex = 1
        object Label5: TLabel
          Left = -112
          Top = 288
          Width = 32
          Height = 13
          Caption = 'String:'
        end
        object Label6: TLabel
          Left = 15
          Top = 18
          Width = 32
          Height = 13
          Caption = 'String:'
        end
        object Label7: TLabel
          Left = 15
          Top = 72
          Width = 19
          Height = 13
          Caption = 'k = '
        end
        object CheckBox2: TCheckBox
          Left = 15
          Top = 96
          Width = 97
          Height = 17
          Caption = 'Tracing'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object Edit4: TEdit
          Left = 15
          Top = 37
          Width = 146
          Height = 21
          TabOrder = 1
          Text = 'ABCD'
        end
        object Edit5: TEdit
          Left = 40
          Top = 69
          Width = 121
          Height = 21
          TabOrder = 2
          Text = '0'
        end
        object Button3: TButton
          Left = 15
          Top = 119
          Width = 146
          Height = 33
          Caption = 'Permutation'
          TabOrder = 3
          OnClick = Button3Click
        end
      end
      object TabSheet6: TTabSheet
        Caption = 'Towers of Hanoi'
        ImageIndex = 2
        object Label4: TLabel
          Left = 16
          Top = 32
          Width = 76
          Height = 13
          Caption = 'Number of Disk:'
        end
        object Edit3: TEdit
          Left = 98
          Top = 29
          Width = 52
          Height = 21
          TabOrder = 0
          Text = '3'
        end
        object Button2: TButton
          Left = 16
          Top = 104
          Width = 134
          Height = 33
          Caption = 'Tower of Hanoi'
          TabOrder = 1
          OnClick = Button2Click
        end
        object CheckBox3: TCheckBox
          Left = 16
          Top = 64
          Width = 97
          Height = 17
          Caption = 'Tracing'
          Checked = True
          State = cbChecked
          TabOrder = 2
        end
      end
    end
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 0
    Width = 472
    Height = 457
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Permutations'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 464
        Height = 429
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Permutation-Tracing'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 464
        Height = 429
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
