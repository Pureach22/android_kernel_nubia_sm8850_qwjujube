__int64 __fastcall populate_dot11f_set_tdls_he_cap(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char is_fw_wideband_capable; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  bool is_24ghz_ch_freq; // w0
  __int64 v27; // x8
  __int64 v28; // x9
  _BYTE *v29; // x1
  __int64 result; // x0
  int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  if ( a2 - 10 >= 4 && a2 )
    return qdf_trace_msg(
             0x35u,
             8u,
             "%s: Not populating he cap as SelfDot11Mode not HE %d",
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "populate_dot11f_set_tdls_he_cap",
             a2);
  populate_dot11f_he_caps(a1, 0, *(_DWORD *)(a5 + 7036), 0, 0, a3);
  is_fw_wideband_capable = wlan_cfg80211_tdls_is_fw_wideband_capable(*(_QWORD *)(a5 + 16));
  v18 = lim_tdls_set_he_chan_width(a1, a3, a5, is_fw_wideband_capable & 1);
  if ( (a3[14] & 4) != 0 )
  {
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284));
    v27 = *(_QWORD *)(a1 + 8);
    v28 = 1453;
    if ( is_24ghz_ch_freq )
      v28 = 1428;
    v29 = (_BYTE *)(v27 + v28);
    if ( *(_BYTE *)(v27 + v28 + 24) )
    {
      a3[32] = 25;
LABEL_56:
      qdf_mem_copy(a3 + 33, v29, 0x19u);
      goto LABEL_57;
    }
    if ( v29[23] )
    {
      a3[32] = 24;
      goto LABEL_56;
    }
    if ( v29[22] )
    {
      a3[32] = 23;
      goto LABEL_56;
    }
    if ( v29[21] )
    {
      a3[32] = 22;
      goto LABEL_56;
    }
    if ( v29[20] )
    {
      a3[32] = 21;
      goto LABEL_56;
    }
    if ( v29[19] )
    {
      a3[32] = 20;
      goto LABEL_56;
    }
    if ( v29[18] )
    {
      a3[32] = 19;
      goto LABEL_56;
    }
    if ( v29[17] )
    {
      a3[32] = 18;
      goto LABEL_56;
    }
    if ( v29[16] )
    {
      a3[32] = 17;
      goto LABEL_56;
    }
    if ( v29[15] )
    {
      a3[32] = 16;
      goto LABEL_56;
    }
    if ( v29[14] )
    {
      a3[32] = 15;
      goto LABEL_56;
    }
    if ( v29[13] )
    {
      a3[32] = 14;
      goto LABEL_56;
    }
    if ( v29[12] )
    {
      a3[32] = 13;
      goto LABEL_56;
    }
    if ( v29[11] )
    {
      a3[32] = 12;
      goto LABEL_56;
    }
    if ( v29[10] )
    {
      a3[32] = 11;
      goto LABEL_56;
    }
    if ( v29[9] )
    {
      a3[32] = 10;
      goto LABEL_56;
    }
    if ( v29[8] )
    {
      a3[32] = 9;
      goto LABEL_56;
    }
    if ( v29[7] )
    {
      a3[32] = 8;
      goto LABEL_56;
    }
    if ( v29[6] )
    {
      a3[32] = 7;
      goto LABEL_56;
    }
    if ( v29[5] )
    {
      a3[32] = 6;
      goto LABEL_56;
    }
    if ( v29[4] )
    {
      a3[32] = 5;
      goto LABEL_56;
    }
    if ( v29[3] )
    {
      a3[32] = 4;
      goto LABEL_56;
    }
    if ( v29[2] )
    {
      a3[32] = 3;
      goto LABEL_56;
    }
    if ( v29[1] )
    {
      a3[32] = 2;
      goto LABEL_56;
    }
    v31 = (unsigned __int8)*v29;
    a3[32] = *v29 != 0;
    if ( v31 )
      goto LABEL_56;
    a3[32] = 1;
  }
LABEL_57:
  result = lim_log_he_cap(v18, v19, v20, v21, v22, v23, v24, v25, a1, (__int64)a3);
  if ( a4 )
    return populate_dot11f_he_6ghz_cap(a1, a5, a4, v32, v33, v34, v35, v36, v37, v38, v39);
  return result;
}
