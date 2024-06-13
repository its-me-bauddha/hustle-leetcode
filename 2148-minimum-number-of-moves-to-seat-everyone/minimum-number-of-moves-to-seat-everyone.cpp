class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int minMove = 0;
        int s = students.size();
        for(int i=0;i<s;i++){
         minMove += abs(students[i] - seats[i]);
        }

      

        return minMove;

    }
};