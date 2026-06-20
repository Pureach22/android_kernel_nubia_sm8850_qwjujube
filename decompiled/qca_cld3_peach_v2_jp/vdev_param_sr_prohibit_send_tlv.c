__int64 __fastcall vdev_param_sr_prohibit_send_tlv(__int64 a1, unsigned __int8 *a2)
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
  __int64 v13; // x22
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "vdev_param_sr_prohibit_send_tlv", 0x1B6u);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 224);
    v14 = v4;
    *(_DWORD *)v13 = 72876044;
    *(_QWORD *)(v13 + 4) = *a2;
    *(_DWORD *)(v13 + 12) = a2[1];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: SR Prohibit enabled: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "vdev_param_sr_prohibit_send_tlv");
    wmi_mtrace(0x5034u, *(_DWORD *)(v13 + 4), 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x10u,
               0x5034u,
               "vdev_param_sr_prohibit_send_tlv",
               0x1C9u,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set neighbour rx param",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "vdev_param_sr_prohibit_send_tlv");
    wmi_buf_free();
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "vdev_param_sr_prohibit_send_tlv");
  }
  return 16;
}
