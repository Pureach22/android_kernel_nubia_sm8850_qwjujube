__int64 __fastcall send_pdev_set_rf_path_cmd_tlv(__int64 a1, unsigned int a2, unsigned __int8 a3)
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
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_pdev_set_rf_path_cmd_tlv", 0xBD7u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 76808200;
  v9 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( *(v9 - 1) != -2112860426 )
    __break(0x8228u);
  v7[1] = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(a1, a3);
  v7[2] = a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: HW mode index:%d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "send_pdev_set_rf_path_cmd_tlv",
    a2);
  qdf_mtrace(49, 100, 0x250u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0xCu,
             0x4050u,
             "send_pdev_set_rf_path_cmd_tlv",
             0xBE9u,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_PDEV_SET_RF_PATH_CMDID",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "send_pdev_set_rf_path_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
