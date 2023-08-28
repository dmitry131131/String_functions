#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#include "Source\StringFunctions.h"

int main()
{
    /*
    char* tex = (char*) calloc(258, sizeof(char));
    size_t n = 258;

    printf("%d\n", getline_custom(&tex, &n, stdin));

    printf("%d\n", n);

    printf("%s", tex);

    free(tex);
    */

   const char* text = " Those hours that with gentle work did frame\n"
                        "The lovely gaze where every eye doth dwell\n"
                        "Will play the tyrants to the very same,\n"
                        "And that unfair which fairly doth excel;\n"
                        "For never-resting time leads summer on\n"
                        "To hideous winter and confounds him there,\n"
                        "Sap checked with frost and lusty leaves quite gone,\n"
                        "Beauty o'ersnowed and bareness every where:\n"
                        "Then were not summer's distillation left\n"
                        "A liquid prisoner pent in walls of glass,\n"
                        "Beauty's effect with beauty were bereft,\n"
                        "Nor it nor no remembrance what it was.\n"
                        "But flowers distilled, though they with winter meet,\n"
                        "Leese but their show; their substance still lives sweet.\n"
                        "Then let not winter's ragged hand deface\n"
                        "In thee thy summer ere thou be distilled:\n"     
                        "Make sweet some vial; treasure thou some place\n"
                        "With beauty's treasure ere it be self-killed:\n"
                        "That use is not forbidden usury\n"
                        "Which happies those that pay the willing loan;\n"
                        "That's for thyself to breed another thee,\n"
                        "Or ten times happier be it ten for one;\n"
                        "Ten times thyself were happier than thou art,\n"
                        "If ten of thine ten times refigured thee:\n"
                        "Then what could death do if thou shouldst depart,\n"
                        "Leaving thee living in posterity?\n"
                        "Be not self-willed, for thou art much too fair\n"
                        "To be death's conquest and make worms thine heir.";

    printf("%d\n", strstrC_custom(text, "That's for thyself to breedanother the"));

    printf("%d", (clock()));

    return 0;
}