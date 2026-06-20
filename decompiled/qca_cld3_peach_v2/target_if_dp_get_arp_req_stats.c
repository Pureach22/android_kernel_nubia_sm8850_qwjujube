__int64 __fastcall target_if_dp_get_arp_req_stats(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x20
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int arp_stats_req; // w0
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20
  const char *v42; // x2

  if ( !a1 )
  {
    v42 = "%s: PSOC is NULL!";
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v42 = "%s: wmi_handle is null";
LABEL_10:
    qdf_trace_msg(0x45u, 2u, v42, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dp_get_arp_req_stats");
    return 4;
  }
  v13 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( !v13 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Can't get vdev by vdev_id:%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_dp_get_arp_req_stats",
      *(unsigned int *)(a2 + 4));
    return 4;
  }
  v22 = v13;
  if ( wlan_cm_is_vdev_active(v13, v14, v15, v16, v17, v18, v19, v20, v21) )
  {
    arp_stats_req = wmi_unified_get_arp_stats_req(v11, a2);
    if ( arp_stats_req )
    {
      v41 = arp_stats_req;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: failed to send get arp stats to FW",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "target_if_dp_get_arp_req_stats");
    }
    else
    {
      v41 = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: vdev id:%d is not started",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_dp_get_arp_req_stats",
      *(unsigned int *)(a2 + 4));
    v41 = 4;
  }
  wlan_objmgr_vdev_release_ref(v22, 0x61u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
  return v41;
}
