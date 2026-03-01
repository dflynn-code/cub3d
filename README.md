*This project has been created as part of the 42 curriculum by akjoerse, daflynn.*

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
This project was developed with extensive and deliberate use of multiple AI tools across every phase, used as an accelerated learning and development pipeline under significant time pressure.
Tools used: ChatGPT, Claude (Anthropic), GitHub Copilot/Codex, Deepseek, and Gemini.

ChatGPT — initial DDA implementation, basic MLX window with ceiling/floor/wall rendering
Claude — progress documentation, architectural review, parser design, image buffer pipeline, valgrind analysis, re-prompting Codex when it made poor structural decisions
Codex — primary coding interface when live testing was unavailable, norm compliance passes after each feature milestone, folder restructuring
Deepseek — wall rendering phase and texture loading concepts
Gemini — texture loading ideas; also integrated into a custom n8n webhook pipeline reading GitHub commits and generating Socratic teaching prompts fed into Google Sheets to help both partners track and understand the evolving codebase

What was done manually: architectural direction between AI iterations, final norm error fixes in vim, integration of versions across machines, and judgment calls about which AI output to accept or re-prompt.
