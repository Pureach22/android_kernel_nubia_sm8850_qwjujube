__int64 __fastcall hdd_set_coex_traffic_shaping_mode(unsigned __int8 *a1, __int64 a2)
{
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  unsigned int v14; // w20

  v4 = _wlan_hdd_validate_context(*(_QWORD *)(*(_QWORD *)a1 + 24LL), "hdd_set_coex_traffic_shaping_mode");
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid HDD ctx, errno : %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_set_coex_traffic_shaping_mode",
      v4);
  }
  else
  {
    v14 = *(unsigned __int8 *)(a2 + 4);
    if ( v14 < 2 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Coex Traffic shaping mode : %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_set_coex_traffic_shaping_mode",
        *(unsigned __int8 *)(a2 + 4));
      return (unsigned int)hdd_send_coex_traffic_shaping_mode(a1[8], v14);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid traffic shaping mode : %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_set_coex_traffic_shaping_mode",
        *(unsigned __int8 *)(a2 + 4));
      return (unsigned int)-22;
    }
  }
  return v13;
}
