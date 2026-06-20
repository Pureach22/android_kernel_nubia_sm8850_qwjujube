__int64 __fastcall sme_get_nud_debug_stats(__int64 a1, const void *a2)
{
  void *v3; // x0
  __int64 v4; // x19
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v3 = (void *)_qdf_mem_malloc(8u, "sme_get_nud_debug_stats", 14053);
  if ( v3 )
  {
    v4 = (__int64)v3;
    qdf_mem_copy(v3, a2, 8u);
    LODWORD(v14) = 4517;
    v15 = v4;
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v14,
               0x36F2u,
               (__int64)"sme_get_nud_debug_stats");
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Not able to post message to WDA",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "sme_get_nud_debug_stats");
      _qdf_mem_free(v4);
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
