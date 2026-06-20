__int64 __fastcall wlan_tdls_notify_start_bss(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD v21[7]; // [xsp+8h] [xbp-38h] BYREF

  v21[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (tdls_is_concurrency_allowed(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v21[2] = tdls_process_cmd;
    memset(&v21[3], 0, 24);
    v21[1] = a1;
    v21[0] = 25;
    result = scheduler_post_message_debug(
               0,
               0,
               73,
               (unsigned __int16 *)v21,
               0xBBu,
               (__int64)"wlan_tdls_handle_sap_start");
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0,
                 2u,
                 "%s: post start bss msg fail",
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 "wlan_tdls_handle_sap_start");
  }
  else
  {
    result = wlan_tdls_check_and_teardown_links_sync(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
