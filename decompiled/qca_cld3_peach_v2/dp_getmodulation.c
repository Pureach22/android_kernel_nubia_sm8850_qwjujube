__int64 __fastcall dp_getmodulation(unsigned __int16 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  __int64 v3; // x8
  __int64 v5; // x9

  if ( a1 > 2u )
  {
    switch ( a1 )
    {
      case 3u:
        if ( a2 < 4u )
          return dp_getmodulation__vht_bw_mod[a2];
        goto LABEL_34;
      case 4u:
        if ( a2 <= 3u )
          return *(unsigned int *)&dp_getmodulation__he_bw_mod[4 * a2];
        goto LABEL_34;
      case 5u:
        switch ( a2 )
        {
          case 5u:
            if ( (unsigned int)a3 - 2 >= 3 )
              v3 = 10;
            else
              v3 = 11 - (unsigned int)a3;
            break;
          case 3u:
            v5 = 5;
            if ( a3 != 1 )
              v5 = 6;
            v3 = 4;
            if ( a3 != 2 )
              v3 = v5;
            break;
          case 2u:
            v3 = 2;
            if ( a3 != 1 )
              v3 = 3;
            break;
          default:
            if ( a2 < 0xBu )
            {
              v3 = a2;
              break;
            }
LABEL_34:
            __break(0x5512u);
LABEL_35:
            __break(1u);
            return dp_getrateindex();
        }
        if ( (unsigned __int64)(4 * v3) <= 0x2B )
          return dp_getmodulation__eht_bw_mod[v3];
        goto LABEL_35;
    }
    return 1;
  }
  if ( a1 == 1 )
    return 0;
  if ( a1 != 2 )
    return 1;
  if ( a2 )
    return 3;
  else
    return 2;
}
