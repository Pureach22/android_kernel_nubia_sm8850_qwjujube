__int64 __fastcall ieee80211_rearrange_tpe(_BYTE *a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  unsigned int v10; // w8
  __int64 v11; // x8
  unsigned int v12; // w8

  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 != 4 && (unsigned int)nl80211_chan_width_to_mhz(v3) + 19 < 0x27 )
    return ieee80211_clear_tpe(a1);
  v7 = *(unsigned int *)(a3 + 8);
  if ( (_DWORD)v7 != 4 && (unsigned int)nl80211_chan_width_to_mhz(v7) + 19 <= 0x26 )
    return ieee80211_clear_tpe(a1);
  ieee80211_rearrange_tpe_psd(a1 + 28, a2, a3);
  ieee80211_rearrange_tpe_psd(a1 + 66, a2, a3);
  v9 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v9 < 0xE && ((0x203Fu >> v9) & 1) != 0 )
  {
    v10 = dword_C082C[v9];
  }
  else
  {
    v10 = 0;
    __break(0x800u);
  }
  if ( v10 < (unsigned __int8)a1[6] )
    a1[6] = v10;
  if ( v10 < (unsigned __int8)a1[20] )
    a1[20] = v10;
  ieee80211_rearrange_tpe_psd(a1 + 47, a2, a3);
  result = ieee80211_rearrange_tpe_psd(a1 + 85, a2, a3);
  v11 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v11 < 0xE && ((0x203Fu >> v11) & 1) != 0 )
  {
    v12 = dword_C082C[v11];
  }
  else
  {
    v12 = 0;
    __break(0x800u);
  }
  if ( v12 < (unsigned __int8)a1[13] )
    a1[13] = v12;
  if ( v12 < (unsigned __int8)a1[27] )
    a1[27] = v12;
  return result;
}
