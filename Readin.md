<h3 align="center"> <img align="center" width="80%" src="https://raw.githubusercontent.com/baotrwg/HSG11-2025/main/assets/terminal.png" alt="Terminal Image"/> </h3>
## Đề
### 👁️‍🗨️ Các đề cần được giải:

- [Arch-Linux](https://github.com/JaKooLit/Arch-Hyprland)

- [OpenSUSE(Tumbleweed)](https://github.com/JaKooLit/OpenSuse-Hyprland)

- [Fedora-Linux](https://github.com/JaKooLit/Fedora-Hyprland)

- [Debian Trixie / SiD](https://github.com/JaKooLit/Debian-Hyprland)

- [Ubuntu 24.04 LTS](https://github.com/JaKooLit/Ubuntu-Hyprland/tree/24.04)

- [NixOS](https://github.com/JaKooLit/NixOS-Hyprland)

#### Hyprland Install scripts on alpha/beta stage

- [Ubuntu 24.10)](https://github.com/JaKooLit/Ubuntu-Hyprland/tree/24.10)

- refer to install scripts what packages needed to install... but atleast, Hyprland packages is needed 😏😏😏 duh!!
- When using the install scripts above, it will pull the releases (stable) of this dotfiles, except for Nixos where it pulls from main


### 🪧 Attention 🪧
- This repo does NOT contain or will NOT install any packages. These are only hyprland configs or dotfiles
- This repo will be pulled by the Distro-Hyprland install scripts above if you opt to download pre-configured dots

### 👀 Screenshots 👀
- All screenshots are collected here [Screenshots](https://github.com/JaKooLit/screenshots/tree/main/Hyprland-ScreenShots)

### 📦 Whats new?
- To easily track changes, I will be updating the [CHANGELOGS](https://github.com/JaKooLit/Hyprland-Dots/wiki/Changelogs)  Screenshots will be included if worth it!

### 💥 Copying / Installation / Update instructions 💥
- [`MORE INFO HERE`](https://github.com/JaKooLit/Hyprland-Dots/wiki/Install_&_Update) 
> [!Note] 
> The auto copy script "copy.sh" will create backups of intended folders to be copied. However, still a good idea to manually backup just incase script failed to backup!
- ~/.config (ags btop cava hypr kitty Kvantum qt5ct qt6ct rofi swappy swaync wallust waybar wlogout) - These are folders to be copied.
- ~/Pictures/wallpapers - Will be backed up
- clone this repo by using git. Change directory, make executable and run the script

> to download from Master branch
```bash
git clone --depth=1 https://github.com/JaKooLit/Hyprland-Dots.git
cd Hyprland-Dots
```

> to download from Development branch (development and testing)
```bash
git clone --depth=1 https://github.com/JaKooLit/Hyprland-Dots.git -b development
cd Hyprland-Dots
```

- automatic copy of pre-configured dots
```bash
chmod +x copy.sh
./copy.sh
```

- to copy/install from releases (stable)
```bash
chmod +x release.sh
./release.sh
```

- UPGRADE.sh function
> [!IMPORTANT]
> You need rsync for it to work
> you should have already up and running KooL's Hyprland before using this function
```bash
chmod +x upgrade.sh
./upgrade.sh
```

## ⚠️⚠️⚠️ Chú ý!
> [!CAUTION]
> Tạo issue nếu có ý tưởng cần bàn
> Gửi mail tại: marino.kari24@gmail.com
> Đây chỉ là trang chia sẻ kiến thức của các HS THPT (hoặc Sinh viên Đại Học).
