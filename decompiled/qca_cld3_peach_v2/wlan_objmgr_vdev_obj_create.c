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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int16 v34; // w8
  int v35; // w10
  int v36; // w8
  int v37; // w8
  __int64 v38; // x9
  __int64 v39; // x22
  __int64 v40; // x23
  __int64 v41; // x1
  int v42; // w0
  __int64 (__fastcall *v43)(__int64, __int64); // x8
  int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  __int64 v54; // x22
  _DWORD *v55; // x9
  __int64 v56; // x1
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7

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
  result = _qdf_mem_malloc(*(_QWORD *)(a2 + 8) + 1424LL, "wlan_objmgr_vdev_obj_create", 212);
  if ( !result )
    return result;
  v14 = result;
  *(_DWORD *)(result + 1336) = 0;
  v15 = _qdf_mem_malloc(0x28u, "wlan_objmgr_vdev_obj_create", 217);
  *(_QWORD *)(v14 + 32) = v15;
  if ( !v15 )
    goto LABEL_14;
  v16 = _qdf_mem_malloc(0x28u, "wlan_objmgr_vdev_obj_create", 223);
  *(_QWORD *)(v14 + 40) = v16;
  if ( !v16 )
  {
    _qdf_mem_free(*(_QWORD *)(v14 + 32));
LABEL_14:
    _qdf_mem_free(v14);
    return 0;
  }
  qdf_mutex_create(v14 + 96);
  v17 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v14 + 1344) = 0;
  *(_DWORD *)(v14 + 236) = v17;
  *(_QWORD *)(v14 + 1352) = 0;
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
      *(unsigned __int8 *)(v14 + 168));
LABEL_13:
    _qdf_mem_free(*(_QWORD *)(v14 + 32));
    _qdf_mem_free(*(_QWORD *)(v14 + 40));
    qdf_mutex_destroy(v14 + 96);
    goto LABEL_14;
  }
  *(_QWORD *)(v14 + 216) = a1;
  if ( (unsigned int)wlan_objmgr_pdev_vdev_attach(a1, (_QWORD *)v14) )
  {
    qdf_trace_msg(
      0x57u,
      2u,
      "%s: pdev vdev attach failed for vdev-id:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_objmgr_vdev_obj_create",
      *(unsigned __int8 *)(v14 + 168));
    ((void (__fastcall *)(__int64, __int64))wlan_objmgr_psoc_vdev_detach)(v10, v14);
    goto LABEL_13;
  }
  *(_DWORD *)(v14 + 16) = *(_DWORD *)a2;
  qdf_mem_copy((void *)(v14 + 74), (const void *)(a2 + 24), 6u);
  qdf_mem_copy((void *)(v14 + 68), (const void *)(a2 + 30), 6u);
  qdf_mem_copy((void *)(v14 + 80), (const void *)(a2 + 36), 6u);
  v34 = *(_WORD *)(a2 + 28);
  v35 = *(_DWORD *)(a2 + 24);
  *(_QWORD *)(v14 + 680) = v14 + 1424;
  *(_WORD *)(v14 + 90) = v34;
  *(_DWORD *)(v14 + 86) = v35;
  v36 = *(unsigned __int8 *)(a2 + 44);
  *(_WORD *)(v14 + 224) = 0;
  *(_DWORD *)(v14 + 164) = v36;
  *(_DWORD *)(v14 + 228) = 0;
  *(_DWORD *)(v14 + 240) = 0;
  *(_BYTE *)(v14 + 169) = 0;
  wlan_objmgr_vdev_get_ref(v14, 0);
  if ( *(_DWORD *)(v14 + 16) )
    v37 = *(unsigned __int16 *)(a1 + 74);
  else
    v37 = 2;
  *(_WORD *)(v14 + 232) = v37;
  v38 = *(_QWORD *)(a2 + 16);
  if ( v38 )
  {
    *(_QWORD *)(*(_QWORD *)(v14 + 680) + 8LL) = v38;
    v37 = *(unsigned __int16 *)(v14 + 232);
  }
  v39 = 1120;
  v40 = 5664;
  *(_QWORD *)(v14 + 192) = v14 + 192;
  *(_QWORD *)(v14 + 200) = v14 + 192;
  *(_DWORD *)(v14 + 208) = 0;
  *(_DWORD *)(v14 + 212) = v37 + 128;
  do
  {
    v43 = *(__int64 (__fastcall **)(__int64, __int64))(g_umac_glb_obj + v40 - 432);
    if ( v43 )
    {
      v41 = *(_QWORD *)(g_umac_glb_obj + v40);
      if ( *((_DWORD *)v43 - 1) != -1744405434 )
        __break(0x8228u);
      v42 = v43(v14, v41);
    }
    else
    {
      v42 = 39;
    }
    *(_DWORD *)(v14 + v39) = v42;
    v39 += 4;
    v40 += 8;
  }
  while ( v39 != 1336 );
  v44 = wlan_objmgr_vdev_object_status(v14);
  switch ( v44 )
  {
    case 40:
      *(_DWORD *)(v14 + 1336) = 3;
      break;
    case 16:
      qdf_trace_msg(
        0x57u,
        2u,
        "%s: VDEV comp objects creation failed for vdev-id:%d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "wlan_objmgr_vdev_obj_create",
        *(unsigned __int8 *)(v14 + 168));
      wlan_objmgr_vdev_obj_delete(v14);
      return 0;
    case 0:
      v53 = g_umac_glb_obj;
      v54 = -432;
      *(_DWORD *)(v14 + 1336) = 1;
      do
      {
        v55 = *(_DWORD **)(v53 + v54 + 7824);
        if ( v55 )
        {
          v56 = *(_QWORD *)(v53 + v54 + 8256);
          if ( *(v55 - 1) != -1188329905 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, _QWORD))v55)(v14, v56, 0);
          v53 = g_umac_glb_obj;
        }
        v54 += 8;
      }
      while ( v54 );
      break;
  }
  wlan_minidump_log(v14, 1424, v10, 56, "wlan_objmgr_vdev");
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Created vdev %d",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "wlan_objmgr_vdev_obj_create",
    *(unsigned __int8 *)(v14 + 168));
  if ( (unsigned int)wlan_objmgr_vdev_mlo_dev_ctxt_attach(v14) )
    return 0;
  else
    return v14;
}
