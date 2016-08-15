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
	int type;
} banana;

extern int startCount;
extern int goalCount;
extern int bumperCount;
extern int bananaCount;
extern int ignoreCount;
start starts[16];
goal goals[16];
bumper bumpers[16];
banana bananas[16];
float fallOutPlane;
char ignoreList[80][80];

void parseConfig(char * configpath);

#endif
