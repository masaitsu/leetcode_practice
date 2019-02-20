const = {'M_MAX_LEN':50}

class Solution:
    def numJewelsInStones(self, J: 'str', S: 'str') -> 'int':
        if const['M_MAX_LEN'] < len(J) or\
           const['M_MAX_LEN'] < len(S):
            return -1
        
        else:
            ret = 0
            jewel_num = len(J)
            stone_num = len(S)
            
            for jewel_index in range(jewel_num):
                skip_flg = False
                
                for jewel_search_index in range( jewel_index + 1, jewel_num ):
                    if J[jewel_index] == J[jewel_search_index]:
                        skip_flg = True;
                        break
                        
                if not skip_flg:
                    for stone_index in range( stone_num ):
                        if J[jewel_index] == S[stone_index]:
                            ret += 1
            return ret