#define M_MAX_LEN ((uint8_t)50)

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if( ( M_MAX_LEN < (uint8_t)(J.length()) )||
            ( M_MAX_LEN < (uint8_t)(S.length()) ))
        {
            return -1;
        }
        else
        {
            uint8_t ret = 0;
            uint8_t jewel_num = (uint8_t)(J.length());
            uint8_t stone_num = (uint8_t)(S.length());
            
            for( uint8_t jewel_index = 0 ; jewel_index < jewel_num ; jewel_index++ )
            {
                bool skip_flg = false;
                for( uint8_t jewel_search_index = ( jewel_index + 1 ) ; jewel_search_index < jewel_num ; jewel_search_index++ )
                {
                    if( J[jewel_index] == J[jewel_search_index] )
                    {
                        skip_flg = true;
                        break;
                    }
                }
                if(!skip_flg)
                {
                    for( uint8_t stone_index = 0 ; stone_index < stone_num ; stone_index++ )
                    {
                        if(J[jewel_index] == S[stone_index])
                        {
                            ret++;
                        }
                    }
                }
            }
            return (ret);
        }
    }
};