/*
 *  lights.h
 *      Simulates traffic lights in
 *      both intersections
 */

enum
{
    EW, NS  //  inidices for each traffic light
};

enum
{
    // bit positions for each color
    RED = 0x04, YELLOW = 0x02, GREEN = 0x01
};

/*
 *  read_light:
 *      reads one of traffic lights
 */

int read_light(int which);

/*
 *  set_light:
 *      writes one of traffic lights
 */

void set_light(int which, int value);

