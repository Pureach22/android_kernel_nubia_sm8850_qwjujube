__int64 __fastcall sme_stats_ext_request(unsigned __int8 a1, const void **a2)
{
  __int64 v4; // x8
  _DWORD *v5; // x0
  __int64 v6; // x19
  size_t v7; // x2
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)a2;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v5 = (_DWORD *)_qdf_mem_malloc(v4 + 8, "sme_stats_ext_request", 9367);
  if ( v5 )
  {
    v6 = (__int64)v5;
    *v5 = a1;
    v7 = *(unsigned int *)a2;
    v5[1] = v7;
    if ( (_DWORD)v7 )
      qdf_mem_copy(v5 + 2, a2[1], v7);
    LODWORD(v17) = 4322;
    v18 = v6;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v17,
               0x24A8u,
               (__int64)"sme_stats_ext_request");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post WMA_STATS_EXT_REQUEST message to WMA",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sme_stats_ext_request");
      _qdf_mem_free(v6);
      result = 16;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
