bool __fastcall wlansap_is_6ghz_included_in_acs_range(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x20
  unsigned __int64 v12; // x21
  bool is_6ghz_chan_freq; // w0

  if ( a1 && (v9 = *(_QWORD *)(a1 + 1544)) != 0 && (v11 = *(_QWORD *)(v9 + 32)) != 0 && *(_BYTE *)(v9 + 40) )
  {
    v12 = 0;
    do
    {
      is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v11 + 4 * v12));
      if ( is_6ghz_chan_freq )
        break;
      ++v12;
    }
    while ( v12 < *(unsigned __int8 *)(*(_QWORD *)(a1 + 1544) + 40LL) );
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: NULL parameters",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlansap_is_6ghz_included_in_acs_range");
    return 0;
  }
  return is_6ghz_chan_freq;
}
