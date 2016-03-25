#include "lmcp.h"

void Lmcp::send_command(uint8_t command, char *target)
{
    static uint8_t data[1];

    data[0] = command;
    transmit(data, 1, target);
}

void Lmcp::send(Surface &surf, char *target)
{
    static int size;
    static int x;
    static int y;
    static int width;
    static int height;
    static int point;
    static int color[3];
    static uint8_t packet[MAX_UDP_PACKETSIZE];
    static rect_t surf_rect;

    surf_rect = surf.get_rect();
    size = surf_rect.size;
    x = surf_rect.x;
    y = surf_rect.y;
    width = surf_rect.width;
    height = surf_rect.height;

    if(size < (1024 - 5))
    {
        packet[0] = this->DRAW_IMG_RECT;
        packet[1] = x;
        packet[2] = y;
        packet[3] = width;
        packet[4] = height;

        point = 5;
        for(int px = 0; px < width; px++)
        {
            for(int py = 0; py < height; py++)
            {
                surf.read_pixel(py, px, color);
                packet[point] = (color[0] + color[1] + color[2]) / 3;
                point++;
            }
        }
        transmit(packet, point, target);
        this->send_command(this->WRITE_BUFF, target);
    }
    else
    {
        return;
    }

}