#!/bin/bash
# ~/.xinitrc by arpinux 2016
############################

## D-Bus ##-------------------------------------------------------------
if which dbus-launch >/dev/null && test -z "$DBUS_SESSION_BUS_ADDRESS"; then
        eval "`dbus-launch --sh-syntax --exit-with-session`"
fi
## read ~.Xresources file ##--------------------------------------------
xrdb -merge ~/.Xresources
## set cursor ##--------------------------------------------------------
xsetroot -cursor_name left_ptr
## enable snap font ##--------------------------------------------------
xset fp+ /usr/share/fonts/livarp_fonts/artwiz-latin1/
xset fp rehash
## set ctrl_alt_bksp as session-killer ##-------------------------------
setxkbmap fr -variant oss -option terminate:ctrl_alt_bksp
## no blank screen ##---------------------------------------------------
#xset -display :0 s off -dpms
## set welcome screen ##------------------------------------------------
#eval $(cat ~/.fehbg) &
feh --bg-fill $HOME/.background.png

## launch Xsession #####################################################
exec ck-launch-session /home/arp/bin/dwm-session
