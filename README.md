*This project has been created as part of the 42 curriculum by [your_login].*

## Description
cub3D is a raycasting-based 3D engine written in C, inspired by Wolfenstein 3D and developed as part of the 42 curriculum. It renders a first-person maze view using the DDA (Digital Differential Analyzer) algorithm and MiniLibX.

## Instructions
### Dependencies
- MiniLibX
- libft
- X11 development libraries

### Compilation
```bash
make
```

### Execution
```bash
./cub3D maps/map.cub
```

### Makefile rules
- `all`: Build the mandatory project
- `clean`: Remove object files
- `fclean`: Remove object files and executable(s)
- `re`: Rebuild from scratch (`fclean` + `all`)
- `bonus`: Build bonus features

## Controls
- `W`, `A`, `S`, `D`: Move
- `Left Arrow` / `Right Arrow`: Rotate camera
- `ESC`: Quit
- Window `X` button: Quit

## Map format
The `.cub` file contains:
- Texture paths: `NO`, `SO`, `EA`, `WE`
- Floor and ceiling colors: `F` and `C` in RGB format
- A map grid using valid characters: `0`, `1`, `N`, `S`, `E`, `W`

The map definition must be the last section of the file and must be fully enclosed by walls.

## Resources
- Lode Vandevenne's Raycasting Tutorial: https://lodev.org/cgtutor/raycasting.html
- Original Wolfenstein 3D (id Software): https://en.wikipedia.org/wiki/Wolfenstein_3D

### AI usage in this project
AI assistance was used to:
- Scaffold the parser architecture
- Debug compiler and linker issues
- Implement the image buffer rendering pipeline
- Write the memory cleanup logic
