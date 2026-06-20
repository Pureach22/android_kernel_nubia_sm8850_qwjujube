__int64 __fastcall send_bss_color_change_enable_cmd_tlv(__int64 a1, int a2, char a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_bss_color_change_enable_cmd_tlv", 0x4DC4u);
  if ( !v6 )
    return 2;
  v7 = *(_DWORD **)(v6 + 224);
  v8 = v6;
  *v7 = 47251464;
  v7[1] = a2;
  v7[2] = a3 & 1;
  qdf_mtrace(49, 100, 0x38Cu, a2, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v8,
             0xCu,
             0x700Cu,
             "send_bss_color_change_enable_cmd_tlv",
             0x4DD1u,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_BSS_COLOR_CHANGE_ENABLE_CMDID",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_bss_color_change_enable_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
