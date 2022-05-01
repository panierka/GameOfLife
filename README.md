## Premise

C++ SFML application, with the sole responsibility of running simulation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life), based on randomly generated starting conditions.

![image](https://user-images.githubusercontent.com/72386943/166153709-8d4bc1e7-ba85-4c18-9f23-6edd3218aa4a.png)

Cells behave properly and are able to reproduce Game of Life's signature structures - for example, gliders.

![image](https://user-images.githubusercontent.com/72386943/166153727-2f299c57-fe90-415d-aca7-775499ee8e5c.png)

## Requirements

- Project was made using SFML-2.5.1 (x64)
- It uses sfml's graphics, window and system .lib files, so you need to put those in the project space (and their debug counterparts, for Debug builds)
- Put `<your path to sfml>/include` in General > Aditional Include Directiories
- Put `<your path to sfml>/lib` in Linker > General > Aditional Library Directiories
