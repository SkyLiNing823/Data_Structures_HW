object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'HW9 by 109705002'#26446#22825#23527
  ClientHeight = 604
  ClientWidth = 910
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
    Left = 257
    Top = 0
    Height = 604
    ExplicitLeft = 328
    ExplicitTop = 224
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 257
    Height = 604
    Align = alLeft
    TabOrder = 0
    object Label4: TLabel
      Left = 24
      Top = 421
      Width = 34
      Height = 13
      Caption = 'Check'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object GroupBox1: TGroupBox
      Left = 24
      Top = 24
      Width = 209
      Height = 137
      Caption = 'Input'
      TabOrder = 0
      object Label1: TLabel
        Left = 51
        Top = 36
        Width = 48
        Height = 16
        Caption = 'Times ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 78
        Top = 62
        Width = 21
        Height = 16
        Caption = 'N ='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 54
        Top = 89
        Width = 45
        Height = 16
        Caption = 'Range='
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 105
        Top = 35
        Width = 88
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Edit2: TEdit
        Left = 105
        Top = 61
        Width = 88
        Height = 21
        TabOrder = 1
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 105
        Top = 88
        Width = 88
        Height = 21
        TabOrder = 2
        Text = '10000'
      end
    end
    object GroupBox2: TGroupBox
      Left = 24
      Top = 167
      Width = 209
      Height = 242
      Caption = 'Sorting'
      TabOrder = 1
      object CheckBox1: TCheckBox
        Left = 16
        Top = 24
        Width = 97
        Height = 17
        Caption = 'Selection sort'
        Checked = True
        State = cbChecked
        TabOrder = 0
      end
      object CheckBox2: TCheckBox
        Left = 16
        Top = 47
        Width = 97
        Height = 17
        Caption = ' Insertion sort'
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
      object CheckBox3: TCheckBox
        Left = 16
        Top = 70
        Width = 97
        Height = 17
        Caption = 'Bubble sort'
        Checked = True
        State = cbChecked
        TabOrder = 2
      end
      object CheckBox4: TCheckBox
        Left = 16
        Top = 93
        Width = 161
        Height = 17
        Caption = 'Quick sort (recursive versions)'
        Checked = True
        State = cbChecked
        TabOrder = 3
      end
      object CheckBox5: TCheckBox
        Left = 16
        Top = 116
        Width = 190
        Height = 17
        Caption = 'Quick sort (non-recursive versions)'
        Checked = True
        State = cbChecked
        TabOrder = 4
      end
      object CheckBox6: TCheckBox
        Left = 16
        Top = 139
        Width = 177
        Height = 17
        Caption = 'Merge sort (recursive versions)'
        Checked = True
        State = cbChecked
        TabOrder = 5
      end
      object CheckBox7: TCheckBox
        Left = 16
        Top = 162
        Width = 190
        Height = 17
        Caption = 'Merge sort (non-recursive versions)'
        Checked = True
        State = cbChecked
        TabOrder = 6
      end
      object CheckBox8: TCheckBox
        Left = 16
        Top = 185
        Width = 97
        Height = 17
        Caption = 'Heap sort'
        Checked = True
        State = cbChecked
        TabOrder = 7
      end
      object CheckBox9: TCheckBox
        Left = 16
        Top = 208
        Width = 97
        Height = 17
        Caption = 'Radix sort'
        Checked = True
        State = cbChecked
        TabOrder = 8
      end
    end
    object Button1: TButton
      Left = 120
      Top = 352
      Width = 97
      Height = 41
      Caption = 'Run'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Memo2: TMemo
      Left = 24
      Top = 440
      Width = 209
      Height = 145
      ScrollBars = ssBoth
      TabOrder = 3
    end
  end
  object PageControl1: TPageControl
    Left = 260
    Top = 0
    Width = 650
    Height = 604
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Diagrams'
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 642
        Height = 576
        Title.Text.Strings = (
          'TChart')
        Chart3DPercent = 19
        View3D = False
        View3DOptions.HorizOffset = 14
        View3DOptions.Zoom = 65
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TLineSeries
          Shadow.Transparency = 52
          Brush.BackColor = clDefault
          Dark3D = False
          LinePen.Width = 0
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series2: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series3: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series4: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series5: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series6: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series7: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series8: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series9: TLineSeries
          Brush.BackColor = clDefault
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Data'
      ImageIndex = 1
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 642
        Height = 576
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
