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
1: with 2 wins, team 1
2: with 1 wins, team 2
3: with 0 wins, team 3

Winners printed
```

### Notes
Ran this with 40 games (list in sample inputs) to find out which was my favourite, my results are below. Feel free to clone this repo and add your results for the same 40 games (or others!) to this readme section; I'd be happy to merge any.
Be warned though, 40 games is (40*39)/2 choices, which as my 1 and 2 keys have recently learned, is not a small amount :).

Kira's 40-games results:
```
Winners:
0: with 40 wins, Clair Obscur
1: with 39 wins, Outer WIlds
2: with 38 wins, Disco
3: with 36 wins, Return of The Obra Dinn
4: with 35 wins, Bioshock
5: with 35 wins, Ori and the WOtW
6: with 34 wins, Silksong
7: with 32 wins, Portal 2
8: with 31 wins, A Highland Song
9: with 31 wins, Journey
10: with 31 wins, What remains of Edith Finch
11: with 29 wins, Sable
12: with 27 wins, Split Fiction
13: with 26 wins, A Hat In Time
14: with 26 wins, Jusant
15: with 25 wins, Dishonored 2
16: with 24 wins, Chants of Sennaar
17: with 21 wins, Deathloop
18: with 21 wins, The Entropy Center
19: with 21 wins, Hi-Fi Rush
20: with 21 wins, Mirrors Edge Catalyst
21: with 20 wins, Ori and the BF
22: with 17 wins, Bioshock Infinite
23: with 15 wins, Elden Ring
24: with 15 wins, Hollow Knight
25: with 15 wins, Sword of the Sea
26: with 14 wins, The Pathless
27: with 13 wins, Maniforld Garden
28: with 13 wins, Portal
29: with 12 wins, It Takes Two
30: with 12 wins, Spyro
31: with 11 wins, Dishonored
32: with 8 wins, Hitman
33: with 7 wins, Sekiro
34: with 5 wins, Abzu
35: with 5 wins, Raft
36: with 5 wins, Rise of the Tomb Rainder
37: with 4 wins, The Bookwalker
38: with 4 wins, Tom Raider
39: with 2 wins, The Outer Worlds
40: with 0 wins, Omno
```