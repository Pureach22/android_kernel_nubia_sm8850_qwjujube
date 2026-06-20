__int64 __fastcall sme_power_debug_stats_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  const char *v16; // x2
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    if ( a2 )
    {
      if ( *(_QWORD *)(a1 + 12968) || *(_QWORD *)(a1 + 12976) )
      {
        v15 = 6;
        v16 = "%s: Already one power stats req in progress";
      }
      else
      {
        *(_QWORD *)(a1 + 12968) = a3;
        *(_QWORD *)(a1 + 12976) = a2;
        v18 = 0;
        LOWORD(v17) = 4496;
        v15 = scheduler_post_message_debug(
                0x34u,
                0x36u,
                54,
                (unsigned __int16 *)&v17,
                0x2923u,
                (__int64)"sme_power_debug_stats_req");
        if ( !v15 )
          goto LABEL_8;
        v16 = "%s: not able to post WDA_POWER_DEBUG_STATS_REQ";
      }
    }
    else
    {
      v15 = 16;
      v16 = "%s: Indication callback did not registered";
    }
    qdf_trace_msg(0x34u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "sme_power_debug_stats_req");
LABEL_8:
    qdf_mutex_release(a1 + 12776);
    result = v15;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
