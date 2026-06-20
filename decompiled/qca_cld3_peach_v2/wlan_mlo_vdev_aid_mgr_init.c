__int64 __fastcall wlan_mlo_vdev_aid_mgr_init(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  __int64 *v12; // x23
  __int64 v13; // x21
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 v24; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x22
  __int64 v29; // x0
  __int64 v31; // x0
  unsigned int v32; // w20
  __int64 v33; // x8
  unsigned int v40; // w9
  unsigned int v42; // w9

  v2 = _qdf_mem_malloc(0x118u, "wlan_mlo_vdev_aid_mgr_init", 1240);
  if ( !v2 )
  {
    *(_QWORD *)(a1[279] + 8) = 0;
    v32 = 2;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s:  ML AID mgr allocation failed",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_mlo_vdev_aid_mgr_init");
    return v32;
  }
  v11 = v2;
  v12 = (__int64 *)(v2 + 264);
  *(_DWORD *)(v2 + 256) = 130482176;
  *(_QWORD *)(a1[279] + 8) = v2;
  v13 = a1[3];
  if ( v13 )
  {
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1[3], v3, v4, v5, v6, v7, v8, v9, v10);
    if ( !cmpt_obj || (v23 = *(_QWORD *)(cmpt_obj + 248)) == 0 )
    {
      v24 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
      if ( !v24 )
      {
        v33 = 0;
LABEL_20:
        v12[v33] = 0;
        v32 = 2;
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: AID bitmap allocation failed for VDEV%d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_mlo_vdev_aid_mgr_init",
          *(unsigned __int8 *)(v13 + 168));
        wlan_mlo_vdev_aid_mgr_deinit(a1);
        return v32;
      }
      v23 = v24;
      *(_DWORD *)(v24 + 256) = 130482176;
      _X8 = (unsigned int *)(v24 + 260);
      *(_DWORD *)(v24 + 260) = 0;
      __asm { PRFM            #0x11, [X8] }
      do
        v40 = __ldxr(_X8);
      while ( __stxr(v40 + 1, _X8) );
    }
    *v12 = v23;
    v26 = wlan_vdev_mlme_get_cmpt_obj(v13, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( v26 )
      *(_QWORD *)(v26 + 248) = v23;
  }
  v13 = a1[4];
  if ( !v13 )
    return 0;
  v27 = wlan_vdev_mlme_get_cmpt_obj(a1[4], v3, v4, v5, v6, v7, v8, v9, v10);
  if ( v27 )
  {
    v28 = *(_QWORD *)(v27 + 248);
    if ( v28 )
      goto LABEL_14;
  }
  v29 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
  if ( !v29 )
  {
    v33 = 1;
    goto LABEL_20;
  }
  v28 = v29;
  *(_DWORD *)(v29 + 256) = 130482176;
  _X8 = (unsigned int *)(v29 + 260);
  *(_DWORD *)(v29 + 260) = 0;
  __asm { PRFM            #0x11, [X8] }
  do
    v42 = __ldxr(_X8);
  while ( __stxr(v42 + 1, _X8) );
LABEL_14:
  *(_QWORD *)(v11 + 272) = v28;
  v31 = wlan_vdev_mlme_get_cmpt_obj(v13, v15, v16, v17, v18, v19, v20, v21, v22);
  v32 = 0;
  if ( v31 )
    *(_QWORD *)(v31 + 248) = v28;
  return v32;
}
