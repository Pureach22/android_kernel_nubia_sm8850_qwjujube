__int64 __fastcall wlan_scan_cached_scan_report_ev_handler(__int64 a1, unsigned __int16 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  v2 = *(_QWORD *)(a1 + 24);
  if ( !v2 )
  {
    qdf_trace_msg(72, 8, "%s: Invalid osif priv object", "wlan_scan_cached_scan_report_ev_handler");
    return 16;
  }
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 )
  {
    qdf_trace_msg(72, 8, "%s: osif scan priv NULL", "wlan_scan_cached_scan_report_ev_handler");
    return 16;
  }
  v5 = _qdf_mem_malloc(32, "wlan_scan_cached_scan_report_ev_handler", 1526);
  if ( v5 )
  {
    v6 = v5;
    if ( a2[1] )
    {
      v7 = _qdf_mem_malloc(68LL * a2[1], "wlan_scan_cached_scan_report_ev_handler", 1533);
      *(_QWORD *)(v6 + 24) = v7;
      if ( !v7 )
        goto LABEL_15;
      qdf_mem_copy(v7, *((_QWORD *)a2 + 3), 68 * (unsigned int)a2[1]);
      *(_WORD *)(v6 + 2) = a2[1];
    }
    if ( !*a2 )
      goto LABEL_10;
    v8 = _qdf_mem_malloc(4LL * *a2, "wlan_scan_cached_scan_report_ev_handler", 1546);
    *(_QWORD *)(v6 + 16) = v8;
    if ( v8 )
    {
      qdf_mem_copy(v8, *((_QWORD *)a2 + 2), 4 * (unsigned int)*a2);
      *(_WORD *)v6 = *a2;
LABEL_10:
      if ( *(_DWORD *)(v3 + 304) )
      {
        v9 = ktime_get_with_offset(1);
        *(_QWORD *)(v6 + 8) = v9 / 1000;
        qdf_trace_msg(72, 8, "%s: Scan cached report ts: %llu", "wlan_scan_cached_scan_report_ev_handler", v9 / 1000);
        *(_QWORD *)(v3 + 352) = v6;
        qdf_event_set_all(v3 + 312);
        return 0;
      }
    }
LABEL_15:
    _qdf_mem_free(*(_QWORD *)(v6 + 24));
    _qdf_mem_free(*(_QWORD *)(v6 + 16));
    _qdf_mem_free(v6);
  }
  return 2;
}
