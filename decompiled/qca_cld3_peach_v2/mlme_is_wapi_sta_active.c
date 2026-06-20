__int64 __fastcall mlme_is_wapi_sta_active(__int64 a1)
{
  _BYTE v2[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  wlan_objmgr_pdev_iterate_obj_list(
    a1,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))mlme_is_sta_vdev_wapi,
    (__int64)v2,
    0,
    0x43u);
  _ReadStatusReg(SP_EL0);
  return v2[0];
}
