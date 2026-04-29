# Round-Robin-Choice-Maker
Simple command line program that pits a list of items against one-another in round robin format. Meant to be used to make ranking items or making choices from many options easier.

The program only supports ASCII characters in team names.

### Installation
Use c compiler of choice to compile `Ranker.c`. The program itself only used standard C libraries and has no header. Best to treat it like a simple script.

E.g. `gcc Ranker.c -o  Ranker` if using gcc on linux.


### Usage
The program takes the name of the file containing the list of "teams" as its first an only argument. The file should be a text file with each team on its own line. The file should also end in a newline.

E.g. tester.txt
```
team 1
team 2
team 3

```
(More input samples can be found in the `sample inputs` folder)

Run with:
`./Ranker tester.txt`

The program will print some information about its setup, then ask you to choose an team for the first "round robin turn". It will continue this for all the remaining turns, then print out the teams ordered by total win count.

E.g. after running the above command:
```
Input check passed

Opened file

Read 3 teams

Team list:
Team 0: team 1
Team 1: team 2
Team 2: team 3
Printed all teams

Created blank array

Choose 1 or 2:
1: team 1
2: team 2
```
The user may then input 1 or 2 to pick their preferred option for all the remaining promts:
```
cont...

Choose 1 or 2:
1: team 1
2: team 2
1

Choose 1 or 2:
1: team 1
2: team 3
1

Choose 1 or 2:
1: team 2
2: team 3
1

Choice portion done

Sorted array created

Winners:
team 1: 2
team 2: 1
team 3: 0

Winners printed
```