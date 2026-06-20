__int64 __fastcall populate_dot11f_reg_connectivity(
        __int64 a1,
        _BYTE *a2,
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  *a2 = 1;
  if ( !(unsigned int)wlan_reg_check_if_6g_pwr_type_supp_for_chan(
                        *(_QWORD *)(a1 + 21632),
                        2u,
                        0x2Bu,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10)
    || !(unsigned int)wlan_reg_check_if_6g_pwr_type_supp_for_chan(
                        *(_QWORD *)(a1 + 21632),
                        0,
                        0x2Bu,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Indoor AP connectivity is valid",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "populate_dot11f_reg_connectivity");
    a2[1] |= 3u;
  }
  if ( !(unsigned int)wlan_reg_check_if_6g_pwr_type_supp_for_chan(
                        *(_QWORD *)(a1 + 21632),
                        2u,
                        0x2Bu,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19)
    || !(unsigned int)wlan_reg_check_if_6g_pwr_type_supp_for_chan(
                        *(_QWORD *)(a1 + 21632),
                        1u,
                        0x2Bu,
                        v20,
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v27) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: SP AP connectivity is valid",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "populate_dot11f_reg_connectivity");
    a2[1] |= 0xCu;
  }
  return 0;
}
