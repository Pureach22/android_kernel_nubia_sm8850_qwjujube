__int64 __fastcall sme_txpower_limit(__int64 a1, _QWORD *a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x20
  unsigned int v6; // w0
  unsigned int v7; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
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
  v4 = (_QWORD *)_qdf_mem_malloc(8u, "sme_txpower_limit", 9234);
  if ( v4 )
  {
    v5 = (__int64)v4;
    *v4 = *a2;
    v6 = qdf_mutex_acquire(a1 + 12848);
    if ( v6 )
    {
      v7 = v6;
      _qdf_mem_free(v5);
    }
    else
    {
      LOWORD(v17) = 4316;
      v18 = v5;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x34u,
                           0x36u,
                           54,
                           (unsigned __int16 *)&v17,
                           0x2421u,
                           (__int64)"sme_txpower_limit") )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: not able to post WMA_TX_POWER_LIMIT",
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          "sme_txpower_limit");
        _qdf_mem_free(v5);
        v7 = 16;
      }
      else
      {
        v7 = 0;
      }
      qdf_mutex_release(a1 + 12848);
    }
  }
  else
  {
    v7 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
