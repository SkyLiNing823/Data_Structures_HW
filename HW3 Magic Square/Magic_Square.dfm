object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW3 Magic_Square by '#26446#22825#23527
  ClientHeight = 452
  ClientWidth = 768
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
    Height = 452
    ExplicitLeft = 184
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 0
    Width = 580
    Height = 452
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Left-Up'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 572
        Height = 424
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Left-Down'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 572
        Height = 424
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
        ExplicitLeft = -1
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Right-Up'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 572
        Height = 424
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Right-Down'
      ImageIndex = 3
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 572
        Height = 424
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 452
    Align = alLeft
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 48
      Width = 88
      Height = 19
      Caption = 'Square Size:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 40
      Top = 108
      Width = 113
      Height = 16
      Caption = '( 3 <= size <= 21 )'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 24
      Top = 81
      Width = 129
      Height = 21
      TabOrder = 0
      Text = '7'
    end
    object Button1: TButton
      Left = 24
      Top = 160
      Width = 129
      Height = 33
      Caption = 'Magic Square'
      TabOrder = 1
      OnClick = Button1Click
    end
  end
end
