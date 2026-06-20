__int64 __fastcall wlan_mlme_get_beacon_interval(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  wlan_util_vdev_mlme_get_param(comp_private_obj, 0, &v11, v2, v3, v4, v5, v6, v7, v8, v9);
  _ReadStatusReg(SP_EL0);
  return v11;
}
