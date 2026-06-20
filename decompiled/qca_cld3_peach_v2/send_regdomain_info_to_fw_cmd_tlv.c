__int64 __fastcall send_regdomain_info_to_fw_cmd_tlv(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        unsigned __int8 a5,
        unsigned __int8 a6)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v12 = wmi_buf_alloc_fl(a1, 0xE0u, "send_regdomain_info_to_fw_cmd_tlv", 0x21EFu);
  if ( !v12 )
    return 2;
  v21 = *(_DWORD **)(v12 + 224);
  v22 = v12;
  *v21 = 5308636;
  v21[2] = a2;
  v21[3] = a3;
  v21[4] = a4;
  v21[5] = a5;
  v21[6] = a6;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: regd = %x, regd_2g = %x, regd_5g = %x, ctl_2g = %x, ctl_5g = %x",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "send_regdomain_info_to_fw_cmd_tlv",
    a2,
    a6);
  qdf_mtrace(49, 100, 0x201u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v22,
             0xE0u,
             0x4001u,
             "send_regdomain_info_to_fw_cmd_tlv",
             0x2205u,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send pdev set regdomain command",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "send_regdomain_info_to_fw_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
