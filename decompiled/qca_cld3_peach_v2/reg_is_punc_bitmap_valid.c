bool __fastcall reg_is_punc_bitmap_valid(int a1, unsigned __int16 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x10
  _BOOL8 result; // x0
  unsigned __int16 *v5; // x8
  __int64 v6; // x10
  int v7; // t1

  switch ( a1 )
  {
    case 2:
      v2 = &unk_AD80C8;
      break;
    case 7:
      v2 = &bw_puncture_bitmap_pair_map;
      break;
    case 3:
      v2 = &unk_AD80B0;
      break;
    default:
      return 0;
  }
  v3 = *((unsigned __int16 *)v2 + 8);
  result = 0;
  if ( *((_WORD *)v2 + 8) )
  {
    v5 = (unsigned __int16 *)v2[1];
    if ( v5 )
    {
      v6 = v3 - 1;
      do
      {
        v7 = *v5++;
        result = v7 == a2;
        if ( v7 == a2 )
          break;
      }
      while ( v6-- );
    }
  }
  return result;
}
