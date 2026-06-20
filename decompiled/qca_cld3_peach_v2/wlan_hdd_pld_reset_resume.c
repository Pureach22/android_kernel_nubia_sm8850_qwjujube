__int64 __fastcall wlan_hdd_pld_reset_resume(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _QWORD *context; // x0
  unsigned int v11; // w19
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  result = _osif_psoc_sync_op_start(a1, v12, "wlan_hdd_pld_reset_resume");
  if ( !(_DWORD)result )
  {
    context = _cds_get_context(61, (__int64)"wlan_hdd_bus_reset_resume", v2, v3, v4, v5, v6, v7, v8, v9);
    if ( context )
      v11 = hif_bus_reset_resume((__int64)context);
    else
      v11 = -14;
    _osif_psoc_sync_op_stop(v12[0], "wlan_hdd_pld_reset_resume");
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
