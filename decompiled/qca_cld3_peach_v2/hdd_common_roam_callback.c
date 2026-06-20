__int64 __fastcall hdd_common_roam_callback(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 a10,
        unsigned int *a11,
        unsigned int a12,
        unsigned int a13)
{
  _QWORD *context; // x0
  __int64 link_info_by_vdev; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w8
  int v28; // w8

  context = _cds_get_context(51, (__int64)"wlan_hdd_get_link_info_from_vdev", a1, a2, a3, a4, a5, a6, a7, a8);
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev %d Get adapter by vdev id failed",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_hdd_get_link_info_from_vdev",
      a10);
    return 4;
  }
  if ( !*(_QWORD *)(*(_QWORD *)link_info_by_vdev + 24LL) )
    return 4;
  v27 = *(_DWORD *)(*(_QWORD *)link_info_by_vdev + 40LL);
  if ( v27 > 0xB )
    goto LABEL_11;
  v28 = 1 << v27;
  if ( (v28 & 0x885) != 0 )
    return hdd_sme_roam_callback(
             (unsigned __int8 *)link_info_by_vdev,
             a11,
             a12,
             a13,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26);
  if ( (v28 & 0xA) != 0 )
    return wlansap_roam_callback(*(_QWORD *)(link_info_by_vdev + 272), a11, a12, a13);
LABEL_11:
  qdf_trace_msg(0x33u, 2u, "%s: Wrong device mode", v19, v20, v21, v22, v23, v24, v25, v26, "hdd_common_roam_callback");
  return 0;
}
