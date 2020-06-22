## personal build of dwm
todo list:
- patch in a clean bar, includes
	- time (no more timedatectl)
	- battery level (no more guessing)
	- weather? optional
	- now playing (nah if too much work)
- add xresources compatibility (for pywal)
- new layouts (grid, attachaside, centered master)
- custom keybinds for 
	- brightness (xbacklight -inc/dec 5)
	- volume (alsamixer?)
	- ncmpcpp (pause, play, next song, shuffle?)
- figure out how to get xinitrc to randomize wallpaper on startup
- where did my extensive list of patches go reeeee
- patches: centered master, cfacts(?), crop windows(?), ewmh (if switching to polybar/lemonbar), fibonacci (?), exresize for floating windows, tabs (for monocle mode), flextile(?? lots of reading), gapless grid + horizontal grid, movestack/push (?), mpdcontrol, rotate stack, save floats (floating aesthetic), sticky, stacker(?) and stackmfact (vertical resizing), three column layout (same as centered master?), xtile (??? lots of reading)

done:
- now uses mononoki nerd font
- autostart patched in, very easy to use and works with everything EXCEPT pywal (reee)
- gaps patched in, custom binds:
  - alt-d for dmenu
  - alt-super-j to decrease gaps
  - alt-super-k to enlarge gaps
  - alt-super-0 to reset gaps and alt-super-shift-0 to toggle gaps
  - default gaps are a nice aesthetic 25
  - alt-q to close a window
  - alt-enter for new terminal, alt-shift-enter for toggle master
  - alt-n for next tag, alt-p for previous tag
  - control-alt-delete to quit (pranking windows users if they find my computer unattended)
- patched in swallow, pertag (for swallow to work, change "st" to "St"), shiftview
- the bar now displays shulk's monado arts (with Source Han Sans to match the aesthetic)
- the bar is now padded (dae bar is literally eris?? -probably aqua)
- everything is blurred  (thanks compton??)

