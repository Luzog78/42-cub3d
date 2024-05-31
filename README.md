<div align="center">

# 42 Cursus - cub3D

![ecole_42](https://github.com/ayogun/42-project-badges/blob/main/badges/cub3dm.png?raw=true)

<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" height="30" alt="c" />
<img width="12" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" height="30" alt="vscode" />

<br><br>

<table><thead><tr>
	<th colspan=2><strong id="team">Team</strong></th>
</tr></thead><tbody><tr>
	<td>
		<a href="https://profile.intra.42.fr/users/hbelle" target="_blank">
			<img src="https://cdn.intra.42.fr/users/55a660712aea8550796f5bca9f1643bc/hbelle.jpg" height="120" alt="hbelle" />
			<br>
			<strong>Héliam Belle</strong>
		</a>
	</td>
	<td>
		<a href="https://profile.intra.42.fr/users/ysabik" target="_blank">
			<img src="https://cdn.intra.42.fr/users/1046eb06e67db02233dde6a9528d95bc/ysabik.jpg" height="120" alt="ysabik" />
			<br>
			<strong>Yanis Sabik</strong>
		</a>
	</td>
</tr></tbody></table>

<br><br>

</div>


https://github.com/fZpHr/cub3d_42/assets/92046611/eca88560-edbe-43c4-9f0a-d648ca9117e4


## Cub3D

Cub3D is a 42 project where you create a simple 3D game using the raycasting technique.
The goal is to build a small game engine capable of rendering a 3D environment from a 2D map,
allowing the player to navigate through it in a first-person perspective. This project helps
reinforce your understanding of graphics programming and computational geometry concepts.

*For more information, please refer to the subject.*


## Installation

To install cub3D, clone the project and download the minilibx :
```bash
git clone git@github.com:Luzog78/42-cub3d.git
cd 42-cub3d
```

Downloading the minilibx :
```bash
wget https://cdn.intra.42.fr/document/document/22379/minilibx-linux.tgz
tar -xf minilibx-linux
```

Then compile the executable using `make` (`make bonus` to compile the bonuses)
```bash
make
```

Finally, launch the game with :
```bash
./cub3D <path_of_the_map>
```


## How to play ?

- **Mandatory**
  - Move with the classic **W**, **A**, **S**, **D**.
  - Rotate with the **Left Arrow** and the **Right Arrow**.

- **Bonus features**
  - Rotate using the **Mouse**.
  - Open an close the doors using **Space**.
  - Enable/Disable the minimap with **M** (or **Tab**).
  - Enable/Disable the debug screen with **I**.


## Map Syntax

> [!IMPORTANT]
> 
> 1. The filename must end with `.cub`
> 
> 2. The map must be closed (no contact between a floor `0` and a space ` ` or a border)
> 
> 3. There has to be at least one player (`N`, `S`, `W`, `E`)

Here is an example of a working map for the mandatory part :
```cub
NO ./textures/bricks-blue-00.xpm
SO ./textures/bricks-blue-00.xpm
WE ./textures/bricks-blue-00.xpm
EA ./textures/bricks-blue-00.xpm

F 255,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
And here is the cheatsheet of the bonus maps :
```cub
NO [<id>] <path_to_the_xpm_file>  // Required for id 1
SO [<id>] <path_to_the_xpm_file>  // There can be multiple definition:
WE [<id>] <path_to_the_xpm_file>  //    the images will be the frames of the animation.
EA [<id>] <path_to_the_xpm_file>  // def_text id=1
                                  // def_text texture=NULL (transparent)

MP <id> (<R>,<G>,<B>)             // def_text 1=238,238,238; 2=0,0,0; others=transparent
TY <id> <type>                    // 0=no collision; 1=collision
                                  // def_text for '0'    >> 0 (void)
                                  // def_text for others >> 1 (wall)
SP <id> <amim_delay_in_frames>    // def_text delay=30

// Map rules:
// 1. ' ' = void
// 2. '1' = wall
// 3. '0' = empty
// 4. 'N', 'S', 'W', 'E' = player
// 5. Void should not be accessible by the player
        (it should be a wall preventing the player from going there)
// 6. There should be at least one player
// 7. Any char is accepted BUT the texture MUST BE DECLARED in the .cub file

// Adds:
// - 'X' = Closed Door >> Should be able to open
// - 'O' = Opened Door >> Should be able to close
// - '-' = Opening Door >> Automatically becomes 'O' once fully opened

F (<R>,<G>,<B>)          // Required & Always end by C or F
C (<R>,<G>,<B>)          // Required & Always end by C or F

        1111111111111111111111111
        1000000000100000000000001
        1011000001110000000000001
        100100000000000000X000001
111111111011000001110000000000001
10000000000011000001110112311111111
11110111111111011100000010001
11110111111111011101010010001
110000001101010111001 1010001
1000000000000001100011010001
1000E000000000001101010000001
1100000111010101111101111000111
11110111 1110101 10111101000011
11111111 1111111 111111111111

// After the map, there must be nothing (either empty lines, comments or EOF)
```

---

### Thanks to my teammate ! Git repo: [Zeph (fZpHr) - cub3d_42](https://github.com/fZpHr/cub3d_42)

<sup><i>This is a modified version of his readme.</i><sup>
