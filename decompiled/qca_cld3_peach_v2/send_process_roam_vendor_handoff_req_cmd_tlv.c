__int64 __fastcall send_process_roam_vendor_handoff_req_cmd_tlv(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x23
  __int64 v16; // x19
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

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_process_roam_vendor_handoff_req_cmd_tlv", 0xEB0u);
  if ( !v6 )
    return 2;
  v15 = *(_DWORD **)(v6 + 224);
  v16 = v6;
  *v15 = 71303176;
  v15[1] = a2;
  if ( (unsigned int)(a3 - 1) >= 8 && a3 != -1 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Invalid param id",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "convert_roam_vendor_control_param");
    a3 = 0;
  }
  v15[2] = a3;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Send GET_VENDOR_CONTROL_PARAM cmd vdev_id:%d, param_id:0x%x",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_process_roam_vendor_handoff_req_cmd_tlv");
  wmi_mtrace(0xB01Du, v15[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0xCu,
             0xB01Du,
             "send_process_roam_vendor_handoff_req_cmd_tlv",
             0xEC1u,
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
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send get vendor control param command",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "send_process_roam_vendor_handoff_req_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
