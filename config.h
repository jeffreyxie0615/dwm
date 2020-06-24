/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 25;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 25;       /* vert inner gap between windows */
static const unsigned int gappoh    = 25;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 25;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
static const char *fonts[]          = { 
	"mononoki Nerd Font:size=11",
	"Source Han Sans:size=11",
};
static const char dmenufont[]       = "mononoki Nerd Font:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

static const char *const autostart[] = {
	"compton", "--config", "/home/simon/.config/compton/compton.conf", NULL,
	"st", NULL,
	"pavucontrol", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "斬", "疾", "翔", "盾", "撃"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "Firefox", NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "St",      NULL,     NULL,           0,         0,          1,          -1,        -1 }, { NULL,      NULL,     "Event Tester", 0,         1,          0,           1,        -1 }, /* xev */ };

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } } //runs commands on keypress
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_F11,    incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_F12,    incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.025} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.025} },
	{ MODKEY|Mod4Mask,              XK_k,      incrgaps,       {.i = +3 } },
	{ MODKEY|Mod4Mask,              XK_j,      incrgaps,       {.i = -3 } },
	{ MODKEY|Mod4Mask,              XK_0,	   defaultgaps,    {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_F8,     view,           {0} }, //not used, yeet
	{ MODKEY,     	                XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_comma,  focusmon,       {.i = -1 } }, //yeet
	{ MODKEY|ControlMask,           XK_period, focusmon,       {.i = +1 } }, //yeet
	{ MODKEY|ShiftMask|ControlMask, XK_comma,  tagmon,         {.i = -1 } }, //yeet
	{ MODKEY|ShiftMask|ControlMask, XK_period, tagmon,         {.i = +1 } }, //yeet
	{ MODKEY,			XK_Tab,    shiftview,      {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Tab,	   shiftview,      {.i = -1 } },	
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ ControlMask|MODKEY,           XK_Delete, quit,           {0} },

	/*event keys: press a key, run a command*/

	{ 0,				XK_F1,	   spawn,	   SHCMD("mpc toggle") }, //toggle pause/play
	{ 0,				XK_F2,	   spawn,	   SHCMD("amixer -q sset Master 3%-") }, //decrease volume 3%
	{ 0,				XK_F3,	   spawn,	   SHCMD("amixer -q sset Master 3%+") }, //increase volume 3%
	{ 0,				XK_F4,	   spawn,	   SHCMD("xbacklight -dec 2.5") }, //increase brightness 2.5%
	{ 0,				XK_F5,	   spawn,	   SHCMD("xbacklight -inc 2.5") }, //increase brightness 2.5%
	{ MODKEY,			XK_comma,  spawn,	   SHCMD("mpc prev") },
	{ MODKEY,			XK_period, spawn,	   SHCMD("mpc next") },
//	{ 0,				XK_F3,	   spawn,	   SHCMD("amixer -q sset Master 3%+") }, screenshot soon
//	{ 0,				XK_F3,	   spawn,	   SHCMD("amixer -q sset Master 3%+") }, maybe ffmpeg/show key
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
