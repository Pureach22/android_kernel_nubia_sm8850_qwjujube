__int64 __fastcall wlan_cfr_pdev_obj_create_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 v30; // x8
  __int64 v31; // x10
  int v32; // w8
  __int64 v33; // x9
  unsigned int v34; // w22
  unsigned int *v35; // x10
  const char *v36; // x2
  unsigned int v37; // w21
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x4
  unsigned __int64 v56; // x22
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
    qdf_trace_msg(0x6Au, 2u, "%s: PDEV is NULL\n", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_pdev_obj_create_handler");
    return 16;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_is_ini_disabled");
    goto LABEL_7;
  }
  if ( ((*(unsigned __int8 *)(cfg_psoc_get_values(v10) + 868) >> *(_BYTE *)(a1 + 40)) & 1) != 0 )
  {
    qdf_trace_msg(
      0x6Au,
      4u,
      "%s: cfr is disabled for pdev[%d]",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_cfr_is_ini_disabled");
LABEL_7:
    *(_DWORD *)(a1 + 16) &= ~1u;
    return 11;
  }
  *(_DWORD *)(a1 + 16) |= 1u;
  v20 = (_QWORD *)_qdf_mem_malloc(0xB98u, "wlan_cfr_pdev_obj_create_handler", 313);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to allocate pdev_cfr object\n",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_cfr_pdev_obj_create_handler");
    return 2;
  }
  *v20 = a1;
  v29 = (__int64)v20;
  v30 = *(_QWORD *)(a1 + 80);
  if ( !v30 )
  {
    v36 = "%s: psoc is null";
LABEL_21:
    qdf_trace_msg(0x6Au, 2u, v36, v21, v22, v23, v24, v25, v26, v27, v28, "wlan_cfr_get_dbr_num_entries");
    v37 = 140;
    *(_DWORD *)(v29 + 80) = 140;
    goto LABEL_27;
  }
  v31 = *(_QWORD *)(v30 + 2800);
  if ( !v31 )
  {
    v36 = "%s: target_psoc_info is null";
    goto LABEL_21;
  }
  v32 = *(_DWORD *)(v31 + 836);
  if ( !v32 )
    LOBYTE(v32) = *(_BYTE *)(v31 + 964);
  v33 = (unsigned __int8)v32;
  if ( (_BYTE)v32 )
  {
    v34 = 140;
    v35 = (unsigned int *)(*(_QWORD *)(v31 + 4592) + 8LL);
    do
    {
      if ( *((_QWORD *)v35 - 1) == (*(unsigned __int8 *)(a1 + 40) | 0x100000000LL) )
        v34 = *v35;
      --v33;
      v35 += 5;
    }
    while ( v33 );
  }
  else
  {
    v34 = 140;
  }
  if ( v34 >= 0x8C )
    v37 = 140;
  else
    v37 = v34;
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: pdev id %d, num_entries %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_cfr_get_dbr_num_entries",
    *(unsigned __int8 *)(a1 + 40),
    v37);
  *(_DWORD *)(v29 + 80) = v37;
  if ( !v34 )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: lut num is 0",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_cfr_pdev_obj_create_handler");
    _qdf_mem_free(v29);
    return 4;
  }
LABEL_27:
  v46 = _qdf_mem_malloc(8 * v37, "wlan_cfr_pdev_obj_create_handler", 326);
  v55 = *(unsigned int *)(v29 + 80);
  *(_QWORD *)(v29 + 72) = v46;
  if ( !v46 )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to allocate lut, lut num %d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "wlan_cfr_pdev_obj_create_handler",
      v55);
    _qdf_mem_free(v29);
    return 2;
  }
  if ( (_DWORD)v55 )
  {
    v56 = 0;
    do
      *(_QWORD *)(*(_QWORD *)(v29 + 72) + 8 * v56++) = _qdf_mem_malloc(0xE8u, "wlan_cfr_pdev_obj_create_handler", 334);
    while ( v56 < *(unsigned int *)(v29 + 80) );
  }
  *(_BYTE *)(v29 + 1721) = 0;
  _qdf_wake_lock_create((_QWORD *)(v29 + 1728), (__int64)"wlan_cfr");
  _qdf_runtime_lock_init((__int64 *)(v29 + 1928), "&pcfr->runtime_lock");
  wlan_objmgr_pdev_component_obj_attach(a1, 0x1Eu, v29, 0, v57, v58, v59, v60, v61, v62, v63, v64);
  return 0;
}
