__int64 __fastcall util_get_prvmlie_mldid(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3, _BYTE *a4)
{
  __int64 result; // x0
  __int16 v6; // w9

  result = 29;
  if ( a1 && a2 && a3 && a4 )
  {
    *a3 = 0;
    *a4 = 0;
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 )
    {
      v6 = *(_WORD *)(a1 + 3);
      if ( (v6 & 7) == 1 )
      {
        if ( (v6 & 0x10) != 0 )
        {
          if ( a2 >= 7 )
          {
            *a4 = a1[6];
            *a3 = 1;
            return 0;
          }
          else
          {
            return 27;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return 11;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
