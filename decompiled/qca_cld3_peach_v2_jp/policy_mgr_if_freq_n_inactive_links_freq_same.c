__int64 __fastcall policy_mgr_if_freq_n_inactive_links_freq_same(__int64 a1)
{
  __int64 v2; // x0
  unsigned int *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v13; // [xsp+0h] [xbp-10h] BYREF
  char v14; // [xsp+4h] [xbp-Ch]
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v13 = 0;
  if ( (unsigned int)policy_mgr_get_mode_specific_conn_info(a1, 0, &v13, 0) == 1 )
  {
    v2 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned __int8)v13,
           24);
    if ( v2 )
      wlan_objmgr_vdev_release_ref(v2, 0x18u, v3, v4, v5, v6, v7, v8, v9, v10, v11);
    else
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d not found",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "policy_mgr_if_freq_n_inactive_links_freq_same",
        (unsigned __int8)v13);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
