__int64 __fastcall wlan_util_get_peer_count_for_mode(__int64 a1, unsigned int a2)
{
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = a2;
  wlan_objmgr_pdev_iterate_obj_list(
    a1,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))wlan_util_get_mode_specific_peer_count,
    (__int64)v3,
    0,
    0);
  _ReadStatusReg(SP_EL0);
  return WORD2(v3[0]);
}
