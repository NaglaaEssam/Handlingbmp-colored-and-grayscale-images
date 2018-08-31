// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <bits/stdc++.h>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char imagE[SIZE][SIZE];
unsigned char temb[SIZE][SIZE];
void loadImage ();
void loadImage1 ();
void saveImage ();
void doSomethingForImage1();
void doSomethingForImage2();
void doSomethingForImage3();
void doSomethingForImage4();
void doSomethingForImage5();
void doSomethingForImage6();
void doSomethingForImage7();
void doSomethingForImage8();
void doSomethingForImage9();
void doSomethingForImageA();
void doSomethingForImageB();

void saveImage1();
int main()
{
    char x[1];
    while(int(x[0])!=48)
    {
        cout<<"     Ahlan ya user ya habibi "<<endl;
        cout<<"  Please enter file name of the image to process: "<<endl;
        cout<<"Please select a filter to apply or 0 to exit: "<<endl;
        cout<<"1- Black & White Filter"<<endl;
        cout<<"2- Invert Filter"<<endl;
        cout<<"3- Merge Filter"<<endl;
        cout<<"4- Flip Image"<<endl;
        cout<<"5- Darken and Lighten Image"<<endl;
        cout<<"6- Rotate Image"<<endl;
        cout<<"7- Detect Image Edges"<<endl;
        cout<<"8- Enlarge Image"<<endl;
        cout<<"9- Shrink Image"<<endl;
        cout<<"a- Mirror 1/2 Image"<<endl;
        cout<<"b- Shuffle Image"<<endl;
        cout<<"c- Blur Image"<<endl;
        cout<<"s- Save the image to a file"<<endl;
        cout<<"0- Exit"<<endl;

        cout<<"input the number : ";
        cin>>x;


        if(int(x[0])==49)
        {
    loadImage();
    doSomethingForImage1();
    saveImage();

    }
    if(int(x[0])==50)
    {
      loadImage();
      doSomethingForImage2();
      saveImage();
    }
    if(int(x[0])==51)
    {
      loadImage1();
      doSomethingForImage3();
      saveImage();
    }
    if(int(x[0])==52)
    {
      loadImage();
      doSomethingForImage4();
      saveImage1();
    }
    if(int(x[0])==53)
    {
      loadImage();
      doSomethingForImage5();
      saveImage1();
    }
    if(int(x[0])==54)
    {
      loadImage();
      doSomethingForImage6();
      saveImage();
    }
    if(int(x[0])==55)
    {
      loadImage();
      doSomethingForImage7();
      saveImage1();
    }
    if(int(x[0])==56)
    {
      loadImage();
      doSomethingForImage8();
      saveImage1();
    }
    if(int(x[0])==57)
    {

      loadImage();
      doSomethingForImage9();
      saveImage1();
    }
    if(int(x[0])==97)
    {
      loadImage();
      doSomethingForImageA();
      saveImage();
    }
    if(int(x[0])==98)
    {
      loadImage();
      doSomethingForImageA();
      saveImage1();
    }
    }
    return 0;
}

//____________________________________________

void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}
void loadImage1 ()
{
    char imageFileName[100];
    char imagefileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    cout << "Enter the source image file name: ";
    cin >> imagefileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    strcat (imagefileName, ".bmp");
    readGSBMP(imageFileName, image);
    readGSBMP(imagefileName, imagE);
}


//_________________________________________
void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName,image);
}
void saveImage1 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName,imagE);
}

void doSomethingForImage1()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {

            if(image[i][j]>127)
                image[i][j]=255;
            else
                image[i][j]=0;
        }
    }
}
void doSomethingForImage2()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if(image[i][j]==255)
                image[i][j]=0;
            if(image[i][j]==0)
                image[i][j]=255;
            else
                image[i][j]=255-image[i][j];
        }
    }
}
void doSomethingForImage3()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            image[i][j]=((image[i][j]+imagE[i][j])/2);
        }
    }
}
void doSomethingForImage4()
{
    char x;

    cout<<"Flip (h) for horizontally "<<endl;
    cout<<"Filp (v) for vertically "<<endl;
    cout<<" your charactar : ";
    cin>>x;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< i; j++)
        {
            /*
            temb[i][j]=image[i][j];
            image[i][j]=image[j][i];
            image[j][i]=temb[i][j];
            */
            if(x=='v')
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j< SIZE; j++)
                    {
                        //imagE[i][j]=image[SIZE-1-j][i];
                        image[i][j]=image[j][(SIZE*2)-1-i];
                    }
                }
            }
            ///image[i][j]=image[i][(SIZE*2)-1-j]
            if(x=='h')
            {
                for (int i = 0; i < SIZE; i++)
                {
                    for (int j = 0; j< SIZE; j++)
                    {
                        imagE[i][j]=image[j][SIZE-1-i];
                    }
                }
            }
        }
    }
}

void doSomethingForImage5()
{
    int x;
    cout<<"1-Rotate (90)  degrees "<<endl;
    cout<<"2-Rotate (180) degrees "<<endl;
    cout<<"3-Rotate (360) degrees "<<endl;
    cout<<"your number : ";
    cin>>x;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if(x==1)
            {
                imagE[i][j]=image[SIZE-1-j][i];
            }

            if(x==2)
            {
                imagE[i][j]=image[SIZE-1-i][SIZE-1-j];
            }
            if(x==3)
            {
                imagE[i][j]=image[j][SIZE-1-i];
            }

        }
    }
}
void doSomethingForImage6()
{
    char x;
    cout<<" Do you want to (d) for darken "<<endl;
    cout<<" Do you want to (l) for lighten"<<endl;
    cout<<"your charactar : ";
    cin>>x;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j<SIZE ; j++)
        {
            if(x=='l'||x=='L')
            {
                if(image[i][j]>170)
                    image[i][j]=255;
                else
                    image[i][j]=(image[i][j]*3)/2;
            }
            if(x=='d'||x=='D')
            {
                image[i][j]=image[i][j]/2;
            }
        }
    }
}
void doSomethingForImage7()
{
    doSomethingForImage1();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j< SIZE; j++)
        {
            if(image[i][j-1]-image[i][j]==0&&image[i][j]-image[i+1][j]==0)
            {
                imagE[i][j]=255;
            }
        }
    }
}
void doSomethingForImage8()
{
    int x;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
    cout<<"your number : ";
    cin>>x;
    if(x==1)
    {
        for (int k=0,i=0; i < SIZE/2; i++,k+=2)
        {
            for (int j = 0,l=0; j< SIZE/2; j++,l+=2)
            {
                imagE[k][l]=image[i][j];
            }
        }
    }

    if(x==2)
    {
        for (int k=0,i=0; i < SIZE/2; i++,k+=2)
        {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l+=2)
            {
                imagE[k][l]=image[i][j];
            }
        }
    }
    if(x==3)
    {
        for (int k=0,i=SIZE/2; i < SIZE; i++,k+=2)
        {
            for (int j = 0,l=0; j< SIZE/2; j++,l+=2)
            {
                imagE[k][l]=image[i][j];
            }
        }
    }
    if(x==4)
    {
        for (int k=0,i=SIZE/2; i < SIZE; i++,k+=2)
        {
            for (int j = SIZE/2,l=0; j< SIZE; j++,l+=2)
            {
                imagE[k][l]=image[i][j];
            }
        }
    }
}
void doSomethingForImage9()
{
    int x;
    cout<<"1-Shrink to (1/2) "<<endl;
    cout<<"2-shrink to (1/3) "<<endl;
    cout<<"3-shrink to (1/4) "<<endl;
    cout<<"your number : ";
    cin>>x;
    if(x==1)
    {
        for (int k=0,i=0; i < SIZE/2; i++,k+=2)
        {
            for (int j = 0,l=0; j< SIZE/2; j++,l+=2)
            {
                imagE[i][j]=image[k][l];
            }
        }
    }
    if(x==2)
    {
        for (int k=0,i=0; i < SIZE/3; i++,k+=3)
        {
            for (int j = 0,l=0; j< SIZE/3; j++,l+=3)
            {
                imagE[i][j]=image[k][l];
            }
        }
    }
    if(x==3)
    {
        for (int k=0,i=0; i < SIZE/4; i++,k+=4)
        {
            for (int j = 0,l=0; j< SIZE/4; j++,l+=4)
            {
                imagE[i][j]=image[k][l];
            }
        }
    }
}


//_________________________________________
void doSomethingForImageA()
{
    char x;
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side : ";
    cout<<"your characatar : ";
    cin>>x;
if(x=='d'){
     for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
           image[i][j]=image[(SIZE)-1-i][j];

        }
     }
}
if(x=='u'){
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
           image[i][j]=image[i][(SIZE)-1-j];
        }
     }
}
if(x=='r'){
     for (int i = SIZE; i >0; i--) {
       for (int j = SIZE; j>0; j--) {
         image[i][j]=image[(SIZE)-1-i][j];
       }
     }
}

if(x=='l'){
    for (int i = SIZE; i >0; i--) {
       for (int j = SIZE; j>0; j--) {
        image[i][j]=image[i][(SIZE)-1-j];
       }
    }
}

}

void doSomethingForImageB()
{
    int arr[4];
    int i;
    cout<<"New order of quarters : ";
    for(i=0; i<4; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<4; i++)
    {
        if(arr[i]==1)
        {
            if(i+1==1)
            {
                for (int k=0,i=0; i < SIZE/2; i++,k++)
                {
                    for (int j = 0,l=0; l< SIZE/2; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }

            if(i+1==2)
            {

                for (int k=0,i=0; i < SIZE/2; i++,k++)
                {
                    for (int j = 0,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }
            if(i+1==3)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=0; j< SIZE/2; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }
            if(i+1==4)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }
        }

        if(arr[i]==2)
        {
            if(i+1==1)
            {
                for (int k=0,i=0; i < SIZE/2; i++,k++)
                {
                    for (int j = 0,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==2)
            {
                for (int k=0,i=0; i < SIZE/2; i++,k++)
                {
                    for (int j = SIZE/2,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==3)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=0; j< SIZE; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }
            if(i+1==4)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[k][l]=image[i][j];
                    }
                }
            }

        }


        if(arr[i]==3)
        {
            if(i+1==1)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=0; j< SIZE/2; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }

            if(i+1==2)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=0; j< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==3)
            {
                for (int k=SIZE/2,i=SIZE/2; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=0; j< SIZE/2; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==4)
            {
                for (int k=SIZE/2,i=SIZE/2; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=0; j< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
        }

        if(arr[i]==4)
        {
            if(i+1==1)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==2)
            {
                for (int k=SIZE/2,i=0; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
            if(i+1==3)
            {
                for (int k=SIZE/2,i=SIZE/2; k < SIZE; i++,k++)
                {
                    for (int j = 0,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }

            if(i+1==4)
            {
                for (int k=SIZE/2,i=SIZE/2; k < SIZE; i++,k++)
                {
                    for (int j = SIZE/2,l=SIZE/2; l< SIZE; j++,l++)
                    {
                        imagE[i][j]=image[k][l];
                    }
                }
            }
        }


    }
}


