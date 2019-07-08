//---------------------------------------------------------------------------

#ifndef UnitNetH
#define UnitNetH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UnitBase.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormNet : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanelMain;
        TPanel *PanelBottomRight;
        TImage *Image2;
        TLabel *HintLabel;
        TSpeedButton *Btn_ResetCounter;
        TStaticText *StaticTextSend;
        TStaticText *StaticTextRecv;
        TPanel *PanelRight2;
        TGroupBox *GroupBox_Network;
        TLabel *Label_Protocol;
        TLabel *Label_IPAddress;
        TLabel *Label_PortNum;
        TSpeedButton *cmBtn_NetConnect;
        TComboBox *ComboBox_Protocol;
        TEdit *Edit_PortNUM;
        TEdit *Edit_IPAddess;
        TPanel *Panel4;
        TSplitter *Splitter2;
        TPanel *Panel5;
        TPanel *Btn_Send;
        TPanel *PanelToolBar;
        TLabel *Label_portNUM2;
        TLabel *Label_IP2;
        TEdit *Edit_PortNUM2;
        TComboBox *ComboBox_Connections;
        TEdit *Edit_IPAddess2;
        TGroupBox *GroupBox3;
        TLabel *Label_Loaddata;
        TLabel *Label_ClearSend;
        TLabel *Label_IntervalUnit;
        TLabel *Label_Interval;
        TCheckBox *CheckBox_SendAutoChecksum;
        TCheckBox *CheckBox_SendRecycled;
        TCheckBox *CheckBox_ClearAfterSend;
        TCheckBox *CheckBox_SendAsHex;
        TEdit *Edit_SendInterval;
        TCheckBox *CheckBox_FileInput;
        TGroupBox *GroupBox2;
        TLabel *Label_ClearRecv;
        TLabel *Label_SaveData;
        TCheckBox *CheckBox_ReceiveAutoReturn;
        TCheckBox *CheckBox_ReceiveShowHex;
        TCheckBox *CheckBox_PauseReceive;
        TCheckBox *CheckBox_FileOutput;
        TGroupBox *GroupBox_Recv;
        TRichEdit *TextRecv;
        TPopupMenu *PopupMenu1;
        TMenuItem *MN_Exit;
        TImageList *ImageList1;
        TPanel *PanelChecksumSel;
        TRadioGroup *RadioGroupChecksum;
        TEdit *Edit_FixChecksum;
        TMenuItem *N2;
        TMenuItem *N4;
    TButton *CH1OFF;
    TButton *CH2ON;
    TButton *CH2OFF;
    TButton *CH3ON;
    TButton *CH1ON;
    TButton *CH3OFF;
    TButton *CH4ON;
    TButton *CH4OFF;
    TEdit *NOW1;
    TGroupBox *GroupBox1;
    TGroupBox *GroupCH1;
    TLabel *labelNOW1;
    TEdit *NOW2;
    TEdit *NOW3;
    TEdit *NOW4;
    TGroupBox *GroupCH2;
    TGroupBox *GroupCH3;
    TGroupBox *GroupCH4;
    TLabel *labelNOW2;
    TLabel *LabelNOW3;
    TLabel *LabelNOW4;
    TButton *CH5ON;
    TButton *CH5OFF;
    TButton *CH6ON;
    TButton *CH6OFF;
    TButton *CH7ON;
    TButton *CH7OFF;
    TButton *CH8ON;
    TButton *CH8OFF;
    TEdit *NOW5;
    TEdit *NOW6;
    TEdit *NOW7;
    TEdit *NOW8;
    TGroupBox *GroupCH5;
    TLabel *LabelNOW5;
    TGroupBox *GroupCH6;
    TLabel *LabelNOW6;
    TGroupBox *GroupCH7;
    TLabel *LabelNOW7;
    TGroupBox *GroupCH8;
    TLabel *LabelNOW8;
    TButton *Send;
    TGroupBox *GroupBox4;
    TButton *Read1;
    TEdit *RD1;
    TButton *Read2;
    TEdit *RD2;
    TButton *Read3;
    TEdit *RD3;
    TButton *Read4;
    TEdit *RD4;
    TButton *Read5;
    TEdit *RD5;
    TButton *Read6;
    TEdit *RD6;
    TButton *Read7;
    TEdit *RD7;
    TButton *Read8;
    TEdit *RD8;
    TEdit *MemoSend;
        void __fastcall ComboBox_ProtocolChange(TObject *Sender);
        void __fastcall Net_BtnClick_SendFromFile(TObject *Sender);
        void __fastcall cmBtn_NetConnectClick(TObject *Sender);
        void __fastcall MySocketAccept(TObject *sender, int socket, DWORD IP, WORD Port);
        void __fastcall MySocketActiveChanged(TObject *Sender);
        void __fastcall MySocketDiscard(TObject *sender, int socket,DWORD IP, WORD Port);
        void __fastcall MySocketError(TObject *sender, int ErroCode,char *ErrorMsg);
        void __fastcall MySocketReceive(TObject *Sender, int PeerSocket,WORD PeerPort, DWORD PeerIP, char *pBuf, int DataLen);
        void __fastcall Btn_SendClick(TObject *Sender);
        void __fastcall Btn_SendMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Btn_SendMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall CheckBox_FileOutputClick(TObject *Sender);
        void __fastcall CheckBox_ReceiveAutoReturnClick(TObject *Sender);
        void __fastcall CheckBox_PauseReceiveClick(TObject *Sender);
        void __fastcall CheckBox_FileInputClick(TObject *Sender);
        void __fastcall EditNumKeyPress(TObject *Sender,
          char &Key);
        void __fastcall Label_SaveDataClick(TObject *Sender);
        void __fastcall Label_ClearRecvClick(TObject *Sender);
        void __fastcall Label_LoaddataClick(TObject *Sender);
        void __fastcall Label_ClearSendClick(TObject *Sender);
        void __fastcall Btn_ResetCounterClick(TObject *Sender);
        void __fastcall MemoSendKeyPress(TObject *Sender, char &Key);
        void __fastcall MN_AboutClick(TObject *Sender);
        void __fastcall CheckBox_SendAutoChecksumClick(TObject *Sender);
        void __fastcall MN_SaveConfigClick(TObject *Sender);
        void __fastcall MN_VisitSiteClick(TObject *Sender);
        void __fastcall MN_ExitClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall CH1OFFClick(TObject *Sender);
    void __fastcall CH2ONClick(TObject *Sender);
    void __fastcall CH2OFFClick(TObject *Sender);
    void __fastcall CH1ONClick(TObject *Sender);
    void __fastcall CH3ONClick(TObject *Sender);
    void __fastcall CH3OFFClick(TObject *Sender);
    void __fastcall CH4ONClick(TObject *Sender);
    void __fastcall CH4OFFClick(TObject *Sender);
    void __fastcall CH5ONClick(TObject *Sender);
    void __fastcall CH5OFFClick(TObject *Sender);
    void __fastcall CH6ONClick(TObject *Sender);
    void __fastcall CH6OFFClick(TObject *Sender);
    void __fastcall CH7ONClick(TObject *Sender);
    void __fastcall CH7OFFClick(TObject *Sender);
    void __fastcall CH8ONClick(TObject *Sender);
    void __fastcall CH8OFFClick(TObject *Sender);
    void __fastcall SendClick(TObject *Sender);
    void __fastcall Read1Click(TObject *Sender);
    void __fastcall Read2Click(TObject *Sender);
    void __fastcall Read3Click(TObject *Sender);
    void __fastcall Read4Click(TObject *Sender);
    void __fastcall Read5Click(TObject *Sender);
    void __fastcall Read6Click(TObject *Sender);
    void __fastcall Read7Click(TObject *Sender);
    void __fastcall Read8Click(TObject *Sender);
private:	// User declarations
        TcmTrayIcon *TrayIcon;
        //TcmForm *cmForm1;
        void __fastcall Wnd_Proc(TMessage &Msg);
        BEGIN_MESSAGE_MAP
          MESSAGE_HANDLER(WM_QUERYENDSESSION, TMessage, Wnd_Proc)
          MESSAGE_HANDLER(WM_ENDSESSION, TMessage, Wnd_Proc)
        END_MESSAGE_MAP(TForm)
        void __fastcall OnHint(TObject *Sender);
public:		// User declarations
        String RecvFileName,SendFileName;
        int ReceivedSize,SendedSize,SendInterval,ChecksumMode,FixedCheckSum;
        TcmSocket *MySocket;
        bool transmitting;
        TcmIPEdit *IPEdit_IPAddress,*IPEdit_IPAddress2;
        String ConnectBtnCaption(void);
        void Net_SyncButtonState(void);
        String get_summary(char *SendText,int OffsetBegin,int OffsetEnd);
        void MyAsyncSleep(int MSec);
        void UpdateConfig(bool bWriteOrRead);
        __fastcall TFormNet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNet *FormNet;
//---------------------------------------------------------------------------
#endif
