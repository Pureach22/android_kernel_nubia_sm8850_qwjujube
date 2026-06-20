__int64 __fastcall sme_del_periodic_tx_ptrn(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v12; // x0
  int v13; // w9
  __int64 v14; // x20
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  __int64 v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "sme_del_periodic_tx_ptrn");
  v12 = (_DWORD *)_qdf_mem_malloc(7u, "sme_del_periodic_tx_ptrn", 7798);
  if ( v12 )
  {
    v13 = *a2;
    v14 = (__int64)v12;
    *(_DWORD *)((char *)v12 + 3) = *(int *)((char *)a2 + 3);
    *v12 = v13;
    v15 = qdf_mutex_acquire(a1 + 12848);
    if ( v15 )
    {
      v24 = v15;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock failed!(status=%d)",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "sme_del_periodic_tx_ptrn",
        v15);
      _qdf_mem_free(v14);
    }
    else
    {
      v35 = v14;
      LOWORD(v34) = 4281;
      qdf_trace(52, 0xFBu, 255, 4281);
      v24 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)&v34,
              0x1E8Bu,
              (__int64)"sme_del_periodic_tx_ptrn");
      if ( v24 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: scheduler_post_msg failed!(err=%d)",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_del_periodic_tx_ptrn",
          v24);
        _qdf_mem_free(v14);
      }
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    v24 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v24;
}
