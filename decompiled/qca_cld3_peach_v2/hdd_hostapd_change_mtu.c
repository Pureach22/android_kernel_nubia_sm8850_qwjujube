__int64 __fastcall hdd_hostapd_change_mtu(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  result = _osif_vdev_sync_op_start(a1, v11, "hdd_hostapd_change_mtu");
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", v3, v4, v5, v6, v7, v8, v9, v10, "__hdd_hostapd_change_mtu", a1 + 296);
    _osif_vdev_sync_op_stop(v11[0], "hdd_hostapd_change_mtu");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
