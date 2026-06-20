__int64 __fastcall hdd_sap_restart_with_channel_switch(
        __int64 a1,
        __int64 *a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v36; // w22
  __int64 v37; // x21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  qdf_trace_msg(0x33u, 8u, "%s: enter", a6, a7, a8, a9, a10, a11, a12, a13, "hdd_sap_restart_with_channel_switch");
  if ( a2 )
  {
    v26 = hdd_softap_set_channel_change(a2, a3, 0, a4, 0, a5 & 1, 0);
    if ( (_DWORD)v26 == -16 || !(_DWORD)v26 )
      return qdf_status_from_os_return(v26);
    v36 = v26;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Vdev %d channel switch failed",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_sap_restart_with_channel_switch",
      *((unsigned __int8 *)a2 + 8));
    v37 = *a2;
    if ( !(unsigned int)_hdd_validate_adapter(*a2, "hdd_is_valid_sap_mode") )
    {
      if ( (*(_DWORD *)(v37 + 40) | 2) == 3 )
      {
        hdd_stop_sap_set_tx_power(a1, a2);
        v26 = v36;
        return qdf_status_from_os_return(v26);
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Device mode: %d, is not SAP or P2P_GO",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "hdd_is_valid_sap_mode");
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid link_info",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_sap_restart_with_channel_switch");
  }
  return 4;
}
