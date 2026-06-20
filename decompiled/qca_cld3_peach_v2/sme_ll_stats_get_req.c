__int64 __fastcall sme_ll_stats_get_req(__int64 a1, __int64 *a2, __int64 a3)
{
  _QWORD *v6; // x0
  __int64 v7; // x8
  __int64 v8; // x10
  __int64 v9; // x19
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v21; // [xsp+10h] [xbp-30h]
  __int64 v22; // [xsp+18h] [xbp-28h]
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = nullptr;
  v6 = (_QWORD *)_qdf_mem_malloc(0x18u, "sme_ll_stats_get_req", 10343);
  if ( v6 )
  {
    v7 = a2[2];
    v8 = *a2;
    v6[1] = a2[1];
    v6[2] = v7;
    *v6 = v8;
    *(_QWORD *)(a1 + 13016) = a3;
    v9 = (__int64)v6;
    v21 = v6;
    LOWORD(v20) = 4337;
    qdf_trace(52, 0xFBu, 255, 4337);
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v20,
               0x2875u,
               (__int64)"sme_ll_stats_get_req");
    if ( (_DWORD)result )
    {
      v19 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_LL_STATS_GET_REQ",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_ll_stats_get_req");
      _qdf_mem_free(v9);
      result = v19;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
