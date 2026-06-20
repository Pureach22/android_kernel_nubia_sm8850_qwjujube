__int64 __fastcall dfs_generate_radar_bitmap(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3)
{
  __int64 v5; // x0
  unsigned __int8 bonding_channel_without_seg_info_for_freq; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned __int8 v15; // w8
  unsigned __int64 v16; // x9
  __int64 result; // x0
  int v18; // w11
  __int64 v19; // x13
  unsigned __int16 *v20; // x14
  int v21; // t1
  _QWORD v22[5]; // [xsp+8h] [xbp-28h] BYREF

  v22[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 14888);
  memset(v22, 0, 32);
  bonding_channel_without_seg_info_for_freq = dfs_get_bonding_channel_without_seg_info_for_freq(v5, v22);
  if ( !bonding_channel_without_seg_info_for_freq )
    goto LABEL_12;
  v15 = bonding_channel_without_seg_info_for_freq;
  v16 = 0;
  result = 0;
  v18 = 1;
  do
  {
    if ( a3 )
    {
      if ( v16 > 0xF )
        __break(0x5512u);
      v19 = a3;
      v20 = a2;
      while ( 1 )
      {
        v21 = *v20++;
        if ( *((unsigned __int16 *)v22 + v16) == v21 )
          break;
        if ( !--v19 )
          goto LABEL_4;
      }
      result = v18 | (unsigned int)result;
    }
LABEL_4:
    ++v16;
    v18 *= 2;
  }
  while ( v16 != v15 );
  if ( !(_WORD)result )
  {
LABEL_12:
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Radar bitmap is zero",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dfs_generate_radar_bitmap");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
