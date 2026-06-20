__int64 __fastcall hdd_green_ap_enable_egap(
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
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19

  result = ucfg_green_ap_enable_egap(*(_QWORD *)(a1 + 8), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
  {
    v18 = result;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enhance green ap is not enabled, status %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "hdd_green_ap_enable_egap",
      (unsigned int)result);
    return qdf_status_to_os_return(v18);
  }
  return result;
}
