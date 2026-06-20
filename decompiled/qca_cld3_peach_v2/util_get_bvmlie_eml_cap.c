__int64 __fastcall util_get_bvmlie_eml_cap(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3, _WORD *a4)
{
  __int64 result; // x0
  unsigned int v6; // w9
  int v7; // w10
  int v8; // w9
  unsigned __int8 *v9; // x8
  unsigned int v10; // t1

  result = 29;
  if ( a1 && a2 && a3 && a4 )
  {
    *a4 = 0;
    *a3 = 0;
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 && (v6 = *(unsigned __int16 *)(a1 + 3), (v6 & 7) == 0) )
    {
      if ( ((v6 >> 4) & 1) != 0 )
        v7 = 8;
      else
        v7 = 7;
      if ( ((v6 >> 4) & 8) != 0 )
      {
        if ( a2 == 5 )
        {
          return 27;
        }
        else
        {
          result = 27;
          v8 = ((v6 >> 5) & 3) + v7;
          v10 = a1[5];
          v9 = a1 + 5;
          if ( v10 >= (unsigned __int8)(v8 + 2) && (unsigned __int64)(unsigned __int8)v8 + 7 <= a2 )
          {
            *a3 = 1;
            *a4 = *(_WORD *)&v9[(unsigned __int8)v8];
            return 0;
          }
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
