__int64 __fastcall handle_band_custom(__int64 result, __int64 a2, __int64 a3)
{
  unsigned __int64 v4; // x25
  __int64 v5; // x26
  int v6; // w8
  unsigned __int64 v7; // x22
  unsigned int v8; // w24
  unsigned int v9; // w28
  bool v10; // w20
  int v11; // w21
  unsigned __int64 v12; // x23
  int v13; // w8
  int v14; // w8
  __int64 v15; // x8
  unsigned int v16; // w8
  int v17; // w9
  int v18; // w8
  unsigned int v19; // w9
  int v20; // w10
  __int64 v21; // [xsp+0h] [xbp-10h]
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = result;
  if ( a2 && *(_DWORD *)(a2 + 20) )
  {
    v4 = 0;
    v5 = a3 + 28;
    v21 = a2;
    do
    {
      v7 = *(_QWORD *)a2 + (v4 << 6);
      v8 = *(unsigned __int16 *)(v7 + 8) + 1000 * *(_DWORD *)(v7 + 4);
      if ( v8 <= 0x2AEA540 )
        v9 = 2000000;
      else
        v9 = 20000000;
      if ( !a3 || !*(_DWORD *)(a3 + 16) )
        goto LABEL_28;
      v10 = 0;
      v11 = 0;
      while ( 1 )
      {
        v12 = v5 + 96LL * v11;
        if ( v10 )
          goto LABEL_21;
        v13 = v8 - *(_DWORD *)v12;
        if ( v13 < 0 )
          v13 = *(_DWORD *)v12 - v8;
        if ( v13 <= v9 )
        {
LABEL_21:
          v10 = 1;
        }
        else
        {
          v14 = v8 - *(_DWORD *)(v12 + 4);
          if ( v14 < 0 )
            v14 = *(_DWORD *)(v12 + 4) - v8;
          v10 = v14 <= v9;
        }
        result = cfg80211_does_bw_fit_range(v5 + 96LL * v11, v8, 20000);
        if ( v10 && (result & 1) != 0 )
          break;
        if ( (unsigned int)++v11 >= *(_DWORD *)(a3 + 16) )
          goto LABEL_28;
      }
      if ( v12 <= 0xFFFFFFFFFFFFF000LL && v12 )
      {
        result = reg_rule_to_chan_bw_flags(a3, v5 + 96LL * v11, v7);
        v15 = jiffies;
        *(_DWORD *)(v7 + 44) = 0;
        *(_BYTE *)(v7 + 28) = 0;
        *(_QWORD *)(v7 + 48) = v15;
        if ( (*(_BYTE *)(v22 + 104) & 0x80) != 0 )
          v17 = *(_DWORD *)(v7 + 32);
        else
          v17 = *(_DWORD *)(v7 + 12);
        v16 = *(_DWORD *)(v12 + 84);
        v18 = v17
            | v16 & 0xE00000
            | (v16 << 6) & 0x240
            | (v16 >> 1) & 8
            | (v16 >> 2) & 0x400
            | (v16 >> 8) & 0x20
            | (v16 >> 10) & 0x10
            | (v16 >> 8) & 0x180
            | (v16 >> 4) & 0x2000
            | (2 * v16) & 0x180000
            | (v16 >> 18) & 4
            | (2 * v16) & 0x2000000
            | (2 * ((v16 & 0x180) != 0))
            | result;
        *(_DWORD *)(v7 + 12) = v18;
        *(_DWORD *)(v7 + 16) = *(_DWORD *)(v12 + 12) / 0x64u;
        v19 = *(_DWORD *)(v12 + 16) / 0x64u;
        *(_DWORD *)(v7 + 20) = v19;
        *(_DWORD *)(v7 + 24) = v19;
        if ( (v18 & 8) != 0 )
        {
          v20 = *(_DWORD *)(v12 + 88);
          if ( !v20 )
            v20 = 60000;
          *(_DWORD *)(v7 + 56) = v20;
        }
        if ( (v18 & 4) != 0 )
          *(_BYTE *)(v7 + 60) = *(_BYTE *)(v12 + 93);
        *(_DWORD *)(v7 + 20) = v19;
      }
      else
      {
LABEL_28:
        if ( (*(_BYTE *)(v22 + 104) & 0x80) != 0 )
        {
          v6 = *(_DWORD *)(v7 + 12) | 1;
        }
        else
        {
          v6 = *(_DWORD *)(v7 + 32) | 1;
          *(_DWORD *)(v7 + 32) = v6;
        }
        *(_DWORD *)(v7 + 12) = v6;
      }
      a2 = v21;
      ++v4;
    }
    while ( v4 < *(unsigned int *)(v21 + 20) );
  }
  return result;
}
