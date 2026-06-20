__int64 __fastcall hdd_close_pre_cac_adapter(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(__int64 **)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = nullptr;
  result = hdd_get_adapter_by_iface_name((__int64)a1, "precac");
  if ( result )
  {
    v3 = result;
    ucfg_pre_cac_clear_work(*a1);
    result = _osif_vdev_sync_trans_start_wait(*(_QWORD *)(v3 + 32), v20, (__int64)"hdd_close_pre_cac_adapter");
    if ( !(_DWORD)result )
    {
      osif_vdev_sync_unregister(*(_QWORD *)(v3 + 32));
      osif_vdev_sync_wait_for_ops((__int64)v20[0]);
      wlan_hdd_release_intf_addr((__int64)a1, (unsigned __int8 *)(v3 + 1617), v4, v5, v6, v7, v8, v9, v10, v11);
      *(_BYTE *)(v3 + 52797) = 1;
      hdd_close_adapter(a1, v3, 1, v12, v13, v14, v15, v16, v17, v18, v19);
      osif_vdev_sync_trans_stop((__int64)v20[0]);
      result = osif_vdev_sync_destroy((__int64)v20[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
