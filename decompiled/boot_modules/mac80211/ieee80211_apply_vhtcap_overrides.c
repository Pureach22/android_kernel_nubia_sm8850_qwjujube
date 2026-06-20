__int64 __fastcall ieee80211_apply_vhtcap_overrides(__int64 result, __int64 a2)
{
  int v2; // w8
  unsigned int v3; // w8
  int v4; // w9
  int v5; // w8
  int v6; // w10
  unsigned int v7; // w11
  unsigned int v8; // w12
  unsigned int v9; // w13
  unsigned int v10; // w14
  unsigned int v11; // w17
  unsigned int v12; // w17

  if ( *(_BYTE *)a2 == 1 && *(_DWORD *)(result + 4720) == 2 )
  {
    v2 = *(_DWORD *)(result + 2600);
    if ( (v2 & 0x10) != 0 && (*(_BYTE *)(result + 2588) & 0x10) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x10u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x20) != 0 && (*(_BYTE *)(result + 2588) & 0x20) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x20u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x40) != 0 && (*(_BYTE *)(result + 2588) & 0x40) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x40u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x80) != 0 && (*(_BYTE *)(result + 2588) & 0x80) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x80u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x800) != 0 && (*(_BYTE *)(result + 2589) & 8) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x800u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x1000) != 0 && (*(_BYTE *)(result + 2589) & 0x10) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x1000u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x10000000) != 0 && (*(_BYTE *)(result + 2591) & 0x10) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x10000000u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x20000000) != 0 && (*(_BYTE *)(result + 2591) & 0x20) == 0 )
    {
      *(_DWORD *)(a2 + 4) &= ~0x20000000u;
      v2 = *(_DWORD *)(result + 2600);
    }
    if ( (v2 & 0x3800000) != 0 )
    {
      v3 = *(_DWORD *)(a2 + 4);
      if ( ((*(_DWORD *)(result + 2588) >> 23) & 7u) < ((v3 >> 23) & 7) )
        *(_DWORD *)(a2 + 4) = v3 & 0xFC7FFFFF | (((*(_DWORD *)(result + 2588) >> 23) & 7) << 23);
    }
    v4 = *(unsigned __int16 *)(result + 2604);
    v5 = 0;
    v6 = *(unsigned __int16 *)(result + 2608);
    v7 = *(unsigned __int16 *)(a2 + 8);
    v8 = *(unsigned __int16 *)(a2 + 12);
    v9 = (unsigned __int16)(*(_WORD *)(result + 2592) & v4);
    v10 = (unsigned __int16)(*(_WORD *)(result + 2596) & v6);
    do
    {
      if ( ((3 << v5) & v4) != 0 )
      {
        if ( (result = (v7 >> v5) & 3, v11 = (v9 >> v5) & 3, (_DWORD)result != 3) && v11 < (unsigned int)result
          || v11 == 3 )
        {
          result = (unsigned __int16)(3 << v5) ^ 0xFFFFu;
          v7 = v9 & (unsigned __int16)(3 << v5) | v7 & result;
        }
      }
      if ( ((3 << v5) & v6) != 0 )
      {
        if ( (result = (v8 >> v5) & 3, v12 = (v10 >> v5) & 3, (_DWORD)result != 3) && v12 < (unsigned int)result
          || v12 == 3 )
        {
          v8 = v10 & (unsigned __int16)(3 << v5) | v8 & ((unsigned __int16)(3 << v5) ^ 0xFFFF);
        }
      }
      v5 += 2;
    }
    while ( v5 != 16 );
    *(_WORD *)(a2 + 8) = v7;
    *(_WORD *)(a2 + 12) = v8;
  }
  return result;
}
