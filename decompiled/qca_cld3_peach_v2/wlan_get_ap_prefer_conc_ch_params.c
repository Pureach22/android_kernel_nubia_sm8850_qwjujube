__int64 __fastcall wlan_get_ap_prefer_conc_ch_params(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  _QWORD *link_info_from_vdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  const char *v16; // x2

  link_info_from_vdev = (_QWORD *)wlan_hdd_get_link_info_from_vdev();
  if ( link_info_from_vdev && (*(_DWORD *)(*link_info_from_vdev + 40LL) | 2) == 3 )
  {
    v15 = link_info_from_vdev[34];
    if ( v15 )
    {
      if ( !(unsigned int)wlansap_context_get(link_info_from_vdev[34]) )
      {
        wlansap_get_csa_chanwidth_from_phymode(v15, a3, a4);
        wlansap_context_put(v15);
        return 0;
      }
      v16 = "%s: sap_context is invalid";
    }
    else
    {
      v16 = "%s: sap_context is null";
    }
  }
  else
  {
    v16 = "%s: Invalid vdev or device mode";
  }
  qdf_trace_msg(0x33u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_get_ap_prefer_conc_ch_params");
  return 16;
}
