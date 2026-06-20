__int64 __fastcall hdd_stop_bss_link(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x22
  __int64 *v11; // x20
  __int64 result; // x0
  double started; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 v36; // x10

  v10 = *a1;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_stop_bss_link");
  v11 = *(__int64 **)(v10 + 24);
  result = _wlan_hdd_validate_context(v11, "hdd_stop_bss_link");
  if ( !(_DWORD)result )
  {
    if ( (a1[552] & 2) != 0 )
    {
      if ( (unsigned int)wlansap_stop_bss(a1[34]) )
      {
        v21 = -16;
      }
      else
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Deleting SAP/P2P link!!!!!!",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_stop_bss_link");
        v21 = 0;
      }
      _X8 = (unsigned __int64 *)(a1 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      policy_mgr_decr_session_set_pcl(*v11, *(_DWORD *)(v10 + 40), *((unsigned __int8 *)a1 + 8));
      started = hdd_green_ap_start_state_mc(v11, *(unsigned int *)(v10 + 40), 0);
    }
    else
    {
      v21 = 0;
    }
    qdf_trace_msg(0x33u, 8u, "%s: exit", started, v14, v15, v16, v17, v18, v19, v20, "hdd_stop_bss_link");
    return v21;
  }
  return result;
}
