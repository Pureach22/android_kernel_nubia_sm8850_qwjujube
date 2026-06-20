__int64 __fastcall send_suspend_cmd_tlv(__int64 a1, _BYTE *a2, unsigned __int8 a3)
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
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_suspend_cmd_tlv", 0xC08u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 7536648;
  v7[2] = *a2 != 0;
  v9 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *(v9 - 1) != -2112860426 )
    __break(0x8228u);
  v7[1] = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(a1, a3);
  qdf_mtrace(49, 100, 0x881u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0xCu,
             0x11001u,
             "send_suspend_cmd_tlv",
             0xC1Cu,
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
    v19 = result;
    wmi_buf_free();
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_PDEV_SUSPEND_CMDID command",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "send_suspend_cmd_tlv");
    return v19;
  }
  return result;
}
