__int64 __fastcall mlo_link_recfg_add_connect_done_indication(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w0
  __int64 v21; // x8
  unsigned int v22; // w19
  __int64 result; // x0
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 3888);
    if ( v11 )
    {
      v24 = a2;
      qdf_mutex_acquire(v11 + 760);
      v20 = wlan_sm_dispatch(
              *(_QWORD *)(*(_QWORD *)(v10 + 3888) + 824LL),
              0xCu,
              4u,
              (__int64)&v24,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19);
      v21 = *(_QWORD *)(v10 + 3888);
      v22 = v20;
      qdf_mutex_release(v21 + 760);
      result = v22;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_link_recfg_add_connect_done_indication");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
