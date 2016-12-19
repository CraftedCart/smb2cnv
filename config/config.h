#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string.h>

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
} start;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	int type;
} goal;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float sclx;
	float scly;
	float sclz;
} bumper;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float sclx;
	float scly;
	float sclz;
} jamabar;

typedef struct
{
	float posx;
	float posy;
	float posz;
	int type;
} banana;

typedef struct
{
	float posx;
	float posy;
	float posz;
	float rotx;
	float roty;
	float rotz;
	float time;
} frame;

typedef struct
{
	float posx;
	float posy;
	float posz;
} center;

extern int startCount;
extern int goalCount;
extern int bumperCount;
extern int jamabarCount;
extern int bananaCount;
extern int ignoreCount;
extern int animCount;
start starts[256];
goal goals[256];
bumper bumpers[256];
jamabar jamabars[256];
banana bananas[256];
float fallOutPlane;
char ignoreList[256][80];
char animList[256][80];
int animFrameCount[256];
frame animFrame[256][256];
center animCenter[256];

void parseConfig(char * configpath);

#endif
