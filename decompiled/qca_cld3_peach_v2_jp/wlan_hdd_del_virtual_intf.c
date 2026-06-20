__int64 __fastcall wlan_hdd_del_virtual_intf(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 result; // x0
  double v7; // d0
  __int64 v8; // x8
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w19
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a2 + 32);
  v17[0] = 0;
  v5 = v4 + 53248;
  *(_BYTE *)(v4 + 55484) = 1;
  result = _osif_vdev_sync_trans_start_wait(*(_QWORD *)(a2 + 32), v17, "wlan_hdd_del_virtual_intf");
  if ( !(_DWORD)result )
  {
    osif_vdev_sync_unregister(*(_QWORD *)(a2 + 32));
    v7 = osif_vdev_sync_wait_for_ops(v17[0]);
    *(_BYTE *)(v5 + 2237) = 1;
    v16 = _wlan_hdd_del_virtual_intf(a1, a2, v8, v7, v9, v10, v11, v12, v13, v14, v15);
    osif_vdev_sync_trans_stop(v17[0]);
    osif_vdev_sync_destroy(v17[0]);
    result = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
