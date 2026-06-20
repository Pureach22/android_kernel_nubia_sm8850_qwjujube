__int64 __fastcall send_vdev_stop_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v3; // w19
  __int64 v5; // x0
  _DWORD *v6; // x8
  __int64 v7; // x20
  int v8; // w3
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v3 = *a2;
  v5 = wmi_buf_alloc_fl(a1, 0xCu, "send_vdev_stop_cmd_tlv", 0x513u);
  if ( !v5 )
    return 2;
  v6 = *(_DWORD **)(v5 + 224);
  v7 = v5;
  *v6 = 6094852;
  v8 = *a2;
  v6[1] = v8;
  v6[2] = 1179648;
  qdf_mtrace(49, 100, 0x286u, v8, 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v7,
                       0xCu,
                       0x5006u,
                       "send_vdev_stop_cmd_tlv",
                       0x521u,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send vdev stop command",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "send_vdev_stop_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    qdf_trace_msg(0x31u, 8u, "%s: vdev id = %d", v17, v18, v19, v20, v21, v22, v23, v24, "send_vdev_stop_cmd_tlv", v3);
    return 0;
  }
}
