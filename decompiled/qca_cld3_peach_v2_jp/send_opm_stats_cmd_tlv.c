__int64 __fastcall send_opm_stats_cmd_tlv(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x22
  __int64 v6; // x19
  _DWORD *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  __int64 v26; // x22

  v4 = wmi_buf_alloc_fl(a1, 8u, "send_opm_stats_cmd_tlv", 0x2063u);
  if ( !v4 )
    return 2;
  v5 = *(_DWORD **)(v4 + 224);
  v6 = v4;
  *v5 = 81199108;
  v7 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3704LL);
  if ( *(v7 - 1) != -2112860426 )
    __break(0x8228u);
  v5[1] = ((__int64 (__fastcall *)(__int64, _QWORD))v7)(a1, a2);
  qdf_mtrace(49, 100, 0xEA6u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v6,
             8u,
             0x1D026u,
             "send_opm_stats_cmd_tlv",
             0x2074u,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             v15);
  if ( (_DWORD)result )
  {
    v25 = result;
    v26 = jiffies;
    if ( send_opm_stats_cmd_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed with ret = %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "send_opm_stats_cmd_tlv",
        (unsigned int)result);
      send_opm_stats_cmd_tlv___last_ticks = v26;
    }
    wmi_buf_free();
    return v25;
  }
  return result;
}
