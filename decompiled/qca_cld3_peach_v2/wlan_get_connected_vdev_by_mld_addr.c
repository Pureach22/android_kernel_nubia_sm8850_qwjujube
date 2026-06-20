__int64 __fastcall wlan_get_connected_vdev_by_mld_addr(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int16 v6; // w9
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  qdf_mem_set(v8, 8u, 0);
  v6 = *(_WORD *)(a2 + 4);
  LODWORD(v8[0]) = *(_DWORD *)a2;
  WORD2(v8[0]) = v6;
  wlan_objmgr_iterate_obj_list(a1, 2, wlan_get_connected_mlo_dev_ctx_handler, (__int64)v8, 1, 0x43u);
  result = BYTE6(v8[0]);
  if ( BYTE6(v8[0]) == 1 )
    *a3 = HIBYTE(v8[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
