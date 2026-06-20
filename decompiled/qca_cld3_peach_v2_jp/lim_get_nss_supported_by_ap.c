__int64 __fastcall lim_get_nss_supported_by_ap(__int64 a1, _BYTE *a2, __int64 a3)
{
  int v3; // w8

  if ( *(_BYTE *)a3 )
  {
    v3 = *(unsigned __int16 *)(a3 + 20);
    goto LABEL_5;
  }
  if ( *(_BYTE *)a1 )
  {
    v3 = *(unsigned __int16 *)(a1 + 6);
LABEL_5:
    if ( (~v3 & 0xC0) == 0 )
    {
      if ( (~v3 & 0x30) == 0 )
      {
        if ( (~v3 & 0xC) != 0 )
          return 2;
        return 1;
      }
      return 3;
    }
    return 4;
  }
  if ( *a2 )
  {
    if ( a2[7] )
      return 4;
    if ( a2[6] )
      return 3;
    if ( a2[5] )
      return 2;
  }
  return 1;
}
