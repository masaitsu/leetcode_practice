#define     M_ROW_COL_MIN   ( (uint8_t) 1 )
#define     M_ROW_COL_MAX   ( (uint8_t) 50 )
#define     M_HEIGHT_MIN    ( (uint8_t) 0 )
#define     M_HEIGHT_MAX    ( (uint8_t) 100 )

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if( ( grid.size()       ==  grid[0].size()   )&&
            ( M_ROW_COL_MIN     <=  grid.size()     )&&
            ( M_ROW_COL_MAX     >=  grid.size()     ) )
        {
            int         ret = 0;
            uint8_t     row_index = 0;
            uint8_t     col_index = 0;
            int         top_btm[grid.size()];
            int         lft_rgt[grid.size()];
            
            /*** initialize ***/
            for( uint8_t index = 0 ; index < grid.size() ; index++ )
            {
                top_btm[index] = 0;
                lft_rgt[index] = 0;
            }
            
            /*** search skyline ***/
            for( row_index = 0 ; row_index < grid.size() ; row_index++ )
            {
                for( col_index = 0 ; col_index < grid.size() ; col_index++ )
                {
                    if( M_HEIGHT_MAX >= grid[row_index][col_index] )
                    {
                        /*** top bottom ***/
                        if( grid[row_index][col_index] > top_btm[col_index] )
                        {
                            top_btm[col_index] = grid[row_index][col_index];
                        }
                        
                        /*** left right ***/
                        if( grid[row_index][col_index] > lft_rgt[row_index] )
                        {
                            lft_rgt[row_index] = grid[row_index][col_index];
                        }
                    }
                    else
                    {
                        return ( -1 );
                    }
                }
            }
            
            /*** increase height ***/
            for( row_index = 0 ; row_index < grid.size() ; row_index++ )
            {
                for( col_index = 0 ; col_index < grid.size() ; col_index++ )
                {
                    if( top_btm[col_index] > lft_rgt[row_index])
                    {
                        ret += ( lft_rgt[row_index] - grid[row_index][col_index] );
                    }
                    else
                    {
                        ret += ( top_btm[col_index] - grid[row_index][col_index] );
                    }
                }
            }
            
            return (ret);
        }
        return (-1);
    }
};
