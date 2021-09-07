## Description

This project aims to be a flexible, [Zandronum](https://zandronum.com/) launcher ready to be easily tooled for any mod in order to compile and launch their game.

It tries to remove the complexities of the command line and more easily support local server launches.

<img src="https://img.shields.io/badge/windows-10-blue.svg" /> <img src="https://img.shields.io/badge/osx-mojave-blue.svg" />

## Getting Started

### Prerequisites

Download and install [QT 5.15](https://www.qt.io/download-open-source) using the online installer. Make sure to use MinGW 64 bit build of QT.

This is required to modify and build the launcher.

### Installing & Making Changes

1. Import the cloned project into QT Creator.
1. Change out key assets to represent your mod:
   * resource/background.png : Main dialog background
   * resource/executable/mod.pk3 : Compiled mod (currently only supports single PK3)
   * resource/executable/mod.ini : Custom mod configuration
1. Build and run.

### Deployment

#### Windows

1. Build in QT Creator, using the above process.
1. Copy the `ZandronumLauncher.exe` from debug build folder used by QT to a new empty deployment folder.
1. Copy everything from `resource/executable/generic` and `resource/executable/win` to the same new folder. Do not include the sub-directories, just the content files.
1. Copy the launch config file from `resource/config.json` to the same new folder. This is required for custom launch client or server parameters.
1. Run the QT deployment executable, to pull in all the DLLs. Make sure to change based on your QT build and MinGW build.
   * Example: `PATH=$PATH:/c/Qt/Tools/mingw810_64/bin/ /c/Qt/5.15.2/mingw81_64/bin/windeployqt.exe --debug ZandronumLauncher.exe`

#### Mac

1. Build in QT Creator, using the above process.
1. Copy the `ZandronumLauncher.app` from debug builder folder to Applications directory.

## Built With

* [Zandronum](https://zandronum.com/) - Multiplayer oriented Doom port, based off Skulltag, for Doom and Doom II
* [Freedoom](https://freedoom.github.io/) - Free build of Doom engine assets, compatible as IWAD of base game

## Authors

* **Jordan Tymburski** - [Portfolio](https://jordantymburski.com/)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

* **Jesze Kaszas** - Artistic Visionary of [Many.](http://simulacruminteractive.ca/) [Different.](https://forestbear.net/) [Projects.](https://www.youtube.com/user/OZetsuiO/)
   * This launcher was created for one of his oldest projects, [Halodoom](https://forestbear.net/projects/halodoom/)
