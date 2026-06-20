__int64 __fastcall lim_is_channel_valid_for_channel_switch(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  char is_freq_enabled; // w8
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 21552);
  v35[0] = 0;
  if ( (unsigned int)policy_mgr_is_chan_ok_for_dnbs(v14, a3, v35, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v23 = "%s: policy_mgr_is_chan_ok_for_dnbs() returned error";
    v24 = 2;
LABEL_13:
    qdf_trace_msg(0x35u, v24, v23, v15, v16, v17, v18, v19, v20, v21, v22, "lim_is_channel_valid_for_channel_switch");
    result = 0;
    goto LABEL_14;
  }
  if ( (v35[0] & 1) == 0 )
  {
    v23 = "%s: channel not ok for DNBS";
    goto LABEL_12;
  }
  is_freq_enabled = wlan_reg_is_freq_enabled(*(_QWORD *)(a1 + 21560), a3, v15, v16, v17, v18, v19, v20, v21, v22);
  result = 0;
  if ( (is_freq_enabled & 1) != 0 )
  {
    if ( *(_DWORD *)(a2 + 7036) == 2
      && (*(_BYTE *)(a2 + 10080) & 1) != 0
      && (tx_timer_running(a1 + 3720) & 1) != 0
      && *(_WORD *)(a2 + 8) == *(unsigned __int8 *)(a1 + 3770) )
    {
      if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), a3, v27, v28, v29, v30, v31, v32, v33, v34) & 1) != 0 )
      {
        v23 = "%s: Channel change to DFS for assisted AP P2P group";
LABEL_12:
        v24 = 8;
        goto LABEL_13;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Stop channel vacate timer",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_is_channel_valid_for_channel_switch");
      tx_timer_deactivate(a1 + 3720);
    }
    result = 1;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
