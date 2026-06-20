__int64 __fastcall wlan_mlo_vdev_free_aid_mgr(
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
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x19
  const char *v14; // x2
  unsigned int v15; // w19
  __int64 v16; // x9
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v20; // x21
  __int64 cmpt_obj; // x0
  unsigned int v28; // w9
  unsigned int v29; // w9

  v10 = a1[279];
  if ( !v10 )
  {
    v14 = "%s:  ML AP context is not initialized";
LABEL_8:
    v15 = 2;
    qdf_trace_msg(0x8Fu, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_vdev_free_aid_mgr");
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
  v17 = v11 + 264;
  v18 = *(_QWORD *)(v11 + 264 + 8 * v13);
  if ( v18 )
  {
    _X8 = (unsigned int *)(v18 + 260);
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v28 = __ldxr(_X8);
      v29 = v28 - 1;
    }
    while ( __stlxr(v29, _X8) );
    __dmb(0xBu);
    if ( !v29 )
    {
      *(_WORD *)(v18 + 258) = 0;
      v20 = a2;
      _qdf_mem_free(v18);
      a2 = v20;
    }
  }
  *(_QWORD *)(v17 + 8 * v13) = 0;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a2, a3, a4, a5, a6, a7, a8, a9, a10);
  v15 = 0;
  if ( cmpt_obj )
    *(_QWORD *)(cmpt_obj + 248) = 0;
  return v15;
}
