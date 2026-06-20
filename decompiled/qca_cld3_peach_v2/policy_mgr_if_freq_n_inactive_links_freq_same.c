__int64 __fastcall policy_mgr_if_freq_n_inactive_links_freq_same(__int64 a1, unsigned int a2)
{
  char v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  double v15; // d0
  char v16; // w0
  unsigned int *v17; // x8
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v26; // [xsp+0h] [xbp-10h] BYREF
  char v27; // [xsp+4h] [xbp-Ch]
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v26 = 0;
  v4 = 0;
  if ( (unsigned int)policy_mgr_get_mode_specific_conn_info(a1, 0, &v26, 0) == 1 )
  {
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           (unsigned __int8)v26,
           24);
    if ( v5 )
    {
      v14 = v5;
      v15 = mlo_mgr_if_freq_n_inactive_links_freq_same(v5, a2);
      v4 = v16;
      wlan_objmgr_vdev_release_ref(v14, 0x18u, v17, v15, v18, v19, v20, v21, v22, v23, v24);
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d not found",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "policy_mgr_if_freq_n_inactive_links_freq_same",
        (unsigned __int8)v26);
      v4 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4 & 1;
}
