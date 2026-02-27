# cub3d

This repository currently contains a minimal `cub3d` layout with source files, project headers, and a vendored `libft`.

## Where we are

- `src/` contains the current game source files (`main.c`, `raycasting.c`).
- `includes/` contains project headers.
- `includes/libft/` contains the `libft` sources and Makefile used by this project.
- `Makefile` builds `libft`, clones/builds MiniLibX when needed, and links the final `cub3d` binary.

## Current build flow

1. Build `libft` from `includes/libft`.
2. Clone `minilibx` if the folder is missing.
3. Build MiniLibX.
4. Compile and link `cub3d`.

## Notes

- In restricted environments, `make` may fail while cloning MiniLibX if network access to GitHub is blocked.
