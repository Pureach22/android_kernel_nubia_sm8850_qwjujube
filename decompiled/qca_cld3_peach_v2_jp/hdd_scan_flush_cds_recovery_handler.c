__int64 __fastcall hdd_scan_flush_cds_recovery_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 pdev_by_id; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  context = _cds_get_context(51, (__int64)"hdd_scan_flush_cds_recovery_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_scan_flush_cds_recovery_handler",
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16);
  if ( !(_DWORD)result && *((_DWORD *)context + 366) == 1 )
  {
    result = *context;
    if ( *context )
    {
      pdev_by_id = wlan_objmgr_get_pdev_by_id(result, 0, 0xCu);
      if ( pdev_by_id )
      {
        v27 = pdev_by_id;
        wlan_cfg80211_cleanup_scan_queue(pdev_by_id, 0);
        return wlan_objmgr_pdev_release_ref(v27, 0xCu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
      }
      else
      {
        return qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: pdev is NULL",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "hdd_scan_flush_cds_recovery_handler");
      }
    }
  }
  return result;
}
