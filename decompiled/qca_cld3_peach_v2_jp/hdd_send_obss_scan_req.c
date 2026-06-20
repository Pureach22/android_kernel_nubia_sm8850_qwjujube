__int64 __fastcall hdd_send_obss_scan_req(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  if ( (unsigned int)hdd_get_first_connected_sta_cli_vdev_id(a1, &v29, 0, a3, a4, a5, a6, a7, a8, a9, a10)
    && (unsigned int)hdd_get_first_connected_sta_cli_vdev_id(a1, &v29, 2, v12, v13, v14, v15, v16, v17, v18, v19) )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Connected STA not found",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "hdd_send_obss_scan_req");
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: reconfig OBSS scan param: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_send_obss_scan_req",
      a2 & 1);
    result = sme_reconfig_obss_scan_param(*(_QWORD *)(a1 + 16), v29, a2 & 1, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
