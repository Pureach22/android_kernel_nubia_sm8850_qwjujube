__int64 __fastcall sme_register_bcn_report_pe_cb(
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a1 )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      mac_register_bcn_report_send_cb(a1, a2, v13, v14, v15, v16, v17, v18, v19, v20);
      qdf_mutex_release(a1 + 12776);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid mac context",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_register_bcn_report_pe_cb");
    return 4;
  }
  return result;
}
