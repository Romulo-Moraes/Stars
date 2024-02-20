<div align="center">
    <img width="100%" src="./assets/stars-project.png"/>
    <h1></h1>
    <h3>UTF-8 Stars for terminal interfaces</h3>
</div>

<img width="100%" src="./assets/stars.gif"/>
<p align="center">Stars was primarily a small program that I wrote to compose my setup a couple of months ago. It only took a few minutes to write it that day; however, I rewrote the source code to make it available on my Github.</p>

## Features
<ul>
    <li>Number of stars is generated based on terminal's dimensions</li>
    <li>Set a custom number of stars based on terminal's dimensions</li>
</ul>

## Table of contents
[Installing the Stars]()

- [Dependencies]()

- [Downloading the source code]()

- [Setting up the Meson build system]()

- [Compiling source code]()

- [Compiling the source code and installing the program in your system]()

[Running the program]()

- [After compiling]()

- [After installing]()

[Customizing]()

- [Number of stars]()

# Installing the Stars
This section contains everything you need to know to compile and run the Stars.

## Dependencies
Stars requires a runtime dependency to be linked with the executable.

<ul>
    <li>Ncurses</li>
</ul>

## Dowloading the source code
Copy/paste this git command on your terminal to download the source code

```sh
git clone https://github.com/Romulo-Moraes/Stars.git
```

## Setting up the Meson build system
Meson build is a build system that helps in development by providing installation/compilation features.

Assuming that you are in the root directory, run:
```sh
meson setup build
cd build
```

## Compiling the source code
The Meson build handles the entire compilation process of the program. To compile the project, run: 
```sh
meson compile
```

## Compiling the source code and installing the program in your system
If you liked the application and want to make it available across your entire system, run:
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

# Customizing
This section will show you everything you need to know to customize the application.

## Number of stars
The number of stars is defined based on the terminal's dimensions. By default, a star is created for every 8 terminal cells. You can define how many cells are necessary to create a single star.

To customize the default value, you can pass any &#8469;<sup>*</sup> number as the first program argument:
```sh
stars 28
```

The program call above will instruct the Stars to create a new star for every 28 terminal cells.

Note: A single star is not limited by the range of a 28-cell block; it is simply a calculation to determine the maximum number of stars shown on the terminal.