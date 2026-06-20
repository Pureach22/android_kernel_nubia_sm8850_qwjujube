__int64 __fastcall send_ipa_offload_control_cmd_tlv(__int64 a1, unsigned int *a2)
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
  __int64 v13; // x19
  _DWORD *v14; // x8
  unsigned int v15; // w3
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

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_ipa_offload_control_cmd_tlv", 0x1A5Du);
  if ( !v4 )
    return 2;
  v13 = v4;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: offload_type=%d, enable=%d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "send_ipa_offload_control_cmd_tlv",
    *a2,
    a2[2]);
  v14 = *(_DWORD **)(v13 + 224);
  *v14 = 22806540;
  v14[1] = *a2;
  v15 = a2[1];
  v14[2] = v15;
  v14[3] = a2[2];
  qdf_mtrace(49, 100, 0x1701u, v15, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v13,
             0x10u,
             0x2E001u,
             "send_ipa_offload_control_cmd_tlv",
             0x1A72u,
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
      "%s: Failed to send WMI_IPA_OFFLOAD_ENABLE_DISABLE_CMDID",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_ipa_offload_control_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
