/*
 * @lc app=leetcode id=853 lang=c
 *
 * [853] Car Fleet
 */

// @lc code=start
   typedef struct 
    {
        int position;
        double time;
    }Car;

    int compare(const void* a, const void* b) {
    Car* carA = (Car*)a;
    Car* carB = (Car*)b;
    return carB->position - carA->position;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) 
{
 

    Car cars[positionSize];
    for(int i=0;i<positionSize;i++)
    {
     cars[i].position=position[i];
     cars[i].time=(target-position[i])/(double)speed[i];
    }
    qsort(cars,positionSize,sizeof(Car),compare);
    int fleet=0;
    double lasttime=0;
    for (int i = 0; i<positionSize; i++)
    {
        if(cars[i].time>lasttime)
        {
            fleet++;
            lasttime=cars[i].time;
        }
    }
    return fleet;
}
// @lc code=end

