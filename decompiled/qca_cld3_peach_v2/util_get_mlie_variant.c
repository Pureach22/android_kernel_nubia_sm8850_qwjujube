__int64 __fastcall util_get_mlie_variant(unsigned __int8 *a1, unsigned __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned int v5; // w8

  result = 29;
  if ( a1 && a2 && a3 )
  {
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 )
    {
      v5 = *(_WORD *)(a1 + 3) & 7;
      if ( v5 <= 4 )
      {
        *a3 = v5;
        return 0;
      }
      else
      {
        return 27;
      }
    }
    else
    {
      return 4;
    }
  }
  return result;
}
