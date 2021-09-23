#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 1000

char input[MAX];
char inv[10][20];
int inv_size = 5;
int first_time = 0;
int f1 = 0, f2 = 0, f3 = 0, f3n = 0, f4 = 0;
int xpos = 0, ypos = 0;
int hidden_place = 0;
int old_planks = 0;
int old_paper = 0;
int nails = 0;
int counter = 0;
int bridge_fixed = 0;
int chest = 0;
int alive = 1;

void help() {
    if (strcmp(input, "help") == 0) {
        if (first_time == 0) {
            printf("So you need help huh?... Typical amateurs\n");
            printf("Let me get this straight!\n");
            printf("You don't know what to do or just inputed the first thing i asked you to do?\n");
            printf("Well... since this is your first time, i will help you out\n");
            first_time = 1;
        }
            printf("1: Always try to 'look around' in every area\n");
            printf("There might be something you overlooked\n");
            printf("2: Try go in the cardinal directions, such as 'go north' or 'go west'\n");
            printf("3: Or try typing 'map' to get a sence where you are in the world\n");
            printf("4: You can also see your inventory by typing 'inv' or 'inventory'\n");
            printf("5: The keyword for grabbing stuff is 'grab <insert item here>'\n\n");
    }
}

void easter_eggs(char input[]) {
    if ((strcmp(input, "stab yourself") == 0) && nails == 1) {
        printf("YOU DIED OF CLOSTRIDIUM TETANI\n");
        printf("If you don't know what that is then you are a pessant\n");
        alive = 0;
    }
}

void map(char input[]) {
    if (strcmp(input, "map") == 0) {
        if (xpos == 0 && ypos == 0) {
            printf("        [ ][ ]-[ ]   \n");
            printf("     [ ][x]          \n");
            printf("     [ ][ ][ ]       \n");
        } else if (xpos == 0 && ypos == 1) {
            printf("        [x][ ]-[ ]   \n");
            printf("     [ ][ ]          \n");
            printf("     [ ][ ][ ]       \n");
        } else if (xpos == 1 && ypos == 1) {
            printf("        [ ][x]-[ ]   \n");
            printf("     [ ][ ]          \n");
            printf("     [ ][ ][ ]       \n");
        } else if (xpos == 2 && ypos == 1) {
            printf("        [ ][ ]-[x]   \n");
            printf("     [ ][ ]          \n");
            printf("     [ ][ ][ ]       \n");
        } else if (xpos == -1 && ypos == 0) {
            printf("        [ ][ ]-[ ]   \n");
            printf("     [x][ ]          \n");
            printf("     [ ][ ][ ]       \n");
        } else if (xpos == -1 && ypos == -1) {
            printf("        [ ][ ]-[ ]   \n");
            printf("     [ ][ ]          \n");
            printf("     [x][ ][ ]       \n");
        } else if (xpos == 0 && ypos == -1) {
            printf("        [ ][ ]-[ ]   \n");
            printf("     [ ][ ]          \n");
            printf("     [ ][x][ ]       \n");
        } else if (xpos == 1 && ypos == -1) {
            printf("        [ ][ ]-[ ]   \n");
            printf("     [ ][ ]          \n");
            printf("     [ ][ ][x]       \n");
        } else {  
            printf("Where the fuck are you!!!???, please call me: 97071741");
        }
    }
}

void user_pos(int xPos, int yPos) {
    xpos = xpos + xPos;
    ypos = ypos + yPos;
}

void cardinal_directions(char input[]) {
    if (strcmp(input, "go north") == 0) {
        if ((xpos == 0 && ypos == 1) || (xpos == -1 && ypos == 0) || (xpos == 1 && ypos == -1) || (xpos == 1 && ypos == 1) || (xpos == 2 && ypos == 1)) {
            printf("The path is gone, you can't go there\n");
        } else {
            printf("You walked north\n");
            user_pos(0, 1);
        }
    } 
    
    else if (strcmp(input, "go south") == 0) {
        if ((xpos == 0 && ypos == -1) || (xpos == -1 && ypos == -1) || (xpos == 1 && ypos == 1) || (xpos == 2 && ypos == 1) || (xpos == 1 && ypos == -2) || ((xpos == 1 && ypos == -1) && hidden_place == 0)) {
            printf("The path is gone, you can't go there\n");
        } else {
            printf("You walked south\n");
            user_pos(0, -1);
        }
    } 
    
    else if (strcmp(input, "go east") == 0) {
        if ((xpos == 0 && ypos == 0) || (xpos == 1 && ypos == -1) || (xpos == 2 && ypos == 1) || (xpos == 1 && ypos == -2) || (xpos == 1 && ypos == 1) && bridge_fixed == 0) {
            printf("The path is gone, you can't go there\n");
        } else {
            printf("You walked east\n");
            user_pos(1, 0);
        }
    } 
    
    else if (strcmp(input, "go west") == 0) {
        if ((xpos == 0 && ypos == 1) || (xpos == -1 && ypos == 0) || (xpos == -1 && ypos == -1) || (xpos == 1 && ypos == -2)) {
            printf("The path is gone, you can't go there\n");
        } else {
            printf("You walked west\n");
            user_pos(-1, 0);
        }
    }
}

void look_around(char input[]) {
    if (strcmp(input, "look around") == 0) {
        
        // Spawn
        if (xpos == 0 && ypos == 0) {
            printf("You see a rock with some strange writings on it\n");
            printf("It doesn't make sence and it looks ancient\n");
            printf("And i think you give a big F anyway\n");
        }

        // Where the bridge is, [1,1]
        if (xpos == 1 && ypos == 1) {
            if (old_planks == 0 && nails == 0 && f3 == 0) {
                printf("There is a broken bridge to the east over a valley\n");
                printf("And by broken, i mean it is missing planks\n");
                printf("So if you don't have planks and nails to fix it, then im sorry to say:\n");
                printf("YOU SHALL NOT PASS!!!!! (explosions sounds)\n");
                f3 = 1;
            } else if (old_planks == 0 && nails == 0 && f3 == 1) {
                printf("I don't want to repeat myself\n");
                printf("Go and get some planks and nails, and only then talk to me\n");
            } else if (old_planks == 0 && nails == 1 && f3 == 0) {
                printf("There is a broken bridge to the east over a valley\n");
                printf("And by broken, i mean it is missing planks\n");
                printf("I can see that you have aquired nails, so that good\n");
                printf("But you can't cross a bridge with only nails, can you?\n");
                printf("I THINK NOT!!! (refrencce to The Incredibles)\n");
                f3 = 1;
            } else if (old_planks == 1 && nails == 0 && f3 == 0) {
                printf("There is a broken bridge to the east over a valley\n");
                printf("And by broken, i mean it is missing some nails\n");
                printf("I can see that you have aquired some planks, so that good\n");
                printf("But you can't cross a bridge with only planks, can you?\n");
                printf("I THINK NOT!!! (refrencce to The Incredibles)\n");
                f3 = 1;
            } else if (old_planks == 1 && nails == 0 && f3 == 1) {
                printf("By now i think you understand what you need right?\n");
                printf("SOME NAILS YOU IDIOT!\n");
                printf("So go and get some");
            } else if (old_planks == 1 && nails == 1 && f3 == 0) {
                printf("There is a broken bridge to the east over a valley\n");
                printf("And coincidentally, you've got everything you need to cross the bridge\n");
                printf("So you just have to say the word, 'fix bridge' or 'suck on these nutz'\n");
                f3 = 1;
            } else if (old_planks == 0 && nails == 1 && f3 == 1) {
                printf("I said it already but i can copy the other lines of code so i have less work\n");
                printf("There is a broken bridge to the east over a valley\n");
                printf("And by broken, i mean it is missing some nails\n");
                printf("I can see that you have aquired some planks, so that good\n");
                printf("But you can't cross a bridge with only planks, can you?\n");
                printf("I THINK NOT!!! (refrencce to The Incredibles)\n");
            } else if (old_planks == 1 && nails == 1 && f3 == 1) {
                printf("Either i've just said what your should do or you are kinda dumb\n");
                printf("But just say 'fix bridge'\n");
            }
        }

        // Where the planks and old papers are, [1,-1]
        if (xpos == 1 && ypos == -1) {
            if (old_paper == 0 && old_planks == 0 && f2 == 0) {
                printf("There is a scrap of old paper laying next to some planks\n");
                printf("I would recommend not to grab those planks, they might have corona on it\n");
                printf("I mean, it's your decision, to be or not to be alive anymore\n");
                f2 = 1;
            } else if (old_paper == 0 && old_planks == 0 && f2 == 1) {
                printf("Omg, you don't listen\n");
                printf("There is the fucking piece of paper and some fucking planks next to you!\n");
            } else if (old_paper == 0 && old_planks == 1 && f2 == 0) {
                printf("There are a piece of old paper by your side if you want it\n");
                printf("And stop grabbing things you didn't know were there\n");
                f2 = 1;
            } else if (old_paper == 1 && old_planks == 0 && f2 == 0) {
                printf("I still don't know how you knew there was paper there, but anyway\n");
                printf("There is some old planks to your leg\n");
                f2 = 1;
            } else if (old_paper == 0 && old_planks == 1 && f2 == 1) {
                printf("There is still the paper i said earlier if you did listen\n");
            } else if (old_paper == 1 && old_planks == 1 && f2 == 0) {
                printf("You are a cheater!\n");
                printf("Yeah i said it, whatcha gonna do now punk?\n");
                printf("Cry on your moms lap? I DON'T THINK SO!\n");
                f2 = 1;
            } else if (old_paper == 1 && old_planks == 0 && f2 == 1) {
                printf("There are some old planks next to your poisonous hairy leg\n");
            } else if (old_paper == 1 && old_planks == 1 && f2 == 1) {
                printf("I think your bacteria has scared away the important things here\n");
                printf("Move on you fat pig\n");
            }
        }

        // Where the nails are, [0, 1]
        if (xpos == 0 && ypos == 1) {
            if (f1 == 0 && nails == 0) {
                printf("Let me tell you something\n");
                printf("Do you think a girrafe would swim on their back or on their tummy?\n");
                printf("I don't care anyway what you think\n");
                printf("But what i can tell you is that there are some nails laying on a burnt firepit\n");
                f1 = 1;
            } else if (f1 == 0 && nails == 1) {
                printf("There is nothing here you idiot\n");
            } else if (f1 == 1 && nails == 0) {
                printf("Once again, there are some nails at you right foot\n");
                printf("In that burnt firepit, but that you already knew\n");
            } else if (f1 == 1 && nails == 1) {
                printf("There is nothing more to see than your curiosity\n");
            }
        }

        // Where the chest is, [0,-1]
        if (xpos == 0 && ypos == -1) {
            if (f3 == 0 && chest == 0 && f3n == 0) {
                printf("There is a chest with a lock on it\n");
                printf("You must find a key or something that fits\n");
                printf("And no! You can't put your dick in it, perv\n");
                f3 = 1;
            } else if (f3 == 1 && chest == 0 && f3n == 0) {
                printf("The chest hasn't moved since last time you asked\n");
            } else if (f3 == 1 && chest == 1 && f3n == 0) {
                printf("There is nothing more to see, i think\n");
                f3n = 1;
            } else if (f3 == 1 && chest == 1 && f3n == 1) {
                printf("AHA FOOLED YOU!! THERE WAS NOTHING HERE AFTER ALL MOAHAHAHA!!!");
            }
        }
        
        if (xpos == -1 && ypos == 0) {
            printf("Not Implemeted Yet");
        }
        if (xpos == -1 && ypos == -1) {
            printf("Not Implemeted Yet");
        }
    }   
}

void grab_things(char input[]) {
    // Where the old planks and paper is, [1,-1]
    if (xpos == 1 && ypos == -1) {
        if (((strcmp(input, "grab planks") == 0) || (strcmp(input, "grab old planks") == 0)) && old_planks == 0) {
            if (f2 == 0) {
                printf("WTF MAN, stop cheating, have your patetic planks\n");
            }
            printf("\n** YOU AQUIRED PLANKS! **\n");
            printf("Don't worry about the text in caps, it's just there i guess\n");
            printf("I didn't make the game or anything :)\n");
            stpcpy(inv[counter], "Old Planks");
            old_planks = 1;
            counter++;
        }
        if (((strcmp(input, "grab paper") == 0) || (strcmp(input, "grab old paper") == 0)) && old_paper == 0) {
            if (f2 == 0) {
                printf("HOW THE FUCK DID YOU KNOW THERE WAS PAPER THERE?!?\n");
                printf("Like wtf\n");
            }
                printf("\n** YOU AQUIRED PAPER! **\n");
                printf("How do you feel now?, I think i know the answer\n");
                printf("A4\n");
                stpcpy(inv[counter], "Old Paper");
                old_paper = 1;
                counter++;
        }
    }

    // Where the nails is, [0,1]
    if (xpos == 0, ypos == 1) {
        if ((strcmp(input, "grab nails") == 0) && nails == 0) {
            if (f1 == 0) {
                printf("How did you know that there were nails here?...\n");
                printf("#EXPOSED, either you have a bigger brain than your cat\n");
                printf("Or you are just a dickhead that played this game before\n");
                printf("Either way, we can conclude that you are a twat, case closed\n");
            }
            printf("\n** YOU AQUIRED NAILS! **\n");
            printf("Bitch please, don't stab yourself\n");
            stpcpy(inv[counter], "Nails");
            nails = 1;
            counter++;
        }
    }

    // Spawn
    if (xpos == 0, ypos == 0) {
        if (strcmp(input, "grab rock") == 0) {
            printf("Yeahhhh, no, you can't do that i am afraid\n");
        }
    }

    // Where the chest is, [0,-1]
    if (xpos == 0 && ypos == -1) {
        if (strcmp(input, "grab chest") == 0) {
            printf("You have to become Captain Sabertooth to get that\n");
            printf("And for what i can see, you are not him, thankfully\n");
        }
    }
} 

void fix_bridge(char input[]) {
    if (strcmp(input, "fix bridge") == 0) {
        if (old_planks == 0 && nails == 0 && f3 == 0) {
            printf("I have two questions here young wierdo\n");
            printf("1. How did you know there was a bridge here that needed fixing?!\n");
            printf("2. How do you expect to fix a bridge with nothing to fix with?\n");
            printf("Get yourself some items before fixing\n");
        } else if (old_planks == 0 && nails == 0 && f3 == 1) {
            printf("I have just 1 questions wierdo\n");
            printf("1. How do you expect to fix a bridge with nothing to fix with?\n");
            printf("Get yourself some items before fixing\n");
        } else if (old_planks == 0 && nails == 1 && f3 == 0) {
            printf("I have two questions here young wierdo\n");
            printf("1. How did you know there was a bridge here that needed fixing?!\n");
            printf("2. How do you expect to fix a bridge with just nails to fix with?\n");
            printf("Get yourself some planks before fixing\n");
        } else if (old_planks == 1 && nails == 0 && f3 == 0) {
            printf("I have two questions here young wierdo\n");
            printf("1. How did you know there was a bridge here that needed fixing?!\n");
            printf("2. How do you expect to fix a bridge with just planks to fix with?\n");
            printf("Get yourself some nails before fixing\n");
        } else if (old_planks == 0 && nails == 1 && f3 == 1) {
            printf("You just need some planks and then you are good to go\n");
        } else if (old_planks == 1 && nails == 0 && f3 == 1) {
            printf("You just need some nails and then you are good to go\n");
        } else if (old_planks == 1 && nails == 1 && f3 == 0) {
            printf("HOW THE FUCK DO YOU KNOW THAT THE BRIDGE NEEDS FIXING?\n");
            printf("Fuck you and your planks and nails\n");
            printf("The bridge is build now... go on\n");
            for (int j = 0; j < inv_size; j++) {
                if (strcmp(inv[j], "Old Planks") == 0) {
                    for (int i = j; i < inv_size; i++) {
                        stpcpy(inv[i], inv[i+1]);
                    }
                }
            }
            for (int j = 0; j < inv_size; j++) {
                if (strcmp(inv[j], "Nails") == 0) {
                    for (int i = j; i < inv_size; i++) {
                        stpcpy(inv[i], inv[i+1]);
                    }
                }
            }
            counter--;
            counter--;
            bridge_fixed = 1;
        } else if (old_planks == 1 && nails == 1 && f3 == 1) {
            printf("You have everything you need\n");
            printf("You've done well young padawan, now go over to the other side\n"); 
            bridge_fixed = 1;
        }
    }
}

void inventory() {
    if ((strcmp(input, "inv") == 0) || (strcmp(input, "inventory") == 0)) {
        printf("\nYour inventory is:\n");
        for (int i = 0; i < inv_size; i++) {
            printf("- %s\n", inv + i);
        }
    }
}

void menu() {

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Welcome to this game\n");
    printf("Right now you are alone\n");
    printf("No one is here except you\n");
    printf("You probably wonder who i am\n\n");
    printf("...........Well i can tell you\n");
    printf("I am your imagination, uuuuuuuuuu\n");
    printf("If you ever feel like you're stuck (like your stepsister), just type 'help'\n");
    printf("Well do something, you slob\n\n");

    while(fgets(input, MAX, stdin)) {
        input[strlen(input)-1] = '\0';

        help(input);

        inventory(input);

        fix_bridge(input);

        cardinal_directions(input);

        look_around(input);

        map(input);

        grab_things(input);

        easter_eggs(input);
    }
}

int main() {
    if (alive == 1) { 
        menu();
    }
    return 0;
}

// Map
//         [Nails][Broken Bridge-] - []
//  [-----][Spawn]
//  [-----][-----][Planks'n paper]
//                [Hidden--------]
