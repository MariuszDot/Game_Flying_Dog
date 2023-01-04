# Game about a flying dog dealing with enemies

![](Gameplay_gif.gif)

Project was created to compare the exact same games written in Python (which you can see [here](https://github.com/MariuszDot/Game_OOP)) and in C/C++. Made entirely from scratch using SDL2 libraries.
Uses C++17.

## You want to compile it?
Just fork the repository and compile it by typing the command:
```
g++ -Isrc/include -Lsrc/lib -std=c++17 -g *.cpp -o main.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
```
All needed libraries are already in there. Just make sure you're compiling it in 64bit.
If you're using VS Code it's even easier - I've included tasks.json and other VSC files, so simple F5 should do the trick.

## You want to play it?
Just download Venom Adventures.rar from repo, unzip it and start "Venom Adventures.exe" file. It's already statically compiled with libraries that Windows needs and in 32bit, so that older computers can also use it.
Unfortunately, I don't know how that program would behave on Mac - I haven't had a chance to test it.

## You want to contribute/use it?
Feel free to do whatever you want with that code. Although I don't suppose anyone will contribute, I'd be very glad for any new graphics, new mechanics, any contribution.

## My special thanks for different entities I have used:
[explosion animation](https://opengameart.org/content/2d-explosion-animations-frame-by-frame)\
[fire sparks](https://opengameart.org/content/sparks-fire-ice-blood)\
[plane](https://iconarchive.com/show/remixed-icons-by-iconblock/Plane-icon.html)\
[tree nr 2](https://freepngdownload.com/tree/tree-png-free-image)\
[grass](www.freepik.com)\
[bulding, power towers](https://opengameart.org/content/sunshine-city-building-and-tree)\
[bomb](https://www.flaticon.com/free-icons/bomb)\
[black tower](https://opengameart.org/content/fantasy-tower-dark)\
[fireball animation](https://opengameart.org/content/fireball-spell)\
[blue bird](https://opengameart.org/content/free-game-asset-grumpy-flappy-bird-sprite-sheets)\
[green bird](https://www.pngegg.com/en/png-nqbuh)\
[black bird](https://opengameart.org/content/flappy-bird-flying-gentleman-sprite)\
[icon](https://www.flaticon.com/free-icons/paw)\
[main music](https://uppbeat.io/track/philip-anderson/achievement)\
[explosion sound](http://creativecommons.org/licenses/by-sa/3.0/)\
[birds sound](https://mixkit.co/free-sound-effects/bird/)

Thank you for reading!
Have a good day,
Mariusz

