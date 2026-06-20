__int64 __fastcall policy_mgr_get_srd_enable_for_vdev(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  unsigned int *v4; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  char v14; // w8
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v3 )
  {
    v13 = *(_DWORD *)(v3 + 16);
    wlan_objmgr_vdev_release_ref(v3, 0x18u, v4, v5, v6, v7, v8, v9, v10, v11, v12);
    wlan_mlme_get_srd_master_mode_for_vdev(a1, v13, v16);
    v14 = v16[0];
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev is NULL",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_get_srd_enable_for_vdev");
    v14 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v14 & 1;
}
