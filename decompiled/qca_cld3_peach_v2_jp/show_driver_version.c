__int64 __fastcall show_driver_version(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w20
  int v22; // w0
  __int64 v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"show_driver_version", a1, a2, a3, a4, a5, a6, a7, a8);
  v24[0] = 0;
  v21 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"show_driver_version",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( !v21 )
  {
    v21 = _osif_psoc_sync_op_start(context[12], v24, (__int64)"show_driver_version");
    if ( !v21 )
    {
      scnprintf(a11, 4096, "5.2.1.137C");
      v21 = v22;
      _osif_psoc_sync_op_stop(v24[0], (__int64)"show_driver_version");
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
