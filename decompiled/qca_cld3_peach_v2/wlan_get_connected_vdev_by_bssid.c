__int64 __fastcall wlan_get_connected_vdev_by_bssid(__int64 a1, const void *a2, _BYTE *a3)
{
  __int64 v5; // x21
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 80);
  v7[0] = 0;
  qdf_mem_set(v7, 8u, 0);
  qdf_mem_copy(v7, a2, 6u);
  wlan_objmgr_iterate_obj_list(v5, 2, wlan_get_connected_vdev_handler, (__int64)v7, 1, 0x4Fu);
  result = BYTE6(v7[0]);
  if ( BYTE6(v7[0]) == 1 )
    *a3 = HIBYTE(v7[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
