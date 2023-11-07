#ifndef CONFIG_H_
#define  CONFIG_H_

#include "user.h"
#include <stdlib.h>
#include <linux/input-event-codes.h>

static const int show_bar = 1;
static const int bar_top = 1;          /* Boolean value, non-zero is true. If not top then bottom */
static const int status_on_active = 1; /* Display the status on active monitor only. If not then on all. */
static const char *font = "Monofur Nerd Font:pixelsize 9";
static const char *rofimenu[] = { "rofi", "-show", "drun", "-modi", "drun", "-location", "1", "-anchor", "1", "-xoffset", "200", "-yoffset", "-30", "-width", "40ch", "-lines", "12", NULL };
/*
 * Colors:
 * Colors are in rgba format.
 * The color scheming format is the same as dwm.
 * We use an enum as a index for our scheme types.
 *
 * cyan  - used in an active background
 * grey3 - used in active text and urgent background
 * grey1 - used in an inactive background
 * grey2 - used in inactive text
 */
static const int cyan[4]  = { 158,   253,  56, 255 }; /*using freshlime code */
static const int green[4]  = { 10,   154,  240, 255 };
static const int grey1[4] = { 38,  50,  56,  255 };
static const int grey2[4] = { 178, 189, 181, 255 };
static const int grey3[4] = { 10, 14, 34, 255 };
static const int urgent[4] = { 229, 143, 150, 255 };

static const int *schemes[3][2] = {
    /* Scheme Type       fg,    bg */
    [InActive_Scheme] = {grey2, grey1},
    [Active_Scheme]   = {cyan, grey3},
    [Urgent_Scheme]   = {urgent, grey3},
};

/*
 * Tags
 * Must not exceed 31 tags and amount must match dwl's tagcount.
 */
/* static const char *tags[] = { "𓀡", "𓀢", "𓀣", "𓀤", "𓀥 ", "𓀦", "𓀧", "𓀨", "𓀩" }; */
   static const char *tags[] = { "௧ ", "௨ ", "௩ ", "௪ ", "௫ ", "௬ ", "௭ ", "௮ ", "௯ " }; /* used Unicode keys */
/* static const char *tags[] = { "௧", "௨", "௩", "௪", "௫", "௬", "௭", "௮", "௯" }; */ /* copy pasted from web page pdf */
/*
 * Buttons
 * See user.h for details on relevant structures.
 */
static const Binding bindings[] = {
    /* Click Location,   button,        callback,     bypass,    arguments */
     { Click_Layout,      BTN_LEFT,      layout,       1,         {.ui = 0} },
     { Click_Layout,      BTN_RIGHT,     layout,       1,         {.ui = 1} },
     { Click_Layout,      BTN_MIDDLE,    spawn,        0,   {.v = rofimenu } },
     { Click_Tag,         BTN_MIDDLE,    tag,          0,         {0} },
     { Click_Tag,         BTN_RIGHT,     toggle_view,  0,         {0} },
     { Click_Tag,         BTN_LEFT,      view,         0,         {0} },
};

#endif // CONFIG_H_
