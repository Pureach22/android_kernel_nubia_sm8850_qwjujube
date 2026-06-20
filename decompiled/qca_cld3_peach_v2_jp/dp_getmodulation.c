__int64 __fastcall dp_getmodulation(unsigned __int16 a1, unsigned __int8 a2)
{
  if ( a1 > 2u )
  {
    if ( a1 == 3 )
    {
      if ( a2 < 4u )
        return dp_getmodulation__vht_bw_mod[a2];
    }
    else
    {
      if ( a1 != 4 )
        return 1;
      if ( a2 <= 3u )
        return *(unsigned int *)&dp_getmodulation__he_bw_mod[4 * a2];
    }
    __break(0x5512u);
    return dp_getrateindex();
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
