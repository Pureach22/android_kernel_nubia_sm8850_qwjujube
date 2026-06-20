__int64 __fastcall wlan_hdd_tdls_antenna_switch(__int64 a1, unsigned int a2)
{
  __int64 vdev_by_user; // x0
  __int64 v4; // x20
  double v5; // d0
  unsigned int v6; // w0
  unsigned int v7; // w19
  unsigned int *v8; // x8
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 1800LL) != 1 )
    return 0;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x57u, (__int64)"wlan_hdd_tdls_antenna_switch");
  if ( !vdev_by_user )
    return 4294967274LL;
  v4 = vdev_by_user;
  v5 = wlan_tdls_antenna_switch(vdev_by_user, a2);
  v7 = v6;
  _hdd_objmgr_put_vdev_by_user(
    v4,
    0x57u,
    (__int64)"wlan_hdd_tdls_antenna_switch",
    v8,
    v5,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15);
  return v7;
}
