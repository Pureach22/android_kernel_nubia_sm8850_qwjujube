__int64 __fastcall wlan_tdls_notify_start_bss(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD v13[7]; // [xsp+8h] [xbp-38h] BYREF

  v13[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (tdls_is_concurrency_allowed(a1) & 1) != 0 )
  {
    v13[2] = tdls_process_cmd;
    memset(&v13[3], 0, 24);
    v13[1] = a1;
    v13[0] = 25;
    result = scheduler_post_message_debug(
               0,
               0,
               73,
               (unsigned __int16 *)v13,
               0xBBu,
               (__int64)"wlan_tdls_handle_sap_start");
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0,
                 2u,
                 "%s: post start bss msg fail",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "wlan_tdls_handle_sap_start");
  }
  else
  {
    result = wlan_tdls_check_and_teardown_links_sync(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
