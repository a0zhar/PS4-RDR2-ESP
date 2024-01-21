#pragma once
#ifndef _VARS_HH
#define _VARS_HH

// Menu Variables
/**Integer**/
extern int SelClrR;
extern int SelClrG;
extern int SelClrB;
extern int scalex_;
extern int scaley_;
extern int SRL_R;
extern int SRL_G;
extern int SRL_B;

extern int featureBG_R;
extern int featureBG_G;
extern int featureBG_B;
extern int BKG_R;
extern int BKG_G;
extern int BKG_B;
extern int TITLE_R;
extern int TITLE_G;
extern int TITLE_B;
extern int BannerR;
extern int BannerG;
extern int BannerB;
extern int TitleColor;
extern int BannersColor;
extern int BackgroundColor;
extern int ScrollerColor;
extern int TitleFont;
extern int OptionsFont;
extern int maxTimerCount;
extern int timer;
extern int frameCount;
extern int TextTimer;
extern int CreditTextTimer;
extern int lastButtonPress;
extern int buttonPressDelay;
extern int NumMenu;
extern int NumMenuLevel;
extern int lastNumMenu[20];
extern int lastOption[20];
extern int currentOption;
extern int optionCount;
extern int buttonID;
extern int maxOptions;
extern int player_count;
extern int timerScrollSpeed;
extern int Static_67;

/**Float**/
extern float CenterDraw;
extern float Menu_X;
extern float Title_X;
extern float Cunt;

/**Boolean**/
extern bool PressX;
extern bool rightPress;
extern bool leftPress;
extern bool fastRPress;
extern bool fastLPress;
extern bool WhiteColor;
extern bool WhiteColor_toggle;
extern bool SelectedItem;
extern bool testT;

/**Strings**/
extern char* InfoText;
extern char* CreditText;

/**Nice Stuff**/
extern bool init;
extern bool drawPlayerBox;
extern bool drawPlayerName;

#endif
