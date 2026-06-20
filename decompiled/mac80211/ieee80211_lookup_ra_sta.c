__int64 __fastcall ieee80211_lookup_ra_sta(__int64 a1, __int64 a2, unsigned __int64 *a3)
{
  int v3; // w9
  unsigned int v5; // w8
  unsigned __int64 v6; // x20
  __int64 v8; // x21
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  _BYTE *v11; // x1
  unsigned __int64 bss; // x0
  __int64 v14; // x9

  v3 = *(_DWORD *)(a1 + 4720);
  v5 = -22;
  if ( v3 > 2 )
  {
    if ( v3 != 3 && v3 != 11 )
    {
      if ( v3 == 4 )
      {
        v6 = *(_QWORD *)(a1 + 2280);
        if ( !v6 )
        {
          if ( (*(_BYTE *)(a1 + 81) & 1) != 0 )
            return (unsigned int)-67;
          goto LABEL_15;
        }
        goto LABEL_18;
      }
      return v5;
    }
LABEL_15:
    v11 = *(_BYTE **)(a2 + 224);
    v6 = -2;
    if ( (*v11 & 1) == 0 )
    {
      bss = sta_info_get_bss(a1, v11);
      if ( bss )
        v6 = bss;
    }
    goto LABEL_18;
  }
  if ( v3 == 1 )
    goto LABEL_15;
  if ( v3 == 2 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 16) + 101LL) & 0x80) != 0 )
    {
      v8 = a1;
      v9 = sta_info_get(a1, *(const void **)(a2 + 224));
      v10 = a2;
      v6 = v9;
      a1 = v8;
      if ( v6 )
      {
        if ( (*(_QWORD *)(v6 + 216) & 0x800) != 0 )
        {
          if ( (*(_QWORD *)(v6 + 216) & 0x1000) != 0 )
            goto LABEL_18;
          v14 = *(_QWORD *)(v10 + 224);
          if ( bswap32(*(unsigned __int16 *)(v14 + 12)) >> 16 != 35085
            || *(_DWORD *)(v10 + 112) < 0xFu
            || *(_BYTE *)(v14 + 14) != 2 )
          {
            return (unsigned int)-22;
          }
        }
      }
    }
    v6 = sta_info_get(a1, (const void *)(a1 + 4802));
    if ( !v6 )
      return (unsigned int)-67;
LABEL_18:
    v5 = 0;
    *a3 = v6;
  }
  return v5;
}
