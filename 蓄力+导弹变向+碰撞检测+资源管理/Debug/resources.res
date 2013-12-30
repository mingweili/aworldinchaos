Sound theSound
{
filename=resources\menu.wav
resgroup=0
}

Sound BulletSound
{
filename=resources\BulletSound.wav
resgroup=0
}

Stream BackgroundMusic
{
filename=resources\BackgroundMusic.mp3
resgroup=0
}

Texture bullet
{
filename=resources\bullet.png
resgroup=0
}

Sprite bulletSprite
{
texture=bullet
rect=0, 0, 32, 32
color=FF808000
hotspot=16,16
resgroup=0
}

Texture box
{
filename=resources\box.png
resgroup=0
}

Sprite BoxSprite
{
texture=box
rect = 0, 0, 32, 32
color=FF808000
hotspot=16, 16
resgroup=0
}

Sprite ParSprite
{
texture=resources\particles.png
rect=32, 32, 32, 32
blendmode=COLORMUL,ALPHAADD,NOZWRITE
hotspot=16,16
resgroup=0
}

Particle par
{
filename=resources\trail.psi
sprite=ParSprite
resgroup=0
}

Font fnt
{
filename=resources\font1.fnt
resgroup=0
}
