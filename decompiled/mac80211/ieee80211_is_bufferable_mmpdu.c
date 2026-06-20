bool __fastcall ieee80211_is_bufferable_mmpdu(__int64 a1)
{
  __int64 v1; // x8
  _BOOL8 result; // x0
  int v3; // w10
  int v5; // w9

  v1 = *(_QWORD *)(a1 + 224);
  if ( (*(_WORD *)v1 & 0xC) != 0 )
    return 0;
  v3 = *(_WORD *)v1 & 0xF0;
  result = 1;
  if ( v3 != 160 && v3 != 192 )
  {
    if ( v3 != 208 )
      return 0;
    if ( *(_DWORD *)(a1 + 112) >= 0x1Au )
    {
      v5 = *(unsigned __int8 *)(v1 + 24);
      if ( v5 == 9 || v5 == 4 )
        return (*(_BYTE *)(v1 + 25) & 0xFE) != 32;
    }
  }
  return result;
}
