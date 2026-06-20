__int64 __fastcall sme_ll_stats_set_thresh(
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
  void *v11; // x0
  __int64 v12; // x19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  const char *v23; // x2
  __int64 v24; // [xsp+8h] [xbp-38h] BYREF
  __int64 v25; // [xsp+10h] [xbp-30h]
  __int64 v26; // [xsp+18h] [xbp-28h]
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  if ( !a2 )
  {
    v23 = "%s: threshold is not valid";
LABEL_8:
    qdf_trace_msg(0x34u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "sme_ll_stats_set_thresh");
    result = 4;
    goto LABEL_9;
  }
  if ( !a1 )
  {
    v23 = "%s: mac_handle is not valid";
    goto LABEL_8;
  }
  v11 = (void *)_qdf_mem_malloc(0xBCu, "sme_ll_stats_set_thresh", 10463);
  if ( v11 )
  {
    v12 = (__int64)v11;
    memcpy(v11, a2, 0xBCu);
    v25 = v12;
    LOWORD(v24) = 4506;
    qdf_trace(52, 0xFBu, 255, 4506);
    result = scheduler_post_message_debug(
               0x34u,
               0x36u,
               54,
               (unsigned __int16 *)&v24,
               0x28ECu,
               (__int64)"sme_ll_stats_set_thresh");
    if ( (_DWORD)result )
    {
      v22 = result;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: not able to post WDA_LL_STATS_GET_REQ",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "sme_ll_stats_set_thresh");
      _qdf_mem_free(v12);
      result = v22;
    }
  }
  else
  {
    result = 2;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
