__int64 __fastcall send_set_enable_disable_mcc_adaptive_scheduler_cmd_tlv(__int64 a1, int a2, unsigned int a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x23
  __int64 v8; // x19
  _DWORD *v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w20

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_set_enable_disable_mcc_adaptive_scheduler_cmd_tlv", 0x31u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 13565960;
  v7[1] = a2;
  v9 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *(v9 - 1) != -2112860426 )
    __break(0x8228u);
  v7[2] = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(a1, a3);
  wmi_mtrace(0x21001u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0xCu,
             0x21001u,
             "send_set_enable_disable_mcc_adaptive_scheduler_cmd_tlv",
             0x43u,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17);
  if ( (_DWORD)result )
  {
    v27 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send enable/disable MCC adaptive scheduler command",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "send_set_enable_disable_mcc_adaptive_scheduler_cmd_tlv");
    wmi_buf_free();
    return v27;
  }
  return result;
}
