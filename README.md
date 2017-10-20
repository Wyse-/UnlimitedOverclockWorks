# UnlimitedOverclockWorks

## Screenshots

![alt tag](https://b.doko.moe/vzzzij.png)

## Description
Written and compiled using Code::Blocks 16.01 and GCC.

This is a software made for overclockable 1440p Korean monitors (Qnix QX2710, X-Star DP2710, Yamakasi Catleap 2b). A known issue for these monitors is the "cold start" one, which occurs when the monitor is overclocked to high refresh rates and the computer its plugged into just booted after being off for a while: a good portion of the monitor displays a dense blackish tint, which will make it completely unusable; one way of fixing this is just waiting: the tint will progressively get smaller, and after a while it will completely disappear. Another way to fix this is to change the refresh rate of the monitor to a lower one.
Apparently this is caused by the temperature of the T-Con board, which needs to heat up to loosen its bandwidth (more bandwidth is needed to display the same resolution at higher refresh rates).

That's where this software comes in: it's supposed to run in autostart, and it automates the switching of the refresh rate from a high one (e.g. 120Hz) to a lower one (e.g. 72Hz). It's highly configurable through its config.ini file, it also has support for displaying a fullscreen white image dismissable my clicking (which should speed up the heating process) and starting [Deliner](https://www.monitortests.com/forum/Thread-Deliner) after the monitor is heated and switched to a high refresh rate.

Keep in mind this software won't work out of the box: follow the how-to instructions below.

## How-to
- Head over to the [releases section](https://github.com/Wyse-/UnlimitedOverclockWorks/releases) to download the main software.
- You will need a copy of "SetDisplayFrequency.exe" executable. This is a proprietary executable included in the [AnyDVD HD demo](https://www.redfox.bz/download.html). Obtaining it is free and you can uninstall the software after copying the executable (which is located in the install folder of the software), however I'm not allowed to redistribute the file itself.
- [Optional] If you intend to use the Deliner auto-start feature you will need to [download deliner](https://www.monitortests.com/forum/Thread-Deliner).
- Extract everything in the same folder (if you don't want to mess with the config.ini file too much the default directory is C:\UOW).
- Configure the config.ini file accordingly, the comments on the right should help you figure out the different options. Remember that depending on your HDD/SSD speed and number of boot up programs you will probably want to tweak the Time1 field.
- Add UOW.exe to autostart.
- Done!
