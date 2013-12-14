/*
 *  paint fill algorithm
 *  C8P6
 */
 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void swap(char *x, char *y)
{
    char *temp;
    *temp = *x;    *x = *y;    *y = *temp;
}

struct canvas_s 
{
    int height;
    int width;
    int **canvas;
};

typedef struct canvas_s canvas_t;
// char swap 


bool checker(int nc, int x, int y, canvas_t *cptr)
{
    if(x < 0 || x >= cptr->width || y < 0 || y >= cptr->height)
      return false;
    else if (nc == cptr->canvas[x][y])
      return false;
    else
      return true;
}
// paint fill function 
// input: new color, starting point, canvas
// output: area filled with new color
void paint_fill(int nc,  int x, int y, canvas_t *cptr)
{
    if(!checker(nc, x, y, cptr)) return;
    
    cptr->canvas[x][y] = nc;
    cout << "[" << x << " " << y << "]" << nc << " " << cptr->canvas[x][y] << endl;
    paint_fill(nc, x-1, y, cptr);
    paint_fill(nc, x+1, y, cptr);
    paint_fill(nc, x, y-1, cptr);
    paint_fill(nc, x, y+1, cptr);
    return;
}

void print_canvas(canvas_t *canvas)
{   
    for(int j = 0; j < canvas->height; j++)
    {
        for(int i = 0; i < canvas->width; i++)
        {
            printf("%d  ", canvas->canvas[i][j]);
        }
        printf(" \n ");
    }
}

int main()
{
    cout << " CC150 C8P6 Paint fill " << endl;
    
    int i,j; 
    canvas_t canvas;
    canvas.height = 4;
    canvas.width = 4;
    
    // init row pointers
    canvas.canvas = (int**)malloc(sizeof(int*) * canvas.height);
    if(!canvas.canvas) return -1;
    
    for(i = 0; i < canvas.height; i++)
    {
       canvas.canvas[i] = (int*)malloc(sizeof(int*) * canvas.width);
       if(!canvas.canvas[i]) return -1;
       memset(canvas.canvas[i], 0, canvas.width);      
    }
    
    print_canvas(&canvas);
    
    
    for(i = 0; i < canvas.height; i++)
    {
        for(j = 0; j < canvas.width; j++)
        {
            canvas.canvas[i][j] = 1;
        }
    }
    
    print_canvas(&canvas);
    
    paint_fill(2, 1, 1, &canvas);
    
    print_canvas(&canvas);
    
    return 0;
}


/*   
Gotcha: 

1. double pointer init needs done by 2 iteration 
2. double pointer can be used as a 2d array fine. 
3. memset was in "string.h"
4. the checker needs to check not real boundaries but also new boundaries on the fly
(the second check in checker)
*/
