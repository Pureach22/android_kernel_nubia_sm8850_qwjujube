__int64 __fastcall util_get_bvmlie_primary_linkid(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3, _BYTE *a4)
{
  __int64 result; // x0
  __int16 v6; // w9

  result = 29;
  if ( a1 && a2 && a3 && a4 )
  {
    *a3 = 0;
    *a4 = 0;
    if ( a2 < 5 )
      return 4;
    if ( *a1 != 255 )
      return 4;
    if ( a1[2] != 107 )
      return 4;
    v6 = *(_WORD *)(a1 + 3);
    if ( (v6 & 7) != 0 )
      return 4;
    if ( a2 < 0xC )
      return 27;
    if ( (v6 & 0x10) != 0 )
    {
      if ( a2 == 12 )
        return 27;
      *a3 = 1;
      *a4 = a1[12] & 0xF;
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
