__int64 __fastcall policy_mgr_get_sap_scc_freq_nan_present(__int64 a1)
{
  _QWORD *v1; // x18
  unsigned int disc_24g_ch_freq; // w19
  unsigned int mode_specific_conn_info; // w0
  unsigned int v5; // w21
  __int64 v6; // x0
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  char v16; // w23
  char v17; // w22
  char v18; // w21
  int v19; // w20
  char v20; // w24
  unsigned __int8 *v21; // x8
  __int64 v22; // x0
  unsigned int *v23; // x8
  __int64 v24; // x0
  unsigned int *v25; // x8
  unsigned int v26; // w25
  __int64 v27; // d4
  __int64 v28; // d5
  __int64 v29; // x0
  unsigned int *v30; // x8
  __int64 v31; // x0
  unsigned int *v32; // x8
  int v34; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v35; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v36; // [xsp+10h] [xbp-20h] BYREF
  __int64 v37; // [xsp+18h] [xbp-18h]
  unsigned int v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  v34 = 0;
  disc_24g_ch_freq = wlan_nan_get_disc_24g_ch_freq();
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                              a1,
                              (unsigned __int64)&v36,
                              (unsigned __int64)&v34,
                              0);
  if ( !mode_specific_conn_info )
    goto LABEL_41;
  v5 = mode_specific_conn_info;
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         a1,
         (unsigned __int8)v34,
         24);
  if ( !v6 )
  {
    v21 = (unsigned __int8 *)&v34;
LABEL_40:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid vdev for id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "policy_mgr_get_ml_and_non_ml_mode_count",
      *v21);
LABEL_41:
    _ReadStatusReg(SP_EL0);
    return disc_24g_ch_freq;
  }
  wlan_objmgr_vdev_release_ref(v6, 0x18u, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v5 == 1 )
  {
    v16 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v20 = 1;
    goto LABEL_13;
  }
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, BYTE1(v34), 24);
  if ( !v22 )
  {
    v21 = (unsigned __int8 *)&v34 + 1;
    goto LABEL_40;
  }
  wlan_objmgr_vdev_release_ref(v22, 0x18u, v23, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v5 < 3 )
  {
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 1;
    goto LABEL_13;
  }
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, BYTE2(v34), 24);
  if ( !v24 )
  {
    v21 = (unsigned __int8 *)&v34 + 2;
    goto LABEL_40;
  }
  wlan_objmgr_vdev_release_ref(v24, 0x18u, v25, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v5 == 3 )
  {
    v20 = 0;
    v16 = 0;
    v18 = 0;
    v19 = 0;
    v17 = 1;
    goto LABEL_13;
  }
  v29 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, HIBYTE(v34), 24);
  if ( !v29 )
  {
    v21 = (unsigned __int8 *)&v34 + 3;
    goto LABEL_40;
  }
  wlan_objmgr_vdev_release_ref(v29, 0x18u, v30, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v5 < 5 )
  {
    v20 = 0;
    v16 = 0;
    v17 = 0;
    v19 = 0;
    v18 = 1;
    goto LABEL_13;
  }
  v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v35, 24);
  if ( !v31 )
  {
    v21 = &v35;
    goto LABEL_40;
  }
  wlan_objmgr_vdev_release_ref(v31, 0x18u, v32, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v5 != 5 )
    goto LABEL_43;
  v20 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 1;
LABEL_13:
  if ( wlan_reg_is_24ghz_ch_freq(v36) )
    v26 = v36;
  else
    v26 = 0;
  if ( (v20 & 1) != 0 )
    goto LABEL_29;
  if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v36)) )
    v26 = HIDWORD(v36);
  if ( (v16 & 1) != 0 )
    goto LABEL_29;
  if ( wlan_reg_is_24ghz_ch_freq(v37) )
    v26 = v37;
  if ( (v17 & 1) != 0 )
    goto LABEL_29;
  if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v37)) )
    v26 = HIDWORD(v37);
  if ( (v18 & 1) != 0 )
    goto LABEL_29;
  if ( wlan_reg_is_24ghz_ch_freq(v38) )
    v26 = v38;
  if ( v19 )
  {
LABEL_29:
    if ( v26 )
      disc_24g_ch_freq = v26;
    goto LABEL_41;
  }
  __break(0x5512u);
LABEL_43:
  __break(1u);
  *v1 = v27;
  v1[1] = v28;
  return policy_mgr_is_restart_sap_required();
}
