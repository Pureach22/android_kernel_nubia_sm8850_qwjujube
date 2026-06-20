bool __fastcall mlo_mgr_is_link_switch_in_progress_by_psoc(__int64 a1)
{
  int v1; // w8
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  wlan_objmgr_iterate_obj_list(a1, 2, mlo_mgr_vdev_iterate_handler, (__int64)&v3, 1, 0x5Au);
  v1 = v3;
  _ReadStatusReg(SP_EL0);
  return v1 != 0;
}
