__int64 __fastcall sme_ll_stats_set_req(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  __int64 v11; // x4
  __int64 v12; // x5
  _QWORD *v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x19
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  __int64 v27; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *((unsigned int *)a10 + 2);
  v12 = *((unsigned int *)a10 + 3);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = nullptr;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: MPDU Size = %u Aggressive Stats Collections = %u",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "sme_ll_stats_set_req",
    v11,
    v12);
  v13 = (_QWORD *)_qdf_mem_malloc(0x10u, "sme_ll_stats_set_req", 10311);
  if ( v13 )
  {
    v15 = *a10;
    v14 = a10[1];
    v16 = (__int64)v13;
    *v13 = v15;
    v13[1] = v14;
    v28 = v13;
    LOWORD(v27) = 4336;
    qdf_trace(52, 0xFBu, 255, 4336);
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v27,
               0x2855u,
               (__int64)"sme_ll_stats_set_req");
    if ( (_DWORD)result )
    {
      v26 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: not able to post WMA_LL_STATS_SET_REQ",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_ll_stats_set_req");
      _qdf_mem_free(v16);
      result = v26;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
