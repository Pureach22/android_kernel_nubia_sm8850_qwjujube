__int64 __fastcall dfs_generate_radar_bitmap(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0
  unsigned __int8 bonding_channel_without_seg_info_for_freq; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 v23; // w8
  unsigned __int64 v24; // x9
  __int64 result; // x0
  int v26; // w11
  __int64 v27; // x13
  unsigned __int16 *v28; // x14
  int v29; // t1
  _QWORD v30[3]; // [xsp+8h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 14888);
  v30[0] = 0;
  v30[1] = 0;
  bonding_channel_without_seg_info_for_freq = dfs_get_bonding_channel_without_seg_info_for_freq(
                                                v13,
                                                v30,
                                                a4,
                                                a5,
                                                a6,
                                                a7,
                                                a8,
                                                a9,
                                                a10,
                                                a11);
  if ( !bonding_channel_without_seg_info_for_freq )
    goto LABEL_12;
  v23 = bonding_channel_without_seg_info_for_freq;
  v24 = 0;
  result = 0;
  v26 = 1;
  do
  {
    if ( a3 )
    {
      if ( v24 > 7 )
        __break(0x5512u);
      v27 = a3;
      v28 = a2;
      while ( 1 )
      {
        v29 = *v28++;
        if ( *((unsigned __int16 *)v30 + v24) == v29 )
          break;
        if ( !--v27 )
          goto LABEL_4;
      }
      result = v26 | (unsigned int)result;
    }
LABEL_4:
    ++v24;
    v26 *= 2;
  }
  while ( v24 != v23 );
  if ( !(_WORD)result )
  {
LABEL_12:
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Radar bitmap is zero",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dfs_generate_radar_bitmap");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
