__int64 __fastcall wlan_coex_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w19

  if ( (unsigned int)wlan_objmgr_unregister_psoc_destroy_handler(
                       0x21u,
                       (__int64)wlan_coex_psoc_destroyed_notification,
                       a1,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8) )
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: Failed to unregister psoc delete handler",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_coex_deinit");
  result = wlan_objmgr_unregister_psoc_create_handler(
             0x21u,
             (__int64)wlan_coex_psoc_created_notification,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    v25 = result;
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: Failed to unregister psoc create handler",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_coex_deinit");
    return v25;
  }
  return result;
}
