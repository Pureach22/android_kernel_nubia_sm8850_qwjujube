__int64 __fastcall wlan_hdd_pld_suspend_noirq(__int64 a1)
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
  unsigned int v10; // w19
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  result = _osif_psoc_sync_op_start(a1, v11, "wlan_hdd_pld_suspend_noirq");
  if ( !(_DWORD)result )
  {
    v10 = wlan_hdd_bus_suspend_noirq(v2, v3, v4, v5, v6, v7, v8, v9);
    _osif_psoc_sync_op_stop(v11[0], "wlan_hdd_pld_suspend_noirq");
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
