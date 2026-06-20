__int64 __fastcall send_vdev_fils_enable_cmd_send(__int64 a1, unsigned __int8 *a2)
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
  _DWORD *v13; // x23
  __int64 v14; // x19
  int v15; // w6
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_vdev_fils_enable_cmd_send", 0x4E6Du);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 45219852;
  v15 = v13[3];
  v13[1] = *a2;
  v13[2] = *((_DWORD *)a2 + 1);
  if ( (a2[8] & 1) != 0 )
    v13[3] = v15 | 1;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev id: %d fd_period: %d cmd->Flags %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_vdev_fils_enable_cmd_send");
  qdf_mtrace(49, 100, 0x591u, v13[1], v13[2]);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x10u,
             0xB011u,
             "send_vdev_fils_enable_cmd_send",
             0x4E7Fu,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Sending FILS cmd failed, vdev_id: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_vdev_fils_enable_cmd_send",
      *a2);
    wmi_buf_free();
    return 16;
  }
  return result;
}
