__int64 __fastcall aw882xx_chipid_auth(int a1)
{
  bool v2; // cc
  __int64 result; // x0

  v2 = a1 <= 8469;
  result = 0;
  if ( v2 )
  {
    if ( a1 > 8241 )
    {
      if ( ((unsigned int)(a1 - 8242) > 0x3F || ((1LL << ((unsigned __int8)a1 - 50)) & 0x8000000800000001LL) == 0)
        && a1 != 8467 )
      {
        return 4294967274LL;
      }
      return result;
    }
    if ( a1 == 6226 || a1 == 8211 )
      return result;
    return 4294967274LL;
  }
  if ( a1 > 9222 )
  {
    if ( a1 == 9223 || a1 == 9240 )
      return result;
    return 4294967274LL;
  }
  if ( ((unsigned int)(a1 - 8968) > 0x28 || ((1LL << ((unsigned __int8)a1 - 8)) & 0x10200000001LL) == 0) && a1 != 8470 )
    return 4294967274LL;
  return result;
}
