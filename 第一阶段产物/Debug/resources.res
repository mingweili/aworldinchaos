//声音资源
Sound yell
{
filename=resources\sound\yell.wav
resgroup=0
}

Sound shout
{
filename=resources\sound\breath.wav
resgroup=0
}

Sound theSound
{
filename=resources\sound\menu.wav
resgroup=0
}

//机关资源
Texture SoftLand
{
filename=resources\doohickey\SoftLand.jpg
resgroup=0
}

Sprite SoftLand
{
texture=sl
rect=0, 0, 300, 40
hotspot=150, 20
resgroup=0
}

Texture ladder
{
filename=resources\doohickey\ladder.jpg
resgroup=0
}

Sprite ladder
{
texture=ladder
rect=0, 0, 100, 590
hotspot=50, 295
resgroup=0
}

Texture book
{
filename=resources\doohickey\book.jpg
resgroup=0
}

Sprite book
{
texture=book
rect=0, 0, 100, 100
hotspot=50, 50
resgroup=0
}

Texture BookEstrade
{
filename=resources\doohickey\BookEstrade.jpg
resgroup=0
}

Sprite BookEstrade
{
texture=BookEstrade
rect=0, 0, 100, 60
hotspot=50, 30
color=FF808023
resgroup=0
}


//地图背景资源
Texture bg
{
filename=resources\background\bg.jpg
resgroup=0
}

Sprite bg
{
texture=bg
rect=0, 0, 1000, 800
color=FF808000
hotspot=0,0
resgroup=0
}

Texture bg2
{
filename=resources\background\bg2.jpg
resgroup=0
}

Sprite bg2
{
texture=bg2
rect=0, 0, 1000, 800
color=FF808000
hotspot=0, 0
resgroup=0
}
Texture tex10
{
filename=resources\background\pic1.png
resgroup=1
}

Texture tex11
{
filename=resources\background\pic2.png
resgroup=1
}

Texture tex12                                                                                                                         
{
filename=resources\background\pic3.png
resgroup=1
}

Texture tex13
{
filename=resources\background\pic4.png
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

//小人图片（无用，静态）
Texture player
{
filename=resources\anima\player.jpg
resgroup=0
}

Sprite PlayerSprite
{
texture=player
rect = 0, 0, 60, 80
hotspot=30, 40
resgroup=0
}


//小人动画！
Texture walk
{
filename=resources\anima\walk.png
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

Texture fall
{
filename=resources\anima\fall.png
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

Texture climb
{
filename=resources\anima\climb.png
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


//字体资源
Font fnt
{
filename=resources\font\font1.fnt
resgroup=0
}


