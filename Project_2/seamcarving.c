
#include "seamcarving.h"
#include <stdio.h>
#include <math.h>
void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    int height = im->height;//y
    int width = im->width;//x
    create_img(grad, height, width);
    //printf("%d\n", height);
    //printf("%d\n", width);
    int i;//y
    int j;//x
    int rgb[height][width][3];
    for(i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            rgb[i][j][0] = get_pixel(im, i, j, 0);
            rgb[i][j][1] = get_pixel(im, i, j, 1);
            rgb[i][j][2] = get_pixel(im, i, j, 2);
        }
    }
    int energy[height][width];
    int Rx, Gx, Bx, Ry, Gy, By;
    //higher left corner
    Rx = rgb[0][1][0] - rgb[0][width-1][0];
    Gx = rgb[0][1][1] - rgb[0][width-1][1];
    Bx = rgb[0][1][2] - rgb[0][width-1][2];
    Ry = rgb[1][0][0] - rgb[height-1][0][0];
    Gy = rgb[1][0][1] - rgb[height-1][0][1];
    By = rgb[1][0][2] - rgb[height-1][0][2];
    energy[0][0] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    //higher right corner
    Rx = rgb[0][0][0] - rgb[0][width - 2][0];
    Gx = rgb[0][0][1] - rgb[0][width - 2][1];
    Bx = rgb[0][0][2] - rgb[0][width - 2][2];
    Ry = rgb[1][width - 1][0] - rgb[height-1][width - 1][0];
    Gy = rgb[1][width - 1][1] - rgb[height-1][width - 1][1];
    By = rgb[1][width - 1][2] - rgb[height-1][width - 1][2];
    energy[0][width - 1] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    //lower left corner
    Rx = rgb[height-1][1][0] - rgb[height-1][width-1][0];
    Gx = rgb[height-1][1][1] - rgb[height-1][width-1][1];
    Bx = rgb[height-1][1][2] - rgb[height-1][width-1][2];
    Ry = rgb[0][0][0] - rgb[height-2][0][0];
    Gy = rgb[0][0][1] - rgb[height-2][0][1];
    By = rgb[0][0][2] - rgb[height-2][0][2];
    energy[height-1][0] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    //lower right corner
    Rx = rgb[height - 1][0][0] - rgb[height - 1][width - 2][0];
    Gx = rgb[height - 1][0][1] - rgb[height - 1][width - 2][1];
    Bx = rgb[height - 1][0][2] - rgb[height - 1][width - 2][2];
    Ry = rgb[0][width - 1][0] - rgb[height - 2][width - 1][0];
    Gy = rgb[0][width - 1][1] - rgb[height - 2][width - 1][1];
    By = rgb[0][width - 1][2] - rgb[height - 2][width - 1][2];
    energy[height - 1][width - 1] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    //top
    for (j = 1; j < width - 1; j++) {
        Rx = rgb[0][j + 1][0] - rgb[0][j - 1][0];
        Gx = rgb[0][j + 1][1] - rgb[0][j - 1][1];
        Bx = rgb[0][j + 1][2] - rgb[0][j - 1][2];
        Ry = rgb[1][j][0] - rgb[height - 1][j][0];
        Gy = rgb[1][j][1] - rgb[height - 1][j][1];
        By = rgb[1][j][2] - rgb[height - 1][j][2];
        energy[0][j] = sqrt(pow(Rx, 2) + pow(Gx, 2) + pow(Bx, 2) + pow(Ry, 2) + pow(Gy, 2) + pow(By, 2));
    }
    //bottom
    for (j = 1; j < width - 1; j++) {
        Rx = rgb[height-1][j+1][0] - rgb[height-1][j-1][0];
        Gx = rgb[height-1][j+1][1] - rgb[height-1][j-1][1];
        Bx = rgb[height-1][j+1][2] - rgb[height-1][j-1][2];
        Ry = rgb[0][j][0] - rgb[height-2][j][0];
        Gy = rgb[0][j][1] - rgb[height-2][j][1];
        By = rgb[0][j][2] - rgb[height-2][j][2];
        energy[height-1][j] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    }
    //left
    for (i = 1; i < height - 1; i++) {
        Rx = rgb[i][1][0] - rgb[i][width-1][0];
        Gx = rgb[i][1][1] - rgb[i][width-1][1];
        Bx = rgb[i][1][2] - rgb[i][width-1][2];
        Ry = rgb[i+1][0][0] - rgb[i-1][0][0];
        Gy = rgb[i+1][0][1] - rgb[i-1][0][1];
        By = rgb[i+1][0][2] - rgb[i-1][0][2];
        energy[i][0] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    }
    //right
    for (i = 1; i < height - 1; i++) {
        Rx = rgb[i][0][0] - rgb[i][width-2][0];
        Gx = rgb[i][0][1] - rgb[i][width-2][1];
        Bx = rgb[i][0][2] - rgb[i][width-2][2];
        Ry = rgb[i+1][width - 1][0] - rgb[i-1][width - 1][0];
        Gy = rgb[i+1][width - 1][1] - rgb[i-1][width - 1][1];
        By = rgb[i+1][width - 1][2] - rgb[i-1][width - 1][2];
        energy[i][width - 1] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
    }
    //middle
    for(i = 1; i < height-1; i++){
        for (j = 1; j < width-1; j++){
            Rx = rgb[i][j+1][0] - rgb[i][j-1][0];
            Gx = rgb[i][j+1][1] - rgb[i][j-1][1];
            Bx = rgb[i][j+1][2] - rgb[i][j-1][2];
            Ry = rgb[i+1][j][0] - rgb[i-1][j][0];
            Gy = rgb[i+1][j][1] - rgb[i-1][j][1];
            By = rgb[i+1][j][2] - rgb[i-1][j][2];
            energy[i][j] = sqrt(pow(Rx,2)+pow(Gx,2)+pow(Bx,2)+pow(Ry,2)+pow(Gy,2)+pow(By,2));
            }
    }//complete energy
    for(i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r;
            r = (energy[i][j])/10;
            set_pixel(*grad, i, j, r, r, r);
        }
    }
     
}



void dynamic_seam(struct rgb_img *grad, double **best_arr){
    (*best_arr) = (double *)malloc(sizeof(double)*((grad->height) * (grad->width)));
    int height = grad->height;
    int width = grad->width;
    int i = 0;
    while(i<width){
        (*best_arr)[i] = get_pixel(grad, 0, i, 0);
        // printf("%f\n",(*best_arr)[i]);
        i++;
    }
    int j;
    for (j = width; j< (height * width); j++){
        if((j+1)%width == 1){ // Left
            int minimum = ((*best_arr)[j-width]> (*best_arr)[j-width+1] ? (*best_arr)[j-width+1]:(*best_arr)[j-width]);   
            (*best_arr)[j] = minimum + get_pixel(grad, j/width, j%width, 0);
            // printf("%f\n",(*best_arr)[j]);
        }
        else if((j+1)%width == 0){ // Right
            int minimum = ((*best_arr)[j-width]> (*best_arr)[j-width-1] ? (*best_arr)[j-width-1]:(*best_arr)[j-width]);
            (*best_arr)[j] = minimum + get_pixel(grad, j/width, j%width, 0);
            // printf("%f\n",(*best_arr)[j]);
        }
        else{
            int left = (*best_arr)[j-width-1];
            int right = (*best_arr)[j-width+1];
            int middle = (*best_arr)[j-width];
            int minimum = ((left > right ? right:left)> middle? middle: (left > right ? right:left));
            (*best_arr)[j] = minimum + get_pixel(grad, j/width, j%width, 0);
            // printf("%f\n",(*best_arr)[j]);   
        }
    }
}



void recover_path(double *best, int height, int width, int **path){
    int i = 0;
    *path = (int*)malloc(sizeof(int) * height);
    int location = -1;
    for (i=0; i<height; i++){
        if(location == -1){
            int minimum = 10000;
            int j = (height-i)*width;
            for (j = (height-i-1)*width; j < (height)*width; j++){
                if (best[j]<minimum){
                    minimum = best[j];
                    location = j- (height-i-1)*width;
                    (*path)[i] = location;
                }
            }
        }
        else{
            if (location == 0){ // Left
                double right = best[height * width -(width*(i+1))+location+1];
                double middle = best[height * width -(width*(i+1))+location];
                double minimum =(right>middle?middle:right);
                if(minimum == right){
                    location ++;
                    (*path)[i] = location;
                }
                else{
                    (*path)[i] = location;
                }
            }
            else if(location == width -1){ // Right
                double left = best[height * width -(width*(i+1))+location-1];
                double middle = best[height * width -(width*(i+1))+location];
                double minimum =(left>middle?middle:left);
                if(minimum == left){
                    location --;
                    (*path)[i] = location;
                }
                else{
                    (*path)[i] = location;
                }
            }
            else{
                double left = best[height * width -(width*(i+1))+location-1];
                double right = best[height * width -(width*(i+1))+location+1];
                double middle = best[height * width -(width*(i+1))+location];
                double minimum = ((left > right ? right:left)> middle ? middle: (left > right ? right:left));
                if(minimum == left){
                    location = location-1;
                    (*path)[i] = location;
                }
                else if(minimum == right){
                    location = location+1;
                    (*path)[i] = location;
                }
                else{
                    location = location;
                    (*path)[i] = location;
                }
            }
        }
    }
    // Reverse
    int m = 0;
    for (m = 0; m<height/2; m++){
        int temp = (*path)[m];
        (*path)[m] = (*path)[height-m-1];
        (*path)[height-m-1] = temp;
    }
}


// void recover_path1(double *best, int height, int width, int **path){
//     int i, j;
//     (*path) = (int *)malloc(sizeof(int)*height);
//     int index = 0;
//     for(j = 1; j < width ; j++){
//         if (best[(height-1)*width + j] < best[(height-1)*width + index])
//             index = j;
//     }
//     (*path)[height-1] = index;
//     for(i = height - 2; i > -1; i--){
//         if(index == 0){
//             if(best[i*width]<best[i*width+1])
//                 index = 0;
//             else
//                 index = 1;
//         }else if(index == width-1){
//             if(best[i*width+width-2]<best[i*width+width-1])
//                 index = width-2;
//             else
//                 index = width-1;
//         }else{
//             int d = 0;
//             while(best[i*width + index -1]&&best[i*width + index]&&best[i*width + index+1]){
//                 best[i*width + index -1]--;
//                 printf("%f\n",best[i*width + index -1]);
//                 best[i*width + index]--;
//                 printf("%f\n",best[i*width + index]);
//                 best[i*width + index+1]--;
//                 printf("%f\n",best[i*width + index+1]);
//                 d++;
//             }if(best[i*width + index -1]==0)
//                 index = index -1;
//             else if(best[i*width + index]==0)
//                 index = index;
//             else if(best[i*width + index+1]==0)
//                 index = index+1;
//         }
//         (*path)[i] = index;
//     }
// }

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    int height = src->height;//y
    int width = src->width;//x
    create_img(dest, height, width-1);
    int i;//y height
    int j;//x width
    for(i = 0; i < height; i++){
        for(j = 0; j < path[i]; j++){
            int r = get_pixel(src, i, j, 0);
            int g = get_pixel(src, i, j, 1);
            int b = get_pixel(src, i, j, 2);
            set_pixel(*dest, i, j, r, g, b);
        }
        for(j = path[i]; j < width; j++){
            int r = get_pixel(src, i, j+1, 0);
            int g = get_pixel(src, i, j+1, 1);
            int b = get_pixel(src, i, j+1, 2);
            set_pixel(*dest, i, j, r, g, b);
        }
    }
}

