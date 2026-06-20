__int64 __fastcall reg_find_nearest_puncture_pattern(int a1, unsigned __int16 a2)
{
  _QWORD *v2; // x10
  __int64 v3; // x9
  __int64 result; // x0
  unsigned __int16 *v5; // x10
  unsigned int v6; // t1

  if ( !a2 )
    return 0;
  if ( a1 == 2 )
  {
    v2 = &unk_AD80C8;
    goto LABEL_8;
  }
  if ( a1 == 7 )
  {
    v2 = &bw_puncture_bitmap_pair_map;
    goto LABEL_8;
  }
  if ( a1 != 3 )
    return 0;
  v2 = &unk_AD80B0;
LABEL_8:
  v3 = *((unsigned __int16 *)v2 + 8);
  result = 0;
  if ( *((_WORD *)v2 + 8) )
  {
    v5 = (unsigned __int16 *)v2[1];
    if ( v5 )
    {
      while ( 1 )
      {
        v6 = *v5++;
        result = v6;
        if ( (v6 | a2) == v6 )
          break;
        if ( !--v3 )
          return 0;
      }
    }
  }
  return result;
}
