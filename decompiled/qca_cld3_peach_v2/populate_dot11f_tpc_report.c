__int64 __fastcall populate_dot11f_tpc_report(
        __int64 a1,
        _BYTE *a2,
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
  char channel_reg_power_for_freq; // w0
  unsigned int v13; // w20

  if ( (unsigned int)(*(_DWORD *)(a3 + 88) - 1) >= 2 )
  {
    v13 = 16;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to get the STAID in Populate Dot11fTPCReport; lim_get_mgmt_staid returned status %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "populate_dot11f_tpc_report",
      16);
  }
  else
  {
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(
                                   *(_QWORD *)(a1 + 21632),
                                   *(_DWORD *)(a3 + 284),
                                   a4,
                                   a5,
                                   a6,
                                   a7,
                                   a8,
                                   a9,
                                   a10,
                                   a11);
    v13 = 0;
    a2[2] = 0;
    a2[1] = channel_reg_power_for_freq;
    *a2 = 1;
  }
  return v13;
}
