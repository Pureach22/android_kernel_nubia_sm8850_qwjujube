__int64 __fastcall sme_get_apf_capabilities(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+18h] [xbp-28h]
  __int64 v35; // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "sme_get_apf_capabilities");
  v14 = qdf_mutex_acquire(a1 + 12848);
  if ( !v14 )
  {
    *(_QWORD *)(a1 + 14568) = a2;
    *(_QWORD *)(a1 + 14360) = a3;
    v33 = 0;
    LOWORD(v32) = 4469;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x34u,
                         0x36u,
                         54,
                         (unsigned __int16 *)&v32,
                         0x332Du,
                         (__int64)"sme_get_apf_capabilities") )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Post apf get offload msg fail",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "sme_get_apf_capabilities");
      v14 = 16;
    }
    else
    {
      v14 = 0;
    }
    qdf_mutex_release(a1 + 12848);
  }
  qdf_trace_msg(0x34u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "sme_get_apf_capabilities");
  _ReadStatusReg(SP_EL0);
  return v14;
}
