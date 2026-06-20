_QWORD *__fastcall wlan_hdd_pld_crash_shutdown(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *result; // x0
  unsigned int v9; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  result = _cds_get_context(54, (__int64)"wlan_hdd_crash_shutdown", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( result )
  {
    v9 = wma_crash_inject(result, 1, 0);
    if ( v9 )
    {
      return (_QWORD *)qdf_trace_msg(
                         0x33u,
                         2u,
                         "%s: Failed to send crash inject:%d",
                         v10,
                         v11,
                         v12,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         "wlan_hdd_crash_shutdown",
                         v9);
    }
    else
    {
      _cds_get_context(61, (__int64)"wlan_hdd_crash_shutdown", v10, v11, v12, v13, v14, v15, v16, v17);
      return (_QWORD *)hif_crash_shutdown();
    }
  }
  return result;
}
