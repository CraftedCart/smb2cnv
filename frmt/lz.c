#include "lz.h"
#include "extmath.h"
#include "../objparse/objparse.h"
#include "../config/config.h"

int individualSize[80] = {0};
int cumulativeSize[80] = {0};
int indAnimSize[80] = {0};
int cumAnimSize[80] = {0};

void writeNullBytes(FILE * fp,int count)
{
	for(int i=0; i<count; i++) putc(0,fp);
}

void writeLz()
{
	//Write object data
	FILE * temp = fopen("./temp/tempcfg.lz.raw.part","wb");
	int sectOffs[4]; //Index 0: Goals offset / 1: Bumpers offset / 2: Jamabars offset (Not used in smb2cnv) / 3: Bananas offset

	sectOffs[0]=0x8B4;
	for(int i=0; i<goalCount; i++)
	{
		int posx = toInt(goals[i].posx);
		int posy = toInt(goals[i].posy);
		int posz = toInt(goals[i].posz);
		int rotx = cnvAngle(goals[i].rotx);
		int roty = cnvAngle(goals[i].roty);
		int rotz = cnvAngle(goals[i].rotz);
		int type = (goals[i].type==2?(0x0201):(goals[i].type==1?(0x0101):(1)));
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((rotx>>8)&0xFF,temp);
		putc(rotx&0xFF,temp);
		putc((roty>>8)&0xFF,temp);
		putc(roty&0xFF,temp);
		putc((rotz>>8)&0xFF,temp);
		putc(rotz&0xFF,temp);
		putc((type>>8)&0xFF,temp);
		putc(type&0xFF,temp);
	}

	sectOffs[1]=ftell(temp)+0x8B4;
	for(int i=0; i<bumperCount; i++)
	{
		int posx = toInt(bumpers[i].posx);
		int posy = toInt(bumpers[i].posy);
		int posz = toInt(bumpers[i].posz);
		int rotx = cnvAngle(bumpers[i].rotx);
		int roty = cnvAngle(bumpers[i].roty);
		int rotz = cnvAngle(bumpers[i].rotz);
		int sclx = toInt(bumpers[i].sclx);
		int scly = toInt(bumpers[i].scly);
		int sclz = toInt(bumpers[i].sclz);
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((rotx>>8)&0xFF,temp);
		putc(rotx&0xFF,temp);
		putc((roty>>8)&0xFF,temp);
		putc(roty&0xFF,temp);
		putc((rotz>>8)&0xFF,temp);
		putc(rotz&0xFF,temp);
		putc(0,temp);
		putc(0,temp);
		putc((sclx>>24)&0xFF,temp);
		putc((sclx>>16)&0xFF,temp);
		putc((sclx>>8)&0xFF,temp);
		putc(sclx&0xFF,temp);
		putc((scly>>24)&0xFF,temp);
		putc((scly>>16)&0xFF,temp);
		putc((scly>>8)&0xFF,temp);
		putc(scly&0xFF,temp);
		putc((sclz>>24)&0xFF,temp);
		putc((sclz>>16)&0xFF,temp);
		putc((sclz>>8)&0xFF,temp);
		putc(sclz&0xFF,temp);
	}

    sectOffs[2]=ftell(temp)+0x8B4;
    for(int i=0; i<jamabarCount; i++)
    {
        int posx = toInt(bumpers[i].posx);
        int posy = toInt(bumpers[i].posy);
        int posz = toInt(bumpers[i].posz);
        int rotx = cnvAngle(bumpers[i].rotx);
        int roty = cnvAngle(bumpers[i].roty);
        int rotz = cnvAngle(bumpers[i].rotz);
        int sclx = toInt(bumpers[i].sclx);
        int scly = toInt(bumpers[i].scly);
        int sclz = toInt(bumpers[i].sclz);
        putc((posx>>24)&0xFF,temp);
        putc((posx>>16)&0xFF,temp);
        putc((posx>>8)&0xFF,temp);
        putc(posx&0xFF,temp);
        putc((posy>>24)&0xFF,temp);
        putc((posy>>16)&0xFF,temp);
        putc((posy>>8)&0xFF,temp);
        putc(posy&0xFF,temp);
        putc((posz>>24)&0xFF,temp);
        putc((posz>>16)&0xFF,temp);
        putc((posz>>8)&0xFF,temp);
        putc(posz&0xFF,temp);
        putc((rotx>>8)&0xFF,temp);
        putc(rotx&0xFF,temp);
        putc((roty>>8)&0xFF,temp);
        putc(roty&0xFF,temp);
        putc((rotz>>8)&0xFF,temp);
        putc(rotz&0xFF,temp);
        putc(0,temp);
        putc(0,temp);
        putc((sclx>>24)&0xFF,temp);
        putc((sclx>>16)&0xFF,temp);
        putc((sclx>>8)&0xFF,temp);
        putc(sclx&0xFF,temp);
        putc((scly>>24)&0xFF,temp);
        putc((scly>>16)&0xFF,temp);
        putc((scly>>8)&0xFF,temp);
        putc(scly&0xFF,temp);
        putc((sclz>>24)&0xFF,temp);
        putc((sclz>>16)&0xFF,temp);
        putc((sclz>>8)&0xFF,temp);
        putc(sclz&0xFF,temp);
    }

	sectOffs[3]=ftell(temp)+0x8B4;
	for(int i=0; i<bananaCount; i++)
	{
		int posx = toInt(bananas[i].posx);
		int posy = toInt(bananas[i].posy);
		int posz = toInt(bananas[i].posz);
		int type = bananas[i].type;
		putc((posx>>24)&0xFF,temp);
		putc((posx>>16)&0xFF,temp);
		putc((posx>>8)&0xFF,temp);
		putc(posx&0xFF,temp);
		putc((posy>>24)&0xFF,temp);
		putc((posy>>16)&0xFF,temp);
		putc((posy>>8)&0xFF,temp);
		putc(posy&0xFF,temp);
		putc((posz>>24)&0xFF,temp);
		putc((posz>>16)&0xFF,temp);
		putc((posz>>8)&0xFF,temp);
		putc(posz&0xFF,temp);
		putc((type>>24)&0xFF,temp);
		putc((type>>16)&0xFF,temp);
		putc((type>>8)&0xFF,temp);
		putc(type&0xFF,temp);
	}
	fclose(temp);
	//Write animation data
	for(int i=0; i<animCount; i++)
	{
		indAnimSize[i] = 0x78*animFrameCount[i] + 0x30;
		if(i==0) cumAnimSize[i] = 0x78*animFrameCount[i] + 0x30;
		else cumAnimSize[i] = 0x78*animFrameCount[i] + 0x30 + cumAnimSize[i-1];
	}
	//Write collision triangles
	int noBgModels=0;
	temp = fopen("./temp/tempcol.lz.raw.part","wb");
	for(int i=0; i<tallyObjs; i++)
	{
		int ignoreMe = 0;
		for(int j=0; j<ignoreCount; j++)
		{
			if(strcmp(ignoreList[j],cmnObjNames[i].name)==0) ignoreMe=1;
		}
		if(ignoreMe==0)
		{
			int tallySize = 0;
			for(int j=0; j<tallyTris[i]; j++)
			{
				vec3 na = {cmnVertices.vs[cmnObjs[i].tris[j].vna-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vna-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vna-1].z};
				vec3 a = {cmnVertices.vs[cmnObjs[i].tris[j].va-1].x,cmnVertices.vs[cmnObjs[i].tris[j].va-1].y,cmnVertices.vs[cmnObjs[i].tris[j].va-1].z};
				vec3 b = {cmnVertices.vs[cmnObjs[i].tris[j].vb-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vb-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vb-1].z};
				vec3 c = {cmnVertices.vs[cmnObjs[i].tris[j].vc-1].x,cmnVertices.vs[cmnObjs[i].tris[j].vc-1].y,cmnVertices.vs[cmnObjs[i].tris[j].vc-1].z};
				vec3 ba = {b.x-a.x,b.y-a.y,b.z-a.z};
				vec3 ca = {c.x-a.x,c.y-a.y,c.z-a.z};
				vec3 normal = normalize(cross(normalize(ba),normalize(ca)));
				float l = sqrtf(normal.x*normal.x + normal.z*normal.z);
				float cy = normal.z/l;
				float sy = -normal.x/l;
				if(fabs(l)<0.001)
				{
					cy = 1.0;
					sy = 0.0;
				}
				float cx = l;
				float sx = normal.y;
				vec3 Rxr0 = {1.0,0.0,0.0};
				vec3 Rxr1 = {0.0,cx,sx};
				vec3 Rxr2 = {0.0,-sx,cx};
				vec3 Ryr0 = {cy,0.0,-sy};
				vec3 Ryr1 = {0.0,1.0,0.0};
				vec3 Ryr2 = {sy,0.0,cy};
				vec3 dotry = dotm(ba,Ryr0,Ryr1,Ryr2);
				vec3 dotrxry = dotm(dotry,Rxr0,Rxr1,Rxr2);
				l = sqrtf(dotrxry.x*dotrxry.x + dotrxry.y*dotrxry.y);
				float cz = dotrxry.x/l;
				float sz = -dotrxry.y/l;
				vec3 Rzr0 = {cz,sz,0.0};
				vec3 Rzr1 = {-sz,cz,0.0};
				vec3 Rzr2 = {0.0,0.0,1.0};
				vec3 dotrz = dotm(dotrxry,Rzr0,Rzr1,Rzr2);
				dotry = dotm(ca,Ryr0,Ryr1,Ryr2);
				dotrxry = dotm(dotry,Rxr0,Rxr1,Rxr2);
				vec3 dotrzrxry = dotm(dotrxry,Rzr0,Rzr1,Rzr2);
				vec3 n0v = {dotrzrxry.x-dotrz.x,dotrzrxry.y-dotrz.y,dotrzrxry.z-dotrz.z};
				vec3 n1v = {-dotrzrxry.x,-dotrzrxry.y,-dotrzrxry.z};
				vec3 n0 = normalize(hat(n0v));
				vec3 n1 = normalize(hat(n1v));
				float rot_x = 360.0-reverse_angle(cx,sx);
				float rot_y = 360.0-reverse_angle(cy,sy);
				float rot_z = 360.0-reverse_angle(cz,sz);
				int putMe = toInt(a.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(a.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(a.z);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(normal.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(normal.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(normal.z);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = cnvAngle(rot_x);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = cnvAngle(rot_y);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = cnvAngle(rot_z);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putc(0,temp);
				putc(0,temp);
				putMe = toInt(dotrz.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(dotrz.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(dotrzrxry.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(dotrzrxry.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(n0.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(n0.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(n1.x);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				putMe = toInt(n1.y);
				putc((putMe>>24)&0xFF,temp);
				putc((putMe>>16)&0xFF,temp);
				putc((putMe>>8)&0xFF,temp);
				putc(putMe&0xFF,temp);
				tallySize++;
			}
			individualSize[i] = tallySize;
			if(i==0) {cumulativeSize[i] = tallySize;}
			else {cumulativeSize[i] = tallySize+cumulativeSize[i-1];}
		}
		else {noBgModels++; individualSize[i] = 0; if(i==0) {cumulativeSize[i] = 0;} else {cumulativeSize[i] = cumulativeSize[i-1];}}
	}
	fclose(temp);
	//Write complete (uncompressed) file
	FILE * fpCfg = fopen("./temp/tempcfg.lz.raw.part","rb");
	FILE * fpCol = fopen("./temp/tempcol.lz.raw.part","rb");
	temp = fopen("./temp/output.lz.raw","wb");
	fseek(fpCfg,0,SEEK_END);
	int cfgSize = ftell(fpCfg);
	rewind(fpCfg);
	fseek(fpCol,0,SEEK_END);
	int colSize = ftell(fpCol);
	rewind(fpCol);
	int realColSize = colSize + (0xA9C*(tallyObjs+1)) + (0x200*(colSize/0x40));
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc(0,temp);
	putc('D',temp);
	putc('z',temp);
	putc(0,temp);
	putc(0,temp);
	putc(((tallyObjs+1)>>24)&0xFF,temp);
	putc(((tallyObjs+1)>>16)&0xFF,temp);
	putc(((tallyObjs+1)>>8)&0xFF,temp);
	putc((tallyObjs+1)&0xFF,temp);
	putc(((cfgSize+0x8B4)>>24)&0xFF,temp);
	putc(((cfgSize+0x8B4)>>16)&0xFF,temp);
	putc(((cfgSize+0x8B4)>>8)&0xFF,temp);
	putc((cfgSize+0x8B4)&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	putc(8,temp);
	putc(0x9C,temp);
	putc(0,temp);
	putc(0,temp);
	putc(8,temp);
	putc(0xB0,temp);
	if(goalCount)
	{
		putc((goalCount>>24)&0xFF,temp);
		putc((goalCount>>16)&0xFF,temp);
		putc((goalCount>>8)&0xFF,temp);
		putc(goalCount&0xFF,temp);
		putc((sectOffs[0]>>24)&0xFF,temp);
		putc((sectOffs[0]>>16)&0xFF,temp);
		putc((sectOffs[0]>>8)&0xFF,temp);
		putc(sectOffs[0]&0xFF,temp);
	}
	else
	{
		writeNullBytes(temp,8);
	}
	if(bumperCount)
	{
		putc((bumperCount>>24)&0xFF,temp);
		putc((bumperCount>>16)&0xFF,temp);
		putc((bumperCount>>8)&0xFF,temp);
		putc(bumperCount&0xFF,temp);
		putc((sectOffs[1]>>24)&0xFF,temp);
		putc((sectOffs[1]>>16)&0xFF,temp);
		putc((sectOffs[1]>>8)&0xFF,temp);
		putc(sectOffs[1]&0xFF,temp);
	}
	else
	{
		writeNullBytes(temp,8);
	}
    if(jamabarCount)
    {
        putc((jamabarCount>>24)&0xFF,temp);
        putc((jamabarCount>>16)&0xFF,temp);
        putc((jamabarCount>>8)&0xFF,temp);
        putc(jamabarCount&0xFF,temp);
        putc((sectOffs[2]>>24)&0xFF,temp);
        putc((sectOffs[2]>>16)&0xFF,temp);
        putc((sectOffs[2]>>8)&0xFF,temp);
        putc(sectOffs[2]&0xFF,temp);
    }
    else
    {
        writeNullBytes(temp,8);
    }
	if(bananaCount)
	{
		putc((bananaCount>>24)&0xFF,temp);
		putc((bananaCount>>16)&0xFF,temp);
		putc((bananaCount>>8)&0xFF,temp);
		putc(bananaCount&0xFF,temp);
		putc((sectOffs[3]>>24)&0xFF,temp);
		putc((sectOffs[3]>>16)&0xFF,temp);
		putc((sectOffs[3]>>8)&0xFF,temp);
		putc(sectOffs[3]&0xFF,temp);
	}
	else
	{
		writeNullBytes(temp,8);
	}
	writeNullBytes(temp,32);
	putc(((noBgModels)>>24)&0xFF,temp);
	putc(((noBgModels)>>16)&0xFF,temp);
	putc(((noBgModels)>>8)&0xFF,temp);
	putc((noBgModels)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x180)+realColSize+cfgSize+0x8B4)>>24)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x180)+realColSize+cfgSize+0x8B4)>>16)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x180)+realColSize+cfgSize+0x8B4)>>8)&0xFF,temp);
	putc((((tallyObjNames-noBgModels)*0x180)+realColSize+cfgSize+0x8B4)&0xFF,temp);
	writeNullBytes(temp,15);
	putc(1,temp);
	writeNullBytes(temp,28);
	putc(((tallyObjNames-noBgModels)>>24)&0xFF,temp);
	putc(((tallyObjNames-noBgModels)>>16)&0xFF,temp);
	putc(((tallyObjNames-noBgModels)>>8)&0xFF,temp);
	putc((tallyObjNames-noBgModels)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x80)+realColSize+cfgSize+0x8B4)>>24)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x80)+realColSize+cfgSize+0x8B4)>>16)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x80)+realColSize+cfgSize+0x8B4)>>8)&0xFF,temp);
	putc((((tallyObjNames-noBgModels)*0x80)+realColSize+cfgSize+0x8B4)&0xFF,temp);
	putc(((tallyObjNames-noBgModels)>>24)&0xFF,temp);
	putc(((tallyObjNames-noBgModels)>>16)&0xFF,temp);
	putc(((tallyObjNames-noBgModels)>>8)&0xFF,temp);
	putc((tallyObjNames-noBgModels)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x100)+realColSize+cfgSize+0x8B4)>>24)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x100)+realColSize+cfgSize+0x8B4)>>16)&0xFF,temp);
	putc(((((tallyObjNames-noBgModels)*0x100)+realColSize+cfgSize+0x8B4)>>8)&0xFF,temp);
	putc((((tallyObjNames-noBgModels)*0x100)+realColSize+cfgSize+0x8B4)&0xFF,temp);
	writeNullBytes(temp,2048);
	int posx = toInt(starts[0].posx);
	int posy = toInt(starts[0].posy);
	int posz = toInt(starts[0].posz);
	int rotx = cnvAngle(starts[0].rotx);
	int roty = cnvAngle(starts[0].roty);
	int rotz = cnvAngle(starts[0].rotz);
	putc((posx>>24)&0xFF,temp);
	putc((posx>>16)&0xFF,temp);
	putc((posx>>8)&0xFF,temp);
	putc(posx&0xFF,temp);
	putc((posy>>24)&0xFF,temp);
	putc((posy>>16)&0xFF,temp);
	putc((posy>>8)&0xFF,temp);
	putc(posy&0xFF,temp);
	putc((posz>>24)&0xFF,temp);
	putc((posz>>16)&0xFF,temp);
	putc((posz>>8)&0xFF,temp);
	putc(posz&0xFF,temp);
	putc((rotx>>8)&0xFF,temp);
	putc(rotx&0xFF,temp);
	putc((roty>>8)&0xFF,temp);
	putc(roty&0xFF,temp);
	putc((rotz>>8)&0xFF,temp);
	putc(rotz&0xFF,temp);
	putc(0,temp);
	putc(0,temp);
	int putMe = toInt(fallOutPlane);
	putc((putMe>>24)&0xFF,temp);
	putc((putMe>>16)&0xFF,temp);
	putc((putMe>>8)&0xFF,temp);
	putc(putMe&0xFF,temp);
	for(int i=0; i<cfgSize; i++)
	{
		putc(getc(fpCfg),temp);
	}
	fclose(fpCfg);
	int whereAreWe = ftell(temp);
	for(int i=0; i<(tallyObjs+1); i++)
	{
		int animMe = 0;
		if(i!=0)
		{
			for(int j=0; j<animCount; j++)
			{
				if(strcmp(animList[j],cmnObjNames[i-1].name)==0) animMe=10+j;
			}
		}
		if(i==0)
		{
			writeNullBytes(temp,36);
		}
		else
		{
			int putMe = toInt(animCenter[animMe-10].posx);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animCenter[animMe-10].posy);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animCenter[animMe-10].posz);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			writeNullBytes(temp,8);
			if(animMe!=0)
			{
				putc(((realColSize+(80*tallyObjNames)+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+((animMe==10)?0:cumAnimSize[animMe-11])+cfgSize+0x8B4)>>24)&0xFF,temp);
				putc(((realColSize+(80*tallyObjNames)+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+((animMe==10)?0:cumAnimSize[animMe-11])+cfgSize+0x8B4)>>16)&0xFF,temp);
				putc(((realColSize+(80*tallyObjNames)+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+((animMe==10)?0:cumAnimSize[animMe-11])+cfgSize+0x8B4)>>8)&0xFF,temp);
				putc((realColSize+(80*tallyObjNames)+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+((animMe==10)?0:cumAnimSize[animMe-11])+cfgSize+0x8B4)&0xFF,temp);
			}
			else
			{
				writeNullBytes(temp,4);
			}
			writeNullBytes(temp,12);
		}
		putc(((whereAreWe+(0x49C*(tallyObjs+1)))>>24)&0xFF,temp);
		putc(((whereAreWe+(0x49C*(tallyObjs+1)))>>16)&0xFF,temp);
		putc(((whereAreWe+(0x49C*(tallyObjs+1)))>>8)&0xFF,temp);
		putc((whereAreWe+(0x49C*(tallyObjs+1)))&0xFF,temp);
		putc(((whereAreWe+(0x400*i)+(0x69C*(tallyObjs+1))+colSize+(0x200*(colSize/0x40)))>>24)&0xFF,temp);
		putc(((whereAreWe+(0x400*i)+(0x69C*(tallyObjs+1))+colSize+(0x200*(colSize/0x40)))>>16)&0xFF,temp);
		putc(((whereAreWe+(0x400*i)+(0x69C*(tallyObjs+1))+colSize+(0x200*(colSize/0x40)))>>8)&0xFF,temp);
		putc((whereAreWe+(0x400*i)+(0x69C*(tallyObjs+1))+colSize+(0x200*(colSize/0x40)))&0xFF,temp);
		putc(0xC3,temp);
		putc(0x80,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0xC3,temp);
		putc(0x80,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0x42,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0x42,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(16,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(16,temp);
		if(goalCount && (i==0))
		{
			putc((goalCount>>24)&0xFF,temp);
			putc((goalCount>>16)&0xFF,temp);
			putc((goalCount>>8)&0xFF,temp);
			putc(goalCount&0xFF,temp);
			putc((sectOffs[0]>>24)&0xFF,temp);
			putc((sectOffs[0]>>16)&0xFF,temp);
			putc((sectOffs[0]>>8)&0xFF,temp);
			putc(sectOffs[0]&0xFF,temp);
		}
		else
		{
			writeNullBytes(temp,8);
		}
		if(bumperCount && (i==0))
		{
			putc((bumperCount>>24)&0xFF,temp);
			putc((bumperCount>>16)&0xFF,temp);
			putc((bumperCount>>8)&0xFF,temp);
			putc(bumperCount&0xFF,temp);
			putc((sectOffs[1]>>24)&0xFF,temp);
			putc((sectOffs[1]>>16)&0xFF,temp);
			putc((sectOffs[1]>>8)&0xFF,temp);
			putc(sectOffs[1]&0xFF,temp);
		}
		else
		{
			writeNullBytes(temp,8);
		}
        if(jamabarCount && (i==0))
        {
            putc((jamabarCount>>24)&0xFF,temp);
            putc((jamabarCount>>16)&0xFF,temp);
            putc((jamabarCount>>8)&0xFF,temp);
            putc(jamabarCount&0xFF,temp);
            putc((sectOffs[2]>>24)&0xFF,temp);
            putc((sectOffs[2]>>16)&0xFF,temp);
            putc((sectOffs[2]>>8)&0xFF,temp);
            putc(sectOffs[2]&0xFF,temp);
        }
        else
        {
            writeNullBytes(temp,8);
        }
		if(bananaCount && (i==0))
		{
			putc((bananaCount>>24)&0xFF,temp);
			putc((bananaCount>>16)&0xFF,temp);
			putc((bananaCount>>8)&0xFF,temp);
			putc(bananaCount&0xFF,temp);
			putc((sectOffs[3]>>24)&0xFF,temp);
			putc((sectOffs[3]>>16)&0xFF,temp);
			putc((sectOffs[3]>>8)&0xFF,temp);
			putc(sectOffs[3]&0xFF,temp);
		}
		else
		{
			writeNullBytes(temp,8);
		}
		writeNullBytes(temp,48);
		if(i==0)
		{
			writeNullBytes(temp,8);
		}
		else
		{
			if(i!=0) { writeNullBytes(temp,3); putc(1,temp); }
			else writeNullBytes(temp,4);
			putc(((((tallyObjNames-noBgModels)*0x100)+(4*(i-1))+realColSize+cfgSize+0x8B4)>>24)&0xFF,temp);
			putc(((((tallyObjNames-noBgModels)*0x100)+(4*(i-1))+realColSize+cfgSize+0x8B4)>>16)&0xFF,temp);
			putc(((((tallyObjNames-noBgModels)*0x100)+(4*(i-1))+realColSize+cfgSize+0x8B4)>>8)&0xFF,temp);
			putc((((tallyObjNames-noBgModels)*0x100)+(4*(i-1))+realColSize+cfgSize+0x8B4)&0xFF,temp);
		}
		writeNullBytes(temp,1024);
	}
	for(int i=0; i<colSize; i++)
	{
		putc(getc(fpCol),temp);
	}
	fclose(fpCol);
	whereAreWe = ftell(temp);
	for(int k=0; k<256; k++)
	{
		int curj=0;
		for(int i=0; i<(tallyObjs+1); i++)
		{
			if(i!=0)
			{
				for(int j=curj; j<cumulativeSize[i-1]; j++)
				{
					putc((j>>8)&0xFF,temp);
					putc(j&0xFF,temp);
				}
				curj+=individualSize[i-1];
			}
			putc(0xFF,temp);
			putc(0xFF,temp);
		}
	}
	for(int i=0; i<(tallyObjs+1); i++)
	{
		if(i==0)
		{
			for(int j=0; j<256; j++)
			{
				putc(((whereAreWe+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>24)&0xFF,temp);
				putc(((whereAreWe+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>16)&0xFF,temp);
				putc(((whereAreWe+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>8)&0xFF,temp);
				putc((whereAreWe+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))&0xFF,temp);
			}
		}
		else if(i==1)
		{
			for(int j=0; j<256; j++)
			{
				putc(((whereAreWe+2+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>24)&0xFF,temp);
				putc(((whereAreWe+2+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>16)&0xFF,temp);
				putc(((whereAreWe+2+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>8)&0xFF,temp);
				putc((whereAreWe+2+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))&0xFF,temp);
			}
		}
		else
		{
			for(int j=0; j<256; j++)
			{
				putc(((whereAreWe+(2*i)+(2*cumulativeSize[i-2])+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>24)&0xFF,temp);
				putc(((whereAreWe+(2*i)+(2*cumulativeSize[i-2])+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>16)&0xFF,temp);
				putc(((whereAreWe+(2*i)+(2*cumulativeSize[i-2])+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))>>8)&0xFF,temp);
				putc((whereAreWe+(2*i)+(2*cumulativeSize[i-2])+(2*j*(tallyObjs+1))+(2*j*(colSize/0x40)))&0xFF,temp);
			}
		}
	}
	whereAreWe = ftell(temp);
	int whereAreWeSave = whereAreWe;
	for(int i=0; i<(tallyObjNames-noBgModels); i++)
	{
		writeNullBytes(temp,12);
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x180)+(80*i))>>24)&0xFF,temp);
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x180)+(80*i))>>16)&0xFF,temp);
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x180)+(80*i))>>8)&0xFF,temp);
		putc((whereAreWe+((tallyObjNames-noBgModels)*0x180)+(80*i))&0xFF,temp);
	}
	writeNullBytes(temp,0x70*(tallyObjNames-noBgModels));
	for(int i=0; i<(tallyObjNames-noBgModels); i++)
	{
		writeNullBytes(temp,7);
		putc(1,temp);
		putc(((whereAreWe+8+(16*i))>>24)&0xFF,temp);
		putc(((whereAreWe+8+(16*i))>>16)&0xFF,temp);
		putc(((whereAreWe+8+(16*i))>>8)&0xFF,temp);
		putc((whereAreWe+8+(16*i))&0xFF,temp);
	}
	writeNullBytes(temp,0x74*(tallyObjNames-noBgModels));
	for(int i=0; i<(tallyObjNames-noBgModels); i++)
	{
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x80)+(12*i))>>24)&0xFF,temp);
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x80)+(12*i))>>16)&0xFF,temp);
		putc(((whereAreWe+((tallyObjNames-noBgModels)*0x80)+(12*i))>>8)&0xFF,temp);
		putc((whereAreWe+((tallyObjNames-noBgModels)*0x80)+(12*i))&0xFF,temp);
	}
	writeNullBytes(temp,0x7C*(tallyObjNames-noBgModels));
	whereAreWe = ftell(temp);
	for(int i=0; i<noBgModels; i++)
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0x1F,temp);
		putc(((whereAreWe+(noBgModels*0x38)+(i*80))&0xFF000000)>>24,temp);
		putc(((whereAreWe+(noBgModels*0x38)+(i*80))&0xFF0000)>>16,temp);
		putc(((whereAreWe+(noBgModels*0x38)+(i*80))&0xFF00)>>8,temp);
		putc((whereAreWe+(noBgModels*0x38)+(i*80))&0xFF,temp);
		writeNullBytes(temp,24);
		putc(0x3F,temp);
		putc(0x80,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0x3F,temp);
		putc(0x80,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0x3F,temp);
		putc(0x80,temp);
		putc(0,temp);
		putc(0,temp);
		writeNullBytes(temp,12);
	}
	writeNullBytes(temp,72*noBgModels);
	for(int i=0; i<tallyObjNames; i++)
	{
		int ignoreMe = 0;
		for(int j=0; j<ignoreCount; j++)
		{
			if(strcmp(ignoreList[j],cmnObjNames[i].name)==0) ignoreMe=1;
		}
		if(ignoreMe==0)
		{
			for(int j=0; j<80; j++)
			{
				putc(cmnObjNames[i].name[j],temp);
			}
		}
	}
	int whereAreWeNow = ftell(temp);
	int whereAreWeDiff = whereAreWeNow-whereAreWeSave;
	for(int i=0; i<((tallyObjs*0x80)-whereAreWeDiff); i++) {putc(0,temp);}
	for(int i=0; i<animCount; i++)
	{
		int curPos = ftell(temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30)>>24)&0xFF,temp);
		putc(((curPos+0x30)>>16)&0xFF,temp);
		putc(((curPos+0x30)>>8)&0xFF,temp);
		putc((curPos+0x30)&0xFF,temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30+(0x14*animFrameCount[i]))>>24)&0xFF,temp);
		putc(((curPos+0x30+(0x14*animFrameCount[i]))>>16)&0xFF,temp);
		putc(((curPos+0x30+(0x14*animFrameCount[i]))>>8)&0xFF,temp);
		putc((curPos+0x30+(0x14*animFrameCount[i]))&0xFF,temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30+(0x28*animFrameCount[i]))>>24)&0xFF,temp);
		putc(((curPos+0x30+(0x28*animFrameCount[i]))>>16)&0xFF,temp);
		putc(((curPos+0x30+(0x28*animFrameCount[i]))>>8)&0xFF,temp);
		putc((curPos+0x30+(0x28*animFrameCount[i]))&0xFF,temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30+(0x3C*animFrameCount[i]))>>24)&0xFF,temp);
		putc(((curPos+0x30+(0x3C*animFrameCount[i]))>>16)&0xFF,temp);
		putc(((curPos+0x30+(0x3C*animFrameCount[i]))>>8)&0xFF,temp);
		putc((curPos+0x30+(0x3C*animFrameCount[i]))&0xFF,temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30+(0x50*animFrameCount[i]))>>24)&0xFF,temp);
		putc(((curPos+0x30+(0x50*animFrameCount[i]))>>16)&0xFF,temp);
		putc(((curPos+0x30+(0x50*animFrameCount[i]))>>8)&0xFF,temp);
		putc((curPos+0x30+(0x50*animFrameCount[i]))&0xFF,temp);
		putc((animFrameCount[i]>>24)&0xFF,temp);
		putc((animFrameCount[i]>>16)&0xFF,temp);
		putc((animFrameCount[i]>>8)&0xFF,temp);
		putc(animFrameCount[i]&0xFF,temp);
		putc(((curPos+0x30+(0x64*animFrameCount[i]))>>24)&0xFF,temp);
		putc(((curPos+0x30+(0x64*animFrameCount[i]))>>16)&0xFF,temp);
		putc(((curPos+0x30+(0x64*animFrameCount[i]))>>8)&0xFF,temp);
		putc((curPos+0x30+(0x64*animFrameCount[i]))&0xFF,temp);
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].rotx);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].roty);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].rotz);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].posx);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].posy);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
		for(int j=0; j<animFrameCount[i]; j++)
		{
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(2,temp);
			int putMe = toInt(animFrame[i][j].time);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putMe = toInt(animFrame[i][j].posz);
			putc((putMe>>24)&0xFF,temp);
			putc((putMe>>16)&0xFF,temp);
			putc((putMe>>8)&0xFF,temp);
			putc(putMe&0xFF,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
			putc(0,temp);
		}
	}
	for(int i=0; i<(tallyObjNames-noBgModels); i++)
	{
		putc(((whereAreWeSave+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+(80*i))>>24)&0xFF,temp);
		putc(((whereAreWeSave+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+(80*i))>>16)&0xFF,temp);
		putc(((whereAreWeSave+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+(80*i))>>8)&0xFF,temp);
		putc((whereAreWeSave+(0x80*noBgModels)+(0x180*(tallyObjNames-noBgModels))+(80*i))&0xFF,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	if(ftell(temp)%8 == 4)
	{
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
		putc(0,temp);
	}
	fclose(temp);
}
