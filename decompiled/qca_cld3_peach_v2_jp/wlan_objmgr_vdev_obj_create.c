__int64 __fastcall wlan_objmgr_vdev_obj_create(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 result; // x0
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int16 v35; // w8
  int v36; // w10
  int v37; // w8
  int v38; // w8
  __int64 v39; // x9
  __int64 v40; // x22
  __int64 v41; // x23
  __int64 v42; // x1
  int v43; // w0
  __int64 (__fastcall *v44)(__int64, __int64); // x8
  int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  __int64 v55; // x22
  _DWORD *v56; // x9
  __int64 v57; // x1
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_objmgr_vdev_obj_create");
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: psoc is NULL for pdev-id:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_objmgr_vdev_obj_create",
      *(unsigned __int8 *)(a1 + 40));
    return 0;
  }
  result = _qdf_mem_malloc(*(_QWORD *)(a2 + 8) + 1344LL, "wlan_objmgr_vdev_obj_create", 212);
  if ( !result )
    return result;
  v14 = result;
  *(_DWORD *)(result + 1264) = 0;
  v15 = _qdf_mem_malloc(0x20u, "wlan_objmgr_vdev_obj_create", 217);
  *(_QWORD *)(v14 + 32) = v15;
  if ( !v15 )
    goto LABEL_15;
  v16 = _qdf_mem_malloc(0x20u, "wlan_objmgr_vdev_obj_create", 223);
  *(_QWORD *)(v14 + 40) = v16;
  if ( !v16 )
  {
    v26 = *(_QWORD *)(v14 + 32);
LABEL_14:
    _qdf_mem_free(v26);
LABEL_15:
    _qdf_mem_free(v14);
    return 0;
  }
  v17 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v14 + 1272) = 0;
  *(_DWORD *)(v14 + 164) = v17;
  *(_QWORD *)(v14 + 1280) = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64))wlan_objmgr_psoc_vdev_attach)(v10, v14) )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: psoc vdev attach failed for vdev-id:%d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_objmgr_vdev_obj_create",
      *(unsigned __int8 *)(v14 + 104));
LABEL_13:
    _qdf_mem_free(*(_QWORD *)(v14 + 32));
    v26 = *(_QWORD *)(v14 + 40);
    goto LABEL_14;
  }
  *(_QWORD *)(v14 + 152) = a1;
  if ( (unsigned int)wlan_objmgr_pdev_vdev_attach(a1, (_QWORD *)v14) )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: pdev vdev attach failed for vdev-id:%d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_objmgr_vdev_obj_create",
      *(unsigned __int8 *)(v14 + 104));
    ((void (__fastcall *)(__int64, __int64))wlan_objmgr_psoc_vdev_detach)(v10, v14);
    goto LABEL_13;
  }
  *(_DWORD *)(v14 + 16) = *(_DWORD *)a2;
  qdf_mem_copy((void *)(v14 + 74), (const void *)(a2 + 24), 6u);
  qdf_mem_copy((void *)(v14 + 68), (const void *)(a2 + 30), 6u);
  qdf_mem_copy((void *)(v14 + 80), (const void *)(a2 + 36), 6u);
  v35 = *(_WORD *)(a2 + 28);
  v36 = *(_DWORD *)(a2 + 24);
  *(_QWORD *)(v14 + 608) = v14 + 1344;
  *(_WORD *)(v14 + 90) = v35;
  *(_DWORD *)(v14 + 86) = v36;
  v37 = *(unsigned __int8 *)(a2 + 44);
  *(_WORD *)(v14 + 160) = 0;
  *(_DWORD *)(v14 + 96) = v37;
  *(_DWORD *)(v14 + 168) = 0;
  *(_BYTE *)(v14 + 105) = 0;
  wlan_objmgr_vdev_get_ref(v14, 0);
  if ( *(_DWORD *)(v14 + 16) )
    v38 = *(unsigned __int16 *)(a1 + 74);
  else
    v38 = 2;
  *(_WORD *)(v14 + 162) = v38;
  v39 = *(_QWORD *)(a2 + 16);
  if ( v39 )
  {
    *(_QWORD *)(*(_QWORD *)(v14 + 608) + 8LL) = v39;
    v38 = *(unsigned __int16 *)(v14 + 162);
  }
  v40 = 1048;
  v41 = 5656;
  *(_QWORD *)(v14 + 128) = v14 + 128;
  *(_QWORD *)(v14 + 136) = v14 + 128;
  *(_DWORD *)(v14 + 144) = 0;
  *(_DWORD *)(v14 + 148) = v38 + 128;
  do
  {
    v44 = *(__int64 (__fastcall **)(__int64, __int64))(g_umac_glb_obj + v41 - 432);
    if ( v44 )
    {
      v42 = *(_QWORD *)(g_umac_glb_obj + v41);
      if ( *((_DWORD *)v44 - 1) != -1744405434 )
        __break(0x8228u);
      v43 = v44(v14, v42);
    }
    else
    {
      v43 = 39;
    }
    *(_DWORD *)(v14 + v40) = v43;
    v40 += 4;
    v41 += 8;
  }
  while ( v40 != 1264 );
  v45 = wlan_objmgr_vdev_object_status(v14);
  switch ( v45 )
  {
    case 40:
      *(_DWORD *)(v14 + 1264) = 3;
      break;
    case 16:
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: VDEV comp objects creation failed for vdev-id:%d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wlan_objmgr_vdev_obj_create",
        *(unsigned __int8 *)(v14 + 104));
      wlan_objmgr_vdev_obj_delete(v14);
      return 0;
    case 0:
      v54 = g_umac_glb_obj;
      v55 = -432;
      *(_DWORD *)(v14 + 1264) = 1;
      do
      {
        v56 = *(_DWORD **)(v54 + v55 + 7816);
        if ( v56 )
        {
          v57 = *(_QWORD *)(v54 + v55 + 8248);
          if ( *(v56 - 1) != -1188329905 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v56)(v14, v57, 0);
          v54 = g_umac_glb_obj;
        }
        v55 += 8;
      }
      while ( v55 );
      break;
  }
  wlan_minidump_log(v14, 1344, v10, 56, "wlan_objmgr_vdev");
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Created vdev %d",
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    "wlan_objmgr_vdev_obj_create",
    *(unsigned __int8 *)(v14 + 104));
  if ( (unsigned int)wlan_objmgr_vdev_mlo_dev_ctxt_attach(v14) )
    return 0;
  else
    return v14;
}
