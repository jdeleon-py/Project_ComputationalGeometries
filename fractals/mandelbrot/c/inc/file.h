// FILE HANDLING HEADER FILE

#ifndef __FILE_H__
#define __FILE_H__

#define MAX_FILENAME 30

// (DEFINED IN QUADTREE.C)
extern void load_quadtree(char* filename);

extern void save_quadtree(char* filename);
extern void save_iters(char* filename);
extern void save_colors(char* filename);

#endif
