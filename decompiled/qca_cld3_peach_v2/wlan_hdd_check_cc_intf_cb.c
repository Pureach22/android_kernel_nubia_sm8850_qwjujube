__int64 __fastcall wlan_hdd_check_cc_intf_cb(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 link_info_from_vdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 v14; // x20

  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev();
  if ( link_info_from_vdev )
  {
    if ( (*(_QWORD *)(link_info_from_vdev + 5968) & 2) != 0 )
    {
      v14 = *(_QWORD *)(link_info_from_vdev + 272);
      if ( v14 )
      {
        if ( !(unsigned int)wlansap_context_get(*(_QWORD *)(link_info_from_vdev + 272)) )
        {
          *a3 = (unsigned __int16)wlansap_check_cc_intf(v14);
          wlansap_context_put(v14);
          return 0;
        }
        v13 = "%s: sap_context is invalid";
      }
      else
      {
        v13 = "%s: sap_context is null";
      }
    }
    else
    {
      v13 = "%s: SOFTAP_BSS_STARTED not set";
    }
  }
  else
  {
    v13 = "%s: Invalid vdev";
  }
  qdf_trace_msg(0x33u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_hdd_check_cc_intf_cb");
  return 16;
}
