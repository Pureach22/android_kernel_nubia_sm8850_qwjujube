__int64 __fastcall populate_dot11f_rnr_tbtt_info_16(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int16 v9; // w8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w22
  unsigned int v21; // w23
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  char v40; // w8
  __int64 v41; // x0
  unsigned __int8 channel_reg_power_for_freq; // w22
  unsigned __int16 bw_value; // w0
  int v44; // w9
  unsigned int v45; // w9
  unsigned int v46; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v47; // [xsp+Ch] [xbp-14h]
  unsigned __int16 v48; // [xsp+10h] [xbp-10h]
  unsigned __int8 v49; // [xsp+14h] [xbp-Ch]
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_WORD *)(a4 + 1);
  *(_BYTE *)a4 = 1;
  *(_WORD *)(a4 + 1) = v9 & 0xFFFC;
  *(_BYTE *)(a4 + 3) = lim_op_class_from_bandwidth(a1, *(_DWORD *)(a3 + 284), *(_DWORD *)(a3 + 7176));
  *(_BYTE *)(a4 + 4) = wlan_reg_freq_to_chan(
                         *(_QWORD *)(a1 + 21632),
                         *(_DWORD *)(a3 + 284),
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17);
  v18 = *(_WORD *)(a4 + 1) & 0xFFFB | (4 * ((*(unsigned __int16 *)(a5 + 1) >> 2) & 1));
  *(_WORD *)(a4 + 1) = v18;
  v19 = v18 & 0xFFFFFF0F | (16 * ((*(unsigned __int16 *)(a5 + 1) >> 4) & 0xF));
  *(_WORD *)(a4 + 1) = v19;
  *(_WORD *)(a4 + 1) = (unsigned __int8)v19 | (*(unsigned __int8 *)(a5 + 2) << 8);
  *(_BYTE *)(a4 + 8) = *(_BYTE *)(a5 + 8);
  qdf_mem_copy((void *)(a4 + 9), (const void *)(a3 + 30), 6u);
  *(_DWORD *)(a4 + 16) = *(_DWORD *)(a5 + 16);
  *(_BYTE *)(a4 + 20) = *(_BYTE *)(a5 + 20);
  v20 = *(_DWORD *)(a3 + 284);
  v21 = *(_DWORD *)(a3 + 7176);
  if ( wlan_reg_is_6ghz_chan_freq(v20) )
  {
    v30 = *(_QWORD *)(a1 + 21632);
    v49 = 0;
    v48 = 0;
    v47 = 0;
    v46 = 0;
    wlan_reg_get_cur_6g_ap_pwr_type(v30, &v46, v22, v23, v24, v25, v26, v27, v28, v29);
    wlan_reg_get_client_power_for_6ghz_ap();
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: chan_freq %d, is_psd_pwr %d eirp_pwr %d, eirp_psd_pwr %d",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "mlo_rnr_get_6g_20mhz_psd",
               v20,
               v49,
               v48,
               v47);
    v40 = 2 * v47;
    if ( !v49 )
      v40 = -2;
  }
  else
  {
    v41 = *(_QWORD *)(a1 + 21632);
    LOWORD(v46) = 0;
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                   v41,
                                   v20,
                                   v22,
                                   v23,
                                   v24,
                                   v25,
                                   v26,
                                   v27,
                                   v28,
                                   v29);
    bw_value = wlan_reg_get_bw_value(v21);
    result = wlan_reg_eirp_2_psd(*(_QWORD *)(a1 + 21632), bw_value, channel_reg_power_for_freq, &v46);
    v40 = 2 * v46;
  }
  *(_BYTE *)(a4 + 21) = v40;
  v44 = *(_DWORD *)(a4 + 23);
  *(_BYTE *)(a4 + 22) = 0;
  v45 = v44 & 0xFFFFFFF0 | *(_BYTE *)(*(_QWORD *)(a3 + 16) + 93LL) & 0xF;
  *(_DWORD *)(a4 + 23) = v45;
  *(_DWORD *)(a4 + 23) = v45 & 0xFFFF00FF | (*(unsigned __int8 *)(a3 + 10660) << 8);
  _ReadStatusReg(SP_EL0);
  return result;
}
