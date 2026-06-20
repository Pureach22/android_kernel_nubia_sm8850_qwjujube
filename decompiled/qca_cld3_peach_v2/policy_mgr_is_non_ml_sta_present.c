__int64 __fastcall policy_mgr_is_non_ml_sta_present(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  char v67; // w20

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    if ( !(_DWORD)pm_conc_connection_list && BYTE4(qword_8D4F00) == 1 )
    {
      v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F00,
              24);
      if ( v12 )
      {
        v21 = v12;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v12, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
          goto LABEL_28;
        wlan_objmgr_vdev_release_ref(v21, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      }
    }
    if ( !(_DWORD)qword_8D4F0C && BYTE4(qword_8D4F24) == 1 )
    {
      v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F24,
              24);
      if ( v31 )
      {
        v21 = v31;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v31, v32, v33, v34, v35, v36, v37, v38, v39) & 1) == 0 )
          goto LABEL_28;
        wlan_objmgr_vdev_release_ref(v21, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      }
    }
    if ( !(_DWORD)qword_8D4F30 && BYTE4(qword_8D4F48) == 1 )
    {
      v40 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F48,
              24);
      if ( v40 )
      {
        v21 = v40;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v40, v41, v42, v43, v44, v45, v46, v47, v48) & 1) == 0 )
          goto LABEL_28;
        wlan_objmgr_vdev_release_ref(v21, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      }
    }
    if ( (_DWORD)qword_8D4F54 )
      goto LABEL_22;
    if ( BYTE4(qword_8D4F6C) != 1 )
      goto LABEL_22;
    v49 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            (unsigned int)qword_8D4F6C,
            24);
    if ( !v49 )
      goto LABEL_22;
    v21 = v49;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v49, v50, v51, v52, v53, v54, v55, v56, v57) & 1) != 0 )
    {
      wlan_objmgr_vdev_release_ref(v21, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
LABEL_22:
      if ( (_DWORD)qword_8D4F78
        || BYTE4(qword_8D4F90) != 1
        || (v58 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1,
                    (unsigned int)qword_8D4F90,
                    24)) == 0 )
      {
        v67 = 0;
LABEL_30:
        qdf_mutex_release(v11 + 56);
        return v67 & 1;
      }
      v21 = v58;
      v67 = wlan_vdev_mlme_is_mlo_vdev(v58, v59, v60, v61, v62, v63, v64, v65, v66) ^ 1;
LABEL_29:
      wlan_objmgr_vdev_release_ref(v21, 0x18u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      goto LABEL_30;
    }
LABEL_28:
    v67 = 1;
    goto LABEL_29;
  }
  qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_is_non_ml_sta_present");
  v67 = 0;
  return v67 & 1;
}
