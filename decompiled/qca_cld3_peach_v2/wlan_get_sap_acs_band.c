__int64 __fastcall wlan_get_sap_acs_band(__int64 a1, __int64 a2, int *a3)
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
  int v13; // w8

  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev();
  if ( link_info_from_vdev && (*(_DWORD *)(*(_QWORD *)link_info_from_vdev + 40LL) | 2) == 3 )
  {
    if ( *(_BYTE *)(link_info_from_vdev + 1424) )
      v13 = *(_DWORD *)(link_info_from_vdev + 2004);
    else
      v13 = 4;
    *a3 = v13;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid vdev or device mode",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_get_sap_acs_band");
    return 16;
  }
}
