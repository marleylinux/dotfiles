\\ DotfilesInstaller + Dotfiles //

This is my current dotfiles + an dotfilesinstall script to download, install and copy the correct files in the correct places

It's a good 'minimal' base from what I believe. 

GTK theme (adwgtk3)

Wallpaper 

Cursor theme (catppuccin-mochadark)

vimrc 

bashrc

nwg apps


Instructions. 

##YOU MAY NEED TO sudo chmod 777 the app if it wont launch as ./ 

git clone https://github.com/marleylinux/dotfiles && cd dotfiles

then gcc dotfilesinstaller.c -o DotfilesInstaller && ./DotfilesInstaller

-----------------------------------------------------------------------------------

We can also chain the commands together at once.

git clone https://github.com/marleylinux/dotfiles && cd dotfiles && gcc dotfilesinstaller.c -o DotfilesInstaller && ./DotfilesInstaller

-----------------------------------------------------------------------------------------------------------------------------------------------

