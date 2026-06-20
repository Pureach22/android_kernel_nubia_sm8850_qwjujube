__int64 __fastcall send_periodic_chan_stats_config_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  _DWORD *v6; // x21
  __int64 v7; // x19
  __int64 v8; // x1
  __int64 (__fastcall *v9)(__int64, __int64); // x8
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

  v4 = 16;
  v5 = wmi_buf_alloc_fl(a1, 0x10u, "send_periodic_chan_stats_config_cmd_tlv", 0x235Fu);
  if ( v5 )
  {
    v6 = *(_DWORD **)(v5 + 224);
    v7 = v5;
    *v6 = 34406412;
    v6[1] = *(unsigned __int8 *)(a2 + 4);
    v6[2] = *(_DWORD *)a2;
    v8 = *(unsigned int *)(a2 + 8);
    v9 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3664LL);
    if ( *((_DWORD *)v9 - 1) != -2112860426 )
      __break(0x8228u);
    v6[3] = v9(a1, v8);
    qdf_mtrace(49, 100, 0x221u, 0xFFu, 0);
    v4 = wmi_unified_cmd_send_fl(
           a1,
           v7,
           0x10u,
           0x4021u,
           "send_periodic_chan_stats_config_cmd_tlv",
           0x2371u,
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17);
    if ( v4 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Sending periodic chan stats config failed",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "send_periodic_chan_stats_config_cmd_tlv");
      wmi_buf_free();
    }
  }
  return v4;
}
