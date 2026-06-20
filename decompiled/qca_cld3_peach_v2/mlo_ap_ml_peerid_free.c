__int64 __fastcall mlo_ap_ml_peerid_free(unsigned int a1)
{
  __int64 mlo_ctx; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x4
  const char *v12; // x2
  unsigned int v13; // w1
  __int64 v15; // x21

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return qdf_trace_msg(0x8Fu, 2u, "%s: MLO context is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "mlo_ap_ml_peerid_free");
  v11 = (unsigned __int16)a1;
  if ( (unsigned __int16)(a1 + 1) <= 1u
    || (unsigned __int16)a1 > 0x400u
    || *(unsigned __int16 *)(mlo_ctx + 344) < (unsigned int)(unsigned __int16)a1 )
  {
    v12 = "%s:  ML peer id %d is invalid";
    v13 = 2;
  }
  else
  {
    v15 = mlo_ctx;
    qdf_mutex_acquire(mlo_ctx + 128);
    if ( ((*(_QWORD *)(v15 + 216 + ((a1 >> 3) & 0x1FF8LL)) >> a1) & 1) != 0 )
      *(_QWORD *)(v15 + 216 + ((a1 >> 3) & 0x1FF8LL)) &= ~(1LL << a1);
    qdf_mutex_release(v15 + 128);
    v12 = "%s:  ML peer id %d is freed";
    v13 = 8;
    v11 = (unsigned __int16)a1;
  }
  return qdf_trace_msg(0x8Fu, v13, v12, v3, v4, v5, v6, v7, v8, v9, v10, "mlo_ap_ml_peerid_free", v11);
}
