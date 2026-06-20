__int64 __fastcall wlan_util_is_vdev_active(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  _BYTE v3[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  if ( a1 )
  {
    wlan_objmgr_pdev_iterate_obj_list(
      a1,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))wlan_vdev_active,
      (__int64)v3,
      0,
      a2);
    result = 4 * (unsigned int)(v3[0] != 1);
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
