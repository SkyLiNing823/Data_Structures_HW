object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW7 by109705002'#26446#22825#23527
  ClientHeight = 485
  ClientWidth = 736
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
    Left = 249
    Top = 0
    Width = 487
    Height = 485
    Align = alClient
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 249
    Height = 485
    Align = alLeft
    TabOrder = 1
    object Label1: TLabel
      Left = 40
      Top = 40
      Width = 42
      Height = 13
      Caption = 'Element:'
    end
    object Edit1: TEdit
      Left = 88
      Top = 37
      Width = 121
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '50'
    end
    object Button1: TButton
      Left = 40
      Top = 80
      Width = 169
      Height = 25
      Caption = 'Insert into BST'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 40
      Top = 111
      Width = 169
      Height = 25
      Caption = 'Delete from BST'
      TabOrder = 2
      OnClick = Button2Click
    end
    object GroupBox1: TGroupBox
      Left = 24
      Top = 168
      Width = 201
      Height = 185
      TabOrder = 3
      object Label2: TLabel
        Left = 49
        Top = 28
        Width = 9
        Height = 13
        Caption = 'k:'
      end
      object Label3: TLabel
        Left = 23
        Top = 72
        Width = 35
        Height = 13
        Caption = 'Range:'
      end
      object Edit2: TEdit
        Left = 64
        Top = 26
        Width = 121
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '10'
      end
      object Edit3: TEdit
        Left = 64
        Top = 67
        Width = 121
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '100'
      end
      object Button3: TButton
        Left = 23
        Top = 120
        Width = 162
        Height = 41
        Caption = 'Random Intergers'
        TabOrder = 2
        OnClick = Button3Click
      end
    end
  end
  object Memo1: TMemo
    Left = 249
    Top = 0
    Width = 487
    Height = 485
    Align = alClient
    TabOrder = 2
  end
end
