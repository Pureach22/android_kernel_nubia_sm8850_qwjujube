char *__fastcall lim_copy_bss_he_cap(
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
  char *result; // x0
  char *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x22
  bool is_24ghz_ch_freq; // w0
  unsigned __int64 *v23; // x8
  __int64 v24; // x9
  unsigned __int64 v25; // x9
  char v26; // w12
  unsigned __int64 v27; // x9

  result = (char *)wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 16), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = result;
    lim_revise_req_he_cap_per_band(result, a1);
    v20 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
    if ( v20 && *(_QWORD *)(v20 + 80) )
    {
      v21 = *(_QWORD *)(a1 + 8608) + 20480LL;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a1 + 284));
      v23 = (unsigned __int64 *)(v11 + 23905);
      v24 = *(_QWORD *)(v11 + 23905);
      if ( is_24ghz_ch_freq )
      {
        v25 = *(_QWORD *)(v21 + 1317) & 0x380000LL | v24 & 0xFFFFFFFFF8C7FFFFLL;
LABEL_9:
        *v23 = v25;
        return (char *)qdf_mem_copy((void *)(a1 + 8680), v11 + 23896, 0x3Cu);
      }
      v26 = v11[23903];
      v27 = v24 & 0xFFFFFFFFFFC7FFFFLL | (((*(_QWORD *)(v21 + 1377) >> 19) & 7LL) << 19);
      *v23 = v27;
      if ( (v26 & 0x30) != 0 )
      {
        v25 = v27 & 0xFFFFFFFFF8FFFFFFLL | (((*(_QWORD *)(v21 + 1377) >> 24) & 7LL) << 24);
        goto LABEL_9;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to get psoc",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_revise_req_he_bfee_per_band");
    }
    return (char *)qdf_mem_copy((void *)(a1 + 8680), v11 + 23896, 0x3Cu);
  }
  return result;
}
