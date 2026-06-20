__int64 __fastcall if_mgr_disable_roaming(__int64 a1, __int64 a2, int a3)
{
  unsigned __int8 v3; // w8
  __int64 result; // x0
  _DWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a2 + 168);
  v5[0] = a3;
  v5[1] = v3;
  result = wlan_objmgr_pdev_iterate_obj_list(
             a1,
             2,
             (void (__fastcall *)(__int64, __int64, __int64))if_mgr_disable_roaming_on_vdev,
             (__int64)v5,
             0,
             0x4Eu);
  _ReadStatusReg(SP_EL0);
  return result;
}
