<div align="center">
    <img width="100%" src="./assets/stars-project.png"/>
    <h1></h1>
    <h3>Unicode stars for terminal interfaces with customizable colors and proportionalities</h3>
</div>

<img width="100%" src="./assets/stars.gif"/>

## Table of contents
[Installing the Stars](#installing-the-stars)

- [Dependencies](#dependencies)

- [Downloading the source code](#dowloading-the-source-code)

- [Encoding configuration](#encoding-configuration)

- [Setting up Meson build system](#setting-up-meson-build-system)

- [Compiling the source code](#compiling-the-source-code)

- [Compiling the source code and installing the program in your system](#compiling-the-source-code-and-installing-the-program-in-your-system)

[Running the program](#running-the-program)

- [After compiling](#after-compiling)

- [After installing](#after-installing)

[Customization](#customization)

- [Number of stars](#number-of-stars)

- [Colors](#color)

# Installing the stars
This section contains everything you need to know to compile and run the Stars.

## Dependencies
Stars requires the following dependencies to be linked with the executable.

<ul>
    <li>Ncurses</li>
    <li>Anemone</li>
</ul>

## Dowloading the source code
Copy/paste this git command on your terminal to download the source code

```sh
git clone --recursive https://github.com/Romulo-Moraes/Stars.git
```

## Encoding configuration
This program uses UTF-8 encoding to display various types of stars. To ensure it functions properly, you must have the `en_US.utf8` encoding available on your system. You can verify the existence of this encoding by running the command `locale -a`. If it is not installed, you can generate it by executing the following command:
```sh
sudo locale-gen en_US.UTF-8
```

## Setting up Meson build system
The process of setting up the build system is completely done by running the `build.sh` script on the project root. It will initialize the Meson Build system for the Stars and its dependencies.

<b>If you don't have the Meson on your system, you can get it from here: https://mesonbuild.com/Getting-meson_ptbr.html. Or from your package manager if available.</b>

## Compiling the source code
The Meson build system handles the entire compilation process of the program. To compile the project, run the following command inside the `build/` directory: 
```sh
meson compile
```

## Compiling the source code and installing the program in your system
You can also make the stars be available across your entire system. To do that, you must run the meson install command:
```sh
# The Meson needs sudo permissions to install the app in your bin directory
sudo meson install
```

# Running the program

## After compiling
After compiling the project, the executable will be created in the build/ directory. Assuming that you have just compiled using the Meson build and still in the same directory, run:
```sh
./stars
```

## After installing
After installing the project, the Stars app will be available throughout your entire system. To launch the app, run:
```sh
stars
``` 

# Customization
This section provides everything you need to customize the stars program according to your preferences.

## Number of stars
The number of stars is defined based on the terminal's dimensions. By default, a star is created for every 8 terminal cells. You can define how many cells are necessary to create a single star.

To set a new value to this parameter, you can pass any &#8469;<sup>*</sup> number using the `--proportionality` flag:
```sh
stars --proportionality 28
```

The program call above will instruct the Stars to create a new star for every 28 terminal cells.

Note: A single star is not confined to the limits of a 28-cell block; it merely represents a calculation for determining the maximum number of stars displayed on screen

## Color
The color of the stars is defined using the flag `--color` and accepts the following set of colors:
<ul>
   <li>black</li>
   <li>blue</li>
   <li>cyan</li>
   <li>green</li>
   <li>magenta</li>
   <li>red</li>
   <li>white</li>
   <li>yellow</li>
</ul>

```sh
stars --color yellow
```
Note: the default color is `white`

## Modes
You can choose between two modes when launching the application. Each mode offers unique features, creating distinct star patterns.

### Queue (Default)
The queue mode generates a star queue with a size defined by the proportionality configuration. In each render loop, a new star is added and displayed on the screen. Once the queue reaches its limit, the oldest stars start to disappear as new ones are created at random positions.

#### Characteristics
<ul>
    <li>Stars don't blink</li>
    <li>New stars are created every time on different positions during the program's execution</li>
    <li>If the proportionality value is low, stars may stay on the screen for a long time before disappearing</li>
    <li>Good for small resolutions</li>
</ul>

#### Using the Queue mode
The queue mode is the stars' default mode; however, you can make it explicit with the following flag:
```sh
stars --mode queue
```

### Fixed
The fixed mode generates all stars at startup, assigning each a fixed position and an interval value in milliseconds. When the elapsed time matches the interval, the star will either appear or disappear, depending on its previous state.

#### Characteristics
<ul>
    <li>Stars blink independently</li>
    <li>No new stars are created during the program's execution</li>
    <li>The interval range in milliseconds may be defined on program's startup</li>
    <li>After each blink, a star receives a new interval value, making the duration of each blink different</li>
    <li>The default visibility state assigned to a star upon its creation is random, which means even short intervals, such as 600-601, may produce a cool effect</li>
    <li>Good for large resolutions</li>
</ul>

#### Using the Fixed mode
To use the fixed mode, the following flag and value must be set:
```sh
stars --mode fixed
```

#### Creating a custom interval range
At startup, each newly created star is assigned a random blink interval (in milliseconds) within the default or specified range.

You can use the following flag and format to create a custom range:
```sh
stars --mode fixed --interval 500-1000
```

<b>Note: the default range is 800-1500</b>
