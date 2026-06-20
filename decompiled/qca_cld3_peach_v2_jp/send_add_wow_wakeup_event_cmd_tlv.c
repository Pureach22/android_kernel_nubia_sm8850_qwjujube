__int64 __fastcall send_add_wow_wakeup_event_cmd_tlv(__int64 a1, int a2, const void *a3, char a4)
{
  __int64 v8; // x0
  _DWORD *v9; // x24
  __int64 v10; // x19
  const char *v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v8 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_add_wow_wakeup_event_cmd_tlv", 0x83u);
  if ( !v8 )
    return 2;
  v9 = *(_DWORD **)(v8 + 224);
  v10 = v8;
  *v9 = 8978456;
  v9[1] = a2;
  v9[2] = a4 & 1;
  if ( (a4 & 1) != 0 )
    v11 = "enabled";
  else
    v11 = "disabled";
  qdf_mem_copy(v9 + 3, a3, 0x10u);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Wakeup pattern 0x%x|%x|%x|%x %s in fw",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "send_add_wow_wakeup_event_cmd_tlv",
    (unsigned int)v9[3],
    (unsigned int)v9[4],
    (unsigned int)v9[5],
    (unsigned int)v9[6],
    v11);
  wmi_mtrace(0x13003u, v9[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v10,
             0x1Cu,
             0x13003u,
             "send_add_wow_wakeup_event_cmd_tlv",
             0x98u,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to config wow wakeup event %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "send_add_wow_wakeup_event_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
