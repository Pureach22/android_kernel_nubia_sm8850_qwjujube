__int64 __fastcall send_pdev_set_hw_mode_cmd_tlv(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  __int64 (__fastcall *v7)(__int64, __int64); // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
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

  v4 = wmi_buf_alloc_fl(a1, 0x10u, "send_pdev_set_hw_mode_cmd_tlv", 0xBA7u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 33751052;
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *((_DWORD *)v7 - 1) != -2112860426 )
    __break(0x8228u);
  v5[1] = v7(a1, 255);
  v5[2] = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: HW mode index:%d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "send_pdev_set_hw_mode_cmd_tlv",
    a2);
  qdf_mtrace(49, 100, 0x21Eu, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             0x10u,
             0x401Eu,
             "send_pdev_set_hw_mode_cmd_tlv",
             0xBB9u,
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
      "%s: Failed to send WMI_PDEV_SET_HW_MODE_CMDID",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "send_pdev_set_hw_mode_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
