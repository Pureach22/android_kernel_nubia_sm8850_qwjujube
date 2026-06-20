__int64 __fastcall wlan_hdd_get_station_bcn_rssi_history(
        __int64 *a1,
        void *a2,
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
  __int64 v12; // x20
  __int64 *v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v12 = *a1;
    v14 = a1;
    if ( (unsigned int)_hdd_validate_adapter(
                         *a1,
                         (__int64)"wlan_hdd_get_station_bcn_rssi_history",
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10)
      || *(_DWORD *)(v12 + 40) )
    {
      return 4294967274LL;
    }
    v23 = *(_QWORD **)(v12 + 24);
    if ( (unsigned int)_wlan_hdd_validate_context(
                         (__int64)v23,
                         (__int64)"wlan_hdd_get_station_bcn_rssi_history",
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid hdd context",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_hdd_get_station_bcn_rssi_history");
      return 4294967274LL;
    }
    if ( (ucfg_cp_stats_is_bcn_rssi_history_report_cfg_enable(*v23) & 1) == 0
      || (wlan_hdd_is_mlo_connection(*(_QWORD *)(v12 + 52824), v32, v33, v34, v35, v36, v37, v38, v39) & 1) != 0
      || *(__int64 **)(v12 + 52824) != v14 )
    {
      return 4294967274LL;
    }
    else
    {
      qdf_mem_copy(a2, v14 + 536, 0x50u);
      return 0;
    }
  }
  return result;
}
