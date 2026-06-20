__int64 __fastcall hdd_disable_monitor_mode(
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
  __int64 (**v17)(void); // x8
  __int64 (*v18)(void); // x8

  context = _cds_get_context(71, (__int64)"hdd_disable_monitor_mode", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context || !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v9, v10, v11, v12, v13, v14, v15, v16, "cdp_reset_monitor_mode");
    return 0;
  }
  v17 = *(__int64 (***)(void))(*context + 24LL);
  if ( !v17 )
    return 0;
  v18 = *v17;
  if ( !v18 )
    return 0;
  if ( *((_DWORD *)v18 - 1) != -254072184 )
    __break(0x8228u);
  return v18();
}
