__int64 __fastcall sme_configure_stats_avg_factor(__int64 a1, char a2, __int16 a3)
{
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v27; // [xsp+8h] [xbp-38h] BYREF
  __int64 v28; // [xsp+10h] [xbp-30h]
  __int64 v29; // [xsp+18h] [xbp-28h]
  __int64 v30; // [xsp+20h] [xbp-20h]
  __int64 v31; // [xsp+28h] [xbp-18h]
  __int64 v32; // [xsp+30h] [xbp-10h]
  __int64 v33; // [xsp+38h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v6 = _qdf_mem_malloc(4u, "sme_configure_stats_avg_factor", 10846);
  if ( v6 )
  {
    v7 = v6;
    v8 = qdf_mutex_acquire(a1 + 12848);
    if ( v8 )
    {
      v17 = v8;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme_acquire_global_lock error!",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sme_configure_stats_avg_factor");
      _qdf_mem_free(v7);
    }
    else
    {
      *(_BYTE *)v7 = a2;
      *(_WORD *)(v7 + 2) = a3;
      LOWORD(v27) = 4360;
      v28 = v7;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x34u,
                           0x36u,
                           54,
                           (unsigned __int16 *)&v27,
                           0x2A70u,
                           (__int64)"sme_configure_stats_avg_factor") )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Not able to post SIR_HAL_CONFIG_STATS_FACTOR to WMA!",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "sme_configure_stats_avg_factor");
        _qdf_mem_free(v7);
        v17 = 16;
      }
      else
      {
        v17 = 0;
      }
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    v17 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
