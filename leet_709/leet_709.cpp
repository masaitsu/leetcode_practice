#define M_UPPERCASE_A       ( (uint8_t)'A' )
#define M_UPPERCASE_Z       ( (uint8_t)'Z' )
#define M_UPPER_TO_LOWER    ( (uint8_t)32 )

class Solution {
public:
    string toLowerCase( string str ) {
        std:string ret( str.length(), '\0' );
        
        for( uint8_t str_index = 0 ; str_index < str.length() ; str_index++ )
        {
            if( ( M_UPPERCASE_A <= (uint8_t)str[str_index] )&&
                ( M_UPPERCASE_Z >= (uint8_t)str[str_index] ) )
            {
                ret[str_index] = (char)( (uint8_t)str[str_index] + M_UPPER_TO_LOWER );
            }
            else
            {
                ret[str_index] = str[str_index];
            }
        }
        
        return ret;
    }
};
