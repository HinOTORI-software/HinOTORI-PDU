object FormNet: TFormNet
  Left = 318
  Top = 126
  BorderStyle = bsNone
  Caption = 'FormNet'
  ClientHeight = 541
  ClientWidth = 642
  Color = 14671839
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  DesignSize = (
    642
    541)
  PixelsPerInch = 96
  TextHeight = 13
  object PanelMain: TPanel
    Left = 4
    Top = 31
    Width = 626
    Height = 505
    Anchors = [akLeft, akTop, akRight, akBottom]
    BevelOuter = bvNone
    Caption = '0x00DFDFDF'
    TabOrder = 0
    object PanelBottomRight: TPanel
      Left = 0
      Top = 472
      Width = 626
      Height = 33
      Align = alBottom
      BevelOuter = bvNone
      Color = 14671839
      TabOrder = 0
      DesignSize = (
        626
        33)
      object Image2: TImage
        Left = 4
        Top = 10
        Width = 16
        Height = 16
        Anchors = [akLeft, akBottom]
        Center = True
        ParentShowHint = False
        Picture.Data = {
          07544269746D617036030000424D360300000000000036000000280000001500
          00000C000000010018000000000000030000C30E0000C30E0000000000000000
          0000FFFFFF9B9B9B737373E7E7E7F2F2F27F84826D7270727572707777727878
          726D6A858885E3E2E1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF8F8D8D2E3B3A537C767CD4CF6ACDC8A5DAD27D9999658888
          75E8E1A1DCD79EABA8ECECECFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF858081315D5375F6EF85FFFF88FFFF8BFFFF686A6B321F1D
          3053524042412F3738A4A2A1FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF847C7C3898968BFFFF88FFFF65F2F364989A21383963B4AB
          5EA19A5FA9A16CA59D656864FDFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF847C7C459B9B8FFFFF5FE8E972928A5F42375D53533D8383
          477F7F3B84844863634A5353E2E2E2FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF837C7C4A9B9B8AFFFF68EEEF9FE4DEC2A2924E3C363F6F67
          496D653D6B6445736C47726A949090FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFF857C7C319B9B86FFFF84FFFF7FFFFF82D6D36D4B4555B7B6
          68B8B854BDBC66BDBC0078778F9090F9F9F9F8F8F8F7F7F7F8F8F8F3F3F3FEFE
          FE00FFFFFFFFFFFF7E7C7C989B9BA6FFFF7CFFFF7AFFFF75FFFF65BBB46E524B
          3427241C15122A3F3935413A51676251625C51615C4A605C44554FA0AAA7E3E2
          E100FFFFFFFFFFFF848585695F5FA9BEBED2FDFDE4FFFF8AFFFF9BFFFFB6FBF7
          73E7E34E6255837B7671EAE77BDDD972DDDA72DDDA7BDDD971DEDAA8EFEC94AA
          AA00FFFFFFB6B6B69F9F9FF7F7F7FDFDFDE7E8E8E9E3E3B2BFBFC6BABA88ECEC
          BBFFFF7BF2ED6679729C9E9FB0B2B2ACAFAFACAFAFADAFAFACAFAFA2A5A6F6F6
          F600FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9F9F9D5D5D5DDDDDDDCDCDCDEE7E7
          B4C1C1EEFFFF90CECEEBEBEBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFAFA
          F2F2F2D6DADADFE4E4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF00}
        ShowHint = True
        Transparent = True
      end
      object HintLabel: TLabel
        Left = 29
        Top = 12
        Width = 332
        Height = 12
        Anchors = [akLeft, akRight, akBottom]
        AutoSize = False
        Caption = 'Finish'
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        Transparent = True
      end
      object Btn_ResetCounter: TSpeedButton
        Left = 544
        Top = 10
        Width = 75
        Height = 16
        Hint = #21457#36865'/'#25509#25910#35745#25968#22120#28165#38646
        Anchors = [akRight, akBottom]
        Caption = 'Reset Counter '
        ParentShowHint = False
        ShowHint = True
        OnClick = Btn_ResetCounterClick
      end
      object StaticTextSend: TStaticText
        Left = 333
        Top = 9
        Width = 99
        Height = 17
        Hint = #24050#32463#21457#36865#30340#23383#33410#25968
        Alignment = taCenter
        Anchors = [akRight, akBottom]
        AutoSize = False
        BorderStyle = sbsSunken
        Caption = 'Send : 0'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
      end
      object StaticTextRecv: TStaticText
        Left = 440
        Top = 9
        Width = 100
        Height = 17
        Hint = #24050#32463#25509#25910#21040#30340#23383#33410#25968
        Alignment = taCenter
        Anchors = [akRight, akBottom]
        AutoSize = False
        BorderStyle = sbsSunken
        Caption = 'Receive : 0'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
    end
    object PanelRight2: TPanel
      Left = 0
      Top = 0
      Width = 160
      Height = 472
      Align = alLeft
      BevelOuter = bvNone
      Color = 14671839
      TabOrder = 1
      DesignSize = (
        160
        472)
      object GroupBox_Network: TGroupBox
        Left = 8
        Top = 0
        Width = 145
        Height = 181
        Caption = 'Network Settings'
        Color = 14671839
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        TabOrder = 0
        object Label_Protocol: TLabel
          Left = 10
          Top = 17
          Width = 102
          Height = 13
          AutoSize = False
          BiDiMode = bdLeftToRight
          Caption = #65288'1'#65289'Protocol Type'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentBiDiMode = False
          ParentFont = False
        end
        object Label_IPAddress: TLabel
          Left = 10
          Top = 61
          Width = 117
          Height = 13
          AutoSize = False
          Caption = #65288'2'#65289'Local IP Address'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object Label_PortNum: TLabel
          Left = 10
          Top = 105
          Width = 127
          Height = 13
          AutoSize = False
          Caption = #65288'3'#65289'Local Port Number'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
        end
        object cmBtn_NetConnect: TSpeedButton
          Left = 12
          Top = 144
          Width = 125
          Height = 29
          Caption = 'Connect'
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #38582#20070
          Font.Style = []
          ParentFont = False
          OnClick = cmBtn_NetConnectClick
        end
        object ComboBox_Protocol: TComboBox
          Left = 14
          Top = 32
          Width = 121
          Height = 21
          Hint = #26356#25913#21327#35758#31867#22411
          Style = csDropDownList
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          ItemHeight = 13
          ItemIndex = 0
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Text = '   UDP'
          OnChange = ComboBox_ProtocolChange
          Items.Strings = (
            '   UDP'
            '  TCP Server'
            '  TCP Client')
        end
        object Edit_PortNUM: TEdit
          Left = 14
          Top = 119
          Width = 119
          Height = 21
          Hint = #26356#25913#31471#21475#21495
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          MaxLength = 5
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          Text = '0'
          OnKeyPress = EditNumKeyPress
        end
        object Edit_IPAddess: TEdit
          Left = 13
          Top = 76
          Width = 120
          Height = 21
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          TabOrder = 2
          Text = '192.168.10.1'
        end
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 184
        Width = 145
        Height = 172
        Anchors = [akLeft, akBottom]
        Caption = 'Send Setup'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object Label_Loaddata: TLabel
          Left = 8
          Top = 147
          Width = 69
          Height = 12
          Cursor = crHandPoint
          Hint = #20174#22806#37096#25991#20214#23548#20837#36755#20837#26694
          Alignment = taCenter
          AutoSize = False
          Caption = 'import file'
          Color = clBtnFace
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlue
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = [fsUnderline]
          ParentColor = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          Transparent = True
          OnClick = Label_LoaddataClick
        end
        object Label_ClearSend: TLabel
          Left = 85
          Top = 147
          Width = 55
          Height = 12
          Cursor = crHandPoint
          Hint = #28165#31354#36755#20837#26694#20869#23481
          Alignment = taCenter
          AutoSize = False
          Caption = 'Clear '
          Color = clBtnFace
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlue
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = [fsUnderline]
          ParentColor = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          Transparent = True
          OnClick = Label_ClearSendClick
        end
        object Label_IntervalUnit: TLabel
          Left = 109
          Top = 124
          Width = 33
          Height = 13
          AutoSize = False
          Caption = #27627#31186
          Transparent = True
          Visible = False
        end
        object Label_Interval: TLabel
          Left = 14
          Top = 124
          Width = 64
          Height = 13
          AutoSize = False
          Caption = #21457#36865#38388#38548
          Transparent = True
          Visible = False
        end
        object CheckBox_SendAutoChecksum: TCheckBox
          Left = 13
          Top = 40
          Width = 124
          Height = 17
          Hint = #27599#21457#36865#19968#32452#25968#25454#65292#33258#21160#22312#26411#23614#21152#19978#26657#39564#20301
          Caption = #33258#21160#21457#36865#38468#21152#20301
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          Visible = False
          OnClick = CheckBox_SendAutoChecksumClick
        end
        object CheckBox_SendRecycled: TCheckBox
          Left = 13
          Top = 97
          Width = 113
          Height = 18
          Hint = #25351#20196#24490#29615#21457#36865
          Caption = #25968#25454#27969#24490#29615#21457#36865
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          Visible = False
        end
        object CheckBox_ClearAfterSend: TCheckBox
          Left = 13
          Top = 59
          Width = 124
          Height = 18
          Hint = #25968#25454#21457#36865#23436#65292#28165#31354#36755#20837#26694
          Caption = 'Clear after send'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
        end
        object CheckBox_SendAsHex: TCheckBox
          Left = 13
          Top = 78
          Width = 123
          Height = 17
          Hint = #36755#20837#26694#20869#23481#21313#20845#36827#21046#36716#25442
          Caption = 'Send by HEX'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
        end
        object Edit_SendInterval: TEdit
          Left = 71
          Top = 121
          Width = 36
          Height = 21
          Hint = #25351#20196#21457#36865#21450#25351#20196#24490#29615#30340#38388#38548
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          MaxLength = 8
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 5
          Text = '1000'
          Visible = False
          OnKeyPress = EditNumKeyPress
        end
        object CheckBox_FileInput: TCheckBox
          Left = 13
          Top = 20
          Width = 128
          Height = 18
          Hint = #20174#22806#37096#25991#20214#35835#21462#25968#25454#21457#36865'...'
          Caption = #21551#29992#25991#20214#25968#25454#28304'...'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Visible = False
          OnClick = CheckBox_FileInputClick
        end
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 360
        Width = 145
        Height = 127
        Caption = 'Receive Setup'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        object Label_ClearRecv: TLabel
          Left = 70
          Top = 103
          Width = 55
          Height = 12
          Cursor = crHandPoint
          Hint = #28165#31354#25509#25910#21306#26174#31034#20869#23481
          Alignment = taCenter
          AutoSize = False
          Caption = 'Clear'
          Color = clBtnFace
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlue
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = [fsUnderline]
          ParentColor = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          Transparent = True
          OnClick = Label_ClearRecvClick
        end
        object Label_SaveData: TLabel
          Left = 11
          Top = 103
          Width = 55
          Height = 12
          Cursor = crHandPoint
          Hint = #23558#25509#25910#21306#30340#20869#23481#20445#23384#21040#25991#20214'...'
          Alignment = taCenter
          AutoSize = False
          Caption = 'Save Data'
          Color = clBtnFace
          Font.Charset = GB2312_CHARSET
          Font.Color = clBlue
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = [fsUnderline]
          ParentColor = False
          ParentFont = False
          ParentShowHint = False
          ShowHint = True
          Transparent = True
          OnClick = Label_SaveDataClick
        end
        object CheckBox_ReceiveAutoReturn: TCheckBox
          Left = 13
          Top = 39
          Width = 124
          Height = 17
          Hint = #33258#21160#25442#34892#65306#27599#25910#21040#19968#32452#25968#25454#65292#33258#21160#21152#22238#36710
          Caption = 'auto linefeed'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = CheckBox_ReceiveAutoReturnClick
        end
        object CheckBox_ReceiveShowHex: TCheckBox
          Left = 13
          Top = 59
          Width = 116
          Height = 16
          Hint = #25509#25910#21306#20197#21313#20845#36827#21046#26174#31034
          Caption = 'hexadecimal'
          Checked = True
          ParentShowHint = False
          ShowHint = True
          State = cbChecked
          TabOrder = 2
        end
        object CheckBox_PauseReceive: TCheckBox
          Left = 13
          Top = 79
          Width = 124
          Height = 16
          Hint = #25509#25910#21306#26242#20572'/'#32487#32493#25968#25454#25509#25910
          Caption = #26242#20572#25509#25910#26174#31034
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          Visible = False
          OnClick = CheckBox_PauseReceiveClick
        end
        object CheckBox_FileOutput: TCheckBox
          Left = 13
          Top = 18
          Width = 124
          Height = 19
          Hint = #33258#21160#23558#25509#25910#21040#30340#25968#25454#20445#23384#33267#25991#20214'...'
          Caption = #25509#25910#36716#21521#25991#20214'...'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          Visible = False
          OnClick = CheckBox_FileOutputClick
        end
      end
      object GroupBox1: TGroupBox
        Left = 160
        Top = 76
        Width = 185
        Height = 101
        Caption = 'GroupBox1'
        TabOrder = 3
      end
    end
    object Panel4: TPanel
      Left = 160
      Top = 0
      Width = 466
      Height = 472
      Align = alClient
      BevelOuter = bvNone
      Color = 14671839
      TabOrder = 2
      object Splitter2: TSplitter
        Left = 0
        Top = 461
        Width = 466
        Height = 11
        Cursor = crVSplit
        Align = alBottom
      end
      object Panel5: TPanel
        Left = 0
        Top = 40
        Width = 459
        Height = 265
        BevelOuter = bvNone
        TabOrder = 0
        object GroupCH8: TGroupBox
          Left = 340
          Top = 152
          Width = 101
          Height = 105
          Caption = 'Channel 8'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 32
          object LabelNOW8: TLabel
            Left = 12
            Top = 80
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH7: TGroupBox
          Left = 228
          Top = 152
          Width = 105
          Height = 105
          Caption = 'Channel 7'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 31
          object LabelNOW7: TLabel
            Left = 12
            Top = 80
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH6: TGroupBox
          Left = 116
          Top = 152
          Width = 105
          Height = 105
          Caption = 'Channel 6'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 30
          object LabelNOW6: TLabel
            Left = 12
            Top = 80
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH5: TGroupBox
          Left = 12
          Top = 152
          Width = 97
          Height = 105
          Caption = 'Channel 5'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          object LabelNOW5: TLabel
            Left = 12
            Top = 80
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH4: TGroupBox
          Left = 340
          Top = 32
          Width = 101
          Height = 109
          Caption = 'Channel 4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
          object LabelNOW4: TLabel
            Left = 12
            Top = 84
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH3: TGroupBox
          Left = 228
          Top = 32
          Width = 105
          Height = 109
          Caption = 'Channel 3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          object LabelNOW3: TLabel
            Left = 12
            Top = 84
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH2: TGroupBox
          Left = 116
          Top = 32
          Width = 105
          Height = 109
          Caption = 'Channel 2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
          object labelNOW2: TLabel
            Left = 12
            Top = 84
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object GroupCH1: TGroupBox
          Left = 12
          Top = 32
          Width = 97
          Height = 109
          Caption = 'Channel 1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
          object labelNOW1: TLabel
            Left = 14
            Top = 84
            Width = 27
            Height = 13
            Caption = 'CMD:'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
          end
        end
        object Btn_Send: TPanel
          Left = 226
          Top = 244
          Width = 99
          Height = 33
          BevelInner = bvRaised
          Caption = 'Channel 1 ON'
          Color = 14671839
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Visible = False
          OnClick = Btn_SendClick
          OnMouseDown = Btn_SendMouseDown
          OnMouseUp = Btn_SendMouseUp
        end
        object CH1OFF: TButton
          Left = 16
          Top = 80
          Width = 89
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clGreen
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = CH1OFFClick
        end
        object CH2ON: TButton
          Left = 120
          Top = 48
          Width = 93
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = CH2ONClick
        end
        object CH2OFF: TButton
          Left = 120
          Top = 80
          Width = 93
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = CH2OFFClick
        end
        object CH3ON: TButton
          Left = 232
          Top = 48
          Width = 93
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = CH3ONClick
        end
        object CH1ON: TButton
          Left = 16
          Top = 48
          Width = 89
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          OnClick = CH1ONClick
        end
        object CH3OFF: TButton
          Left = 232
          Top = 80
          Width = 93
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = CH3OFFClick
        end
        object CH4ON: TButton
          Left = 344
          Top = 48
          Width = 89
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          OnClick = CH4ONClick
        end
        object CH4OFF: TButton
          Left = 344
          Top = 80
          Width = 89
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          OnClick = CH4OFFClick
        end
        object NOW1: TEdit
          Left = 60
          Top = 112
          Width = 37
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 9
          Text = 'NOW1'
        end
        object NOW2: TEdit
          Left = 164
          Top = 112
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 11
          Text = 'NOW2'
        end
        object NOW3: TEdit
          Left = 276
          Top = 112
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 12
          Text = 'NOW3'
        end
        object NOW4: TEdit
          Left = 384
          Top = 112
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 13
          Text = 'NOW4'
        end
        object CH5ON: TButton
          Left = 16
          Top = 168
          Width = 89
          Height = 21
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 17
          OnClick = CH5ONClick
        end
        object CH5OFF: TButton
          Left = 16
          Top = 196
          Width = 89
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 18
          OnClick = CH5OFFClick
        end
        object CH6ON: TButton
          Left = 120
          Top = 168
          Width = 93
          Height = 21
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 19
          OnClick = CH6ONClick
        end
        object CH6OFF: TButton
          Left = 120
          Top = 200
          Width = 93
          Height = 21
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 20
          OnClick = CH6OFFClick
        end
        object CH7ON: TButton
          Left = 232
          Top = 164
          Width = 93
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 21
          OnClick = CH7ONClick
        end
        object CH7OFF: TButton
          Left = 232
          Top = 196
          Width = 93
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 22
          OnClick = CH7OFFClick
        end
        object CH8ON: TButton
          Left = 344
          Top = 164
          Width = 89
          Height = 25
          Caption = 'ON'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 23
          OnClick = CH8ONClick
        end
        object CH8OFF: TButton
          Left = 344
          Top = 196
          Width = 89
          Height = 25
          Caption = 'OFF'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 24
          OnClick = CH8OFFClick
        end
        object NOW5: TEdit
          Left = 60
          Top = 228
          Width = 41
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 25
          Text = 'NOW5'
        end
        object NOW6: TEdit
          Left = 164
          Top = 228
          Width = 45
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 26
          Text = 'NOW6'
        end
        object NOW7: TEdit
          Left = 276
          Top = 228
          Width = 45
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 27
          Text = 'NOW7'
        end
        object NOW8: TEdit
          Left = 384
          Top = 228
          Width = 45
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 28
          Text = 'NOW8'
        end
        object MemoSend: TEdit
          Left = 12
          Top = 4
          Width = 341
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 33
          Text = 'MemoSend'
        end
      end
      object PanelToolBar: TPanel
        Left = 0
        Top = 4
        Width = 393
        Height = 29
        BevelOuter = bvLowered
        ParentColor = True
        TabOrder = 1
        object Label_portNUM2: TLabel
          Left = 269
          Top = 6
          Width = 43
          Height = 12
          Alignment = taRightJustify
          AutoSize = False
          Caption = #31471#21475':'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = []
          ParentFont = False
          Transparent = True
          Visible = False
        end
        object Label_IP2: TLabel
          Left = 1
          Top = 6
          Width = 116
          Height = 12
          Alignment = taCenter
          AutoSize = False
          Caption = 'Destination Host:'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = []
          ParentFont = False
          Transparent = True
        end
        object Edit_PortNUM2: TEdit
          Left = 326
          Top = 1
          Width = 63
          Height = 21
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          MaxLength = 5
          TabOrder = 0
          OnKeyPress = EditNumKeyPress
        end
        object ComboBox_Connections: TComboBox
          Left = 115
          Top = 1
          Width = 120
          Height = 21
          Style = csDropDownList
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          ItemHeight = 13
          TabOrder = 1
        end
        object Edit_IPAddess2: TEdit
          Left = 162
          Top = 1
          Width = 117
          Height = 21
          Hint = #26356#25913'IP'#22320#22336
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          ParentShowHint = False
          ShowHint = False
          TabOrder = 2
          Text = 'Edit_IPAddess2'
        end
      end
      object GroupBox_Recv: TGroupBox
        Left = 4
        Top = 392
        Width = 445
        Height = 101
        Caption = 'Received Data'
        TabOrder = 2
        object TextRecv: TRichEdit
          Left = 2
          Top = 15
          Width = 439
          Height = 74
          Font.Charset = GB2312_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = #23435#20307
          Font.Style = []
          ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
        end
        object PanelChecksumSel: TPanel
          Left = 16
          Top = 80
          Width = 355
          Height = 116
          AutoSize = True
          Caption = 'PanelChecksumSel'
          Color = 14671839
          TabOrder = 1
          Visible = False
          object RadioGroupChecksum: TRadioGroup
            Left = 1
            Top = 1
            Width = 353
            Height = 113
            Caption = #38468#21152#20301#35774#32622
            Color = 14671839
            ItemIndex = 0
            Items.Strings = (
              #36127#26657#39564'  '#65288#38468#21152#20301#23383#33410#30340#20540#20026#20854#20182#25152#26377#23383#33410#21644#30340#36127#25968#65289
              #27491#26657#39564'  '#65288#38468#21152#20301#23383#33410#30340#20540#20026#20854#20182#25152#26377#23383#33410#30340#21644#65289
              #22266#23450#20301'  '#65288#38468#21152#20301#23383#33410#30340#20540#20026#22266#23450#30340'16'#36827#21046#25968':     H'#65289'  ')
            ParentColor = False
            TabOrder = 0
          end
          object Edit_FixChecksum: TEdit
            Left = 293
            Top = 94
            Width = 25
            Height = 21
            ImeName = #20013#25991' - '#32043#20809#21326#23431#25340#38899#36755#20837#27861'V6'
            MaxLength = 2
            TabOrder = 1
            Text = '0d'
          end
        end
      end
      object Send: TButton
        Left = 368
        Top = 44
        Width = 65
        Height = 25
        Caption = 'Send'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        OnClick = SendClick
      end
      object GroupBox4: TGroupBox
        Left = 0
        Top = 308
        Width = 461
        Height = 73
        Caption = 'Read Current Channel State'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        object Read1: TButton
          Left = 4
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          OnClick = Read1Click
        end
        object RD1: TEdit
          Left = 4
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 1
          Text = 'RD1'
        end
        object Read2: TButton
          Left = 61
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Read2Click
        end
        object RD2: TEdit
          Left = 61
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 3
          Text = 'RD2'
        end
        object Read3: TButton
          Left = 118
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          OnClick = Read3Click
        end
        object RD3: TEdit
          Left = 118
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 5
          Text = 'RD3'
        end
        object Read4: TButton
          Left = 175
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 4'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = Read4Click
        end
        object RD4: TEdit
          Left = 175
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 7
          Text = 'RD4'
        end
        object Read5: TButton
          Left = 232
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 5'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          OnClick = Read5Click
        end
        object RD5: TEdit
          Left = 232
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 9
          Text = 'RD5'
        end
        object Read6: TButton
          Left = 289
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 6'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          OnClick = Read6Click
        end
        object RD6: TEdit
          Left = 289
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 11
          Text = 'RD6'
        end
        object Read7: TButton
          Left = 346
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 7'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 12
          OnClick = Read7Click
        end
        object RD7: TEdit
          Left = 346
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 13
          Text = 'RD7'
        end
        object Read8: TButton
          Left = 404
          Top = 20
          Width = 53
          Height = 21
          Caption = 'Read 8'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 14
          OnClick = Read8Click
        end
        object RD8: TEdit
          Left = 404
          Top = 44
          Width = 53
          Height = 21
          ImeName = #20013#25991' ('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
          TabOrder = 15
          Text = 'RD8'
        end
      end
    end
  end
  object PopupMenu1: TPopupMenu
    AutoHotkeys = maManual
    Left = 604
    Top = 112
    object N4: TMenuItem
      Caption = #20851#20110
      OnClick = MN_AboutClick
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object MN_Exit: TMenuItem
      Caption = #36864#20986
      OnClick = MN_ExitClick
    end
  end
  object ImageList1: TImageList
    Height = 32
    Width = 32
    Left = 572
    Top = 112
    Bitmap = {
      494C010102000400040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000002000000001002000000000000040
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF000000FF000000FF000000FF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF00000000000000000000000000FFFFFF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF00FFFFFF000000000000000000000000000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF000000FF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF000000FF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF000000FF000000FF000000FF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000080000000200000000100010000000000000200000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFFFFEFFFF0000000000000000FFFFFFFFFFFEFFFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFEFFFF7F0000000000000000
      FFF83FFFFF783EFF0000000000000000FFE00FFFFFE00FFF0000000000000000
      FFC007FFFFC007FF0000000000000000FF8003FFFF8003FF0000000000000000
      FF8003FFFF8003FF0000000000000000FF0001FFFF0001FF0000000000000000
      FF0001FFFF0001FF0000000000000000FF0001FFF300019F0000000000000000
      FF0001FFFF0001FF0000000000000000FF0001FFFF0001FF0000000000000000
      FF8003FFFF8003FF0000000000000000FF8003FFFF8003FF0000000000000000
      FFC007FFFFC007FF0000000000000000FFE00FFFFFE00FFF0000000000000000
      FFF83FFFFF783DFF0000000000000000FFFFFFFFFEFFFEFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFEFFFF0000000000000000
      FFFFFFFFFFFEFFFF0000000000000000FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFFFFFFFFF0000000000000000FFFFFFFFFFFFFFFF0000000000000000
      FFFFFFFFFFFFFFFF000000000000000000000000000000000000000000000000
      000000000000}
  end
end
