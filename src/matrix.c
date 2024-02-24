#include "../inc/header.h"


int main(int argc, char *argv[]){
    /*if(argc > 1){
        mx_printerr();
    }*/
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);        
    init_droplets();
    atexit(cleanup);

    if(!has_colors()){
        printf("You have no colors :(\n");
        exit(0);
    }
    start_color();
    use_default_colors();
    init_pair(1, COLOR_BLACK, -1);
    init_pair(2, COLOR_RED, -1); 
    init_pair(3, COLOR_GREEN, -1);
    init_pair(4, COLOR_YELLOW, -1);
    init_pair(5, COLOR_BLUE, -1); 
    init_pair(6, COLOR_MAGENTA, -1);
    init_pair(7, COLOR_CYAN, -1); 
    init_pair(8, COLOR_WHITE, -1);
    
    struct timespec ts;
    ts.tv_sec = 20/10000;
    ts.tv_nsec = (20 % 1000) * 1000000;
    
    refresh_rate = 7;
    multicolor_trail = 0;
    velocity = 1;
    primary_color = 3;
    secondary_color = 7;

    while(1){
        draw_rain();
        refresh();
        usleep(20000);
        switch(getch()){
            case 'q':
                exit(0);
                break;
            case 'c':
                if(multicolor_trail){
                    multicolor_trail = 0;
                }
                else{
                    multicolor_trail = 1;
                }
                break;
            case 'v':
                velocity *= 0.5;
                break;
            case '1':
                primary_color = 1;
                break;
            case '2':
                primary_color = 2;
                break;
            case '3':
                primary_color = 3;
                break;
            case '4':
                primary_color = 4;
                break;
            case '5':
                primary_color = 5;
                break;
            case '6':
                primary_color = 6;
                break;
            case '7':
                primary_color = 7;
                break;
            case '8':
                primary_color = 8;
                break;
            case KEY_F(1):
                secondary_color = 1;
                break;
            case KEY_F(2):
                secondary_color = 2;
                break;
            case KEY_F(3):
                secondary_color = 3;
                break;
            case KEY_F(4):
                secondary_color = 4;
                break;
            case KEY_F(5):
                secondary_color = 5;
                break;
            case KEY_F(6):
                secondary_color = 6;
                break;
            case KEY_F(7):
                secondary_color = 7;
                break;
            case KEY_F(8):
                secondary_color = 8;
                break;
            case KEY_DOWN:
                if(refresh_rate < 20){
                    refresh_rate++;
                }
                break;
            case KEY_UP:
                if(refresh_rate > 1){
                    refresh_rate--;
                }
                break;
            case 't'://test
                printf("%u", refresh_rate);
                break;
            default:
                break;
        }
    }
    
    printf("Reached end of main, this should never happen\n");
    return 0;
}

