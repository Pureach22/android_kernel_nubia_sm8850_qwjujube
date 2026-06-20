__int64 __fastcall policy_mgr_pick_link_vdev_from_inactive_list(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        _BYTE *a4,
        unsigned int *a5,
        _BYTE *a6,
        _BYTE *a7)
{
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  unsigned int v33; // w1
  const char *v34; // x2
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  __int64 v44; // x28
  __int64 assoc_link_vdev; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w4
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 result; // x0
  unsigned int *v65; // x8
  _BYTE *v66; // [xsp+8h] [xbp-D8h]
  unsigned __int8 v67[4]; // [xsp+14h] [xbp-CCh] BYREF
  _QWORD v68[22]; // [xsp+18h] [xbp-C8h] BYREF
  int v69; // [xsp+C8h] [xbp-18h]
  __int64 v70; // [xsp+D0h] [xbp-10h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  memset(v68, 0, sizeof(v68));
  v67[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "policy_mgr_pick_link_vdev_from_inactive_list");
    goto LABEL_24;
  }
  v23 = context;
  v66 = a6;
  qdf_mutex_acquire(context + 56);
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, unsigned __int8 *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    *(unsigned __int8 *)(a2 + 168),
    v68,
    v67);
  if ( !a3 )
    goto LABEL_23;
  v32 = a3;
  while ( (wlan_get_vdev_link_removed_flag_by_vdev_id(a1, (unsigned __int8)*a4) & 1) != 0 )
  {
    v33 = 8;
    v34 = "%s: skip removed link vdev %d";
LABEL_5:
    qdf_trace_msg(
      0x4Fu,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_pick_link_vdev_from_inactive_list");
LABEL_6:
    --v32;
    ++a4;
    ++a5;
    if ( !v32 )
      goto LABEL_23;
  }
  v43 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned __int8)*a4,
          24);
  if ( !v43 )
  {
    v33 = 2;
    v34 = "%s: invalid partner_vdev %d ";
    goto LABEL_5;
  }
  *a7 = *a4;
  v44 = v43;
  if ( *(_DWORD *)(v43 + 16) || (wlan_vdev_mlme_is_mlo_vdev(v43, v35, v36, v37, v38, v39, v40, v41, v42) & 1) == 0 )
  {
    v54 = 0;
  }
  else if ( (*(_BYTE *)(v44 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v44)) != 0 )
  {
    if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v46, v47, v48, v49, v50, v51, v52, v53) )
      v54 = 3;
    else
      v54 = 1;
  }
  else
  {
    v54 = 1;
  }
  if ( (policy_mgr_is_concurrency_allowed(a1, 0, *a5, 3, v54, 0) & 1) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v44, 0x18u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
    goto LABEL_6;
  }
  v65 = (unsigned int *)(unsigned __int8)*a4;
  *v66 = (_BYTE)v65;
  wlan_objmgr_vdev_release_ref(v44, 0x18u, v65, v56, v57, v58, v59, v60, v61, v62, v63);
LABEL_23:
  policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v68, v67[0], v24, v25, v26, v27, v28, v29, v30, v31);
  result = qdf_mutex_release(v23 + 56);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
