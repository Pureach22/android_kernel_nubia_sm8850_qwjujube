__int64 __fastcall send_vdev_down_cmd_tlv(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_vdev_down_cmd_tlv", 0x538u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 6160388;
  v5[1] = a2;
  qdf_mtrace(49, 100, 0x287u, a2, 0);
  if ( (unsigned int)wmi_unified_cmd_send_fl(
                       a1,
                       v6,
                       8u,
                       0x5007u,
                       "send_vdev_down_cmd_tlv",
                       0x542u,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11,
                       v12,
                       v13,
                       v14) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send vdev down",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "send_vdev_down_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  else
  {
    qdf_trace_msg(0x31u, 8u, "%s: vdev_id %d", v15, v16, v17, v18, v19, v20, v21, v22, "send_vdev_down_cmd_tlv", a2);
    return 0;
  }
}
