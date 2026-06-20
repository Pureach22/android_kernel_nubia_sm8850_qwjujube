__int64 __fastcall send_vdev_stop_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  unsigned int v2; // w19
  int v5; // w22
  __int64 v6; // x0
  _DWORD *v7; // x24
  __int64 v8; // x20
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

  v2 = *a2;
  v5 = vdev_stop_mlo_params_size(a2);
  v6 = wmi_buf_alloc_fl(a1, v5 + 8, "send_vdev_stop_cmd_tlv", 0x513u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 6094852;
  v7[1] = *a2;
  vdev_stop_add_mlo_params(v7 + 2, a2);
  qdf_mtrace(49, 100, 0x286u, v7[1], 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v8,
                       v5 + 8,
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
    qdf_trace_msg(0x31u, 8u, "%s: vdev id = %d", v17, v18, v19, v20, v21, v22, v23, v24, "send_vdev_stop_cmd_tlv", v2);
    return 0;
  }
}
