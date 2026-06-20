__int64 __fastcall util_get_mlie_common_info_len(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3)
{
  __int64 result; // x0

  result = 29;
  if ( a1 && a2 && a3 )
  {
    if ( a2 >= 5 && *a1 == 255 && a1[2] == 107 && (*(_WORD *)(a1 + 3) & 7) == 0 )
    {
      if ( a2 >= 0xC )
      {
        *a3 = a1[5];
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
