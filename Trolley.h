#pragma once

class Trolley : Drawable
{

    int wood;
     int ground, inner_down_sides, inner_up_sides, package_room,ceiling;
   
    GLuint list;

public:
    void Init()
    {
        wood = LoadTexture((char*)"Trolley_Texture/wood.bmp");
        inner_down_sides = LoadTexture((char *)"Trolley_Texture/inner down sides.bmp");
        inner_up_sides = LoadTexture((char *)"Trolley_Texture/inner side up.bmp");
        package_room = LoadTexture((char *)"Trolley_Texture/package room.bmp");
        ceiling= LoadTexture((char *)"Trolley_Texture/ceil.bmp");
        list = glGenLists(1);
        glNewList(list, GL_COMPILE);

        glDisable(GL_LIGHTING);
        // glEnable(GL_TEXTURE_2D);

        // glBindTexture(GL_TEXTURE_2D, wood);
       
        // Ceiling right up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -15); 
        glVertex3d(-40, 12.5, -10); 
        glVertex3d(40, 12.5, -10); 
        glVertex3d(40, 12.5, -15);
        glEnd();

       
        // Celing right down
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, ceiling);
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0, 0);
        glVertex3d(40, 12.499, -15);
        glTexCoord2d(0, 25);
        glVertex3d(40, 12.499, -10);
        glTexCoord2d(1, 25);
        glVertex3d(-40, 12.499, -10);
        glTexCoord2d(1, 0);
        glVertex3d(-40, 12.499, -15);
        glEnd();

        glDisable(GL_TEXTURE_2D);

        // Ceiling left up
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 15);
        glVertex3d(40, 12.5, 10);
        glVertex3d(-40, 12.5, 10);
        glVertex3d(-40, 12.5, 15);
        glEnd();
        // Ceiling left down 
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 12.499, 15);
        glTexCoord2d(0,25);
        glVertex3d(-40, 12.499, 10);
        glTexCoord2d(1,25);
        glVertex3d(40, 12.499, 10);
        glTexCoord2d(1,0);
        glVertex3d(40, 12.499, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Ceiling side left out
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 12.5, 10);
        glVertex3d(40, 15, 10);
        glVertex3d(-40, 15, 10);
        glVertex3d(-40, 12.5, 10);
        glEnd();

        // Ceiling side left in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 12.5, 9.999);
        glTexCoord2d(0,25);
        glVertex3d(-40, 15, 9.999);
        glTexCoord2d(1,25);
        glVertex3d(40, 15, 9.999);
        glTexCoord2d(1,0);
        glVertex3d(40, 12.5, 9.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Ceiling side right out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 12.5, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(40, 15, -10);
        glVertex3d(40, 12.5, -10);
        glEnd();

        // Ceiling side right in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, 12.5, -9.999);
        glTexCoord2d(0,25);
        glVertex3d(40, 15, -9.999);
        glTexCoord2d(1,25);
        glVertex3d(-40, 15, -9.999);
        glTexCoord2d(1,0);
        glVertex3d(-40, 12.5, -9.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Celing center out
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glVertex3d(40, 15, 10);
        glVertex3d(40, 15, -10);
        glVertex3d(-40, 15, -10);
        glVertex3d(-40, 15, 10);
        glEnd();

        // Celing center in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 14.999, 10);
        glTexCoord2d(0,100);
        glVertex3d(-40, 14.999, -10);
        glTexCoord2d(100,1);
        glVertex3d(40, 14.999, -10);
        glTexCoord2d(100,0);
        glVertex3d(40, 14.999, 10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front side door left out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -12.5, 15);
        glTexCoord2d(0,1);     
        glVertex3d(-40, 7.5, 15);
        glTexCoord2d(1,1);
        glVertex3d(-40, 7.5, 5);
        glTexCoord2d(1,0);
        glVertex3d(-40, -12.5, 5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front side door left in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
         glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-39.999, -12.5, 5);
        glTexCoord2d(0,1);
        glVertex3d(-39.999, 7.5, 5);
        glTexCoord2d(1,1);
        glVertex3d(-39.999, 7.5, 15);
        glTexCoord2d(1,0);
        glVertex3d(-39.999, -12.5, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front side door right out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -12.5, -5);
        glTexCoord2d(0,1);
        glVertex3d(-40, 7.5, -5);
        glTexCoord2d(1,1);
        glVertex3d(-40, 7.5, -15);
        glTexCoord2d(1,0);
        glVertex3d(-40, -12.5, -15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front side door right in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-39.999, -12.5, -15);
        glTexCoord2d(0,1);
        glVertex3d(-39.999, 7.5, -15);
        glTexCoord2d(1,1);
        glVertex3d(-39.999, 7.5, -5);
        glTexCoord2d(1,0);
        glVertex3d(-39.999, -12.5, -5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front up door out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 7.5, 15);
        glTexCoord2d(0,1);
        glVertex3d(-40, 12.5, 15);
        glTexCoord2d(1,1);
        glVertex3d(-40, 12.5, -15);
        glTexCoord2d(1,0);
        glVertex3d(-40, 7.5, -15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Front up door in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0); 
        glVertex3d(-39.999, 7.5, -15);
        glTexCoord2d(0,1);
        glVertex3d(-39.999, 12.5, -15);
        glTexCoord2d(1,1);
        glVertex3d(-39.999, 12.5, 15);
        glTexCoord2d(1,0);
        glVertex3d(-39.999, 7.5, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Celing front side out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 15, 10);
        glTexCoord2d(0,1);
        glVertex3d(-40, 15, -10);
        glTexCoord2d(1,1);
        glVertex3d(-40, 12.5, -10);
        glTexCoord2d(1,0);
        glVertex3d(-40, 12.5, 10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Celing front side in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-39.999, 12.5, 10);
        glTexCoord2d(0,1);
        glVertex3d(-39.999, 12.5, -10);
        glTexCoord2d(1,1);
        glVertex3d(-39.999, 15, -10);
        glTexCoord2d(1,0);
        glVertex3d(-39.999, 15, 10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back door side left out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -12.5, 5);
        glTexCoord2d(0,1);
        glVertex3d(40, 7.5, 5);
        glTexCoord2d(1,1);
        glVertex3d(40, 7.5, 15);
        glTexCoord2d(1,0);
        glVertex3d(40, -12.5, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back door side left in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(39.999, -12.5, 15);
        glTexCoord2d(0,1);
        glVertex3d(39.999, 7.5, 15);
        glTexCoord2d(1,1);
        glVertex3d(39.999, 7.5, 5);
        glTexCoord2d(1,0);
        glVertex3d(39.999, -12.5, 5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back door side right out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -12.5, -15);
        glTexCoord2d(0,1);
        glVertex3d(40, 7.5, -15);
        glTexCoord2d(1,1);
        glVertex3d(40, 7.5, -5);
        glTexCoord2d(1,0);
        glVertex3d(40, -12.5, -5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back door side right in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(39.999, -12.5, -5);
        glTexCoord2d(0,1);
        glVertex3d(39.999, 7.5, -5);
        glTexCoord2d(1,1);
        glVertex3d(39.999, 7.5, -15);
        glTexCoord2d(1,0);
        glVertex3d(39.999, -12.5, -15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back up door out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, 7.5, -15);
        glTexCoord2d(0,1);
        glVertex3d(40, 12.5, -15);
        glTexCoord2d(1,1);
        glVertex3d(40, 12.5, 15);
        glTexCoord2d(1,0);
        glVertex3d(40, 7.5, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back up door in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(39.999, 7.5, 15);
        glTexCoord2d(0,1);
        glVertex3d(39.999, 12.5, 15);
        glTexCoord2d(1,1);
        glVertex3d(39.999, 12.5, -15);
        glTexCoord2d(1,0);
        glVertex3d(39.999, 7.5, -15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Celing back side out
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, 12.5, 10);
        glTexCoord2d(0,1);
        glVertex3d(40, 12.5, -10);
        glTexCoord2d(1,1);
        glVertex3d(40, 15, -10);
        glTexCoord2d(1,0);
        glVertex3d(40, 15, 10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Celing back side in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(39.999, 15, 10);
        glTexCoord2d(0,1);
        glVertex3d(39.999, 15, -10);
        glTexCoord2d(1,1);
        glVertex3d(39.999, 12.5, -10);
        glTexCoord2d(1,0);
        glVertex3d(39.999, 12.5, 10);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Right window side bottom out  
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, -15);
        glVertex3d(-40, -2.5, -15);
        glVertex3d(40, -2.5, -15);
        glVertex3d(40, -12.5, -15);
        glEnd();
       
        // Right window side bottom in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -12.5, -14.999);
        glTexCoord2d(0,1);
        glVertex3d(40, -2.5, -14.999);
        glTexCoord2d(1,1);
        glVertex3d(-40, -2.5, -14.999);
        glTexCoord2d(1,0);
        glVertex3d(-40, -12.5, -14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Right window side up out
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-40, 12.5, -15);
        glVertex3d(40, 12.5, -15);
        glVertex3d(40, 7.5, -15);
        glEnd();
        
        // Right window side up in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, 7.5, -14.999);
        glTexCoord2d(0,1);
        glVertex3d(40, 12.5, -14.999);
        glTexCoord2d(1,1);
        glVertex3d(-40, 12.5, -14.999);
        glTexCoord2d(1,0);
        glVertex3d(-40, 7.5, -14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Right window side back up
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(37.5, -2.5, -15);
        glVertex3d(37.5, 7.5, -15);
        glVertex3d(40, 7.5, -15);
        glVertex3d(40, -2.5, -15);
        glEnd();

        // Right window side back in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -2.5, -14.999);
        glTexCoord2d(0,1);
        glVertex3d(40, 7.5, -14.999);
        glTexCoord2d(1,1);
        glVertex3d(37.5, 7.5, -14.999);
        glTexCoord2d(1,0);
        glVertex3d(37.5, -2.5, -14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Right window side front out
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, 7.5, -15);
        glVertex3d(-37.5, 7.5, -15);
        glVertex3d(-37.5, -2.5, -15);
        glVertex3d(-40, -2.5, -15);
        glEnd();
        // Right window side font in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -2.5, -14.999);
        glTexCoord2d(0,1);
        glVertex3d(-37.5, -2.5, -14.999);
        glTexCoord2d(1,1);
        glVertex3d(-37.5, 7.5, -14.999);
        glTexCoord2d(1,0);
        glVertex3d(-40, 7.5, -14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Left window side bottom out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, 15);
        glVertex3d(40, -2.5, 15);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        // Left window side bottom in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -12.5, 14.999);
        glTexCoord2d(0,1);
        glVertex3d(-40, -2.5, 14.999);
        glTexCoord2d(1,1);
        glVertex3d(40, -2.5, 14.999);
        glTexCoord2d(1,0);
        glVertex3d(40, -12.5, 14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Left window side up out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, 7.5, 15);
        glTexCoord2d(0,1);
        glVertex3d(40, 12.5, 15);
        glTexCoord2d(1,1);
        glVertex3d(-40, 12.5, 15);
        glTexCoord2d(1,0);
        glVertex3d(-40, 7.5, 15);
        glEnd();
        // Left window side up in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 7.5, 14.999);
        glTexCoord2d(0,1);
        glVertex3d(-40, 12.5, 14.999);
        glTexCoord2d(1,1);
        glVertex3d(40, 12.5, 14.999);
        glTexCoord2d(1,0);
        glVertex3d(40, 7.5, 14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Left window side back out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -2.5, 15);
        glVertex3d(40, 7.5, 15);
        glVertex3d(37.5, 7.5, 15);
        glVertex3d(37.5, -2.5, 15);
        glEnd();
        // Left widnow side back in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(37.5, -2.5, 14.999);
        glTexCoord2d(0,1);
        glVertex3d(37.5, 7.5, 14.999);
        glTexCoord2d(1,1);
        glVertex3d(40, 7.5, 14.999);
        glTexCoord2d(1,0);
        glVertex3d(40, -2.5, 14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Left window side front out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -2.5, 15);
        glVertex3d(-37.5, -2.5, 15);
        glVertex3d(-37.5, 7.5, 15);
        glVertex3d(-40, 7.5, 15);
        glEnd();

        // Left window side front in
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, 7.5, 14.999);
        glTexCoord2d(0,1);
        glVertex3d(-37.5, 7.5, 14.999);
        glTexCoord2d(1,1);
        glVertex3d(-37.5, -2.5, 14.999);
        glTexCoord2d(1,0);
        glVertex3d(-40, -2.5, 14.999);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Floor up
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -15, 15);
        glTexCoord2d(0,1);
        glVertex3d(-40, -15, -15);
        glTexCoord2d(1,1);
        glVertex3d(40, -15, -15);
        glTexCoord2d(1,0);
        glVertex3d(40, -15, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Floor bottom
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -12.5, 15);
        glTexCoord2d(0,1);
        glVertex3d(40, -12.5, -15);
        glTexCoord2d(1,1);
        glVertex3d(-40, -12.5, -15);
        glTexCoord2d(1,0);
        glVertex3d(-40, -12.5, 15);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Floor right side
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(40, -12.5, -15);
        glVertex3d(40, -15, -15);
        glVertex3d(-40, -15, -15);
        glVertex3d(-40, -12.5, -15);
        glEnd();
        // Floor left side
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-40, -12.5, 15);
        glVertex3d(-40, -15, 15);
        glVertex3d(40, -15, 15);
        glVertex3d(40, -12.5, 15);
        glEnd();

        // Back step up
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(45, -12.5, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(45, -12.5, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(40, -12.5, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(40, -12.5, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Back step down
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -15, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(40, -15, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(45, -15, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(45, -15, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step back front side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(45, -12.5, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(45, -15, 17.5);
        glTexCoord2d(1,1);
        glVertex3d(45, -15, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(45, -12.5, -17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step back back side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -12.5, -17.5);
        glTexCoord2d(0,1);
        glVertex3d(40, -15, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(40, -15, 17.5);
        glTexCoord2d(1,0);
        glVertex3d(40, -12.5, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step back left side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(45, -15, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(45, -12.5, 17.5);
        glTexCoord2d(1,1);
        glVertex3d(40, -12.5, 17.5);
        glTexCoord2d(1,0);
        glVertex3d(40, -15, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step back right side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(40, -15, -17.5);
        glTexCoord2d(0,1);
        glVertex3d(40, -12.5, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(45, -12.5, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(45, -15, -17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front up
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -12.5, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(-40, -12.5, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(-45, -12.5, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(-45, -12.5, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front down
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, -1, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-45, -15, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(-45, -15, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(-40, -15, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(-40, -15, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front front side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-45, -12.5, -17.5);
        glTexCoord2d(0,1);
        glVertex3d(-45, -15, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(-45, -15, 17.5);
        glTexCoord2d(1,0);
        glVertex3d(-45, -12.5, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front back side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -12.5, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(-40, -15, 17.5);
        glTexCoord2d(1,1);
        glVertex3d(-40, -15, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(-40, -12.5, -17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front right side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-40, -15, 17.5);
        glTexCoord2d(0,1);
        glVertex3d(-40, -12.5, 17.5);
        glTexCoord2d(1,1);
        glVertex3d(-45, -12.5, 17.5);
        glTexCoord2d(1,0);
        glVertex3d(-45, -15, 17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Step front left side
        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, wood);
        
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glTexCoord2d(0,0);
        glVertex3d(-45, -15, -17.5);
        glTexCoord2d(0,1);
        glVertex3d(-45, -12.5, -17.5);
        glTexCoord2d(1,1);
        glVertex3d(-40, -12.5, -17.5);
        glTexCoord2d(1,0);
        glVertex3d(-40, -15, -17.5);
        glEnd();
        glDisable(GL_TEXTURE_2D);


        // Bottom box back
        glNormal3d(-1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, 13);
        glVertex3d(35, -18, 13);
        glVertex3d(35, -18, -13);
        glVertex3d(35, -15, -13);
        glEnd();
        // Bottom box front
        glNormal3d(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-35, -15, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -18, 13);
        glVertex3d(-35, -15, 13);
        glEnd();

        // Bottom box right
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        glVertex3d(35, -15, -13);
        glVertex3d(35, -18, -13);
        glVertex3d(-35, -18, -13);
        glVertex3d(-35, -15, -13);
        glEnd();
        // Bottom box left
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-35, -15, 13);
        glVertex3d(-35, -18, 13);
        glVertex3d(35, -18, 13);
        glVertex3d(35, -15, 13);
        glEnd();

        // Back left wheel out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();
        // Back left wheel in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.899);
        }
        glEnd();

        // Front left wheel out
        glNormal3d(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.9);
        }
        glEnd();

        // Front left wheel in
        glNormal3d(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, 12.899);
        }
        glEnd();

        // Back right wheel out
        glNormal3f(0, 0, -1);
        glBegin(GL_POLYGON);
        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();

        // Back right wheel in
        glNormal3f(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) + 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.899);
        }
        glEnd();

        // Front right wheel out
        glNormal3f(0, 0, -1);
        glBegin(GL_POLYGON);

        for (double a = 2 * (3.15); a >= 0; a -= 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.9);
        }
        glEnd();

        // Front right wheel in
        glNormal3f(0, 0, 1);
        glBegin(GL_POLYGON);
        for (double a = 0; a <= 2 * (3.15); a += 0.5)
        {
            double x = 4 * cos(a) - 25;
            double y = 4 * sin(a) - 18;
            glVertex3d(x, y, -12.899);
        }
        glEnd();

        glEnable(GL_LIGHTING);

        glEndList();
    }
    void Draw()
    {
        glCallList(list);
    }
};