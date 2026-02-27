# cub3d

This repository contains a minimal `cub3d` layout with source files, project headers, and a vendored `libft`.

## Project layout

```text
.
├── Makefile
├── includes/
│   ├── cub3d.h
│   ├── libft.h
│   └── libft/
└── src/
    ├── main.c
    └── raycasting.c
```

- `src/` contains the current game source files.
- `includes/` contains project headers.
- `includes/libft/` contains the vendored `libft` sources and its Makefile.
- `Makefile` builds `libft`, clones/builds MiniLibX when needed, and links the final `cub3d` binary.

## Build flow

1. Build `libft` from `includes/libft`.
2. Clone `minilibx` if the folder is missing.
3. Build MiniLibX.
4. Compile and link `cub3d`.

```bash
make
```

## Notes

In restricted environments, `make` may fail while cloning MiniLibX if network access to GitHub is blocked.
