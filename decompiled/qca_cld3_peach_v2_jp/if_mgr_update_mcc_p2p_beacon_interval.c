__int64 __fastcall if_mgr_update_mcc_p2p_beacon_interval(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 result; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 80)) != 0 && (v6[0] = 0, wlan_mlme_get_mcc_feature(v3, v6), v6[0]) )
  {
    wlan_objmgr_pdev_iterate_obj_list(
      v2,
      2,
      (void (__fastcall *)(__int64, __int64, __int64))if_mgr_update_beacon_interval,
      a2,
      0,
      0x4Eu);
    result = *(unsigned int *)(a2 + 16);
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
