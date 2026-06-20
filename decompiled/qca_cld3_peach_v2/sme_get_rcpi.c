__int64 __fastcall sme_get_rcpi(__int64 a1, const void *a2)
{
  void *v4; // x0
  __int64 v5; // x19
  int v6; // w0
  int v7; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w20
  __int64 result; // x0
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  __int64 v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h]
  __int64 v21; // [xsp+20h] [xbp-20h]
  __int64 v22; // [xsp+28h] [xbp-18h]
  __int64 v23; // [xsp+30h] [xbp-10h]
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v4 = (void *)_qdf_mem_malloc(0x20u, "sme_get_rcpi", 14161);
  if ( v4 )
  {
    v5 = (__int64)v4;
    qdf_mem_copy(v4, a2, 0x20u);
    v6 = qdf_mutex_acquire(a1 + 12848);
    if ( !v6 )
    {
      v19 = v5;
      LOWORD(v18) = 4501;
      v7 = scheduler_post_message_debug(0x34u, 0x36u, 54, (unsigned __int16 *)&v18, 0x375Du, (__int64)"sme_get_rcpi");
      qdf_mutex_release(a1 + 12848);
      if ( !v7 )
      {
        result = 0;
        goto LABEL_7;
      }
      qdf_trace_msg(0x34u, 2u, "%s: post get rcpi req failed", v8, v9, v10, v11, v12, v13, v14, v15, "sme_get_rcpi");
      v6 = 16;
    }
    v16 = v6;
    _qdf_mem_free(v5);
    result = v16;
  }
  else
  {
    result = 2;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
