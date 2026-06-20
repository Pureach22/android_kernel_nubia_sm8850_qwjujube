__int64 __fastcall target_if_dp_set_arp_req_stats(
        __int64 a1,
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
  unsigned int *v31; // x8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  const char *v41; // x2
  unsigned int v43; // w0

  if ( !a1 )
  {
    v41 = "%s: PSOC is NULL!";
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 16)) == 0 )
  {
    v41 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x45u, 2u, v41, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_dp_set_arp_req_stats");
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
      "target_if_dp_set_arp_req_stats",
      *a2);
    return 4;
  }
  v22 = v13;
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev id:%d is not started",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "target_if_dp_set_arp_req_stats",
      *a2);
    v40 = 4;
  }
  else
  {
    v43 = wmi_unified_set_arp_stats_req(v11, a2);
    if ( v43 )
    {
      v40 = v43;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: failed to set arp stats to FW",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "target_if_dp_set_arp_req_stats");
    }
    else
    {
      v40 = 0;
    }
  }
  wlan_objmgr_vdev_release_ref(v22, 0x61u, v31, v32, v33, v34, v35, v36, v37, v38, v39);
  return v40;
}
