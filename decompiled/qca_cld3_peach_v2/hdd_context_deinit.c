__int64 __fastcall hdd_context_deinit(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  flush_work(a1 + 8248);
  *(_BYTE *)(a1 + 8296) = 0;
  cancel_work_sync(a1 + 8248);
  _qdf_wake_lock_destroy(a1 + 3288);
  ((void (__fastcall *)(_QWORD))wlan_hdd_cfg80211_deinit)(*(_QWORD *)(a1 + 24));
  ucfg_dp_bbm_context_deinit(*(_QWORD *)a1);
  hdd_sap_context_destroy(a1);
  result = hdd_scan_context_destroy(a1);
  if ( *(_DWORD *)(a1 + 64) )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: list length not equal to zero",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "qdf_list_destroy");
  return result;
}
