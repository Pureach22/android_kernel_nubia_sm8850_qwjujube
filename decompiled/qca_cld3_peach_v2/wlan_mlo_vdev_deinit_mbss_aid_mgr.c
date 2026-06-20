__int64 __fastcall wlan_mlo_vdev_deinit_mbss_aid_mgr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  __int64 cmpt_obj; // x0
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x4
  const char *v20; // x2
  __int64 result; // x0
  __int64 v22; // x9
  __int64 v23; // x8
  __int16 v25; // w26
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 v47; // x8
  __int16 v48; // w25
  __int64 v49; // x0
  __int64 v50; // x21
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  unsigned int v67; // w9
  unsigned int v69; // w9
  unsigned int v70; // w9
  unsigned int v72; // w9
  unsigned int v74; // w9
  unsigned int v75; // w9

  if ( !a1 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: ML DEV pointer is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_vdev_deinit_mbss_aid_mgr");
    return 16;
  }
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 2232) + 8LL);
  if ( !v11 )
  {
    v19 = *(unsigned __int8 *)(a1 + 16);
    v20 = "%s: AID mgr of ML VDEV(%d) is invalid";
    goto LABEL_13;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cmpt_obj || (v16 = *(_QWORD *)(cmpt_obj + 248)) == 0 )
  {
    v19 = *(unsigned __int8 *)(a3 + 168);
    v20 = "%s: AID mgr of Tx VDEV%d is invalid";
LABEL_13:
    qdf_trace_msg(0x8Fu, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_vdev_deinit_mbss_aid_mgr", v19);
    return 16;
  }
  v17 = wlan_vdev_mlme_get_cmpt_obj(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !v17 || (v18 = *(_QWORD *)(v17 + 248)) == 0 )
  {
    v19 = *(unsigned __int8 *)(a2 + 168);
    v20 = "%s: AID mgr of VDEV%d is invalid";
    goto LABEL_13;
  }
  if ( v18 != v16 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID mgr of VDEV%d and tx vdev(%d) aid mgr doesn't match",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_mlo_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168),
      *(unsigned __int8 *)(a3 + 168));
    return 16;
  }
  v22 = *(_QWORD *)(a1 + 24);
  v23 = a1;
  _X24 = (unsigned int *)(v16 + 260);
  if ( v22 && v22 == a2 )
  {
    v25 = *(_WORD *)(v11 + 258);
    v26 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
    if ( !v26 )
      goto LABEL_32;
    v35 = v26;
    _X8 = (unsigned int *)(v26 + 260);
    *(_WORD *)(v26 + 256) = 0;
    *(_WORD *)(v26 + 258) = v25;
    *(_DWORD *)(v26 + 260) = 0;
    __asm { PRFM            #0x11, [X8] }
    do
      v67 = __ldxr(_X8);
    while ( __stxr(v67 + 1, _X8) );
    v37 = wlan_vdev_mlme_get_cmpt_obj(a2, v27, v28, v29, v30, v31, v32, v33, v34);
    if ( v37 )
      *(_QWORD *)(v37 + 248) = v35;
    v46 = a3;
    *(_QWORD *)(v11 + 264) = v35;
    __asm { PRFM            #0x11, [X24] }
    do
    {
      v69 = __ldxr(_X24);
      v70 = v69 - 1;
    }
    while ( __stlxr(v70, _X24) );
    __dmb(0xBu);
    if ( !v70 )
    {
      *(_WORD *)(v16 + 258) = 0;
      _qdf_mem_free(v16);
      v46 = a3;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AID mgr restored for vdev %d (txvdev %d)",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_mlo_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168),
      *(unsigned __int8 *)(v46 + 168));
    v23 = a1;
  }
  v47 = *(_QWORD *)(v23 + 32);
  result = 0;
  if ( !v47 || v47 != a2 )
    return result;
  v48 = *(_WORD *)(v11 + 258);
  v49 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
  if ( !v49 )
  {
LABEL_32:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID bitmap allocation failed for VDEV%d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_mlo_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168));
    return 2;
  }
  v50 = v49;
  _X8 = (unsigned int *)(v49 + 260);
  *(_WORD *)(v49 + 256) = 0;
  *(_WORD *)(v49 + 258) = v48;
  *(_DWORD *)(v49 + 260) = 0;
  __asm { PRFM            #0x11, [X8] }
  do
    v72 = __ldxr(_X8);
  while ( __stxr(v72 + 1, _X8) );
  v52 = wlan_vdev_mlme_get_cmpt_obj(a2, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( v52 )
    *(_QWORD *)(v52 + 248) = v50;
  v61 = a3;
  *(_QWORD *)(v11 + 272) = v50;
  __asm { PRFM            #0x11, [X24] }
  do
  {
    v74 = __ldxr(_X24);
    v75 = v74 - 1;
  }
  while ( __stlxr(v75, _X24) );
  __dmb(0xBu);
  if ( !v75 )
  {
    *(_WORD *)(v16 + 258) = 0;
    _qdf_mem_free(v16);
    v61 = a3;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: AID mgr restored for vdev %d (txvdev %d)",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "wlan_mlo_vdev_deinit_mbss_aid_mgr",
    *(unsigned __int8 *)(a2 + 168),
    *(unsigned __int8 *)(v61 + 168));
  return 0;
}
