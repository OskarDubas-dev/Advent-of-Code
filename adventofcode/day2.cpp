/*
 *
*It seems like the submarine can take a series of commands like forward 1, down 2, or up 3:

forward X increases the horizontal position by X units.
down X increases the depth by X units.
up X decreases the depth by X units.
Note that since you're on a submarine, down and up affect your depth, and so they have the opposite result of what you might expect.

Calculate the horizontal position and depth you would have after following the planned course.
What do you get if you multiply your final horizontal position by your final depth?



--- Part Two ---
Based on your calculations, the planned course doesn't seem to make any sense. You find the submarine manual and discover that the process is actually slightly more complicated.

In addition to horizontal position and depth, you'll also need to track a third value, aim, which also starts at 0. The commands also mean something entirely different than you first thought:

down X increases your aim by X units.
up X decreases your aim by X units.
forward X does two things:
It increases your horizontal position by X units.
It increases your depth by your aim multiplied by X.
*/

#include "day2.h"
#include <iostream>
#include <fstream>
#include <string>


day2::day2()
{
    std::string line;
    int value;
    int horizontal = 0, depth = 0, depthPART2 = 0, aim = 0;
    std::ifstream file("input2.txt");

    if (file.is_open())
    {
        while (file >> line >> value)
        {
            if (line == "forward")
            {
                horizontal += value;
                depthPART2 += (aim * value);
            }
            else if (line == "down")
            {
                depth += value;
                aim += value;
            }
            else if (line == "up")
            {
                depth -= value;
                aim -= value;
            }
        }

        std::cout << "Part 1 answer is: " << horizontal * depth << std::endl;
        std::cout << "Part 2 answer is: " << horizontal * depthPART2 << std::endl;
    }
    file.close();
}
