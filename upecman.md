## Upecman
<img src="assets/images/upecman-image.png">

In order to have the most similar experience to the original game I've tried to replicate all the features and characteristics that I could such as pre-move, ghosts' movement, speed and modes, behaviour of the cherry, supper pellets etc. All of these characteristics and the methods that I've used to replicate them are explained down bellow, if you have any doubts feel free to ask me.

<h2 id="summ">Summary</h2>
1. <a href="#pac">Pacman</a>
- <a href="#preM">Pre-Move</a>


<h2 id="pac">Pacman</h2>
<h3 id="preM">Pre-Move</h3>

Pre-Move is a characteristic related to the Pacman's movement, when you are developing a game nothing is just as simple as "if the player press the key when that direction is open, the pacman will move". Hardly a player's response time will match the precise moment when the pacman needs to move, developing towards this thinking renders the game unplayable and not fun, this is where the pre-move comes around.

The Pre-Move stores the last pressed key and not only as soon as possible the pacman will move to that direction, it will also overwrite this key if a new one is pressed before the pacman reaching an avaible position to change his direction, eg.

```markdown

if(kin == KEY_LEFT)
    next = left;
if(kin == KEY_RIGHT)
    next = right;
if(kin == KEY_DOWN)
    next = down;
if(kin == KEY_UP)
    next = up;

```
where `next` is the variable that stores the pacman next intended position and `kin` is the key input. 

With that in mind all of the pacman movement is based on this behaviour, it moves in a fixed direction and changes it if a new direction key is pressed and that direction is not blocked by the maze, otherwise it will maintain its current direction and keep moving. ie.

```markdown

if(next == up)
    if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
        g.pacman.dir = up;

if(g.pacman.dir == up)
{
    if(g.lab[g.pacman.pos.y - 1][g.pacman.pos.x] != '#')
    {
        xinc = 0;
        yinc = -1;
    }
    else
    {
        xinc = 0;
        yinc = 0;
    }
}
```
you can observe that the double check of the position is necessary because it will otherwise change its direction and then stop moving.
