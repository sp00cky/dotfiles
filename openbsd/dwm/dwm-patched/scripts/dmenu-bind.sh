#!/bin/bash
#include personnal bin folder
if [ -e "$HOME/bin" ]; then
	PATH="$HOME/bin:$PATH"
fi
# launch dmenu
exe=`dmenu_run -fn "snap" -nb '#090909' -nf '#A0A0A0' -sb '#320000' -sf '#DEDEDE' -p 'exec:'` && eval "exec $exe" &
#exe=`dmenu_run -fn "Droid Sans 6" -nb '#1F1F1F' -nf '#eeeeee' -sb '#2F5B91' -sf '#F9F9F9' -p 'exec:'` && eval "exec $exe" &
exit 0
