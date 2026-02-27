# cub3d

A minimal `cub3d` repository with project sources, headers, and a vendored `libft`.

---

## 📁 Project layout

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

| Path | Purpose |
|---|---|
| `src/` | Main game source files. |
| `includes/` | Project headers. |
| `includes/libft/` | Vendored `libft` sources + its Makefile. |
| `Makefile` | Orchestrates libft, MiniLibX, and final `cub3d` build. |

---

## 🛠️ Build flow

The root `Makefile` performs these steps:

1. Build `libft` from `includes/libft`.
2. Clone `minilibx` if missing.
3. Build MiniLibX.
4. Compile and link `cub3d`.

Typical command:

```bash
make
```

---

## ⚠️ Environment note

In restricted environments, `make` may fail while cloning MiniLibX if GitHub access is blocked.
