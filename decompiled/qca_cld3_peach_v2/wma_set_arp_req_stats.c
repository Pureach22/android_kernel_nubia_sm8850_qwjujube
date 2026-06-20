__int64 __fastcall wma_set_arp_req_stats(
        __int64 *a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x4
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2

  if ( !a1 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid WMA handle (via %s)",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__wma_validate_handle",
             "wma_set_arp_req_stats");
  v10 = *a1;
  result = _wmi_validate_handle(*a1, (__int64)"wma_set_arp_req_stats", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (_DWORD)result )
    return result;
  if ( (wma_is_vdev_valid(*a2, v14, v15, v16, v17, v18, v19, v20, v21) & 1) == 0 )
  {
    v31 = *a2;
    v50 = "%s: vdev id:%d is not active";
    return qdf_trace_msg(0x36u, 2u, v50, v22, v23, v24, v25, v26, v27, v28, v29, "wma_set_arp_req_stats", v31);
  }
  v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[3], *a2, 8);
  v31 = *a2;
  if ( !v30 )
  {
    v50 = "%s: Can't get vdev by vdev_id:%d";
    return qdf_trace_msg(0x36u, 2u, v50, v22, v23, v24, v25, v26, v27, v28, v29, "wma_set_arp_req_stats", v31);
  }
  v32 = v30;
  if ( (wma_is_vdev_up((unsigned int)v31) & 1) != 0 )
  {
    if ( (unsigned int)wmi_unified_set_arp_stats_req(v10, a2) )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: failed to set arp stats to FW",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "wma_set_arp_req_stats");
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev id:%d is not started",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "wma_set_arp_req_stats",
      *a2);
  }
  return wlan_objmgr_vdev_release_ref(v32, 8u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
}
