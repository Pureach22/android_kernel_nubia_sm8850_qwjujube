__int64 __fastcall util_get_bvmlie_bssparamchangecnt(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3, _BYTE *a4)
{
  __int64 result; // x0
  unsigned int v6; // w22
  unsigned __int8 *v7; // x23
  unsigned __int64 v11; // x10
  _BYTE *v12; // x9
  _BYTE *v13; // x11
  unsigned __int64 v14; // x13

  result = 29;
  if ( a1 && a2 && a3 && a4 )
  {
    *a3 = 0;
    *a4 = 0;
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 )
    {
      v6 = *(unsigned __int16 *)(a1 + 3);
      if ( (v6 & 7) != 0 )
        return 11;
      v7 = a1;
      if ( (unsigned int)util_validate_bv_mlie_min_seq_len(a2) )
      {
        return 4;
      }
      else
      {
        if ( ((v6 >> 4) & 1) != 0 )
        {
          if ( a2 < 0xD )
            return 27;
          v14 = a2;
          v12 = a4;
          v13 = a3;
          v11 = 8;
        }
        else
        {
          v11 = 7;
          v12 = a4;
          v13 = a3;
          v14 = a2;
        }
        if ( ((v6 >> 4) & 2) != 0 )
        {
          result = 27;
          if ( v11 < v7[5] && v11 + 6 <= v14 )
          {
            *v13 = 1;
            *v12 = v7[v11 + 5];
            return 0;
          }
        }
        else
        {
          return 0;
        }
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
