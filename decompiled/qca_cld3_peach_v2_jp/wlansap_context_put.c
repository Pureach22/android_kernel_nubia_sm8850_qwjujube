__int64 __fastcall wlansap_context_put(__int64 result)
{
  __int64 v1; // x19
  __int64 *v2; // x21
  __int64 v3; // x20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v19; // w9
  unsigned int v20; // w9

  if ( result )
  {
    v1 = result;
    qdf_mutex_acquire((__int64)&sap_context_lock);
    v2 = &gp_sap_ctx;
    if ( gp_sap_ctx == v1 )
    {
      v3 = 0;
    }
    else
    {
      v2 = &qword_855E88;
      if ( qword_855E88 == v1 )
      {
        v3 = 1;
      }
      else
      {
        v2 = &qword_855E90;
        if ( qword_855E90 == v1 )
        {
          v3 = 2;
        }
        else
        {
          v2 = &qword_855E98;
          if ( qword_855E98 == v1 )
          {
            v3 = 3;
          }
          else
          {
            v2 = &qword_855EA0;
            if ( qword_855EA0 == v1 )
            {
              v3 = 4;
            }
            else
            {
              v2 = &qword_855EA8;
              if ( qword_855EA8 != v1 )
                return qdf_mutex_release((__int64)&sap_context_lock);
              v3 = 5;
            }
          }
        }
      }
    }
    _X8 = (unsigned int *)&sap_ctx_ref_count[v3];
    __asm { PRFM            #0x11, [X8] }
    do
    {
      v19 = __ldxr(_X8);
      v20 = v19 - 1;
    }
    while ( __stlxr(v20, _X8) );
    __dmb(0xBu);
    if ( !v20 )
    {
      v5 = *(_QWORD *)(v1 + 1488);
      if ( v5 )
      {
        _qdf_mem_free(v5);
        *(_QWORD *)(v1 + 1488) = 0;
        *(_BYTE *)(v1 + 1496) = 0;
      }
      _qdf_mem_free(v1);
      *v2 = 0;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap session freed: %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlansap_context_put",
        (unsigned int)v3);
    }
    return qdf_mutex_release((__int64)&sap_context_lock);
  }
  return result;
}
