__int64 __fastcall wlan_is_scan_allowed(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w21
  __int64 v6; // x20

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 80);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v1 + 24);
    if ( v3 )
    {
      v4 = *(_DWORD *)(a1 + 16);
      qdf_mutex_acquire(*(_QWORD *)(v3 + 16) + 24LL);
      if ( (policy_mgr_is_scan_simultaneous_capable(v2) & 1) != 0
        || (qdf_list_empty(*(_QWORD *)(v3 + 16)) & 1) != 0
        || v4 == 1 )
      {
        qdf_mutex_release(*(_QWORD *)(v3 + 16) + 24LL);
        return 1;
      }
      qdf_mutex_release(*(_QWORD *)(v3 + 16) + 24LL);
      v6 = jiffies;
      if ( wlan_is_scan_allowed___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(72, 2, "%s: Simultaneous scan disabled, reject scan", "wlan_is_scan_allowed");
        wlan_is_scan_allowed___last_ticks = v6;
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(72, 2, "%s: Invalid osif priv object", "wlan_is_scan_allowed");
    }
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: Invalid psoc object", "wlan_is_scan_allowed");
  }
  return 0;
}
