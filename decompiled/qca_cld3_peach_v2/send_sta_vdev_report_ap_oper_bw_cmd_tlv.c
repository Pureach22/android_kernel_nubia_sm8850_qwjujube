__int64 __fastcall send_sta_vdev_report_ap_oper_bw_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x22
  __int64 v14; // x19
  unsigned int v15; // w8
  unsigned int v16; // w5
  unsigned int v17; // w20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_sta_vdev_report_ap_oper_bw_cmd_tlv", 0x5AC9u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 81985544;
    v13[1] = *a2;
    v15 = *((_DWORD *)a2 + 1) - 1;
    if ( v15 > 0x27 )
      v16 = 33;
    else
      v16 = dword_AD8F10[v15];
    v13[2] = v16;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id %u ap_phymode %u",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_sta_vdev_report_ap_oper_bw_cmd_tlv");
    qdf_mtrace(49, 100, 0x2B9u, v13[1], v13[2]);
    v17 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0xCu,
            0x5039u,
            "send_sta_vdev_report_ap_oper_bw_cmd_tlv",
            0x5ADAu,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( v17 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send ap operating bandwidth: %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "send_sta_vdev_report_ap_oper_bw_cmd_tlv",
        v17);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v17;
}
