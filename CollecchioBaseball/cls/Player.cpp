//
// Created by andrew-drink on 10/06/23.
//

#include "Player.h"
#include <vector>

void initialize( Player* p ) {
    p[0] = Player( "Andrea", "Center Field", false, true );
    p[1] = Player( "Zambo", "Left Field", false, true );
    p[2] = Player( "Alinovi", "Right Field", true, false );
    p[3] = Player( "Nava", "Right Field e Catcher", false, true );
    p[4] = Player( "Pi", "Second Base", false, true );
    p[5] = Player( "Bue", "First Base e Right Field", false, true );
    p[6] = Player( "Buzzo", "Pitcher", true, false );
    p[7] = Player( "Code", "Pitcher e Left Field", false, true );
    p[8] = Player( "Mutti", "Third Base", true, false );
    p[9] = Player( "Pagano", "Third Base", true, false );
    p[10] = Player( "Gabbo", "Third Base", true, true );
    p[11] = Player( "San", "Pitcher", true, true );
    p[12] = Player( "Schiaro", "Third Base, Shortstop e Pitcher", false, true );
    p[13] = Player( "Filli", "Shortstop", true, true );
    p[14] = Player( "Pella", "Pitcher", true, true );
    p[15] = Player( "Cigolo", "Left Field", true, false );
    p[16] = Player();
}

string wb[20] = { "chi è il migliore?", "chi è il migliore ?", "chi sono i migliori?", "chi sono i migliori ?", "è il migliore ?", "è il migliore?", "is the best ?", "is the best?" };
string wg[20] = { "è gay?", "è gay ?", "è omosessuale ?", "è omosessuale?", "gli piace il cazzo?", "gli piace il cazzo ?" };

bool isInside( string s ) {
    for ( s )
}

int searchSpace( string s ) {
    for ( int i = 0; i < s.length(); i++ ) {
        if ( s.at(i) == ' ' )
            return i;
    }
    return s.length();
}