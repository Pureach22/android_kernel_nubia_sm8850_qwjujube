bool __fastcall wlan_ll_sap_is_cur_cu_greater_than_th(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 comp_private_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int trnsprt_switch_rjt_th_cu; // w0
  unsigned __int8 v45[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45[0] = 1;
  policy_mgr_get_mac_id_by_session_id(a1, a2, v45);
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 105);
  if ( v4 )
  {
    v13 = v4;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v4, 0x34u);
    if ( comp_private_obj )
    {
      v24 = *(_DWORD *)(comp_private_obj + 32);
      wlan_objmgr_vdev_release_ref(v13, 0x69u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
      goto LABEL_7;
    }
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: ll_sap obj null ref by vdev: %u",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "ll_sap_get_cur_freq_unused_cu",
      (unsigned __int8)a2);
    wlan_objmgr_vdev_release_ref(v13, 0x69u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
  }
  else
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ll_sap_get_cur_freq_unused_cu",
      (unsigned __int8)a2);
  }
  v24 = 0;
LABEL_7:
  trnsprt_switch_rjt_th_cu = wlan_dcs_get_trnsprt_switch_rjt_th_cu(a1, v45[0], v25, v26, v27, v28, v29, v30, v31, v32);
  _ReadStatusReg(SP_EL0);
  return v24 && v24 > trnsprt_switch_rjt_th_cu;
}
