__int64 __fastcall policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w21
  __int64 v4; // x0
  unsigned int *v5; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w19
  __int64 context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  int v34; // [xsp+0h] [xbp-10h] BYREF
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v4 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Vdev[%d] is null",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id",
      v2);
    goto LABEL_28;
  }
  wlan_objmgr_vdev_release_ref(v4, 0x18u, v5, v6, v7, v8, v9, v10, v11, v12, v13);
  policy_mgr_is_any_dfs_beaconing_session_present(a1, &v35, &v34);
  v14 = v35;
  if ( !v35 )
  {
LABEL_28:
    result = 0;
    goto LABEL_29;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id");
    goto LABEL_28;
  }
  v24 = context;
  qdf_mutex_acquire(context + 56);
  if ( (BYTE4(qword_81C458) != 1
     || ((unsigned int)pm_conc_connection_list | 2) != 2
     || (_DWORD)qword_81C458 != v2
     || HIDWORD(pm_conc_connection_list) != v14)
    && (BYTE4(qword_81C47C) != 1
     || ((unsigned int)qword_81C464 | 2) != 2
     || (_DWORD)qword_81C47C != v2
     || HIDWORD(qword_81C464) != v14)
    && (BYTE4(qword_81C4A0) != 1
     || ((unsigned int)qword_81C488 | 2) != 2
     || (_DWORD)qword_81C4A0 != v2
     || HIDWORD(qword_81C488) != v14)
    && (BYTE4(qword_81C4C4) != 1
     || ((unsigned int)qword_81C4AC | 2) != 2
     || (_DWORD)qword_81C4C4 != v2
     || HIDWORD(qword_81C4AC) != v14)
    && (BYTE4(qword_81C4E8) != 1
     || ((unsigned int)qword_81C4D0 | 2) != 2
     || (_DWORD)qword_81C4E8 != v2
     || HIDWORD(qword_81C4D0) != v14) )
  {
    qdf_mutex_release(v24 + 56);
    goto LABEL_28;
  }
  qdf_trace_msg(0x4Fu, 8u, "sta/p2p client vdev id %d scc on %d", v25, v26, v27, v28, v29, v30, v31, v32);
  qdf_mutex_release(v24 + 56);
  result = 1;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
