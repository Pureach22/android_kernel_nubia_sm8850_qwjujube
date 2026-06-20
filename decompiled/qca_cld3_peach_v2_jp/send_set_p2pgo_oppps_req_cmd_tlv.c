__int64 __fastcall send_set_p2pgo_oppps_req_cmd_tlv(__int64 a1, __int64 a2)
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
  unsigned int v15; // w9
  int v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_p2pgo_oppps_req_cmd_tlv", 0x68u);
  if ( !v4 )
    return 16;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 14024712;
  v15 = v13[2] & 0xFFFFFF01;
  v13[1] = *(unsigned __int8 *)(a2 + 25);
  v16 = v15 | (*(_DWORD *)(a2 + 4) != 0);
  v13[2] = v16;
  v13[2] = v16 & 0xFFFFFF01 | (2 * (*(_DWORD *)(a2 + 4) & 0x7F));
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: SET P2P GO OPPPS:vdev_id:%d ctwindow:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_set_p2pgo_oppps_req_cmd_tlv");
  v17 = wmi_mtrace(53257, (unsigned int)v13[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0xCu,
             0xD009u,
             "send_set_p2pgo_oppps_req_cmd_tlv",
             0x7Cu,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24);
  if ( (_DWORD)result )
  {
    v34 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_P2P_SET_OPPPS_PARAM_CMDID",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_set_p2pgo_oppps_req_cmd_tlv");
    wmi_buf_free();
    return v34;
  }
  return result;
}
