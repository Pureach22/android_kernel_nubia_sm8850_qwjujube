__int64 __fastcall send_time_stamp_sync_cmd_tlv(__int64 a1)
{
  __int64 result; // x0
  _DWORD *v3; // x21
  __int64 v4; // x19
  int time_of_the_day_ms; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  result = wmi_buf_alloc_fl(a1, 0x10u, "send_time_stamp_sync_cmd_tlv", 0xED0u);
  if ( result )
  {
    v3 = *(_DWORD **)(result + 224);
    v4 = result;
    *v3 = 35454988;
    time_of_the_day_ms = qdf_get_time_of_the_day_ms();
    v3[3] = 0;
    v3[1] = 0;
    v3[2] = time_of_the_day_ms;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: WMA --> DBGLOG_TIME_STAMP_SYNC_CMDID mode %d time_stamp low %d high %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "send_time_stamp_sync_cmd_tlv",
      0);
    qdf_mtrace(49, 100, 0xE94u, 0xFFu, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v4,
               0x10u,
               0x1D014u,
               "send_time_stamp_sync_cmd_tlv",
               0xEECu,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21);
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_DBGLOG_TIME_STAMP_SYNC_CMDID command",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "send_time_stamp_sync_cmd_tlv");
      return wmi_buf_free();
    }
  }
  return result;
}
