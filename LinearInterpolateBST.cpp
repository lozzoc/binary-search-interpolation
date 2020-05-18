#include <math.h>
#include <stdio.h>

/*
 1 d array of pairs [x1,y1,x2,y2,...]
its easier to test this way, in one malloc compared to many.
*/
float InterpolateYGivenXBST(float * array, int numpairs, float searchTerm) {

  float x1, /*searchTerm,*/ x3, y1, y3;

  if(array[0] >= searchTerm){
    return array[1];
  }
  else if(array[(numpairs-1)*2] <= searchTerm){
    return array[numpairs*2-1];
  }
  else{

    int mid, low = 0, high = numpairs - 1;

    while (low <= high) {

      mid = (low + high) / 2;
      if (array[mid*2] == searchTerm) {
        return array[mid*2+1];

      } else if (array[mid*2] < searchTerm){
        // if we have sandwhich faceing right
          if(array[2*(mid+1)] > searchTerm ){
            x1 = array[2*mid];
            x3 = array[2*mid+2];
            y1 = array[2*mid+1];
            y3 = array[2*mid+3];
            return (searchTerm - x1) * (y3-y1) / (x3-x1) + y1;
            // return array[mid*2+1];
          }
          else{
            low = mid + 1;
          }

      } else {
        // if we have sandwhich faceing rleft
           if(array[2*(mid-1)] < searchTerm ){
             x1 = array[2*mid-2];
             x3 = array[2*mid];
             y1 = array[2*mid-1];
             y3 = array[2*mid+1];
             return (searchTerm - x1) * (y3-y1) / (x3-x1) + y1;
          }
          else{
            high = mid - 1;

            }
        }
      }
      //end while loop
      return  array[mid*2+1];
    }

}


// int main(){
//
//   float nums[14]= {1.0,2 , 2.0,4,3,8 ,4,16 ,5,32 , 6,64, 7,128};
//
//   printf("Can it return the value? 4: %.2f\n", binary_search(nums,7,4.5));
//   printf("Can it return the value? 6.5: %.2f\n", binary_search(nums,7,6.5));
//   printf("Can it return the value? 7.5: %.2f\n", binary_search(nums,7,7.5));
//
//
//
//
//
// }