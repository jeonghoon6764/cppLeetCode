class Solution {
    /*
    LeetCode Problem 54
    Spiral Matrix

    complexity analysis:
    Time Complexity: O(n*m)
    Space Complexity: O(1) except output vectors
    */
public:

    enum Direction {
        RIGHT,
        LEFT,
        UP,
        DOWN,
    };

    const int visited = -200;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0;
        int y = 0;

        vector<int> path;
        enum Direction dir = RIGHT;
        do {
            path.push_back(matrix[y][x]);
            matrix[y][x] = visited;
        } while (NextIndex(&dir, &x, &y, matrix));
        
        return path;
    }

    bool NextIndex(Direction* dir, int* x, int* y, vector<vector<int>>& matrix) {
        if (*dir == RIGHT) {
            ++*x;
            if (matrix[0].size() <= *x || matrix[*y][*x] == visited) {
                --*x;
                *dir = DOWN;
            } else {
                return true;
            }
        }
        if (*dir == DOWN) {
            ++*y;
            if (matrix.size() <= *y || matrix[*y][*x]== visited) {
                --*y;
                *dir = LEFT;
            } else {
                return true;
            }
        }
        if (*dir == LEFT) {
            --*x;
            if (0 > *x || matrix[*y][*x] == visited) {
                ++*x;
                *dir = UP;
            } else {
                return true;
            }
        }
        if (*dir == UP) {
            --*y;
            if (0 > *y || matrix[*y][*x] == visited) {
                ++*y;
                *dir = RIGHT;
            } else {
                return true;
            }
        }
        if (*dir == RIGHT) {
            ++*x;
            if (matrix[0].size() <= *x || matrix[*y][*x] == visited) {
                --*x;
                *dir = DOWN;
            } else {
                return true;
            }
        }
        if (*dir == DOWN) {
            ++*y;
            if (matrix.size() <= *y || matrix[*y][*x]== visited) {
                --*y;
                *dir = LEFT;
            } else {
                return true;
            }
        }
        if (*dir == LEFT) {
            --*x;
            if (0 > *x || matrix[*y][*x] == visited) {
                ++*x;
                *dir = UP;
            } else {
                return true;
            }
        }
        return false;
    }
};