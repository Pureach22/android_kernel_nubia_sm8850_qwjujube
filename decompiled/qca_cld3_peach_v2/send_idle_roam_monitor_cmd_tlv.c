__int64 __fastcall send_idle_roam_monitor_cmd_tlv(__int64 a1, char a2)
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
  _DWORD *v13; // x8
  __int64 v14; // x19
  int v15; // w4
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_idle_roam_monitor_cmd_tlv", 0x15ABu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  if ( a2 )
    v15 = 1;
  else
    v15 = 2;
  *v13 = 52363268;
  v13[1] = v15;
  qdf_trace_msg(0x31u, 8u, "%s: val: %d", v5, v6, v7, v8, v9, v10, v11, v12, "send_idle_roam_monitor_cmd_tlv");
  result = wmi_unified_cmd_send_fl(
             a1,
             v14,
             8u,
             0x1D01Au,
             "send_idle_roam_monitor_cmd_tlv",
             0x15BAu,
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
    wmi_buf_free();
    return 16;
  }
  return result;
}
