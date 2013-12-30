//GUI资源
Texture cursor
{
filename=resources\GUI\cursor.png
resgroup=0
}

Sprite cursor
{
texture=cursor
rect=0, 0, 32,  32
hotspot=0, 0
resgroup=0
}

//GUI的按钮
Texture Button
{
filename=resources\GUI\button.png
resgroup=0
}

Sprite Button 
{
texture=Button
rect=0, 0, 50, 90
hotspot=0
resgroup=0
}

//暂时用作GUI的纯白色背景
Texture vback
{
filename=resources\GUI\vback.png
resgroup=0
}

Sprite vback
{
texture=vback
rect=0, 0, 800, 600
hotspot=0, 0
resgroup=0
}

Sound GUISound
{
filename=resources\GUI\button.wav
resgroup=0
}

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
texture=SoftLand
rect=0, 0, 300, 40
hotspot=150, 20
resgroup=0
}

Texture Door
{
filename=resources\doohickey\door.jpg
resgroup=0
}

Sprite Door
{
texture=Door
rect=0, 0, 100, 60
hotspot=50, 30
resgroup=0
}

Texture Key
{
filename=resources\doohickey\Key.jpg
resgroup=0
}

Sprite Key
{
texture=Key
rect=0, 0, 60, 100
hotspot = 30, 50
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

Texture elevator
{
filename=resources\doohickey\elevator.jpg
resgroup=0
}

Sprite elevator
{
texture=elevator
rect=0, 0, 120, 120
hotspot=60, 60
resgroup=0
}

Texture CaskFragment
{
filename=resources\doohickey\CaskFragment.jpg
resgroup=0
}

Sprite CaskFragment
{
texture=CaskFragment
rect=0, 0, 30, 50
hotspot=15, 25
resgroup=0
}

Texture MobileLadder
{
filename=resources\doohickey\MobileLadder.jpg
resgroup=0
}

Sprite MobileLadder
{
texture=MobileLadder
rect=0, 0, 40, 80
hotspot=20, 40
resgroup=0
}

Texture Pesticide
{
filename=resources\doohickey\Pesticide.jpg
resgroup=0
}

Sprite Pesticide
{
texture=Pesticide
rect=0, 0, 30, 30
hotspot=15, 15
resgroup=0
}

Texture Coffin
{
filename=resources\doohickey\Coffin.jpg
resgroup=0
}

Sprite Coffin
{
texture=Coffin
rect=0, 0, 60, 160
hotspot=30, 80
resgroup=0
}


//背景资源
Texture bg11
{
filename=resources\background\bg11.jpg
resgroup=0
}

Sprite bg11
{
texture=bg11
rect=0, 0, 1000, 800
hotspot=0,0
resgroup=0
}

Texture bg12
{
filename=resources\background\bg12.jpg
resgroup=0
}

Sprite bg12
{
texture=bg12
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

Texture bg21
{
filename=resources\background\bg21.jpg
resgroup=0
}

Sprite bg21
{
texture=bg21
rect=0, 0, 1000, 800
hotspot=0,0
resgroup=0
}

Texture bg22
{
filename=resources\background\bg22.jpg
resgroup=0
}

Sprite bg22
{
texture=bg22
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

Texture bg31
{
filename=resources\background\bg31.jpg
resgroup=0
}

Sprite bg31
{
texture=bg31
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

Texture bg32
{
filename=resources\background\bg32.jpg
resgroup=0
}

Sprite bg32
{
texture=bg32
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

Texture bg33
{
filename=resources\background\bg33.jpg
resgroup=0
}

Sprite bg33
{
texture=bg33
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

Texture bg34
{
filename=resources\background\bg34.jpg
resgroup=0
}

Sprite bg34
{
texture=bg34
rect=0, 0, 1000, 800
hotspot=0, 0
resgroup=0
}

//小人资源
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


//动画资源
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


