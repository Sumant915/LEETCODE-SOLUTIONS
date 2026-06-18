class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutes_angle=minutes*6;
        double hour_angle=hour*30+0.5*minutes;
        double ans=abs(minutes_angle-hour_angle);
        return min(ans,360-ans);
    }
};