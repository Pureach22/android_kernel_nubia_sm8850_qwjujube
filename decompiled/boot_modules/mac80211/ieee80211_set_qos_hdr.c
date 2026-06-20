__int64 __fastcall ieee80211_set_qos_hdr(__int64 result, __int64 a2)
{
  unsigned __int16 *v2; // x10
  int v3; // w8
  bool v4; // zf
  __int64 v5; // x8
  int v6; // w9
  unsigned __int16 *v7; // x8
  char v8; // w12
  int v9; // w10
  char v10; // w11

  v2 = *(unsigned __int16 **)(a2 + 224);
  v3 = *v2;
  if ( (v3 & 0x8C) == 0x88 )
  {
    v4 = (~v3 & 0x300) == 0;
    v5 = 12;
    if ( v4 )
      v5 = 15;
    v6 = *(_DWORD *)(a2 + 40);
    v7 = &v2[v5];
    if ( (v6 & 0x80) != 0 )
    {
      if ( (*(_BYTE *)v7 & 0x20) != 0 )
        *(_DWORD *)(a2 + 40) = v6 | 4;
    }
    else
    {
      v8 = *((_BYTE *)v2 + 4);
      v9 = *(_DWORD *)(a2 + 144);
      v10 = *(_BYTE *)v7 & 0x90;
      if ( (v8 & 1) != 0 || (((unsigned __int64)*(unsigned __int16 *)(result + 1888) >> (v9 & 7)) & 1) != 0 )
      {
        v10 |= 0x20u;
        *(_DWORD *)(a2 + 40) = v6 | 4;
      }
      *((_BYTE *)v7 + 1) = 0;
      *(_BYTE *)v7 = v10 | v9 & 7;
    }
  }
  return result;
}
