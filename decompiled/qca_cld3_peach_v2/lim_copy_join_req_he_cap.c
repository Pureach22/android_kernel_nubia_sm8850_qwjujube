__int64 __fastcall lim_copy_join_req_he_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  __int64 v20; // x21
  __int64 v21; // x8
  bool is_24ghz_ch_freq; // w0
  unsigned __int64 *v23; // x8
  __int64 v24; // x9
  unsigned __int64 v25; // x9
  char v26; // w12
  unsigned __int64 v27; // x9
  bool v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int64 v37; // x9
  unsigned __int64 v38; // x9

  result = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    return result;
  v19 = result;
  v20 = *(_QWORD *)(a1 + 8608) + 20480LL;
  if ( !*(_BYTE *)(*(_QWORD *)(a1 + 8608) + 21708LL) )
  {
    v21 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
    if ( v21 && *(_QWORD *)(v21 + 80) )
    {
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284));
      v23 = (unsigned __int64 *)(v19 + 23905);
      v24 = *(_QWORD *)(v19 + 23905);
      if ( is_24ghz_ch_freq )
      {
        v25 = *(_QWORD *)(v20 + 1317) & 0x380000LL | v24 & 0xFFFFFFFFF8C7FFFFLL;
LABEL_10:
        *v23 = v25;
        goto LABEL_11;
      }
      v26 = *(_BYTE *)(v19 + 23903);
      v27 = v24 & 0xFFFFFFFFFFC7FFFFLL | (((*(_QWORD *)(v20 + 1377) >> 19) & 7LL) << 19);
      *v23 = v27;
      if ( (v26 & 0x30) != 0 )
      {
        v25 = v27 & 0xFFFFFFFFF8FFFFFFLL | (((*(_QWORD *)(v20 + 1377) >> 24) & 7LL) << 24);
        goto LABEL_10;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get psoc",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "lim_revise_req_he_bfee_per_band");
    }
  }
LABEL_11:
  lim_revise_req_he_cap_per_band(v19, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  qdf_mem_copy((void *)(a1 + 8680), (const void *)(v19 + 23896), 0x3Cu);
  v28 = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284));
  v37 = 0xFEBBFFFFFFFFFFFFLL;
  if ( v28 )
    v37 = 0xFE47FFFFFFFFFFFFLL;
  v38 = *(_QWORD *)(a1 + 8681) & v37;
  *(_QWORD *)(a1 + 8681) = v38;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: HE width 0:%d 1:%d 2:%d 3:%d 4:%d 5:%d 6:%d",
           v29,
           v30,
           v31,
           v32,
           v33,
           v34,
           v35,
           v36,
           "lim_print_he_channel_widths",
           (v38 >> 50) & 1,
           (v38 >> 51) & 1,
           (v38 >> 52) & 1,
           (v38 >> 53) & 1,
           (v38 >> 54) & 1,
           (v38 >> 55) & 1,
           0);
}
