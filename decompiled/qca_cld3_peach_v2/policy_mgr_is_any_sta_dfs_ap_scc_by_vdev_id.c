__int64 __fastcall policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w21
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  char is_mlo_vdev; // w22
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w19
  __int64 context; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  int v44; // [xsp+0h] [xbp-10h] BYREF
  int v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v4 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Vdev[%d] is null",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id",
      v2);
LABEL_27:
    result = 0;
    goto LABEL_28;
  }
  v13 = v4;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v4, v5, v6, v7, v8, v9, v10, v11, v12);
  wlan_objmgr_vdev_release_ref(v13, 0x18u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( (is_mlo_vdev & 1) != 0 )
    goto LABEL_27;
  policy_mgr_is_any_dfs_beaconing_session_present(a1, &v45, &v44);
  v24 = v45;
  if ( !v45 )
    goto LABEL_27;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id");
    goto LABEL_27;
  }
  v34 = context;
  qdf_mutex_acquire(context + 56);
  if ( (BYTE4(qword_8D4F00) != 1
     || ((unsigned int)pm_conc_connection_list | 2) != 2
     || (_DWORD)qword_8D4F00 != v2
     || HIDWORD(pm_conc_connection_list) != v24)
    && (BYTE4(qword_8D4F24) != 1
     || ((unsigned int)qword_8D4F0C | 2) != 2
     || (_DWORD)qword_8D4F24 != v2
     || HIDWORD(qword_8D4F0C) != v24)
    && (BYTE4(qword_8D4F48) != 1
     || ((unsigned int)qword_8D4F30 | 2) != 2
     || (_DWORD)qword_8D4F48 != v2
     || HIDWORD(qword_8D4F30) != v24)
    && (BYTE4(qword_8D4F6C) != 1
     || ((unsigned int)qword_8D4F54 | 2) != 2
     || (_DWORD)qword_8D4F6C != v2
     || HIDWORD(qword_8D4F54) != v24)
    && (BYTE4(qword_8D4F90) != 1
     || ((unsigned int)qword_8D4F78 | 2) != 2
     || (_DWORD)qword_8D4F90 != v2
     || HIDWORD(qword_8D4F78) != v24) )
  {
    qdf_mutex_release(v34 + 56);
    goto LABEL_27;
  }
  qdf_trace_msg(0x4Fu, 8u, "sta/p2p client vdev id %d scc on %d", v35, v36, v37, v38, v39, v40, v41, v42);
  qdf_mutex_release(v34 + 56);
  result = 1;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
