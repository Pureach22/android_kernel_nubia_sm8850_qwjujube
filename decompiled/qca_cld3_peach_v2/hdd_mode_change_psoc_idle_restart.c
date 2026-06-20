__int64 __fastcall hdd_mode_change_psoc_idle_restart(
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
  _QWORD *v9; // x19
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int started; // w19

  context = _cds_get_context(51, (__int64)"hdd_mode_change_psoc_idle_restart", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 4294967274LL;
  v9 = context;
  result = hdd_soc_idle_restart_lock();
  if ( !(_DWORD)result )
  {
    started = hdd_wlan_start_modules(v9, 0, v11, v12, v13, v14, v15, v16, v17, v18);
    hdd_soc_idle_restart_unlock();
    return started;
  }
  return result;
}
