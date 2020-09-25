## Linux Shell

The Linux Shell is created by using `C`.

`System Calls` used in this task can be found from:

<a href="https://man7.org/linux/man-pages/man2/syscalls.2.html#:~:text=DESCRIPTION%20top,or%20perhaps%20some%20other%20library)."><img src="https://e7.pngegg.com/pngimages/201/564/png-clipart-linux-distribution-operating-systems-unix-like-open-source-software-linux-logo-bird.png" width="150" height="50"/></a>


## Index

- [References](https://github.com/Lovepreet-Singh-LPSK/LinuxShell#references)
  - [Screenshots](https://github.com/tasdikrahman/spaceShooter#screenshots)
- [Game Features](https://github.com/tasdikrahman/spaceShooter#game-features)
  - [Controls](https://github.com/tasdikrahman/spaceShooter#controls)
- [Installation](https://github.com/tasdikrahman/spaceShooter#installation)
  - [For Windows](https://github.com/tasdikrahman/spaceShooter#for-windows)
  - [Linux/Debian based systems](https://github.com/tasdikrahman/spaceShooter#linuxdebian-based-systems)
    - [Option 1: Download the zipped executable file](https://github.com/tasdikrahman/spaceShooter#option-1-download-the-zipped-executable-file)
    - [Option 2: Build from source](https://github.com/tasdikrahman/spaceShooter#option-2-build-from-source)
  - [For MAC OS X](https://github.com/tasdikrahman/spaceShooter#for-mac-os-x)
- [Contributing](https://github.com/tasdikrahman/spaceShooter#contributing)
  - [Contributers](https://github.com/tasdikrahman/spaceShooter#contributers)
  - [To-do](https://github.com/tasdikrahman/spaceShooter#to-do)
- [Issues](https://github.com/tasdikrahman/spaceShooter#issues)
- [Credits](https://github.com/tasdikrahman/spaceShooter#credits)
- [Similar](https://github.com/tasdikrahman/spaceShooter#similar)
- [License](https://github.com/tasdikrahman/spaceShooter#license)
- [Donation](https://github.com/tasdikrahman/spaceShooter#donation)

## References

[[Back to top]](https://github.com/Lovepreet-Singh-LPSK/LinuxShell#index)

Follow this <a href="https://brennan.io/2015/01/16/write-a-shell-in-c/">Tutorial</a> for structure or architecture of the ``Shell``<br>
For Different commands like `ls`,`cd`,`grep` etc. Follow my Repo and Give a Star if you Like :)

## Screenshots

[[Back to top]](https://github.com/Lovepreet-Singh-LPSK/LinuxShell#index)

| ![Screen 1](https://github.com/Lovepreet-Singh-LPSK/LinuxShell/blob/master/pics/1.png) | ![Screen 2](https://github.com/Lovepreet-Singh-LPSK/LinuxShell/blob/master/pics/2.png) |
|---------------------------------------------|---------------------------------------------|
| ![Screen 3](https://github.com/Lovepreet-Singh-LPSK/LinuxShell/blob/master/pics/3.png) | ![Screen 4](https://github.com/Lovepreet-Singh-LPSK/LinuxShell/blob/master/pics/4.png) |

## Shell Features

[[Back to top]](https://github.com/Lovepreet-Singh-LPSK/LinuxShell#index)

- Commands can run in parallel or in background by using `&` at the end of the command.
- All Commands of basic linux shell run in this shell too, even in background using `&`.
- Commands which are manually coded includes ``g`` symbol at the front of the command. Ex. `gls`, `gcd`, `ggrep`.
- Shell implemented using only system calls.
- Extra Functions like help command, exit command also implemented.

## How To Run Shell

**NOTE** : Please install `git` and `make` on your OS first. 

[[Back to top]](https://github.com/Lovepreet-Singh-LPSK/LinuxShell#index)

```bash
$ git clone https://github.com/Lovepreet-Singh-LPSK/LinuxShell.git
$ cd LinuxShell
$ make
$ ./sh
```


```bash
$ sudo apt-get install unzip
```
That should fix the error.

- Run the executable named `spaceShooter`

A Similar process would be followed for `OS X`

#### Option 2: Build from source

You need to have `pygame` installed for this option. 

### For `FreeBSD`

```sh
$ sudo pkg install devel/py-game
```

##### Clone the repo
```sh
$ git clone https://github.com/tasdikrahman/spaceShooter.git
$ cd spaceShooter/
$ chmod +x spaceShooter.py
$ python spaceShooter.py
```


### For `Ubuntu/Debian`

```bash
$ sudo apt-get install python-pygame
```

##### Clone the repo

```bash
$ git clone https://github.com/tasdikrahman/spaceShooter.git
$ cd spaceShooter/ 
$ python spaceShooter.py
```

### For `MAC OS X` 

You have to build from source to get it up and running on `OS X`. Reason?
I don't have an `OS X` system to build the executable! So I would love for a Pull request on that one.

Building from source will do the trick though


```bash
$ pip3 install hg+http://bitbucket.org/pygame/pygame
```

Install Pygame specific dependencies

```bash
$ brew install sdl sdl_image sdl_ttf portmidi libogg libvorbis
$ brew install sdl_mixer --with-libvorbis
```

##### Clone the repo

```bash
$ git clone https://github.com/tasdikrahman/spaceShooter.git
$ cd spaceShooter/ 
$ python spaceShooter.py
```

## Contributing

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

This game was written in one day, so the coding standards might not be up the mark. Don't be shy to make a Pull request :)

For details, please refer [the Contributing page](https://github.com/tasdikrahman/spaceShooter/blob/master/CONTRIBUTING.rst)

### Contributers

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

- [@bardlean86](https://github.com/bardlean86/) for adding the third missile powerup and the main menu

### To-do

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

- [x] Add the `windows` executable file
- [x] Add main menu for the game
- [x] Fix [bug](https://github.com/tasdikrahman/spaceShooter/blob/master/spaceShooter.py#L372) which stops the background music from looping 
- [x] Add support for `WAV` game music file as `ogg` format is not playable as described in [#1](https://github.com/tasdikrahman/spaceShooter/issues/1)
- [ ] Add feature to pause to the game.
- [ ] add feature to replay the game after all players die
- [ ] Add `OS X` executable file as the `Debian` based one fails to execute on it


## Issues

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

You can report the bugs at the [issue tracker](https://github.com/tasdikrahman/spaceShooter/issues)

**OR**

You can [tweet me](https://twitter.com/tasdikrahman) if you can't get it to work. In fact, you should tweet me anyway.

## Credits

The game is a fork of the video instructions given by KidsCanCode. I have made several additional enhancements to it. Do check out their [Channel](https://www.youtube.com/channel/UCNaPQ5uLX5iIEHUCLmfAgKg)!

## Similar

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

- [Bullethell.py ](https://github.com/Frederikxyz/bullethell.py) : A fork of [tasdikrahman/spaceShooter](https://github.com/tasdikrahman/spaceShooter) which adds fancy shooting capabilities

## License

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

Built with ♥ by [Tasdik Rahman](http://tasdikrahman.me)[(@tasdikrahman)](https://twitter.com/tasdikrahman) under [MIT License](http://tasdikrahman.mit-license.org)

You can find a copy of the License at http://tasdikrahman.mit-license.org/

- The images used in the game are taken from [http://opengameart.org/](http://opengameart.org/), more particulary from the [Space shooter content pack](http://opengameart.org/content/space-shooter-redux) from [@kenney](http://opengameart.org/users/kenney).

License for them is in `Public Domain`

- The game sounds were again taken from [http://opengameart.org/](http://opengameart.org/). The game music, [Frozen Jam](http://opengameart.org/content/frozen-jam-seamless-loop) by [tgfcoder](https://twitter.com/tgfcoder) licensed under [CC-BY-3](http://creativecommons.org/licenses/by/3.0/)

## Donation

[[Back to top]](https://github.com/tasdikrahman/spaceShooter#index)

If you have found my little bits of software being of any use to you, do consider helping me pay my internet bills :)

| PayPal | <a href="https://paypal.me/tasdik" target="_blank"><img src="https://www.paypalobjects.com/webstatic/mktg/logo/AM_mc_vs_dc_ae.jpg" alt="Donate via PayPal!" title="Donate via PayPal!" /></a> |
|:-------------------------------------------:|:-------------------------------------------------------------:|
| Gratipay  | <a href="https://gratipay.com/tasdikrahman/" target="_blank"><img src="https://cdn.rawgit.com/gratipay/gratipay-badge/2.3.0/dist/gratipay.png" alt="Support via Gratipay" title="Support via Gratipay" /></a> |
| Patreon | <a href="https://www.patreon.com/tasdikrahman" target="_blank"><img src="http://i.imgur.com/ICWPFOs.png" alt="Support me on Patreon" title="Support me on Patreon" /></a> |
| £ (GBP) | <a href="https://transferwise.com/pay/d804d854-6862-4127-afdd-4687d64cbd28" target="_blank"><img src="http://i.imgur.com/ARJfowA.png" alt="Donate via TransferWise!" title="Donate via TransferWise!" /></a> |
| € Euros | <a href="https://transferwise.com/pay/64c586e3-ec99-4be8-af0b-59241f7b9b79" target="_blank"><img src="http://i.imgur.com/ARJfowA.png" alt="Donate via TransferWise!" title="Donate via TransferWise!" /></a> |
| ₹ (INR)  | <a href="https://www.instamojo.com/@tasdikrahman" target="_blank"><img src="https://www.soldermall.com/images/pic-online-payment.jpg" alt="Donate via instamojo" title="Donate via instamojo" /></a> |
