__int64 __fastcall lim_tdls_set_he_chan_width(__int64 result, __int64 a2, __int64 a3, char a4)
{
  __int64 v6; // x21
  int v7; // w9
  __int64 v8; // x8
  unsigned __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  __int64 v20; // x8

  if ( (a4 & 1) != 0 && (v6 = result, result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284)), (result & 1) == 0) )
  {
    result = wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a3 + 284));
    if ( (result & 1) == 0 )
      return result;
    result = wlan_reg_is_dfs_for_freq(
               *(_QWORD *)(v6 + 21560),
               *(_DWORD *)(a3 + 284),
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17);
    v7 = *(_DWORD *)(a3 + 7176);
    if ( (result & 1) == 0 )
    {
      v20 = *(_QWORD *)(a2 + 1);
      if ( (unsigned int)v7 < 3 )
        v20 &= 0xFE0FFFFFFFFFFFFFLL;
      v18 = v20 & 0xFE1FFFFFFFFFFFFFLL;
      goto LABEL_24;
    }
    v8 = *(_QWORD *)(a2 + 1);
    if ( v7 <= 2 )
    {
      if ( v7 == 1 )
        goto LABEL_17;
      if ( v7 == 2 )
        goto LABEL_6;
LABEL_16:
      v19 = v8 & 0xFFFBFFFFFFFFFFFFLL;
LABEL_18:
      v9 = v19 & 0xFFF7FFFFFFFFFFFFLL;
      goto LABEL_19;
    }
  }
  else
  {
    v7 = *(_DWORD *)(a3 + 7176);
    v8 = *(_QWORD *)(a2 + 1);
    if ( v7 <= 2 )
    {
      if ( v7 != 1 )
      {
        if ( v7 == 2 )
        {
LABEL_6:
          v9 = v8 | 0x8000000000000LL;
LABEL_19:
          v18 = v9 & 0xFFCFFFFFFFFFFFFFLL;
          goto LABEL_24;
        }
        goto LABEL_16;
      }
LABEL_17:
      v19 = v8 | 0x4000000000000LL;
      goto LABEL_18;
    }
  }
  if ( v7 == 3 )
  {
    v18 = v8 & 0xFFCFFFFFFFFFFFFFLL | 0x10000000000000LL;
    goto LABEL_24;
  }
  if ( v7 != 4 )
    goto LABEL_16;
  v18 = v8 | 0x20000000000000LL;
LABEL_24:
  *(_QWORD *)(a2 + 1) = v18;
  return result;
}
