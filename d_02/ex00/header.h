#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
	struct s_stone {
		int size;
		struct s_stone *next;
	};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_group {
	int				size;
	struct s_stone	*head;
	struct s_stone	*end;
};

struct s_group **group_stones(struct s_stone *stone, int *max);
void combine_group(struct s_group **group, int max);

#endif
