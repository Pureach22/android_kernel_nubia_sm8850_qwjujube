__int64 __fastcall mlo_internal_disconnect_links(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *v18; // x21
  __int64 v19; // x20
  void *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  void *v29; // x0
  __int64 v30; // x0
  __int64 v31; // x20
  __int64 v32; // x0
  __int64 assoc_vdev; // x0
  unsigned int *v34; // x8
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w21
  __int64 v45; // x19
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x19
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  const char *v88; // x2
  unsigned int v89; // w1
  unsigned __int16 v90; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v91; // [xsp+8h] [xbp-18h] BYREF
  __int64 v92; // [xsp+10h] [xbp-10h]
  __int64 v93; // [xsp+18h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  if ( !result )
    goto LABEL_41;
  v9 = result;
  if ( (*(_DWORD *)(result + 16)
     || (wlan_vdev_mlme_is_mlo_vdev(result, a2, a3, a4, a5, a6, a7, a8, a9) & 1) == 0
     || (*(_BYTE *)(v9 + 60) & 2) != 0)
    && (mlo_mgr_is_link_switch_on_assoc_vdev(v9) & 1) == 0 )
  {
    goto LABEL_35;
  }
  v18 = *(_QWORD **)(v9 + 1360);
  if ( !v18 )
  {
    v88 = "%s: Invalid mlo_dev_ctx";
LABEL_39:
    v89 = 2;
    goto LABEL_40;
  }
  v19 = v18[278];
  if ( !v19 )
  {
    v88 = "%s: Invalid sta_ctx";
    goto LABEL_39;
  }
  qdf_trace_msg(0x8Fu, 8u, "%s: enter", v10, v11, v12, v13, v14, v15, v16, v17, "mlo_free_copied_conn_req");
  qdf_mutex_acquire(v19 + 40);
  v20 = *(void **)(v19 + 32);
  if ( v20 )
  {
    wlan_cm_free_connect_req(v20);
    *(_QWORD *)(v19 + 32) = 0;
  }
  qdf_mutex_release(v19 + 40);
  v29 = *(void **)(v19 + 24);
  if ( v29 )
  {
    wlan_cm_free_connect_req(v29);
    *(_QWORD *)(v19 + 24) = 0;
  }
  v30 = v18[3];
  if ( (!v30
     || (wlan_vdev_mlme_is_mlo_vdev(v30, v21, v22, v23, v24, v25, v26, v27, v28) & 1) == 0
     || (v31 = v18[3], (*(_BYTE *)(v31 + 60) & 2) != 0))
    && ((v32 = v18[4]) == 0
     || (wlan_vdev_mlme_is_mlo_vdev(v32, v21, v22, v23, v24, v25, v26, v27, v28) & 1) == 0
     || (v31 = v18[4], (*(_BYTE *)(v31 + 60) & 2) != 0))
    || !v31 )
  {
    assoc_vdev = mlo_mgr_link_switch_get_assoc_vdev(v9);
    if ( !assoc_vdev )
    {
      v88 = "%s: Couldn't get assoc vdev";
      goto LABEL_36;
    }
    v31 = assoc_vdev;
    mlo_release_vdev_ref(assoc_vdev, v34, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  v91 = 0;
  v92 = 0;
  result = mlo_sta_get_vdev_list(v9, &v90, &v91);
  v44 = v90;
  if ( v90 )
  {
    v45 = v91;
    if ( v91 != v31
      && (wlan_cm_is_vdev_connected(v91, v36, v37, v38, v39, v40, v41, v42, v43)
       || wlan_cm_is_vdev_connecting(v45, v46, v47, v48, v49, v50, v51, v52, v53)
       || wlan_cm_is_vdev_idle_due_to_link_switch(v45, v54, v55, v56, v57, v58, v59, v60, v61)) )
    {
      wlan_cm_disconnect(v45, 13, 1, nullptr);
      v45 = v91;
      v44 = v90;
    }
    result = mlo_release_vdev_ref(v45, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( v44 >= 2 )
    {
      v71 = v92;
      if ( v92 != v31
        && (wlan_cm_is_vdev_connected(v92, v63, v64, v65, v66, v67, v68, v69, v70)
         || wlan_cm_is_vdev_connecting(v71, v72, v73, v74, v75, v76, v77, v78, v79)
         || wlan_cm_is_vdev_idle_due_to_link_switch(v71, v80, v81, v82, v83, v84, v85, v86, v87)) )
      {
        wlan_cm_disconnect(v71, 13, 1, nullptr);
        v71 = v92;
        v44 = v90;
      }
      result = mlo_release_vdev_ref(v71, v62, v63, v64, v65, v66, v67, v68, v69, v70);
      if ( v44 > 2 )
      {
        __break(0x5512u);
LABEL_35:
        v88 = "%s: Not an assoc vdev, so ignore disconnect req";
LABEL_36:
        v89 = 8;
LABEL_40:
        result = qdf_trace_msg(0x8Fu, v89, v88, v10, v11, v12, v13, v14, v15, v16, v17, "mlo_internal_disconnect_links");
      }
    }
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
