__int64 __fastcall wlan_util_is_vdev_in_cac_wait(__int64 a1, unsigned int a2)
{
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  wlan_objmgr_pdev_iterate_obj_list(
    a1,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))vdev_cac_in_progress,
    (__int64)v3,
    0,
    a2);
  _ReadStatusReg(SP_EL0);
  return v3[0];
}
