Sound yell
{
filename=resources\yell.wav
resgroup=0
}

Sound shout
{
filename=resources\breath.wav
resgroup=0
}

Sound theSound
{
filename=resources\menu.wav
resgroup=0
}

Texture sl
{
filename=resources\SoftLand.jpg
resgroup=0
}

Texture ladder
{
filename=resources\ladder.jpg
resgroup=0
}

Sprite ladder
{
texture=ladder
rect=0, 0, 100, 590
hotspot=50, 295
resgroup=0
}

Sprite SoftLand
{
texture=sl
rect=0, 0, 300, 40
hotspot=150, 20
resgroup=0
}

Texture bg
{
filename=resources\bg.jpg
resgroup=0
}

Sprite bg
{
texture=bg
rect=0, 0, 1000, 800
color=FF808000
hotspot=500, 400
resgroup=0
}

Texture player
{
filename=resources\player.jpg
resgroup=0
}

Sprite PlayerSprite
{
texture=player
rect = 0, 0, 60, 80
hotspot=30, 40
resgroup=0
}

Texture be
{
filename=resources\BookEstrade.jpg
resgroup=0
}

Sprite BookEstrade
{
texture=be
rect=0, 0, 100, 60
hotspot=50, 30
color=FF808023
resgroup=0
}

Font fnt
{
filename=resources\font1.fnt
resgroup=0
}


Texture walk
{
filename=resources\walk.png
resgroup=0
}

Texture fall
{
filename=resources\fall.png
resgroup=0
}


Texture climb
{
filename=resources\climb.png
resgroup=0
}


Animation walk
{
 texture=walk
 rect=0,0,33,56
 frames=6
 fps=10.0
 hotspot=15,30
 mode=FORWARD,LOOP
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=0
}

Animation fall
{
 texture=fall
 rect=0,0,33,57
 frames=2
 fps=10.0
 hotspot=15,30
 mode=FORWARD,LOOP
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=0
}

Animation climb
{
 texture=climb
 rect=0,0,117,58
 frames=12
 fps=12.0
 hotspot=15,30
 mode=FORWARD,LOOP
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=0
}


Texture tex10
{
filename=resources\pic1.png
resgroup=1
}

Texture tex11
{
filename=resources\pic2.png
resgroup=1
}

Texture tex12                                                                                                                         
{
filename=resources\pic3.png
resgroup=1
}

Texture tex13
{
filename=resources\pic4.png
resgroup=1
}

Sprite spr10
{
 texture=tex10
 rect=0,0,1280,800
 hotspot=0,0
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=1
}

Sprite spr11
{
 texture=tex12
 rect=0,0,1280,800
 hotspot=0,0
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=1
}

Sprite spr12
{
 texture=tex13
 rect=0,0,1280,800
 hotspot=0,0
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=1
}

Sprite spr13
{
 texture=tex13
 rect=0,0,1280,800
 hotspot=0,0
 blendmode=COLORMUL,ALPHABLEND,NOZWRITE
 resgroup=1
}



