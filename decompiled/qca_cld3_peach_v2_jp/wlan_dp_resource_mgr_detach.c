__int64 __fastcall wlan_dp_resource_mgr_detach(
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
  const char *v10; // x4
  __int64 result; // x0
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
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  _DWORD *v36; // x20

  if ( *(_QWORD *)(a1 + 3000) )
    v10 = "true";
  else
    v10 = "false";
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: DP resource mgr detaching %s",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_dp_resource_mgr_detach",
             v10);
  if ( *(_QWORD *)(a1 + 3000) )
  {
    if ( (unsigned int)wlan_objmgr_unregister_peer_phymode_change_notify_handler(
                         0x2Eu,
                         (__int64)wlan_dp_resource_mgr_phymode_update,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19) )
    {
      return qdf_trace_msg(
               0x45u,
               2u,
               "%s: Failed to unregister peer phymode notification handler",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "wlan_dp_resource_mgr_detach");
    }
    else
    {
      timer_delete((timer_t)(*(_QWORD *)(a1 + 3000) + 144LL));
      timer_delete_sync(*(_QWORD *)(a1 + 3000) + 144LL);
      v36 = *(_DWORD **)(a1 + 3000);
      if ( v36[14] )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "qdf_list_destroy");
      if ( v36[32] )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "qdf_list_destroy");
      if ( v36[20] )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "qdf_list_destroy");
      if ( v36[26] )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "qdf_list_destroy");
      result = _qdf_mem_free(*(_QWORD *)(a1 + 3000));
      *(_QWORD *)(a1 + 3000) = 0;
    }
  }
  return result;
}
