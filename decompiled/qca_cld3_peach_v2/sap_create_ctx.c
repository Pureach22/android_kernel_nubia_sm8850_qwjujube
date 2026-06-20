__int64 __fastcall sap_create_ctx(__int64 a1)
{
  __int64 v2; // x19
  __int64 *v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v44; // w8

  v2 = _qdf_mem_malloc(0x770u, "sap_create_ctx", 220);
  if ( v2 )
  {
    qdf_mutex_acquire((__int64)&sap_context_lock);
    v3 = &gp_sap_ctx;
    if ( gp_sap_ctx )
    {
      v3 = &qword_91F040;
      if ( qword_91F040 )
      {
        v3 = &qword_91F048;
        if ( qword_91F048 )
        {
          v3 = &qword_91F050;
          if ( qword_91F050 )
          {
            v3 = &qword_91F058;
            if ( qword_91F058 )
            {
              v3 = &qword_91F060;
              if ( qword_91F060 )
              {
                qdf_mutex_release((__int64)&sap_context_lock);
                qdf_trace_msg(
                  0x39u,
                  2u,
                  "%s: failed to save sap context",
                  v4,
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  "wlansap_save_context");
                qdf_trace_msg(
                  0x39u,
                  2u,
                  "%s: failed to save SAP context",
                  v12,
                  v13,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  "sap_create_ctx");
                _qdf_mem_free(v2);
                return 0;
              }
              v20 = 5;
            }
            else
            {
              v20 = 4;
            }
          }
          else
          {
            v20 = 3;
          }
        }
        else
        {
          v20 = 2;
        }
      }
      else
      {
        v20 = 1;
      }
    }
    else
    {
      v20 = 0;
    }
    *v3 = v2;
    _X9 = (unsigned int *)&sap_ctx_ref_count[v20];
    __asm { PRFM            #0x11, [X9] }
    do
      v44 = __ldxr(_X9);
    while ( __stxr(v44 + 1, _X9) );
    qdf_mutex_release((__int64)&sap_context_lock);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sap context saved at index: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlansap_save_context",
      (unsigned int)v20);
    *(_QWORD *)(v2 + 1216) = a1;
    qdf_trace_msg(0x39u, 8u, "%s: Exit", v30, v31, v32, v33, v34, v35, v36, v37, "sap_create_ctx");
  }
  return v2;
}
