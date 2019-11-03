//
// Created by brayden on 2019-11-03.
//

#include "Interaction.h"
#include "opencv2/highgui.hpp"

cv::Rect box;
bool drawing_box = false;

void my_mouse_callback(
        int event, int x, int y, int flags, void* param ){
    cv::Mat& image = *(cv::Mat*) param;
    switch( event ) {
        case cv::EVENT_MOUSEMOVE: { if( drawing_box ) {
                box.width = x-box.x;
                box.height = y-box.y; }
        } break;
        case cv::EVENT_LBUTTONDOWN: { drawing_box = true;
            box = cv::Rect( x, y, 0, 0 );
        } break;
        case cv::EVENT_LBUTTONUP: { drawing_box = false;
            if( box.width < 0 ) {
                box.x += box.width;
                box.width *= -1; }
            if( box.height < 0 ) { box.y += box.height; box.height *= -1;
            }
            draw_box( image, box ); }
            break; }
}