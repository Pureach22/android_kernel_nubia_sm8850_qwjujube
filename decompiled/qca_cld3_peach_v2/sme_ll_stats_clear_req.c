__int64 __fastcall sme_ll_stats_clear_req(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  _QWORD *v24; // x0
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x19
  __int64 result; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w20
  __int64 v38; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v39; // [xsp+10h] [xbp-30h]
  __int64 v40; // [xsp+18h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *((unsigned __int8 *)a2 + 4);
  v13 = *((unsigned int *)a2 + 2);
  v14 = *((unsigned __int8 *)a2 + 12);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = nullptr;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: staId = %u statsClearReqMask = 0x%X stopReq = %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_ll_stats_clear_req",
    v12,
    v13,
    v14);
  if ( !a1 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: null mac pointer", v15, v16, v17, v18, v19, v20, v21, v22, "sme_is_session_id_valid");
LABEL_9:
    qdf_trace_msg(0x34u, 2u, "%s: invalid staId %d", v15, v16, v17, v18, v19, v20, v21, v22, "sme_ll_stats_clear_req");
    result = 4;
    goto LABEL_10;
  }
  if ( *((unsigned __int8 *)a2 + 4) >= 6u )
    goto LABEL_9;
  v23 = *(_QWORD *)(a1 + 17296);
  if ( !v23 || (*(_BYTE *)(v23 + 96LL * *((unsigned __int8 *)a2 + 4) + 1) & 1) == 0 )
    goto LABEL_9;
  v24 = (_QWORD *)_qdf_mem_malloc(0x10u, "sme_ll_stats_clear_req", 10269);
  if ( v24 )
  {
    v26 = *a2;
    v25 = a2[1];
    v27 = (__int64)v24;
    *v24 = v26;
    v24[1] = v25;
    v39 = v24;
    LOWORD(v38) = 4335;
    qdf_trace(52, 0xFBu, 255, 4335);
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v38,
               0x282Bu,
               (__int64)"sme_ll_stats_clear_req");
    if ( (_DWORD)result )
    {
      v37 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: not able to post WMA_LL_STATS_CLEAR_REQ",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "sme_ll_stats_clear_req");
      _qdf_mem_free(v27);
      result = v37;
    }
  }
  else
  {
    result = 2;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
