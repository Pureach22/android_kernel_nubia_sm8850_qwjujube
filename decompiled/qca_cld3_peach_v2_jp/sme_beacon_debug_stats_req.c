__int64 __fastcall sme_beacon_debug_stats_req(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _DWORD *v17; // x0
  __int64 v18; // x20
  unsigned int v19; // w21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = nullptr;
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    if ( a3 )
    {
      if ( (*(_BYTE *)(a1 + 21957) & 1) != 0 || (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 1064LL) & 1) != 0 )
      {
        v17 = (_DWORD *)_qdf_mem_malloc(4u, "sme_beacon_debug_stats_req", 10567);
        if ( v17 )
        {
          *v17 = a2;
          *(_QWORD *)(a1 + 13000) = a3;
          v18 = (__int64)v17;
          v29 = v17;
          *(_QWORD *)(a1 + 12992) = a4;
          LOWORD(v28) = 4531;
          v19 = scheduler_post_message_debug(
                  0x34u,
                  0x36u,
                  54,
                  (unsigned __int16 *)&v28,
                  0x2954u,
                  (__int64)"sme_beacon_debug_stats_req");
          if ( v19 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: not able to post WMA_BEACON_DEBUG_STATS_REQ",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "sme_beacon_debug_stats_req");
            _qdf_mem_free(v18);
          }
        }
        else
        {
          v19 = 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Beacon Reception stats not supported",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "sme_beacon_debug_stats_req");
        v19 = 11;
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Indication callback did not registered",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sme_beacon_debug_stats_req");
      v19 = 16;
    }
    qdf_mutex_release(a1 + 12776);
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
