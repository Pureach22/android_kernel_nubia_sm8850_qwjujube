__int64 __fastcall hdd_mode_change_psoc_idle_shutdown(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  context = _cds_get_context(51, (__int64)"hdd_mode_change_psoc_idle_shutdown", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
    return hdd_wlan_stop_modules(context, 1, v9, v10, v11, v12, v13, v14, v15, v16);
  else
    return 4294967274LL;
}
