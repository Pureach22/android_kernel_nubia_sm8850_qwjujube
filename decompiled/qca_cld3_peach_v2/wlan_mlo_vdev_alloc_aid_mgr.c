__int64 __fastcall wlan_mlo_vdev_alloc_aid_mgr(
        _QWORD *a1,
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
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x8
  __int64 v13; // x22
  const char *v14; // x2
  unsigned int v15; // w20
  __int64 v16; // x8
  __int64 cmpt_obj; // x0
  __int64 v19; // x19
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v30; // x4
  unsigned int v37; // w9
  __int64 v38; // x0

  v10 = a1[279];
  if ( !v10 )
  {
    v14 = "%s:  ML AP context is not initialized";
LABEL_8:
    v15 = 2;
    qdf_trace_msg(0x8Fu, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_vdev_alloc_aid_mgr");
    return v15;
  }
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 )
  {
    v14 = "%s:  ML AID mgr allocation failed";
    goto LABEL_8;
  }
  v12 = a1[3];
  if ( v12 && v12 == a2 )
  {
    v13 = 0;
  }
  else
  {
    v16 = a1[4];
    v15 = 0;
    if ( !v16 || v16 != a2 )
      return v15;
    v13 = 1;
  }
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj || (v19 = *(_QWORD *)(cmpt_obj + 248)) == 0 )
  {
    v20 = _qdf_mem_malloc(0x108u, "wlan_vdev_aid_mgr_init", 918);
    if ( !v20 )
    {
      v30 = *(unsigned __int8 *)(a2 + 168);
      v15 = 2;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: AID bitmap allocation failed for VDEV%d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_mlo_vdev_alloc_aid_mgr",
        v30);
      return v15;
    }
    v19 = v20;
    *(_DWORD *)(v20 + 256) = 130482176;
    _X8 = (unsigned int *)(v20 + 260);
    *(_DWORD *)(v20 + 260) = 0;
    __asm { PRFM            #0x11, [X8] }
    do
      v37 = __ldxr(_X8);
    while ( __stxr(v37 + 1, _X8) );
    v38 = wlan_vdev_mlme_get_cmpt_obj(a2, v21, v22, v23, v24, v25, v26, v27, v28);
    if ( v38 )
      *(_QWORD *)(v38 + 248) = v19;
  }
  v15 = 0;
  *(_QWORD *)(v11 + 8 * v13 + 264) = v19;
  return v15;
}
