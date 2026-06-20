__int64 __fastcall sme_get_link_status(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x21
  unsigned int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  __int64 v21; // [xsp+10h] [xbp-30h]
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
  v21 = 0;
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    v9 = _qdf_mem_malloc(6u, "sme_get_link_status", 3939);
    if ( v9 )
    {
      *(_BYTE *)(v9 + 5) = a4;
      *(_DWORD *)v9 = 397560;
      *(_QWORD *)(a1 + 13144) = a3;
      v10 = v9;
      v21 = v9;
      *(_QWORD *)(a1 + 13136) = a2;
      LODWORD(v20) = 4344;
      v11 = scheduler_post_message_debug(
              0x34u,
              0x36u,
              54,
              (unsigned __int16 *)&v20,
              0xF75u,
              (__int64)"sme_get_link_status");
      if ( v11 )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: post msg failed, %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "sme_get_link_status",
          v11);
        _qdf_mem_free(v10);
        *(_QWORD *)(a1 + 13136) = 0;
        *(_QWORD *)(a1 + 13144) = 0;
      }
    }
    else
    {
      v11 = 2;
    }
    qdf_mutex_release(a1 + 12848);
    result = v11;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
