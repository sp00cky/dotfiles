/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "snap";
static const char normbordercolor[] = "#090909";
static const char normbgcolor[]     = "#090909";
static const char normfgcolor[]     = "#828282";
static const char selbordercolor[]  = "#320000";
static const char selbgcolor[]      = "#090909";
static const char selfgcolor[]      = "#8F0000";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const double shade           = 0.8;      /* opacity of unfocussed clients */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = False;    /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class              instance    title       tags mask     iscenterd    ifloating  monitor  opacity */
	{ "Claws-mail",       NULL,       NULL,       1 << 0,       False,       False,      -1,      -1 },
	{ "Icedove",          NULL,       NULL,       1 << 0,       False,       False,      -1,      -1 },
	{ "Icedove",          NULL,       "Feed Subscriptions", 1 << 0, True,    True,       -1,      -1 },
	{ "Iceweasel",        NULL,       NULL,       1 << 1,       False,       False,      -1,      -1 },
	{ "Gajim",            NULL,       NULL,       1 << 2,       False,       False,      -1,      -1 },
	{ "Geany",            NULL,       NULL,       1 << 3,       False,       False,      -1,      -1 },
	{ "Oggconvert",       NULL,       NULL,       1 << 4,       True,        True,       -1,      -1 },
	{ "Handbrake-gtk",    NULL,       NULL,       1 << 4,       True,        True,       -1,      -1 },
	{ "Avidemux",         NULL,       NULL,       1 << 4,       True,        True,       -1,      -1 },
	{ "Gimp",             NULL,       NULL,       1 << 5,       False,       False,      -1,      -1 },
	{ "Inkscape",         NULL,       NULL,       1 << 5,       False,       False,      -1,      -1 },
	{ "Filezilla",        NULL,       NULL,       1 << 7,       False,       False,      -1,      -1 },
	{ "gFTP",             NULL,       NULL,       1 << 7,       False,       False,      -1,      -1 },
	{ "Transmission-gtk", NULL,       NULL,       1 << 8,       False,       True,       -1,      0.9 },
	{ "XTerm",            NULL,       NULL,       0,            True,        True,       -1,      0.9 },
	{ "feh",              NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "XCalc",            NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Rox",              NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "luakit",           NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Tor Browser",      NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Lxappearance",     NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "URxvt",            "scratchpad", NULL,     0,            True,        True,       -1,      -1 },
	{ "URxvt",            NULL,       "sound",    0,            True,        True,       -1,      -1 },
	{ "URxvt",            NULL,       "player",   0,            True,        True,       -1,      -1 },
	{ "mpv",              NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "mplayer2",         NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Sxiv",             NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Cyclope",          NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Surf",             NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "tabbed",           NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "MuPDF",            NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ NULL,               NULL,       "Library",  0,            True,        True,       -1,      -1 },
	{ "File-roller",      NULL,       NULL,       0,            True,        True,       -1,      -1 },
	{ "Redshift-config",  NULL,       NULL,       0,            True,        True,       -1,      -1 },
};

/* layout(s) */
static const float mfact      = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = True;  /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol      arrange function */
	{ "[0]",      monocle }, /* first entry is default */
	{ "[|]",       tile },    /* classic tiling */
	{ "[ ]",       NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define MODKEY2 Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]  = { "dmenu-bind.sh", NULL };
static const char *termcmd[]   = { "urxvtcd", NULL };
static const char *xtermcmd[]  = { "xterm", "-geometry", "150x25", NULL };
static const char *scratcmd[]  = { "scratchpad", NULL };
static const char *rangercmd[] = { "urxvtcd", "-e", "ranger", NULL };
static const char *zikcmd[]    = { "urxvtcd", "-T", "player", "-e", "mocp", NULL };
static const char *soundcmd[]  = { "urxvtcd", "-T", "sound", "-e", "alsamixer", NULL };
static const char *roxcmd[]    = { "rox", NULL };
static const char *webcmd[]    = { "surf", "file:///home/arp/.startarp/index.html",NULL };
static const char *torwebcmd[] = { "start-tor-browser", NULL };
static const char *ffxcmd[]    = { "iceweasel", NULL };
static const char *geanycmd[]  = { "geany", NULL };
static const char *irccmd[]    = { "screenirc", NULL };
static const char *wallcmd[]   = { "random_wall", NULL };

#include "push.c"
#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key           function        argument */
	{ MODKEY,                       XK_p,         spawn,          {.v = dmenucmd } },
	{ ControlMask,                  XK_Return,    spawn,          {.v = termcmd } },
	{ MODKEY2,                      XK_Return,    spawn,          {.v = scratcmd } },
	{ 0,                            XK_F12,       spawn,          {.v = xtermcmd } },
	{ MODKEY,                       XK_r,         spawn,          {.v = rangercmd } },
	{ MODKEY,                       XK_z,         spawn,          {.v = zikcmd } },
	{ MODKEY,                       XK_v,         spawn,          {.v = soundcmd } },
	{ MODKEY|ShiftMask,             XK_r,         spawn,          {.v = roxcmd } },
	{ MODKEY,                       XK_w,         spawn,          {.v = webcmd } },
	{ MODKEY2,                      XK_w,         spawn,          {.v = torwebcmd } },
	{ MODKEY|ShiftMask,             XK_w,         spawn,          {.v = ffxcmd } },
	{ MODKEY,                       XK_e,         spawn,          {.v = geanycmd } },
	{ MODKEY,                       XK_x,         spawn,          {.v = irccmd } },
	{ MODKEY|ControlMask,           XK_w,         spawn,          {.v = wallcmd } },
	{ MODKEY,                       XK_b,         togglebar,      {0} },
	{ MODKEY,                       XK_j,         focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,         focusstack,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_j,         pushdown,       {0} },
    { MODKEY|ControlMask,           XK_k,         pushup,         {0} },
	{ MODKEY,                       XK_i,         incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,         incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,         setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,         setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,    zoom,           {0} },
	{ MODKEY,                       XK_Tab,       view,           {0} },
	{ MODKEY,                       XK_q,         killclient,     {0} },
	{ MODKEY,                       XK_m,         setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,         setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,         setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,     setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,     togglefloating, {0} },
	{ MODKEY,                       XK_agrave,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_agrave,    tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,     focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_semicolon, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_semicolon, tagmon,         {.i = +1 } },
    { ControlMask,                  XK_Left,      shiftview,      {.i = -1 } },
    { ControlMask,                  XK_Right,     shiftview,      {.i = +1 } },
	TAGKEYS(                        XK_ampersand,                 0)
	TAGKEYS(                        XK_eacute,                    1)
	TAGKEYS(                        XK_quotedbl,                  2)
	TAGKEYS(                        XK_apostrophe,                3)
	TAGKEYS(                        XK_parenleft,                 4)
	TAGKEYS(                        XK_minus,                     5)
	TAGKEYS(                        XK_egrave,                    6)
	TAGKEYS(                        XK_underscore,                7)
	TAGKEYS(                        XK_ccedilla,                  8)
	{ MODKEY|ShiftMask,             XK_q,      quit,              {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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
