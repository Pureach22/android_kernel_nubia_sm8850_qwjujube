__int64 __fastcall wlan_scan_psoc_created_notification(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  const char *v12; // x2
  unsigned int v13; // w1

  v2 = _qdf_mem_malloc(0x5DB8u, "wlan_scan_psoc_created_notification", 34);
  if ( v2 )
  {
    v11 = wlan_objmgr_psoc_component_obj_attach(a1, 3u, v2, 0);
    if ( v11 )
    {
      v12 = "%s: Failed to attach psoc scan component";
      v13 = 2;
    }
    else
    {
      v12 = "%s: Scan object attach to psoc successful";
      v13 = 8;
    }
  }
  else
  {
    v12 = "%s: Failed to allocate memory";
    v13 = 2;
    v11 = 2;
  }
  qdf_trace_msg(0x15u, v13, v12, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_scan_psoc_created_notification");
  return v11;
}
