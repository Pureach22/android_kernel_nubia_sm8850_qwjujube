__int64 __fastcall wlan_hdd_pld_suspend(
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
  _QWORD *context; // x0
  _QWORD *v11; // x20
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_pld_suspend", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v11 = context;
    result = _wlan_hdd_validate_context(context, "wlan_hdd_pld_suspend");
    if ( !(_DWORD)result )
    {
      hdd_psoc_idle_timer_stop(v11);
      result = _osif_psoc_sync_op_start(a1, v22, "wlan_hdd_pld_suspend");
      if ( !(_DWORD)result )
      {
        v21 = wlan_hdd_bus_suspend(v13, v14, v15, v16, v17, v18, v19, v20);
        _osif_psoc_sync_op_stop(v22[0], "wlan_hdd_pld_suspend");
        result = v21;
      }
    }
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
