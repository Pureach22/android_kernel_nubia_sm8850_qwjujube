__int64 __fastcall send_crash_inject_cmd_tlv(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  unsigned int v7; // w21
  __int64 system_time; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v4 = wmi_buf_alloc_fl(a1, 0xCu, "send_crash_inject_cmd_tlv", 0xCD9u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 9961480;
    v5[1] = *a2;
    v5[2] = a2[1];
    qdf_mtrace(49, 100, 0xE88u, 0xFFu, 0);
    v7 = v5[1];
    LODWORD(v5) = v5[2];
    system_time = qdf_mc_timer_get_system_time();
    qdf_trace_msg(
      0x31u,
      4u,
      "%s: type:%d delay_time_ms:%d current_time:%ld",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "send_crash_inject_cmd_tlv",
      v7,
      (unsigned int)v5,
      system_time);
    v25 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0xCu,
            0x1D008u,
            "send_crash_inject_cmd_tlv",
            0xCE9u,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v25 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set param command, ret = %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "send_crash_inject_cmd_tlv",
        v25);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v25;
}
