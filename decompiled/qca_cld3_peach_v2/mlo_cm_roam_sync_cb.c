__int64 __fastcall mlo_cm_roam_sync_cb(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x8
  __int64 v14; // x20
  unsigned int v15; // w22
  __int64 v16; // x4
  int v17; // w25
  __int64 v18; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x26
  __int64 v29; // x23
  __int64 v30; // x24
  char is_mlo_vdev; // w0
  __int64 v32; // x24
  char v33; // w0
  unsigned int v34; // w8
  unsigned __int64 v35; // x27
  _WORD *v36; // x23
  __int64 v37; // x26
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  __int64 v48; // x1
  _QWORD *v49; // x9
  __int64 v50; // x11
  char v51; // w12
  __int64 v52; // x10
  __int64 v54; // x26
  int v55; // w9
  __int64 v56; // x26
  __int64 v57; // x8
  void *v58; // x0
  unsigned int *v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v13 = *(_QWORD *)(a1 + 216);
  if ( v13 )
    v14 = *(_QWORD *)(v13 + 80);
  else
    v14 = 0;
  v15 = *(unsigned __int8 *)(a1 + 168);
  v16 = *(unsigned int *)(a2 + 56);
  if ( *(unsigned __int8 *)(a2 + 2497) < 2u || (_DWORD)v16 == 1 )
  {
    qdf_trace_msg(0x68u, 8u, "%s: Roam auth status %d", a4, a5, a6, a7, a8, a9, a10, a11, "mlo_cm_roam_sync_cb", v16);
    v17 = *(unsigned __int8 *)(a2 + 2497);
    v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v14, v15, 1);
    if ( v18 )
    {
      v28 = *(_QWORD *)(v18 + 1360);
      v29 = v18;
      if ( v28 )
      {
        v30 = *(_QWORD *)(v28 + 24);
        if ( v30 )
        {
          if ( (*(_BYTE *)(v30 + 60) & 2) != 0 )
          {
            cm_cleanup_mlo_link(*(_QWORD *)(v28 + 24));
          }
          else
          {
            is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v28 + 24), v20, v21, v22, v23, v24, v25, v26, v27);
            if ( !v17 && (is_mlo_vdev & 1) != 0 )
              wlan_vdev_mlme_clear_mlo_vdev(v30, v20, v21, v22, v23, v24, v25, v26, v27);
          }
        }
        v32 = *(_QWORD *)(v28 + 32);
        if ( v32 )
        {
          if ( (*(_BYTE *)(v32 + 60) & 2) != 0 )
          {
            cm_cleanup_mlo_link(*(_QWORD *)(v28 + 32));
          }
          else
          {
            v33 = wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v28 + 32), v20, v21, v22, v23, v24, v25, v26, v27);
            if ( !v17 && (v33 & 1) != 0 )
              wlan_vdev_mlme_clear_mlo_vdev(v32, v20, v21, v22, v23, v24, v25, v26, v27);
          }
        }
      }
      wlan_objmgr_vdev_release_ref(v29, 1u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: VDEV:%d is null",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "mlo_update_vdev_after_roam",
        v15);
    }
  }
  if ( *(_DWORD *)(a2 + 56) == 1 || (v34 = *(unsigned __int8 *)(a2 + 2497), !*(_BYTE *)(a2 + 2497)) )
  {
LABEL_55:
    result = 0;
    goto LABEL_56;
  }
  v35 = 0;
  v36 = (_WORD *)(a2 + 2546);
  while ( 1 )
  {
    if ( v35 == 3 )
      __break(0x5512u);
    v48 = *(unsigned int *)(v36 - 23);
    if ( (_DWORD)v48 == v15 || (_DWORD)v48 == 255 )
      goto LABEL_27;
    v47 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v14, v48, 1);
    if ( !v47 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Link vdev:%d is null",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "mlo_cm_roam_sync_cb",
        *(unsigned int *)(v36 - 23));
      result = 16;
      goto LABEL_56;
    }
    v49 = *(_QWORD **)(v47 + 1360);
    if ( !v49 )
      goto LABEL_26;
    v50 = v49[3];
    v38 = (unsigned int *)v49[278];
    if ( v50 == v47 )
      break;
    if ( v49[4] == v47 )
    {
      v51 = 1;
      goto LABEL_37;
    }
    v37 = v47;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: vdev:%d not found in ml dev ctx list",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "mlo_check_connect_req_bmap",
      *(unsigned __int8 *)(v47 + 168));
    v47 = v37;
LABEL_26:
    wlan_objmgr_vdev_release_ref(v47, 1u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    v34 = *(unsigned __int8 *)(a2 + 2497);
LABEL_27:
    ++v35;
    v36 += 26;
    if ( v35 >= v34 )
      goto LABEL_55;
  }
  v51 = 0;
LABEL_37:
  v52 = *(_QWORD *)v38;
  if ( ((*(_QWORD *)v38 >> v51) & 1) == 0 )
    goto LABEL_26;
  if ( v38 )
  {
    if ( v50 == v47 )
    {
      v52 &= ~1uLL;
      *(_QWORD *)v38 = v52;
    }
    if ( v49[4] == v47 )
      *(_QWORD *)v38 = v52 & 0xFFFFFFFFFFFFFFFDLL;
  }
  if ( *(_DWORD *)v36 | (unsigned __int16)v36[2] )
  {
    if ( *(_DWORD *)v36 != -1 || (__int16)v36[2] != -1 )
    {
      v54 = v47;
      qdf_mem_copy((void *)(v47 + 74), v36, 6u);
      v55 = *(_DWORD *)v36;
      v47 = v54;
      *(_WORD *)(v54 + 90) = v36[2];
      *(_DWORD *)(v54 + 86) = v55;
    }
  }
  v56 = v47;
  v38 = (unsigned int *)(unsigned int)cm_fw_roam_sync_req(v14, *(unsigned int *)(v36 - 23), (unsigned __int8 *)a2, a3);
  v47 = v56;
  if ( !(_DWORD)v38 )
    goto LABEL_26;
  v57 = *(_QWORD *)(v56 + 1360);
  if ( v57 )
  {
    v58 = *(void **)(v57 + 2224);
    if ( v58 )
      qdf_mem_set(v58, 8u, 0);
  }
  if ( a2 )
    wlan_mlo_roam_abort_on_link(v14, a2, *(unsigned __int8 *)(a2 + 13));
  else
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Roam Sync ind ptr is NULL",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "mlo_roam_abort_req");
  wlan_objmgr_vdev_release_ref(v56, 1u, v59, v60, v61, v62, v63, v64, v65, v66, v67);
  result = 16;
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
