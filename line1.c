typedef volatile unsigned short hword;
#define BGR(r, g, b) r+g*32+b*1024
#define RED BGR(0x1F, 0x00, 0x00)
#define GBA_MODE_ADDRESS 0x04000000
#define GBA_MODE 0x0F03
#define VRAM_ADDRESS 0x06000000

void draw_point(hword, hword, hword);
void draw_line (hword, hword, hword, hword, hword);

int main(void){
    hword *ptr;
    ptr = (hword*)GBA_MODE_ADDRESS;
    *ptr = GBA_MODE;
    hword xa=20,ya=10,xb=120,yb=110,color=RED;
    draw_line(xa,ya,xb,yb,color);
	while(1);

	return 0;
}

void draw_point(hword x, hword y, hword color) {
    hword *ptr;
    ptr = (hword*)VRAM_ADDRESS;
    ptr += (x + 240 * y);
    *ptr = color;
}

void draw_line(hword xa, hword ya,hword xb, hword yb, hword color) {
    hword x = (xa+xb)/ 2;
    hword y = (ya+yb)/ 2;
    draw_point(x,y,color);
    if ((x-xa)>=1) {
        draw_line(x,y,xb,yb,color);
        draw_line(xa,ya,x,y,color);
    } else {
        return;
    }

    
}