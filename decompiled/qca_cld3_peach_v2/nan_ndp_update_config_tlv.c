__int64 __fastcall nan_ndp_update_config_tlv(
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
  int v12; // w22
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x23
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v12 = *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id: %d, ndp_instance_id: %d, latency_ms: %d, tput_mbps: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "nan_ndp_update_config_tlv",
    *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL),
    a2[2],
    a2[3],
    a2[4]);
  v13 = wmi_buf_alloc_fl(a1, 0x14u, "nan_ndp_update_config_tlv", 0x307u);
  if ( v13 )
  {
    v22 = *(_DWORD **)(v13 + 224);
    v23 = v13;
    *v22 = 84017168;
    v22[2] = v12;
    v22[1] = a2[2];
    v22[3] = a2[3];
    v22[4] = a2[4];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: latency_ms: %d, tput_mbps: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "nan_ndp_update_config_tlv");
    wmi_mtrace(0x38006u, v22[2], 0);
    v32 = wmi_unified_cmd_send_fl(
            a1,
            v23,
            0x14u,
            0x38006u,
            "nan_ndp_update_config_tlv",
            0x31Au,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
    if ( v32 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_NDP_SET_LATENCY_TPUT_CMDID failed, ret: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "nan_ndp_update_config_tlv",
        v32);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v32;
}
