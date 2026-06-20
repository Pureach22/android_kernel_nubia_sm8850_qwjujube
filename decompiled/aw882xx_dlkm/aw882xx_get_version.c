__int64 __fastcall aw882xx_get_version(__int64 a1, unsigned int a2)
{
  if ( a2 < 7 )
    return 4294967284LL;
  *(_WORD *)(a1 + 4) = 12590;
  *(_DWORD *)a1 = 808333942;
  return 6;
}
