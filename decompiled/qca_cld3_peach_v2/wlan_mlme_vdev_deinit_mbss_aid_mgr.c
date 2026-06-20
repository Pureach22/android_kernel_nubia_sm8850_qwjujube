__int64 __fastcall wlan_mlme_vdev_deinit_mbss_aid_mgr(
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
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x4
  const char *v25; // x2
  __int16 v27; // w23
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v54; // w9
  unsigned int v56; // w9
  unsigned int v57; // w9

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj || (v21 = *(_QWORD *)(cmpt_obj + 248)) == 0 )
  {
    v24 = *(unsigned __int8 *)(a2 + 168);
    v25 = "%s: AID mgr of Tx VDEV%d is invalid";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v25, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_mlme_vdev_deinit_mbss_aid_mgr", v24);
    return 16;
  }
  v22 = wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
  if ( !v22 || (v23 = *(_QWORD *)(v22 + 248)) == 0 )
  {
    v24 = *(unsigned __int8 *)(a1 + 168);
    v25 = "%s: AID mgr of VDEV%d is invalid";
    goto LABEL_9;
  }
  if ( v23 != v21 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID mgr of VDEV%d and tx vdev(%d) aid mgr doesn't match",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_mlme_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a1 + 168),
      *(unsigned __int8 *)(a2 + 168));
    return 16;
  }
  v27 = *(_WORD *)(v21 + 258);
  v28 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
  if ( v28 )
  {
    v37 = v28;
    _X8 = (unsigned int *)(v28 + 260);
    *(_WORD *)(v28 + 256) = 0;
    *(_WORD *)(v28 + 258) = v27;
    *(_DWORD *)(v28 + 260) = 0;
    __asm { PRFM            #0x11, [X8] }
    do
      v54 = __ldxr(_X8);
    while ( __stxr(v54 + 1, _X8) );
    v39 = wlan_vdev_mlme_get_cmpt_obj(a1, v29, v30, v31, v32, v33, v34, v35, v36);
    if ( v39 )
      *(_QWORD *)(v39 + 248) = v37;
    _X8 = (unsigned int *)(v21 + 260);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v56 = __ldxr(_X8);
      v57 = v56 - 1;
    }
    while ( __stlxr(v57, _X8) );
    __dmb(0xBu);
    if ( !v57 )
    {
      *(_WORD *)(v21 + 258) = 0;
      _qdf_mem_free(v21);
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AID mgr restored for vdev %d (txvdev %d)",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "wlan_mlme_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a1 + 168),
      *(unsigned __int8 *)(a2 + 168));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID bitmap allocation failed for VDEV%d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_mlme_vdev_deinit_mbss_aid_mgr",
      *(unsigned __int8 *)(a1 + 168));
    return 2;
  }
}
