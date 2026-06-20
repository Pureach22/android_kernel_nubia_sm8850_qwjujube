__int64 __fastcall rrm_get_mgmt_tx_power(
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
  unsigned __int8 *v10; // x19

  if ( a2 )
  {
    v10 = (unsigned __int8 *)(a2 + 7040);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: tx mgmt pwr %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "rrm_get_mgmt_tx_power",
      (unsigned int)*(char *)(a2 + 7040));
  }
  else
  {
    v10 = (unsigned __int8 *)(a1 + 20225);
  }
  return *v10;
}
