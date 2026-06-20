__int64 __fastcall pre_cac_is_active(__int64 a1)
{
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  wlan_objmgr_iterate_obj_list(a1, 2, pre_cac_is_active_vdev_handler, (__int64)v2, 1, 0x60u);
  _ReadStatusReg(SP_EL0);
  return v2[0];
}
