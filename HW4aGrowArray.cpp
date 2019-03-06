//author: jiaxian xing
// HW4aGrowArray
// notice: File name is "convexhullpoints.dat" current file path
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

class point
{
  public:
    double x, y;
};

class GrowArray //array of point
{
  public:
    point *data; //each data is a point;
    int len;

  private:
    int capacity;
    void grow() // O(n)
    {           // double the size
        if (capacity == 0)
        {
            capacity++;
            point *old = data;
            data = new point[capacity];
            delete[] old;
        }
        else
        {
            capacity = capacity * 2;
            point *old = data;
            data = new point[capacity];
            for (int i = 0; i < len; i++)
            {
                data[i] = old[i];
            }
            delete[] old;
        }
        // cout << "test test grow capacity: " << capacity << " \n";
    }

  public:
    GrowArray()
    {
        data = nullptr;
        len = 0;
        capacity = 0;
    }

    void insert(int pos, point val)
    {
        if (len + 1 > capacity)
            grow();
        for (int i = pos + 1; i <= len; i++)
            data[i] = data[i - 1];
        data[pos] = val;
    }

    void addEnd(point val)
    {
        if (len + 1 > capacity)
            grow();
        data[len] = val; // O(1)
        len++;
    }

    void addStart(point val)
    {
        if (len + 1 > capacity)
            grow();
        for (int i = 1; i <= len; i++)
            data[i] = data[i - 1];
        data[0] = val;
        len++;
    }

    void removeStart()
    {
        for (int i = 1; i < len; i++) // move each one forward
            data[i - 1] = data[i];
        // data[len - 1]; // last one element don't have value
        len--;
    }

    void removeEnd()
    {
        // data[len - 1];//do not have value
        len--;
    }

    // void remove(int pos);

    int size() const
    {
        return len;
    }

    point get(int pos)
    {
        return data[pos - 1];
    }

    void set(int pos, point val)
    {
        data[pos - 1] = val;
    }

    tuple<int, int, int, int, double, double> findBox(int n) // O(n)
    {
        int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
        for (int i = 0; i < len; i++) //single pass through the data
        {
            if (data[xmin].x > data[i].x)
                xmin = i;
            if (data[xmax].x < data[i].x)
                xmax = i;
            if (data[ymin].y > data[i].y)
                ymin = i;
            if (data[ymax].y < data[i].y)
                ymax = i;
        }
        double XperBox = (data[xmax].x - data[xmin].x) / (n - 1);
        double YperBox = (data[ymax].y - data[ymin].y) / (n - 1);
        // cout << "test test " << xmin << " " << xmax << " " << ymax << " " << ymin << "\n";
        // cout << "test test " << data[xmin].x << " " << data[xmax].x << " " << data[ymax].y << " " << data[ymin].y << "\n";
        return make_tuple(xmin, xmax, ymin, ymax, XperBox, YperBox);
    }
};

void readFile(string fileName, GrowArray &all)
{
    ifstream file(fileName); //open the file
    if (file.is_open())
    {
        int count = 1;
        while (!file.eof())
        {
            point p;
            if (file.eof())
                break;
            else
            {
                if (count % 2 == 1)
                {
                    file >> p.x;
                    file >> p.y;
                }
                else if (count % 2 == 0)
                    ;
                all.addEnd(p);
                // cout << "test test "
                //      << "p: " << p.x << " " << p.y << "\n";
            }
        }
        file.close();
        // cout << "the entire file content is in memory\n";
    }
    else
        cout << "Unable to open file\n";
}

class box//use this class type to store all the growarray
{
  public:
    GrowArray *data;
    int pos;
    int len = 256;
    box() : pos(0)
    {
        data = new GrowArray[len];
    }
    void addEnd(GrowArray &g)
    {
        data[pos++] = g;
    }
};

int main()
{
    // get all points in array;
    GrowArray all;
    readFile("convexhullpoints.dat", all);

    // get the boundary of the x, y; also calculate what each little box length is,when divide to n * n  box;
    int n = 16;
    int xmin, xmax, ymin, ymax;
    double XperBox, YperBox;
    tie(xmin, xmax, ymin, ymax, XperBox, YperBox) = all.findBox(n);

    // create grow array for each cell; 16 *16 = 256
    box b;
    for (int gridx = 0; gridx < n; gridx++) // grid is grid boundary value of box
    {
        for (int gridy = 0; gridy < n; gridy++)
        {
            double i = gridx * XperBox;
            double j = gridy * YperBox;
            GrowArray g = GrowArray();
            b.addEnd(g);
            // cout << gridx * 16 + gridy <<" create growarray (i,j)" <<  " " << i << " " << j << "\n";
        }
    }

    // assign point; for each point
    for (int i = 0; i < all.len; i++)
    {
        int grid = int((all.data[i].x - all.data[xmin].x) / XperBox) * 16 + int((all.data[i].y - all.data[ymin].y) / YperBox);
        b.data[grid].addEnd(all.data[i]);
    }

    // display each grid points number
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout <<"cell("<< i << "," << j << ")" << ": " << b.data[i].len<< "\t";
        cout << "\n";
    }
}