object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'B1 (Bonus)  by 109705002 '#26446#22825#23527
  ClientHeight = 458
  ClientWidth = 747
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
    Left = 225
    Top = 0
    Width = 0
    Height = 458
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 225
    Height = 458
    Align = alLeft
    TabOrder = 0
    object Splitter2: TSplitter
      Left = 1
      Top = 1
      Height = 456
      ExplicitLeft = 231
      ExplicitTop = 2
    end
    object GroupBox1: TGroupBox
      Left = 18
      Top = 24
      Width = 185
      Height = 176
      Caption = 'POWER'
      TabOrder = 0
      object Label1: TLabel
        Left = 22
        Top = 23
        Width = 17
        Height = 13
        Caption = 'x ='
      end
      object Label2: TLabel
        Left = 22
        Top = 50
        Width = 17
        Height = 13
        Caption = 'n ='
      end
      object Label3: TLabel
        Left = 133
        Top = 87
        Width = 33
        Height = 13
        Caption = 'time(s)'
      end
      object Button1: TButton
        Left = 22
        Top = 127
        Width = 144
        Height = 33
        Caption = 'x^n'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit1: TEdit
        Left = 45
        Top = 20
        Width = 121
        Height = 21
        TabOrder = 1
        Text = '2'
      end
      object Edit2: TEdit
        Left = 45
        Top = 47
        Width = 121
        Height = 21
        TabOrder = 2
        Text = '30'
      end
      object Edit3: TEdit
        Left = 22
        Top = 84
        Width = 105
        Height = 21
        TabOrder = 3
        Text = '100000000'
      end
    end
    object GroupBox2: TGroupBox
      Left = 18
      Top = 232
      Width = 185
      Height = 177
      Caption = 'POLYNOMIALS'
      TabOrder = 1
      object Label4: TLabel
        Left = 22
        Top = 29
        Width = 16
        Height = 13
        Caption = 'k ='
      end
      object Label5: TLabel
        Left = 22
        Top = 51
        Width = 17
        Height = 13
        Caption = 'n ='
      end
      object Label6: TLabel
        Left = 133
        Top = 80
        Width = 33
        Height = 13
        Caption = 'time(s)'
      end
      object Edit4: TEdit
        Left = 44
        Top = 24
        Width = 122
        Height = 21
        TabOrder = 0
        Text = '5'
      end
      object Button2: TButton
        Left = 22
        Top = 112
        Width = 144
        Height = 33
        Caption = 'Doing f(x)'
        TabOrder = 1
        OnClick = Button2Click
      end
      object Edit5: TEdit
        Left = 45
        Top = 51
        Width = 122
        Height = 21
        TabOrder = 2
        Text = '5'
      end
      object Edit6: TEdit
        Left = 22
        Top = 78
        Width = 105
        Height = 21
        TabOrder = 3
        Text = '100000000'
      end
    end
  end
  object PageControl1: TPageControl
    Left = 225
    Top = 0
    Width = 522
    Height = 458
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Power'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 514
        Height = 430
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Polynomial'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 514
        Height = 430
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
