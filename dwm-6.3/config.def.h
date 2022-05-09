/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 6;       /* vertical padding of bar */
static const int sidepad            = 6;       /* horizontal padding of bar */
static const char *fonts[]          = { "JetBrainsMono Medium Nerd Font:size=10" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_white[]	    = "#ffffff";
static const char col_red[]	    = "#ff0a0a";
static const char col_blue[]	    = "#0022ff";

// dracula color plate 
static const char dra_bg[]       = "#282a36";
static const char dra_fg[]       = "#f8f8f2";
static const char dra_cyan[]     = "#8be9fd";
static const char dra_green[]    = "#50fa7b";
static const char dra_orange[]   = "#ffb86c";
static const char dra_pink[]	 = "#ff79c6";
static const char dra_purple[]	 = "#bd93f9";
static const char dra_red[]	     = "#ff5555";
static const char dra_yellow[]	 = "#f1fa8c";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { dra_pink, dra_bg, dra_bg },
	[SchemeSel]  = { dra_purple, dra_bg,  "#000000"  },
	[SchemeStatus]  = { dra_green, dra_bg,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	//TagBar Left
	[SchemeTagsSel]  = { dra_green, dra_bg,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { dra_pink, dra_bg,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	// InforBar Middle
        [SchemeInfoSel]  = { dra_purple, dra_bg,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { dra_cyan, dra_bg,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *tags[] = {" ","","","","","","","",""};

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance    title       tags mask     isfloating   monitor */
	{ "Gimp",           NULL,       NULL,       0,            1,               -1 },
	{ "Pavucontrol",    NULL,	NULL,	    0,	          1,	           -1 },
        { "st",		    NULL,	NULL,       0,		  1,		   -1 },
        { "kitty",          NULL,       NULL,       0,            1,               -1 },
        { "SimpleScreenRecorder",          NULL,       NULL,       0,            1,               -1 },
        { "simplescreenrecorder",          NULL,       NULL,       0,            1,               -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
        { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Configurations Path Definition */

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,"-c","-l","20", NULL };
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *dmenuterm[] = { "dmenu_term", NULL };
static const char *dmenuswitch[] = { "switch", NULL };
static const char *termcmd[]  = { "termite","--config","/home/mangal/.config/dwm/termite/config" };
static const char *float_term[] = { "st",NULL };

// Custom Apps....
static const char *kitty_htop[] = { "kitty","-e","htop", NULL };
static const char *kitty_btop[] = { "kitty","-e","btop", NULL };
static const char *kitty_ranger[] = { "kitty","-e","ranger", NULL };
static const char *kitty_alsamixer[] = {"kitty","-e","alsamixer", NULL };
static const char *pavucontrol[] = { "pavucontrol" };
static const char *ncdu[] = { "kitty","-e","ncdu","--color","dark", NULL };
// powermenu
static const char *powermenu[] = { "powermenu" };
static const char *wifi_menu[] = { "/home/mangal/bin/rofi-network-manager/rofi-network-manager.sh"};
// screen locker
static const char *betterlockscreen[] = { "betterlockscreen","--lock",NULL };
static const char *fuzzyfinder[] = { "kitty","-e","fzf", NULL };

// screenshot
static const char *flameshot[] = {"flameshot","gui", NULL };

// rofi
static const char *rofiapp[] = {"rofi","-show","drun","-modi","drun",NULL };
static const char *rofiemo[] = {"rofi","-show","emoji","-modi","emoji",NULL };
static const char *rofiwin[] = {"rofi","-show","window","-modi","window",NULL };
static const char *lab[] = {"termite","-e","lab"};

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY|ShiftMask,                       XK_l,      spawn,          {.v = lab } },
    { MODKEY,                       XK_a,      spawn,          {.v = rofiapp } },
    { MODKEY,                       XK_e,      spawn,          {.v = rofiemo } },
    { ALTKEY,                       XK_Tab,      spawn,          {.v = rofiwin } },
    { MODKEY,                       XK_r,      spawn,          {.v = dmenuterm } },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { 0,                            XK_Print,  spawn,          {.v = flameshot } },
	{ ControlMask|ALTKEY,           XK_f,      spawn,          {.v = fuzzyfinder } },
    { MODKEY, 			            XK_l,	   spawn,	       {.v = betterlockscreen } },
    { ControlMask|ALTKEY,           XK_d,      spawn,          {.v = ncdu } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = float_term } },
	{ MODKEY,			XK_n,	   spawn,          {.v = wifi_menu } },
  	{ MODKEY,                       XK_v,      spawn,          {.v = pavucontrol } },
	{ MODKEY|ShiftMask,             XK_v,      spawn,          {.v = kitty_alsamixer } },
 	{ ControlMask|ALTKEY,		    XK_h,      spawn,          {.v = kitty_htop } },
	{ ControlMask|ALTKEY,           XK_b,      spawn,          {.v = kitty_btop } },
	{ MODKEY|ShiftMask,		        XK_s,	   spawn,	       {.v = kitty_ranger} },
	{ MODKEY|ShiftMask,             XK_Left,   movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Right,  movestack,      {.i = -1 } },
	{ ALTKEY,			            XK_F4,	   spawn,	       {.v = powermenu } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Left,   focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Right,  focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ ControlMask,                  XK_Left,   setmfact,       {.f = -0.05} },
	{ ControlMask,                  XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,		    XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

