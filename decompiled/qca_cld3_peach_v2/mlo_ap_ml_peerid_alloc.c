__int64 mlo_ap_ml_peerid_alloc()
{
  __int64 mlo_ctx; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x20
  unsigned int v10; // w9
  unsigned __int64 v11; // x19
  unsigned int v12; // w21
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( mlo_ctx )
  {
    v9 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx + 128);
    v10 = *(unsigned __int16 *)(v9 + 344);
    LODWORD(v11) = *(unsigned __int16 *)(v9 + 346);
    v12 = 0;
    if ( *(_WORD *)(v9 + 344) )
    {
      v13 = v9 + 216;
      do
      {
        v11 = ((int)v11 + 1) % v10;
        if ( (_DWORD)v11 && ((*(_QWORD *)(v13 + ((v11 >> 3) & 0x1FFFFFF8)) >> v11) & 1) == 0 )
        {
          *(_QWORD *)(v13 + ((v11 >> 3) & 0x1FFFFFF8)) |= 1LL << v11;
          goto LABEL_10;
        }
        ++v12;
      }
      while ( v12 < v10 );
      v12 = *(unsigned __int16 *)(v9 + 344);
    }
LABEL_10:
    *(_WORD *)(v9 + 346) = v11;
    qdf_mutex_release(v9 + 128);
    if ( v12 == *(unsigned __int16 *)(v9 + 344) )
      LODWORD(v11) = 0xFFFF;
    else
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s:  ML peer id %d is allocated",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "mlo_ap_ml_peerid_alloc",
        (unsigned int)v11);
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: MLO context is NULL", v1, v2, v3, v4, v5, v6, v7, v8, "mlo_ap_ml_peerid_alloc");
    LODWORD(v11) = 0xFFFF;
  }
  return (unsigned int)v11;
}
