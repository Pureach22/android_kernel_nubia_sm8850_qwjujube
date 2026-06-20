__int64 __fastcall sme_add_periodic_tx_ptrn(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  void *v12; // x0
  __int64 v13; // x20
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v33; // [xsp+8h] [xbp-38h] BYREF
  __int64 v34; // [xsp+10h] [xbp-30h]
  __int64 v35; // [xsp+18h] [xbp-28h]
  __int64 v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "sme_add_periodic_tx_ptrn");
  v12 = (void *)_qdf_mem_malloc(0x610u, "sme_add_periodic_tx_ptrn", 7749);
  if ( v12 )
  {
    v13 = (__int64)v12;
    memcpy(v12, a2, 0x610u);
    v14 = qdf_mutex_acquire(a1 + 12848);
    if ( v14 )
    {
      v23 = v14;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock failed!(status=%d)",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_add_periodic_tx_ptrn",
        v14);
      _qdf_mem_free(v13);
    }
    else
    {
      v34 = v13;
      LOWORD(v33) = 4280;
      qdf_trace(52, 0xFBu, 255, 4280);
      v23 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)&v33,
              0x1E5Au,
              (__int64)"sme_add_periodic_tx_ptrn");
      if ( v23 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: scheduler_post_msg failed!(err=%d)",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "sme_add_periodic_tx_ptrn",
          v23);
        _qdf_mem_free(v13);
      }
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    v23 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
