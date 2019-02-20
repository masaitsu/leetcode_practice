#define M_EMAIL_MAX_NUM         ( (uint8_t)100 )
#define M_EMAIL_MAX_LEN         ( (uint8_t)100 )

#define M_STR_ASCII_AT          ( '@' )
#define M_STR_ASCII_PERIOD      ( '.' )
#define M_STR_ASCII_PLUS        ( '+' )


class Solution
{
public:
    int numUniqueEmails(vector<string>& emails)
    {
        uint8_t email_num = (uint8_t)(emails.size());
        
        if( M_EMAIL_MAX_NUM >= email_num )
        {
            int ret = 0;
//            vector<string> local_tmp(email_num);
//            vector<string> domain_tmp(email_num);
            vector<string> all_tmp(email_num);
            
            for( uint8_t listindex = 0 ; listindex < email_num ; listindex++ )
            {
                uint8_t email_len = (uint8_t)(emails[listindex].length());
                
                /*** 文字列操作 ***/
                if( M_EMAIL_MAX_LEN >= email_len )
                {
                    uint8_t email_search_index = 0;
                    bool find_at = false;
                    bool find_plus = false;
                    
                    while( email_search_index < email_len )
                    {
                        if(find_at)
                        {
                            /* @以降の処理 */
//                            domain_tmp[listindex] += emails[listindex][email_search_index];
                            all_tmp[listindex] += emails[listindex][email_search_index];
                        }
                        else
                        {
                            /* @以前の処理 */
                            if( emails[listindex][email_search_index] == M_STR_ASCII_PERIOD )
                            {
                                /* Do Notinhg */
                            }
                            else if( emails[listindex][email_search_index] == M_STR_ASCII_AT )
                            {
                                find_at = true;
                            }
                            else if( emails[listindex][email_search_index] == M_STR_ASCII_PLUS )
                            {
                                find_plus = true;
                            }
                            else
                            {
                                if(!find_plus)
                                {
//                                    local_tmp[listindex] += emails[listindex][email_search_index];
                                    all_tmp[listindex] += emails[listindex][email_search_index];
                                }
                            }
                        }
                        email_search_index++;
                    }
//                    cout << all_tmp[listindex] << endl;
                }
                
                /*** Count ***/
                uint8_t list_search_index = 0;

                for( list_search_index = 0 ; list_search_index < listindex ; list_search_index++ )
                {
                    if( all_tmp[listindex] == all_tmp[list_search_index] )
                    {
                        break;
                    }
                }
                if( list_search_index == listindex )
                {
                    ret++;
                }
            }
            return ret;
        }
        return -1;
    }
};