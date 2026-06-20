__int64 __fastcall send_get_thermal_stats_cmd_tlv(__int64 a1, int a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  unsigned int v16; // w20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v6 = wmi_buf_alloc_fl(a1, 0xCu, "send_get_thermal_stats_cmd_tlv", 0x1C5u);
  if ( v6 )
  {
    v15 = *(_DWORD **)(v6 + 224);
    *v15 = 66519048;
    v15[1] = a3;
    v15[2] = a2;
    v16 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0xCu,
            0x16011u,
            "send_get_thermal_stats_cmd_tlv",
            0x1D3u,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14);
    if ( v16 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send get thermal stats cmd = %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "send_get_thermal_stats_cmd_tlv",
        v16);
      wmi_buf_free();
    }
  }
  else
  {
    v16 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to allocate wmi buffer",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "send_get_thermal_stats_cmd_tlv");
  }
  return v16;
}
