object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Bonus 3 by 109705002'#26446#22825#23527
  ClientHeight = 477
  ClientWidth = 806
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
    Left = 249
    Top = 0
    Height = 477
    ExplicitLeft = 344
    ExplicitTop = 184
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 249
    Height = 477
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 40
      Top = 63
      Width = 67
      Height = 16
      Caption = 'coefficient: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 46
      Top = 90
      Width = 61
      Height = 16
      Caption = 'exponent: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 40
      Top = 19
      Width = 169
      Height = 35
      Caption = 'new term in Poly A'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 40
      Top = 117
      Width = 169
      Height = 35
      Caption = 'new term in Poly B'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 113
      Top = 60
      Width = 96
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '1'
    end
    object Edit2: TEdit
      Left = 113
      Top = 87
      Width = 96
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '0'
    end
    object GroupBox1: TGroupBox
      Left = 24
      Top = 158
      Width = 201
      Height = 131
      Caption = 'radom setting'
      TabOrder = 4
      object Label3: TLabel
        Left = 50
        Top = 23
        Width = 64
        Height = 16
        Caption = 'max expo: '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 16
        Top = 50
        Width = 98
        Height = 16
        Caption = 'max range:(+/-) '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit3: TEdit
        Left = 120
        Top = 20
        Width = 64
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = '4'
      end
      object Edit4: TEdit
        Left = 120
        Top = 50
        Width = 64
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = '5'
      end
      object Button3: TButton
        Left = 16
        Top = 80
        Width = 169
        Height = 35
        Caption = 'random polys. A and B'
        TabOrder = 2
        OnClick = Button3Click
      end
    end
    object Button4: TButton
      Left = 40
      Top = 318
      Width = 169
      Height = 35
      Caption = 'C = A + B'
      TabOrder = 5
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 40
      Top = 374
      Width = 169
      Height = 35
      Caption = 'Clear'
      TabOrder = 6
      OnClick = Button5Click
    end
  end
  object PageControl1: TPageControl
    Left = 252
    Top = 0
    Width = 554
    Height = 477
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Polynomial'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 546
        Height = 449
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Addition'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 546
        Height = 449
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
end
