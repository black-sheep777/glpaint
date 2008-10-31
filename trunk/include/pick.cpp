#include "pick.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#define PLUS 20
#define MINUS 21

int pick(int x, int y, int wh, int ww)
{
	y = wh - y;

	// Verifica se y esta' na parte superior da tela
	// onde estao os botões de selecao das ferramentas
	if (y < wh-ww/10) return 0;
//<<<<<<< .mine
        else if(x < ww/10   ) return LINE;
        else if(x < ww/5    ) return RECTANGLE;
        else if(x < 3*ww/10 ) return TRIANGLE;
        else if(x < 2*ww/5  ) return POINTS;
        else if(x < ww/2    ) return TEXT;
	    else if(x < 3*ww/5  ) return CIRCLE;
	    else if(x < 7*ww/10 ) return ERASER;
        else return 0;
/*=======
	else if(x < ww/10   ) return LINE;
	else if(x < ww/5    ) return RECTANGLE;
	else if(x < 3*ww/10 ) return TRIANGLE;
	else if(x < 2*ww/5  ) return POINTS;
	else if(x < ww/2    ) return TEXT;
	else if(x < 3*ww/5  ) return ERASER;
	else return 0;
>>>>>>> .r33*/

}


// tem q ajeitar -> ta "pickando" no inicio da paleta!


// as mudanças de cores devem ser feitas só quando o cara clicar
// do jeito que tava sempre q passasse o mouse em cima ele mudava
int pick_color(int x, int y, int wh, int ww)
{
	y = wh - y;

	// Verifica se y esta na parte inferior onde estao as cores
	if(y > ((ww/10 + ww/15))||(y < (ww/10)-ww/15)||(x < ww/10)) return 0;
	else if((x >= ww/10) && (x <= (ww/10+ww/15)) && (y > ww/10)) return RED;
	else if((x > ww/10) && (x < (ww/10+ww/15)) && (y < ww/10)) return GREEN;
	else if(x < (ww/10+2*(ww/15)) && (y> ww/10)) return BLUE;
	else if(x < (ww/10+2*(ww/15)) && (y< ww/10)) return CYAN;
	else if(x < (ww/10+3*(ww/15)) && (y> ww/10)) return MAGENTA;
	else if(x < (ww/10+3*(ww/15)) && (y< ww/10)) return YELLOW;
	else if(x < (ww/10+4*(ww/15)) && (y> ww/10)) return ORANGE;
	else if(x < (ww/10+4*(ww/15)) && (y< ww/10)) return BLACK;
	else if(x < (ww/10+5*(ww/15)) && (y> ww/10)) return GRAY;
	else if(x < (ww/10+5*(ww/15)) && (y< ww/10)) return WHITE;

	return 0;

}

int pick_size(int x, int y, int wh, int ww){
    GLint lwidth,psize;

	// Verifica se y esta na parte inferior onde estao as cores
	if(y > (ww/10) || (x > (ww/2+ww/5+ww/20)) || ( x <(ww/2+ww/5))) return 0;
    else if(y<ww/20) {
            glGetIntegerv(GL_LINE_WIDTH,&lwidth);
            glGetIntegerv(GL_POINT_SIZE,&psize);
            glLineWidth(lwidth+1);
            glPointSize(psize+1);
            return 1;
    } else {
        glGetIntegerv(GL_LINE_WIDTH,&lwidth);
        glGetIntegerv(GL_POINT_SIZE,&psize);
        glLineWidth(lwidth-1);
        glPointSize(psize-1);
        return 1;
    }
	    //else if((x < 8*ww/10)&&y>ww/20) {glLineWidth(glLineWidth-1); glPointSize(glPointSize-1)}return MINUS;
    return 0;
}
