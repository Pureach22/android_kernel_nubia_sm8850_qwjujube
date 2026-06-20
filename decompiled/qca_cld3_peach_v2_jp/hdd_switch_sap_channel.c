__int64 __fastcall hdd_switch_sap_channel(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v11; // x21
  unsigned __int8 v13; // w19
  unsigned int v15; // w20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( *(_QWORD *)a1 && (v11 = *(__int64 **)(*(_QWORD *)a1 + 24LL)) != nullptr && v11[2] )
  {
    v13 = a2;
    v15 = wlan_reg_legacy_chan_to_freq(v11[1], a2, a4, a5, a6, a7, a8, a9, a10, a11);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: chan:%d width:%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_switch_sap_channel",
      v13,
      *(unsigned int *)(a1 + 744));
    return policy_mgr_change_sap_channel_with_csa(
             *v11,
             *(unsigned __int8 *)(a1 + 8),
             v15,
             *(_DWORD *)(a1 + 744),
             a3 & 1);
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: invalid MAC handle", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_switch_sap_channel");
    return 4;
  }
}
