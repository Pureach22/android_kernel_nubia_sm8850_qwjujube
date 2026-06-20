__int64 __fastcall mlo_roam_link_connect_notify(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 v14; // x24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 assoc_link_vdev; // x0
  __int64 v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  __int64 v34; // x25
  int v35; // w26
  unsigned int v36; // w22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  __int64 v46; // x2
  __int64 v47; // x3
  __int64 v48; // x20
  _QWORD *v49; // x8
  _QWORD *v50; // x9
  __int64 v51; // x1
  unsigned int v52; // w21
  void *v53; // x0
  void *v54; // x0
  _QWORD *v55; // x8
  _QWORD *v56; // x9
  char v57; // w10
  _QWORD *v58; // x9
  _QWORD *v59; // x8
  _QWORD *v61; // x3
  char v62; // w10
  char v63; // w9
  _QWORD dest[23]; // [xsp+8h] [xbp-B8h] BYREF

  dest[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1
    || (memset(dest, 0, 176),
        (v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1)) == 0) )
  {
    v52 = 29;
LABEL_53:
    _ReadStatusReg(SP_EL0);
    return v52;
  }
  v12 = *(_QWORD *)(v3 + 1360);
  v13 = v3;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo dev ctx is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_roam_link_connect_notify");
    v52 = 16;
    goto LABEL_52;
  }
  v14 = *(_QWORD *)(v12 + 2224);
  if ( (wlan_vdev_mlme_is_mlo_vdev(v3, v4, v5, v6, v7, v8, v9, v10, v11) & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLO_ROAM: Ignore if not mlo vdev",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlo_roam_link_connect_notify");
    v48 = 0;
    v52 = 16;
    goto LABEL_30;
  }
  assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v13, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !assoc_link_vdev )
  {
LABEL_47:
    v48 = 0;
    v52 = 29;
    if ( !v14 )
      goto LABEL_50;
    goto LABEL_48;
  }
  if ( !v14 || (v33 = *(_QWORD *)(v14 + 288)) == 0 )
  {
    v52 = 29;
    goto LABEL_52;
  }
  v34 = assoc_link_vdev;
  v35 = *(unsigned __int8 *)(assoc_link_vdev + 168);
  memcpy(dest, (const void *)(v33 + 160), 0xB0u);
  v36 = LOBYTE(dest[0]);
  v45 = qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: partner links %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "mlo_roam_link_connect_notify",
          LOBYTE(dest[0]));
  if ( !v36 )
  {
    v48 = 0;
    v52 = 0;
    v54 = *(void **)(v14 + 288);
    if ( v54 )
    {
LABEL_49:
      wlan_cm_free_connect_resp(v54);
      *(_QWORD *)(v14 + 288) = 0;
    }
LABEL_50:
    if ( v48 )
LABEL_51:
      wlan_objmgr_vdev_release_ref(v48, 1u, (unsigned int *)v24, v25, v26, v27, v28, v29, v30, v31, v32);
LABEL_52:
    wlan_objmgr_vdev_release_ref(v13, 1u, (unsigned int *)v24, v25, v26, v27, v28, v29, v30, v31, v32);
    goto LABEL_53;
  }
  if ( v35 == BYTE4(dest[2]) )
  {
    v48 = 0;
LABEL_11:
    v24 = a1;
    goto LABEL_12;
  }
  v45 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1);
  if ( !v45 )
    goto LABEL_46;
  v55 = *(_QWORD **)(v45 + 1360);
  v48 = v45;
  if ( !v55 )
    goto LABEL_11;
  v56 = (_QWORD *)v55[278];
  v45 = v34;
  if ( v55[3] == v48 )
  {
    v57 = 0;
  }
  else
  {
    if ( v55[4] != v48 )
    {
      v45 = qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: vdev:%d not found in ml dev ctx list",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "mlo_check_connect_req_bmap",
              *(unsigned __int8 *)(v48 + 168));
      goto LABEL_11;
    }
    v57 = 1;
  }
  v24 = a1;
  if ( ((*v56 >> v57) & 1) != 0 )
  {
    v61 = &dest[1];
    goto LABEL_65;
  }
LABEL_12:
  if ( v36 == 1 )
    goto LABEL_23;
  if ( v35 == BYTE4(dest[8]) )
    goto LABEL_20;
  v45 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v24);
  if ( !v45 )
  {
LABEL_46:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Link vdev is null",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "mlo_roam_link_connect_notify");
    goto LABEL_47;
  }
  v49 = *(_QWORD **)(v45 + 1360);
  v48 = v45;
  if ( !v49 )
  {
LABEL_19:
    v24 = a1;
    goto LABEL_20;
  }
  v50 = (_QWORD *)v49[278];
  v45 = v34;
  if ( v49[3] == v48 )
  {
    v62 = 0;
  }
  else
  {
    if ( v49[4] != v48 )
    {
      v45 = qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: vdev:%d not found in ml dev ctx list",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "mlo_check_connect_req_bmap",
              *(unsigned __int8 *)(v48 + 168));
      goto LABEL_19;
    }
    v62 = 1;
  }
  v24 = a1;
  if ( ((*v50 >> v62) & 1) != 0 )
  {
    v61 = &dest[7];
    goto LABEL_65;
  }
LABEL_20:
  if ( v36 < 3 )
    goto LABEL_23;
  v51 = BYTE4(dest[14]);
  if ( v35 == BYTE4(dest[14]) )
    goto LABEL_22;
  v45 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v24);
  if ( !v45 )
    goto LABEL_46;
  v58 = *(_QWORD **)(v45 + 1360);
  v48 = v45;
  if ( !v58 )
    goto LABEL_22;
  v59 = (_QWORD *)v58[278];
  if ( v58[3] == v45 )
  {
    v63 = 0;
  }
  else
  {
    if ( v58[4] != v45 )
    {
      v45 = qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: vdev:%d not found in ml dev ctx list",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "mlo_check_connect_req_bmap",
              *(unsigned __int8 *)(v45 + 168));
      goto LABEL_22;
    }
    v63 = 1;
  }
  v45 = v34;
  v24 = *v59 >> v63;
  if ( (v24 & 1) != 0 )
  {
    v61 = &dest[13];
LABEL_65:
    v52 = mlo_roam_prepare_and_send_link_connect_req(v45, v48, v33, v61);
    if ( !v52 )
    {
      mlo_update_connect_req_links(v48, 0);
      goto LABEL_51;
    }
LABEL_24:
    v24 = *(_QWORD *)(v48 + 1360);
    if ( v24 )
    {
      v53 = *(void **)(v24 + 2224);
      if ( v53 )
      {
        qdf_mem_set(v53, 8u, 0);
        goto LABEL_48;
      }
    }
LABEL_30:
    if ( !v14 )
      goto LABEL_50;
LABEL_48:
    v54 = *(void **)(v14 + 288);
    if ( !v54 )
      goto LABEL_50;
    goto LABEL_49;
  }
LABEL_22:
  if ( v36 == 3 )
  {
LABEL_23:
    v52 = 0;
    if ( !v48 )
      goto LABEL_30;
    goto LABEL_24;
  }
  __break(0x5512u);
  return mlo_roam_prepare_and_send_link_connect_req(v45, v51, v46, v47);
}
