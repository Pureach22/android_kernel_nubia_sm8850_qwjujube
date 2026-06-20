__int64 __fastcall wlan_hdd_change_hw_mode_for_given_chnl(
        __int64 a1,
        unsigned int a2,
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
  __int64 *v13; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2

  v13 = *(__int64 **)(a1 + 24);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_change_hw_mode_for_given_chnl");
  if ( (unsigned int)policy_mgr_reset_connection_update(*v13) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: clearing event failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_hdd_change_hw_mode_for_given_chnl");
  v23 = policy_mgr_current_connections_update(*v13, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), a2, a3, 0);
  if ( v23 )
  {
    if ( v23 == 16 )
    {
      v32 = "%s: ERROR: connections update failed!!";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_change_hw_mode_for_given_chnl");
      return 4294967274LL;
    }
  }
  else
  {
    if ( (unsigned int)policy_mgr_wait_for_connection_update(*v13) )
    {
      v32 = "%s: ERROR: qdf wait for event failed!!";
      goto LABEL_8;
    }
    if ( *(_DWORD *)(a1 + 40) == 6 )
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Monitor mode:channel freq:%d (SMM->DBS)",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_hdd_change_hw_mode_for_given_chnl",
        a2);
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_hdd_change_hw_mode_for_given_chnl");
  return 0;
}
