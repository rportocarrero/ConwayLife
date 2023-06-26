#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int ROW = 512;
const int COL = 512;
const int iterations = 512;
const int threads = 2;

int World[ROW][COL];
int newWorld[ROW][COL];

// Generate a New World
void gen_world(){
    srand(time(NULL));

    for(int row=0; row < ROW; row++){
        for(int col=0; col < COL; col++){
            World[row][col] = rand() % 2;
        }
    }
}


// Calculates the Next iteration of the World
void nextIter(){
    for(int row=1;row<ROW-1;row++){
        for(int col=1;col<COL-1;col++){
            int cell = World[row][col];
            int sum = World[row-1][col-1] + 
            World[row-1][col] +
            World[row-1][col+1] +
            World[row][col-1] +
            World[row][col+1] +
            World[row+1][col-1] +
            World[row+1][col] +
            World[row+1][col+1];

            // Rules
            if(cell == 0){
                if(sum == 3) newWorld[row][col] = 1;
            }
            if(cell == 1){
                if(sum == 2 or sum == 3) newWorld[row][col] = 1;
                else newWorld[row][col] = 0;
            }
        }
    }
    
    // Copy newWorld to World
    for(int row=0;row<ROW;row++){
        for(int col=0;col<COL;col++){
            World[row][col] = newWorld[row][col];
        }
    }
}

// Save the World as an image
void world_image(int n){
    ofstream myfile;
    if(n<10)myfile.open("iterations/imageSequence-000"+to_string(n)+".ppm");
    else if(n<100)myfile.open("iterations/imageSequence-00"+to_string(n)+".ppm");
    else if(n<1000) myfile.open("iterations/imageSequence-0"+to_string(n)+".ppm");
    else myfile.open("iterations/imageSequence-"+to_string(n)+".ppm");
    myfile << "P1\n";
    myfile << ROW << " " << COL << " 1\n";
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            myfile << World[i][j] << " ";
        }
        myfile << "\n";
    }
    myfile.close();
}

// Main Function
int main(int argc, char** argv){
    gen_world();
    for(int i=0;i<iterations;i++){
        nextIter();
        world_image(i);
    }
    // Convert to Video
    system("ffmpeg -pattern_type glob -i \"iterations/imageSequence-*.ppm\" \"outputs/Life.mpg\"");
}