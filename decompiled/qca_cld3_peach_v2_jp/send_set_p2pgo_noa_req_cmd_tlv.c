__int64 __fastcall send_set_p2pgo_noa_req_cmd_tlv(__int64 a1, __int64 a2)
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
  int v15; // w4
  __int64 v16; // x8
  int v17; // w6
  int v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  int v37; // [xsp+0h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x28u, "send_set_p2pgo_noa_req_cmd_tlv", 0x2Cu);
  if ( !v4 )
    return 16;
  v13 = *(_QWORD *)(v4 + 224);
  v14 = v4;
  *(_DWORD *)v13 = 14090252;
  v15 = *(unsigned __int8 *)(a2 + 25);
  if ( *(_BYTE *)(a2 + 8) == 1 )
    v16 = 20;
  else
    v16 = 12;
  v17 = *(_DWORD *)(a2 + v16);
  *(_DWORD *)(v13 + 20) = 5832720;
  *(_QWORD *)(v13 + 12) = 0x12001400000001LL;
  *(_DWORD *)(v13 + 4) = v15;
  *(_DWORD *)(v13 + 8) = v17 != 0;
  *(_DWORD *)(v13 + 24) = *(unsigned __int8 *)(a2 + 8);
  *(_DWORD *)(v13 + 28) = v17;
  *(_DWORD *)(v13 + 32) = *(_DWORD *)(a2 + 16);
  v18 = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(v13 + 36) = v18;
  v37 = v18;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: SET P2P GO NOA:vdev_id:%d count:%d duration:%d interval:%d start:%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_set_p2pgo_noa_req_cmd_tlv",
    v37);
  v19 = wmi_mtrace(126978, *(unsigned int *)(v13 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             0x28u,
             0x1F002u,
             "send_set_p2pgo_noa_req_cmd_tlv",
             0x50u,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26);
  if ( (_DWORD)result )
  {
    v36 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_FWTEST_P2P_SET_NOA_PARAM_CMDID",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_set_p2pgo_noa_req_cmd_tlv");
    wmi_buf_free();
    return v36;
  }
  return result;
}
