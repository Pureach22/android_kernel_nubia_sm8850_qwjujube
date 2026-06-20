__int64 __fastcall hdd_set_11be_rate_code(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x8
  int v13; // w4
  __int64 v14; // x20
  __int64 v16; // x20
  __int64 v17; // x21

  if ( *(_DWORD *)(a1 + 40) != 1 || (v12 = *(_QWORD *)(a1 + 52832), v12 == -280) )
  {
    if ( (sme_is_feature_supported_by_fw(14) & 1) == 0 )
    {
      v16 = jiffies;
      if ( hdd_set_11be_rate_code___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Target does not support 11be",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_set_11be_rate_code");
        hdd_set_11be_rate_code___last_ticks = v16;
      }
      return 4294967291LL;
    }
  }
  else
  {
    v13 = *(_DWORD *)(v12 + 320);
    if ( v13 != 0x2000 && v13 != 0x4000 )
    {
      v14 = jiffies;
      if ( hdd_set_11be_rate_code___last_ticks_9 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid hw mode, SAP hw_mode= 0x%x, ch_freq = %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_set_11be_rate_code");
        hdd_set_11be_rate_code___last_ticks_9 = v14;
      }
      return 4294967291LL;
    }
  }
  if ( (a2 & 0xFF00) == 0x500 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: SET_11BE_RATE rate_code %d rix %d preamble %x nss %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_set_11be_rate_code",
      a2,
      a2 & 0x1F,
      5,
      (unsigned int)((unsigned __int8)a2 >> 5) + 1);
    return wma_cli_set_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 27, a2, 1);
  }
  v17 = jiffies;
  if ( hdd_set_11be_rate_code___last_ticks_11 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid input: %x", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_11be_rate_code", a2);
    hdd_set_11be_rate_code___last_ticks_11 = v17;
  }
  return 4294967291LL;
}
