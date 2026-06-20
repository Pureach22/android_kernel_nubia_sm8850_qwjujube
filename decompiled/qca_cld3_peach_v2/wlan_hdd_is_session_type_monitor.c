bool __fastcall wlan_hdd_is_session_type_monitor(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int conparam; // w0

  if ( _cds_get_context(51, (__int64)"wlan_hdd_is_session_type_monitor", a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    conparam = cds_get_conparam();
    return a1 == 6 && conparam != 4;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: HDD context is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_hdd_is_session_type_monitor");
    return 0;
  }
}
