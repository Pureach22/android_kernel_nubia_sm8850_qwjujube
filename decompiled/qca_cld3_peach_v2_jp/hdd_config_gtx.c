__int64 __fastcall hdd_config_gtx(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( *(unsigned __int8 *)(a2 + 4) < 2u )
  {
    v11 = sme_cli_set_command(*(unsigned __int8 *)(a1 + 8), 133, *(unsigned __int8 *)(a2 + 4), 1);
    if ( v11 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set GTX, %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_config_gtx",
        v11);
  }
  else
  {
    v10 = jiffies;
    if ( hdd_config_gtx___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: Invalid config_gtx value %d", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_config_gtx");
      hdd_config_gtx___last_ticks = v10;
    }
    return (unsigned int)-22;
  }
  return v11;
}
