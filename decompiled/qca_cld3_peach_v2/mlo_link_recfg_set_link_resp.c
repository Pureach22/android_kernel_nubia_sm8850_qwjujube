__int64 __fastcall mlo_link_recfg_set_link_resp(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v11; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  __int64 v23; // x8
  unsigned int v24; // w21
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 3888);
    v34 = a2;
    qdf_mutex_acquire(v11 + 760);
    v22 = wlan_sm_dispatch(
            *(_QWORD *)(*(_QWORD *)(v10 + 3888) + 824LL),
            9u,
            4u,
            (__int64)&v34,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21);
    v23 = *(_QWORD *)(v10 + 3888);
    v24 = v22;
    result = qdf_mutex_release(v23 + 760);
    if ( v24 )
      result = qdf_trace_msg(
                 0x8Fu,
                 2u,
                 "%s: fail to deliver set link rsp result %d, vdev %d status %d",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "mlo_link_recfg_set_link_resp",
                 a2,
                 *(unsigned __int8 *)(a1 + 168),
                 v24);
  }
  else
  {
    result = qdf_trace_msg(
               0x8Fu,
               2u,
               "%s: invalid mlo_dev_ctx",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "mlo_link_recfg_set_link_resp");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
