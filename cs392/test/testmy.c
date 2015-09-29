/* David ott
 * I pledge my honor that I have abided by the stevens honor system - DO
 * I love C
 * just kidding
 * =)
 */
#include "my.h"

//test function for libmy
int main() {
    //my_char takes in char and prints it
    int i;
    for (i = 0; i < 128; i++) { // testing my_char for all valid characters including null
        my_char(i);
    }
    my_char(-1);
    my_char(128); // should be too big
    my_char("david");
    my_char("");
    my_char('\0');

    //my_int takes in int and prints it
    my_int(0);
    my_int(1);
    my_int(-1);
    my_int(1000);
    my_int(-1000);
    my_int(2147483647); //max int on 32b machine
    my_int(2147483648); //max + 1
    my_int(-2147483647); //min int
    my_int(-2147483648);//min int - 1
    my_int("david");
    my_int('D');
    my_int(1.3);
    my_int("");
    my_int('\0');

    //my_alpha has no input and prints alphabet
    my_alpha();
    //any parameter will cause it not to compile

    //my_digits has no input and prints 0 - 9
    my_digits();
    //no return, can't pass anything in

    //my_str
    my_str(0);
    my_str("david");
    my_str("");
    my_str("asdfkljasdflkjhasdflkjhasdfkljasdfkalsdjfalksjdaklsjdflkasjdaslkdaskjdfaskldjaskljd");
    //my_str(65);
    //my_str('\0');//null char
    //my_str('A');
    my_str("dav\0id"); //null char in string
    //my_str(98723498723);

    //my_revstr
    my_revstr(0);
    my_revstr("david");
    my_revstr("");
    my_revstr("asdfkljasdflkjhasdflkjhasdfkljasdfkalsdjfalksjdaklsjdflkasjdaslkdaskjdfaskldjaskljd");
    //my_revstr(65);
    //my_revstr('\0');//null char
    //my_revstr('A');
    my_revstr("dav\0id"); //null char in string
    //my_revstr(98723498723);

    //my_strindex
    my_int(my_strindex("david", 'a'));
    my_int(my_strindex("david", 'd')); // there are two of them
    my_int(my_strindex("david", 'b')); // not in string
    my_int(my_strindex("david", '\0'));
    my_int(my_strindex("david", ""));
    my_int(my_strindex("", 'a'));
    my_int(my_strindex("dav\0id", 'i')); //should not find i
    my_int(my_strindex(0, 0));

    //my_strrindex
    my_int(my_strrindex("david", 'a'));
    my_int(my_strrindex("david", 'd')); // there are two of them
    my_int(my_strrindex("david", 'b')); // not in string
    my_int(my_strrindex("david", '\0'));
    my_int(my_strrindex("david", ""));
    my_int(my_strrindex("", 'a'));
    my_int(my_strrindex("dav\0id", 'i')); //should not find i
    my_int(my_strrindex(0, 0));

    //my_strlen
    my_int(my_strlen("david"));//should be 5
    my_int(my_strlen("dav\0id"));
    my_int(my_strlen(""));
    my_int(my_strlen(" "));
    //my_int(my_strlen('a'));
    my_int(my_strlen(0));
    //my_int(my_strlen(1234));

    //my_num_base
    my_num_base(0, 0);//print nothing
    my_num_base(0, "david");
    my_num_base(4, 0);
    my_num_base(-4, 0);
    my_num_base(4, "david");//should print d
    my_num_base(-4, "david");//-d
    my_num_base(5, "?");//?????
    my_num_base(-5, "?");
    //my_num_base("", "david");
    my_num_base('z', "david");

}

