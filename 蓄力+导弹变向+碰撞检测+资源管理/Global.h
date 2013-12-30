#ifndef GLABOL_H
#define GLABOL_H

#include "object.h"
#include "hge.h"
#include "hgeparticle.h"
#include "hgefont.h"
#include "ResourceManager.h"

#include <stdlib.h>
#include <cmath>
#include <time.h>

HGE* hge;

float dt;
float xx, yy;
float power;

bool pre, now = false;
bool entered = false;
bool hitted = false;

#define GRAVITY 1000
#define FRICTION 50

float dx1, dy1, dx2, dy2 = 0;

hgeParticleSystem* par;

HEFFECT snd;
hgeSprite* spr1, *spr2;
hgeFont* fnt;

#endif
