__int64 __fastcall wlan_mlo_vdev_init_mbss_aid_mgr(
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
  __int64 v11; // x22
  __int64 cmpt_obj; // x0
  __int64 v16; // x23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x21
  __int64 v27; // x4
  const char *v28; // x2
  __int64 result; // x0
  __int64 v30; // x9
  __int64 v31; // x8
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  unsigned __int16 v44; // w1
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  __int64 v63; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x8
  unsigned __int16 v73; // w1
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v96; // w8
  unsigned int v98; // w8
  unsigned int v100; // w8
  unsigned int v101; // w8
  unsigned int v103; // w8
  unsigned int v104; // w8

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
      "wlan_mlo_vdev_init_mbss_aid_mgr");
    return 16;
  }
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 2232) + 8LL);
  if ( !v11 )
  {
    v27 = *(unsigned __int8 *)(a1 + 16);
    v28 = "%s: AID mgr of ML VDEV(%d) is invalid";
    goto LABEL_10;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a3, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cmpt_obj || (v16 = *(_QWORD *)(cmpt_obj + 248)) == 0 )
  {
    v27 = *(unsigned __int8 *)(a3 + 168);
    v28 = "%s: AID mgr of Tx VDEV%d is invalid";
LABEL_10:
    qdf_trace_msg(0x8Fu, 2u, v28, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_mlo_vdev_init_mbss_aid_mgr", v27);
    return 16;
  }
  v17 = wlan_vdev_mlme_get_cmpt_obj(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v17 )
    v26 = *(_QWORD *)(v17 + 248);
  else
    v26 = 0;
  v30 = *(_QWORD *)(a1 + 24);
  v31 = a1;
  _X25 = (unsigned int *)(v16 + 260);
  _X24 = (unsigned int *)(v26 + 260);
  if ( v30 && v30 == a2 )
  {
    v34 = wlan_vdev_mlme_get_cmpt_obj(a3, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v34 && (v43 = *(_QWORD *)(v34 + 248)) != 0 )
      v44 = *(_WORD *)(v43 + 256);
    else
      v44 = 0;
    wlan_vdev_mlme_set_start_aid(a2, v44, v35, v36, v37, v38, v39, v40, v41, v42);
    __asm { PRFM            #0x11, [X25] }
    do
      v96 = __ldxr(_X25);
    while ( __stxr(v96 + 1, _X25) );
    v53 = wlan_vdev_mlme_get_cmpt_obj(a2, v45, v46, v47, v48, v49, v50, v51, v52);
    if ( v53 )
      *(_QWORD *)(v53 + 248) = v16;
    *(_QWORD *)(v11 + 264) = v16;
    if ( v26 )
    {
      qdf_trace_msg(
        0x8Fu,
        4u,
        "%s: AID mgr is freed for vdev %d with txvdev %d",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "wlan_mlo_vdev_init_mbss_aid_mgr",
        *(unsigned __int8 *)(a2 + 168),
        *(unsigned __int8 *)(a3 + 168));
      __asm { PRFM            #0x11, [X24] }
      do
      {
        v100 = __ldxr(_X24);
        v101 = v100 - 1;
      }
      while ( __stlxr(v101, _X24) );
      __dmb(0xBu);
      if ( !v101 )
      {
        *(_WORD *)(v26 + 258) = 0;
        _qdf_mem_free(v26);
      }
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AID mgr replaced for vdev %d with txvdev %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wlan_mlo_vdev_init_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168),
      *(unsigned __int8 *)(a3 + 168));
    v31 = a1;
  }
  v62 = *(_QWORD *)(v31 + 32);
  result = 0;
  if ( v62 && v62 == a2 )
  {
    v63 = wlan_vdev_mlme_get_cmpt_obj(a3, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v63 && (v72 = *(_QWORD *)(v63 + 248)) != 0 )
      v73 = *(_WORD *)(v72 + 256);
    else
      v73 = 0;
    wlan_vdev_mlme_set_start_aid(a2, v73, v64, v65, v66, v67, v68, v69, v70, v71);
    __asm { PRFM            #0x11, [X25] }
    do
      v98 = __ldxr(_X25);
    while ( __stxr(v98 + 1, _X25) );
    v82 = wlan_vdev_mlme_get_cmpt_obj(a2, v74, v75, v76, v77, v78, v79, v80, v81);
    if ( v82 )
      *(_QWORD *)(v82 + 248) = v16;
    *(_QWORD *)(v11 + 272) = v16;
    if ( v26 )
    {
      qdf_trace_msg(
        0x8Fu,
        4u,
        "%s: AID mgr is freed for vdev %d with txvdev %d",
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        "wlan_mlo_vdev_init_mbss_aid_mgr",
        *(unsigned __int8 *)(a2 + 168),
        *(unsigned __int8 *)(a3 + 168));
      __asm { PRFM            #0x11, [X24] }
      do
      {
        v103 = __ldxr(_X24);
        v104 = v103 - 1;
      }
      while ( __stlxr(v104, _X24) );
      __dmb(0xBu);
      if ( !v104 )
      {
        *(_WORD *)(v26 + 258) = 0;
        _qdf_mem_free(v26);
      }
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AID mgr replaced for vdev %d with txvdev %d",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "wlan_mlo_vdev_init_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168),
      *(unsigned __int8 *)(a3 + 168));
    return 0;
  }
  return result;
}
