__int64 __fastcall lim_is_dot11h_power_capabilities_in_range(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( *(unsigned __int8 *)(a2 + 3058) <= (char)(wlan_reg_get_channel_reg_power_for_freq(
                                                   *(_QWORD *)(a1 + 21560),
                                                   *(_DWORD *)(a3 + 284),
                                                   a4,
                                                   a5,
                                                   a6,
                                                   a7,
                                                   a8,
                                                   a9,
                                                   a10,
                                                   a11)
                                               - *(_BYTE *)(*(_QWORD *)(a1 + 8) + 4411LL)) )
    return 0;
  qdf_trace_msg(
    0x35u,
    3u,
    "%s: minTxPower (STA): %d, localMaxTxPower (AP): %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "lim_is_dot11h_power_capabilities_in_range");
  return 16;
}
