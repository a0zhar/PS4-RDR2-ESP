#include "../include/vars.h"
//Menu Variables
/**Integer**/
int SelClrR = 255;
int SelClrG = 255;
int SelClrB = 0;
int scalex_ = 0;
int scaley_ = 0;
int SRL_R = 255;
int SRL_G = 255;
int SRL_B = 255;

int featureBG_R = 46;
int featureBG_G = 47;
int featureBG_B = 54;
int BKG_R = 91;
int BKG_G = 8;
int BKG_B = 8;
int TITLE_R = 255;
int TITLE_G = 255;
int TITLE_B = 255;
int BannerR = 53;
int BannerG = 59;
int BannerB = 72;
int TitleColor = 1;
int BannersColor = 1;
int BackgroundColor =1;
int ScrollerColor =1;
int TitleFont = 6;
int OptionsFont = 0;
int maxTimerCount;
int timer = 0;
int frameCount = 0;
int TextTimer = 0;
int CreditTextTimer = 0;
int lastButtonPress = 0;
int buttonPressDelay = 200;
int NumMenu = 0;
int NumMenuLevel;
int lastNumMenu[20];
int lastOption[20];
int currentOption;
int optionCount;
int buttonID;
int maxOptions = 25;
int player_count =0;
int timerScrollSpeed;
int Static_67;


/**Float**/
float CenterDraw = 0.26f;
float Menu_X = 0.758;
float Title_X = 0.6350;
float Cunt = 0.648;


/**Boolean**/
bool PressX = false;
bool rightPress = false;
bool leftPress = false;
bool fastRPress = false;
bool fastLPress = false;
bool WhiteColor;
bool WhiteColor_toggle;
bool SelectedItem;
bool testT;

/**Strings**/
char* InfoText;
char* CreditText = " ";


/**Nice Stuff**/
bool init;
bool GodMode = false;
bool NeverWanted;
bool SuperRun;
bool SuperJump;
bool Forcefield;
bool Invisibility;
bool FreezePos;
bool infiniteAmmo;