//---------------------------------------------------------------------------
#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "UnitBase.h"
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include <ImgList.hpp>
#include "Registry.hpp"
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupMenu1;
        TMenuItem *MN_Exit;
        TImageList *ImageList1;
        TMainMenu *MainMenu1;
        TMenuItem *MN_File;
        TMenuItem *MN_Options;
        TMenuItem *MN_Help;
        TMenuItem *MN_About;
        TMenuItem *MN_Language1;
        TMenuItem *MN_Language0;
        TPanel *PanelRight;
        TTimer *SendTimer;
        TMenuItem *N1;
        TMenuItem *MN_ResetCounter;
        TMenuItem *N2;
        TMenuItem *MN_SaveConfig;
        TMenuItem *MN_LoadConfig;
        TMenuItem *N3;
        TMenuItem *MN_VisitSite;
        TGroupBox *GroupAbout;
        TImage *ImageLogo;
        TLabel *Label_About;
        TPanel *Panel1;
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
        TPanel *Panel4;
        TSplitter *Splitter2;
        TPanel *Panel5;
        TPanel *Btn_Send;
        TRichEdit *MemoSend;
        TPanel *Panel8;
        TPanel *PanelToolBar;
        TLabel *Label_portNUM2;
        TLabel *Label_IP2;
        TEdit *Edit_PortNUM2;
        TComboBox *ComboBox_Connections;
        TEdit *Edit_IPAddess2;
        TGroupBox *GroupBox_Recv;
        TRichEdit *TextRecv;
        void __fastcall MN_ExitClick(TObject *Sender);
        void __fastcall AboutClick(TObject *Sender);
        void __fastcall EditNumKeyPress(TObject *Sender,
          char &Key);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
         void __fastcall Btn_SendMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Btn_SendMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall MN_FileClick(TObject *Sender);
        void __fastcall MN_LanguageClick(TObject *Sender);
        void __fastcall MN_ResetCounterClick(TObject *Sender);
        void __fastcall MN_LoadConfigClick(TObject *Sender);
        void __fastcall MN_SaveConfigClick(TObject *Sender);
        void __fastcall MN_VisitSiteClick(TObject *Sender);
private:	// User declarations
        TcmUartDrv *UartDriver;
        TcmTrayIcon *TrayIcon;
        String RecvFileName,SendFileName;
        bool transmitting;
        int SendCycleRemains;
        int ReceivedSize,SendedSize,SendInterval,ChecksumMode,FixedCheckSum;

        void UpdateLanguageDisplay(void);
        void TxtEditor_SelConverse(TCustomEdit *TxtEditor,bool HexToAscII);

        void __fastcall OnHint(TObject *Sender);


public:		// User declarations
        void MyAsyncSleep(int MSec);

        void UpdateConfig(bool bSaveOrLoad);
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
void format_text(void *dataBuf,int dataSize,char *textBuf,int bufSize);
//---------------------------------------------------------------------------
#endif
