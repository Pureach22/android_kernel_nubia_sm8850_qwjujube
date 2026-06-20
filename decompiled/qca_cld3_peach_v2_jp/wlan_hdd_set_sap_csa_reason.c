__int64 __fastcall wlan_hdd_set_sap_csa_reason(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  __int64 link_info_from_vdev; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 csa_reason_str; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev();
  if ( !link_info_from_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid vdev",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_hdd_set_sap_csa_reason");
  v14 = *(_QWORD *)(link_info_from_vdev + 272);
  if ( v14 )
    *(_DWORD *)(v14 + 732) = a3;
  csa_reason_str = sap_get_csa_reason_str(a3);
  return qdf_trace_msg(
           0x33u,
           8u,
           "vdev %d CSA reason %d %s",
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           a2,
           a3,
           csa_reason_str);
}
