__int64 __fastcall wlan_mlme_vdev_init_mbss_aid_mgr(
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
  __int64 v21; // x22
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v49; // w9
  unsigned int v51; // w9
  unsigned int v52; // w9

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj && (v21 = *(_QWORD *)(cmpt_obj + 248)) != 0 )
  {
    v22 = wlan_vdev_mlme_get_cmpt_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( v22 )
      v31 = *(_QWORD *)(v22 + 248);
    else
      v31 = 0;
    _X8 = (unsigned int *)(v21 + 260);
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 + 1, _X8) );
    v34 = wlan_vdev_mlme_get_cmpt_obj(a1, v23, v24, v25, v26, v27, v28, v29, v30);
    if ( v34 )
      *(_QWORD *)(v34 + 248) = v21;
    if ( v31 )
    {
      qdf_trace_msg(
        0x8Fu,
        4u,
        "%s: AID mgr is freed for vdev %d with txvdev %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlan_mlme_vdev_init_mbss_aid_mgr",
        *(unsigned __int8 *)(a1 + 168),
        *(unsigned __int8 *)(a2 + 168));
      _X8 = (unsigned int *)(v31 + 260);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v51 = __ldxr(_X8);
        v52 = v51 - 1;
      }
      while ( __stlxr(v52, _X8) );
      __dmb(0xBu);
      if ( !v52 )
      {
        *(_WORD *)(v31 + 258) = 0;
        _qdf_mem_free(v31);
      }
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AID mgr replaced for vdev %d with txvdev %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "wlan_mlme_vdev_init_mbss_aid_mgr",
      *(unsigned __int8 *)(a1 + 168),
      *(unsigned __int8 *)(a2 + 168));
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: AID mgr of Tx VDEV%d is invalid",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_mlme_vdev_init_mbss_aid_mgr",
      *(unsigned __int8 *)(a2 + 168));
    return 16;
  }
}
