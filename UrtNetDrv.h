// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cmUartDrv.pas' rev: 6.00

#ifndef cmUartNetDrvHPP
#define cmUartNetDrvHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit
#include <Menus.hpp>
#include <StdCtrls.hpp>
//-- user supplied -----------------------------------------------------------

namespace Cmuartdrv
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TComPortBaudRate { br110, br300, br600, br1200, br2400, br4800, br9600, br14400, br19200, br38400, br56000, br57600, br115200 };
#pragma option pop

#pragma option push -b-
enum TComPortNumber { pnCOM1, pnCOM2, pnCOM3, pnCOM4, pnCOM5, pnCOM6, pnCOM7, pnCOM8, pnCOM9, pnCOM10, pnCOM11, pnCOM12, pnCOM13, pnCOM14, pnCOM15, pnCOM16 };
#pragma option pop

#pragma option push -b-
enum TComPortDataBits { db5BITS, db6BITS, db7BITS, db8BITS };
#pragma option pop

#pragma option push -b-
enum TComPortStopBits { sb1BITS, sb1HALFBITS, sb2BITS };
#pragma option pop

#pragma option push -b-
enum TComPortParity { ptNONE, ptODD, ptEVEN, ptMARK, ptSPACE };
#pragma option pop

#pragma option push -b-
enum TComPortHwHandshaking { hhNONE, hhRTSCTS };
#pragma option pop

#pragma option push -b-
enum TComPortSwHandshaking { shNONE, shXONXOFF };
#pragma option pop

#pragma option push -b-
enum TPacketMode { pmDiscard, pmPass };
#pragma option pop

typedef void __fastcall (__closure *TComPortReceiveDataEvent)(System::TObject* Sender, void * DataPtr, int DataSize);

typedef void __fastcall (__closure *TComPortReceivePacketEvent)(System::TObject* Sender, void * Packet, int DataSize, int ElapsedTime);

class DELPHICLASS TcmUartDrv;
class PASCALIMPLEMENTATION TcmUartDrv : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	unsigned FComPortHandle;
	TComPortNumber FComPort;
	TComPortBaudRate FComPortBaudRate;
	TComPortDataBits FComPortDataBits;
	TComPortStopBits FComPortStopBits;
	TComPortParity FComPortParity;
	TComPortHwHandshaking FComPortHwHandshaking;
	TComPortSwHandshaking FComPortSwHandshaking;
	Word FComPortInBufSize;
	Word FComPortOutBufSize;
	short FPacketSize;
	int FPacketTimeout;
	TPacketMode FPacketMode;
	TComPortReceiveDataEvent FComPortReceiveData;
	TComPortReceivePacketEvent FComPortReceivePacket;
	Word FComPortPollingDelay;
	bool FEnableDTROnOpen;
	Word FOutputTimeout;
	HWND FNotifyWnd;
	void *FTempInBuffer;
	unsigned FFirstByteOfPacketTime;
	void __fastcall SetComHandle(unsigned Value);
	void __fastcall SetComPort(TComPortNumber Value);
	void __fastcall SetComPortBaudRate(TComPortBaudRate Value);
	void __fastcall SetComPortDataBits(TComPortDataBits Value);
	void __fastcall SetComPortStopBits(TComPortStopBits Value);
	void __fastcall SetComPortParity(TComPortParity Value);
	void __fastcall SetComPortHwHandshaking(TComPortHwHandshaking Value);
	void __fastcall SetComPortSwHandshaking(TComPortSwHandshaking Value);
	void __fastcall SetComPortInBufSize(Word Value);
	void __fastcall SetComPortOutBufSize(Word Value);
	void __fastcall SetPacketSize(short Value);
	void __fastcall SetPacketTimeout(int Value);
	void __fastcall SetComPortPollingDelay(Word Value);
	void __fastcall ApplyCOMSettings(void);
	void __fastcall TimerWndProc(Messages::TMessage &msg);
	bool __fastcall IS_COM_Connected(void);
	void __fastcall SetConnectState(bool Value);
	
public:
	__fastcall virtual TcmUartDrv(Classes::TComponent* AOwner);
	__fastcall virtual ~TcmUartDrv(void);
	bool __fastcall Connect(void);
	bool __fastcall Disconnect(void);
	void __fastcall FlushBuffers(bool inBuf, bool outBuf);
	Word __fastcall OutFreeSpace(void);
	unsigned __fastcall SendData(void * DataPtr, unsigned DataSize);
	bool __fastcall SendString(AnsiString s);
	bool __fastcall SendZString(char * s);
	void __fastcall ToggleDTR(bool onOff);
	void __fastcall ToggleRTS(bool onOff);
	__property unsigned ComHandle = {read=FComPortHandle, write=SetComHandle, nodefault};
	
__published:
	__property TComPortNumber ComPort = {read=FComPort, write=SetComPort, default=1};
	__property TComPortBaudRate ComPortSpeed = {read=FComPortBaudRate, write=SetComPortBaudRate, default=6};
	__property TComPortDataBits ComPortDataBits = {read=FComPortDataBits, write=SetComPortDataBits, default=3};
	__property TComPortStopBits ComPortStopBits = {read=FComPortStopBits, write=SetComPortStopBits, default=0};
	__property TComPortParity ComPortParity = {read=FComPortParity, write=SetComPortParity, default=0};
	__property TComPortHwHandshaking ComPortHwHandshaking = {read=FComPortHwHandshaking, write=SetComPortHwHandshaking, default=0};
	__property TComPortSwHandshaking ComPortSwHandshaking = {read=FComPortSwHandshaking, write=SetComPortSwHandshaking, default=0};
	__property Word ComPortInBufSize = {read=FComPortInBufSize, write=SetComPortInBufSize, default=2048};
	__property Word ComPortOutBufSize = {read=FComPortOutBufSize, write=SetComPortOutBufSize, default=2048};
	__property short PacketSize = {read=FPacketSize, write=SetPacketSize, default=-1};
	__property int PacketTimeout = {read=FPacketTimeout, write=SetPacketTimeout, default=-1};
	__property TPacketMode PacketMode = {read=FPacketMode, write=FPacketMode, default=0};
	__property Word ComPortPollingDelay = {read=FComPortPollingDelay, write=SetComPortPollingDelay, default=50};
	__property bool EnableDTROnOpen = {read=FEnableDTROnOpen, write=FEnableDTROnOpen, default=1};
	__property Word OutputTimeout = {read=FOutputTimeout, write=FOutputTimeout, default=4000};
	__property TComPortReceiveDataEvent OnReceiveData = {read=FComPortReceiveData, write=FComPortReceiveData};
	__property TComPortReceivePacketEvent OnReceivePacket = {read=FComPortReceivePacket, write=FComPortReceivePacket};
	__property bool Connected = {read=IS_COM_Connected, write=SetConnectState, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall BaudRateOf(TComPortBaudRate bRate);
extern PACKAGE int __fastcall DelayForRX(TComPortBaudRate bRate, int DataSize);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Cmuartdrv */
using namespace Cmuartdrv; 


namespace Cmipedit
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TFieldChangeEvent)(System::TObject* Sender, Byte OldField, Byte Value);

class DELPHICLASS TcmIPEdit;
class PASCALIMPLEMENTATION TcmIPEdit : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	unsigned FIP_BigEndian;
	unsigned FIP_LittleEndian;
	Byte FFields[4];
	bool FCreating;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnEnter;
	Classes::TNotifyEvent FOnExit;
	TFieldChangeEvent FOnFieldChange;
	void __fastcall SetIP(unsigned Value);
	void __fastcall SetIPstr(AnsiString IPstr);
	AnsiString __fastcall GetIPstr();
	void __fastcall SetIPAddress(void);
	MESSAGE void __fastcall WMNotifyFormat(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMSetFont(Messages::TWMSetFont &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	MESSAGE void __fastcall CMWantSpecialKey(Messages::TWMKey &Message);
	
public:
	__fastcall virtual TcmIPEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TcmIPEdit(void);
	bool __fastcall Empty(void);
	void __fastcall Clear(void);
	Byte __fastcall GetField(int Index);
	void __fastcall SetField(int Index, Byte B);
	void __fastcall SetFieldFocus(Byte Field);
	AnsiString __fastcall IPToStr(unsigned IP);
	unsigned __fastcall StrToIP(AnsiString IPstr);
	
__published:
	__property unsigned IPdata = {read=FIP_BigEndian, write=SetIP, nodefault};
	__property AnsiString IP = {read=GetIPstr, write=SetIPstr};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnEnter = {read=FOnEnter, write=FOnEnter};
	__property Classes::TNotifyEvent OnExit = {read=FOnExit, write=FOnExit};
	__property TFieldChangeEvent OnFieldChange = {read=FOnFieldChange, write=FOnFieldChange};
	__property Color  = {default=-2147483643};
	__property Enabled  = {default=1};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property ParentShowHint  = {default=1};
	__property ShowHint ;
	__property Hint ;
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TcmIPEdit(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Cmipedit */
using namespace Cmipedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.


#include <winsock.h>
#include <Classes.hpp>
#define WM_SOCKET  WM_USER+11
typedef struct cm_Socket_Node
{ struct cm_Socket_Node *next;
  long socket;
  DWORD IP;
  WORD  Port;
}TcmSocketNode;
typedef struct cm_Server_Connections
{ int count;
  TcmSocketNode *first,*last,*node;
}TcmServerConnections;
typedef void __fastcall (__closure *TErroEvents)(System::TObject* sender, int ErroCode, char * ErrorMsg);
typedef void __fastcall (__closure *TSocketDataEvents)(System::TObject* Sender, int PeerSocket, WORD PeerPort, DWORD PeerIP, char *pBuf, int DataLen);
typedef void __fastcall (__closure *TcmSocketEvents)(System::TObject* sender, int socket,DWORD IP, WORD Port);
enum TcmSocketProtocol{cmICMP,cmIGMP,cmUDP,cmRawIP,cmTcpServer,cmTcpClient};
enum TcmCastMode{cmUnicast,cmBroadcast,cmMulticast};
#ifndef SocketsHPP
enum TServerSocketBlockMode{bmBlocking, bmNonBlocking, bmThreadBlocking};
#endif
class PACKAGE TcmSocket : public TComponent
{ private:
     TErroEvents FOnError;
     TNotifyEvent FOnActiveChange;
     TcmSocketEvents FOnAccept,FOnConnectionsDiscard;
     TSocketDataEvents FOnReceive;
     TServerSocketBlockMode FBlockMode;
     TcmSocketProtocol FProtocol;
     SOCKADDR_IN m_sockaddr;
     HWND FNotifyWnd;
     bool FActive,FRelayDump,FBinded;
     char *data_buf;
     String FLocalHost,FRemoteHost;
     int FLocalPort,FRemotePort,FSocket,buf_offset,FRecvBufferSize;
     int ErrorCheck(int rc,char *fail_remark=NULL);
     char* MapErrorCode(int nError);
     void  free_connection_list(TcmServerConnections *head,bool keephead=false);
     void ShowError(char * errCode, int errNum=0);
     void DeclareConnect(bool isActive);
     void reg_connections(long socket,bool add_or_del);
     void ShowMessage(String info);
     void __fastcall SetBufferSize(int size);
     void __fastcall SetActive(bool value);
     void __fastcall OnSocketMessage(TMessage &Msg);
     virtual void __fastcall Loaded();
     static bool wsa_startup(void);
     int  Create(TcmSocketProtocol s_protocol);
     int  Accept(void);//建立连接函数，S为监听Socket对象名；
     bool Connect(char* strRemote, unsigned int iPort);//定义连接函数；
     bool Bind(char* strIP, unsigned int iPort);//绑定函数；
     bool AsyncSelect( HWND hWnd, unsigned int wMsg, long lEvent);
     bool Listen(int iQueuedConnections);//监听函数；
  public:
     TcmServerConnections *Connections;
     void Open(void);
     void Close(void);
     int  Receive(char* p_buf, int BufSize, int PeerSocket=INVALID_SOCKET,SOCKADDR* PeerAddr=NULL);//数据接收函数；
     bool SendTo(DWORD peer_IP, WORD peer_port,void *p_buf, int DataLen=0);//数据发送函数；
     bool SendTo(char *peer_IP, WORD peer_port,void *p_buf, int DataLen=0);//数据发送函数；
     bool SendTo(int peer_socket, void *p_buf, int DataLen=0);//数据发送函数；
     bool Send(void *p_buf, int DataLen=0);//数据发送函数；
     static DWORD IP_UnicastToBroadcast(DWORD ipData);
     static DWORD get_ip_data(char *p_host=NULL,TcmCastMode Mode=cmUnicast);  //是网络字节顺序的IP
     static bool isValidIP(char *IPaddr);/*static指明该方法是一个类方法,它可以通过类名::直接调用*/
     static String HostName();
     static String HostIP(DWORD IPdata=INADDR_NONE);
     static String BroadcastIP(char *IPstr=NULL);
     __fastcall TcmSocket(TComponent* Owner);//类的构造函数
     __fastcall ~TcmSocket();//类的析构函数；
  __published:
     __property TErroEvents OnError = {read=FOnError, write=FOnError};
     __property TSocketDataEvents OnReceive = {read=FOnReceive, write=FOnReceive};
     __property TcmSocketEvents OnAccept={read=FOnAccept,write=FOnAccept};
     __property TNotifyEvent OnActiveChanged={read=FOnActiveChange,write=FOnActiveChange};
     __property TcmSocketEvents OnDiscard={read=FOnConnectionsDiscard,write=FOnConnectionsDiscard};
     __property TcmSocketProtocol Protocol = {read=FProtocol,write=FProtocol};
     __property bool RelayDump = {read=FRelayDump,write=FRelayDump};
     __property int Socket = {read=FSocket};
     __property int BufOffset = {read=buf_offset};
     __property int RemotePort = {read=FRemotePort, write=FRemotePort};
     __property String RemoteHost = {read=FRemoteHost,write=FRemoteHost};
     __property int LocalPort = {read=FLocalPort, write=FLocalPort};
     __property String LocalHost  = {read=FLocalHost,write=FLocalHost};
     __property int MaxBufSize ={read=FRecvBufferSize,write=SetBufferSize};
     __property bool Active = {read=FActive,write=SetActive};  //该属性尽可能放在最后载入     
};
//---------------------------------------------------------------------------
#define WM_SYSTEM_TRAY_NOTIFY (WM_USER + 7)
typedef DWORD (__stdcall *pRegFunction)(DWORD,DWORD);
/*enum TTrayIconMessage {imClick, imDoubleClick, imMouseDown,
                       imMouseUp, imLeftClickUp, imLeftDoubleClick,
                       imRightClickUp, imRightDoubleClick, imNone};
*/
//---------------------------------------------------------------------------
class PACKAGE TcmTrayIcon : public TComponent
{
private:
   String FHint;
   int FIconIndex;
   bool FVisible,FAnimate,FRestoreOnDBCLick,FOnTaskList,FOnTaskBar;
   HINSTANCE hKernelLib;
   pRegFunction RegisterServiceProcess;
   TNotifyIconData FData;
   TIcon *FIcon;
   TImageList* FIconList;
   TPopupMenu* FPopupMenu;
   TTimer *FTimer;
   TWindowHook FApplicationHook;
   TNotifyEvent FOnMinimize;
   TNotifyEvent FOnRestore;
   TNotifyEvent FOnClick;
   TNotifyEvent FOnDblClick;
   TMouseMoveEvent FOnMouseMove;
   TMouseEvent FOnMouseDown;
   TMouseEvent FOnMouseUp;
   TNotifyEvent FOnAnimate;
   void __fastcall SetHint(String Hint);
   int __fastcall GetAnimateInterval();
   void __fastcall SetAnimateInterval(int Value);
   void __fastcall SetAnimate(bool Value);
   void __fastcall setOnTaskList(bool value);
   void __fastcall setOnTaskBar(bool value);
   void __fastcall SetIcon(TIcon *value);
   TShiftState ShiftState();
protected:
   virtual void __fastcall SetVisible(bool Value);
   virtual void __fastcall DoMessage(TMessage &Message);
   virtual void __fastcall DoOnAnimate(TObject *Sender);
   virtual void __fastcall Notification(TComponent *AComponent, TOperation Operation);
   bool __fastcall ApplicationHookProc(TMessage &Message);
   virtual void __fastcall Loaded();
    __property TNotifyIconData Data = {read=FData};
public:
   __property TIcon *Icon={read=FIcon,write=SetIcon};
   __fastcall TcmTrayIcon(TComponent* Owner);
   __fastcall ~TcmTrayIcon();
   virtual void __fastcall Minimize();
   virtual void __fastcall Restore();
   virtual void __fastcall Update();
   virtual void __fastcall ShowMenu();
   virtual void __fastcall SetIconIndex(int Value);
   virtual void __fastcall SetDefaultIcon();
   HWND __fastcall GetHandle();
__published:
   // Properties
   __property bool  OnTaskBar = {read=FOnTaskBar,write=setOnTaskBar,default=true};
   __property bool  OnTaskList = {read=FOnTaskList,write=setOnTaskList,default=true};
   __property bool  RestoreOnDBCLick={read=FRestoreOnDBCLick,write=FRestoreOnDBCLick};
   __property String Hint = {read=FHint,write=SetHint};
   __property TPopupMenu* PopupMenu = {read=FPopupMenu,write=FPopupMenu};
   __property TImageList* Icons = {read=FIconList,write=FIconList};
   __property int IconIndex = {read=FIconIndex,write=SetIconIndex,default=0};
   __property int  AnimateInterval = {read=GetAnimateInterval,write=SetAnimateInterval,default=1000};
   __property bool Animate = {read=FAnimate,write=SetAnimate,default=false};
   __property bool Handle = {read=GetHandle};
   __property bool Visible = {read=FVisible,write=SetVisible,default=false};
   // Events
    __property TNotifyEvent OnMinimize = {read=FOnMinimize,write=FOnMinimize};
    __property TNotifyEvent OnRestore = {read=FOnRestore,write=FOnRestore};
    __property TNotifyEvent OnDblClick = {read=FOnDblClick,write=FOnDblClick};
    __property TNotifyEvent OnClick = {read=FOnClick,write=FOnClick};
    __property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove,write=FOnMouseMove};
    __property TMouseEvent OnMouseUp = {read=FOnMouseUp,write=FOnMouseUp};
    __property TMouseEvent OnMouseDown = {read=FOnMouseDown,write=FOnMouseDown};
    __property TNotifyEvent OnAnimate = {read=FOnAnimate,write=FOnAnimate};
};
//---------------------------------------------------------------------------
#define  DefaultContextPopupMenuCount 13
//---------------------------------------------------------------------------
class PACKAGE TContextPopupMenu : public TPopupMenu
{   private:
      TMenuItem *mn[13];
      void __fastcall OnClick(TObject *Sender);
    protected:
      virtual void __fastcall DoPopup(TObject* Sender);
      virtual void __fastcall Loaded();
    public:
      static void TxtEditor_SelConverse(TCustomEdit *TxtEditor,int mode);
      __fastcall TContextPopupMenu(TComponent* Owner);
   __published:
};
//---------------------------------------------------------------------------
#define MB_USERBUTTON  0xf
#define MB_ICONAPPLICATION 0x50
//---------------------------------------------------------------------------
int data_to_hex(void *pSrc,int SrcSize,char *pBuf,int BufSize,char splitter=32);
int hex_to_data(char* hexStr,void *pBuf,int hexStrSize=-1);
bool isNumeric(char *data);
bool valid_checksum(void *p_buf,int buf_size,int checksummode);
void set_checksum(void *p_buf,int buf_size,int checksummode);
int str_to_int(char *data);
char *format(const char* formatcode, ...);
int hex_to_int(char *hex);
int Wnd_ControlDlg(Controls::TControl* ClientControl, AnsiString TitleText, int Flags = 0x0, Classes::TNotifyEvent OnShowEvent = 0x0);
void Wnd_SetUserButton(AnsiString buttonCaption3, AnsiString buttonCaption2, AnsiString buttonCaption1, AnsiString buttonCaption0);
int Wnd_MessageDlg(AnsiString ContentText, AnsiString TitleText, int Flags);
void Wnd_SetMode(int language,int wndmode);
void Wnd_UserBitmap(TGraphic* UserIcon);
void Wnd_cmForm(TComponent* AOwner,String strTitle,bool bSizeable);
//---------------------------------------------------------------------------
//-- end unit ----------------------------------------------------------------
#endif	// cmUartDrv
