class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int nearest_x = max(x1,min(x2,xc));
        int nearest_y = max(y1,min(y2,yc));
        int dist_x = nearest_x - xc;
        int dist_y = nearest_y - yc;
         return dist_x * dist_x + dist_y * dist_y <= radius * radius;
    }
};