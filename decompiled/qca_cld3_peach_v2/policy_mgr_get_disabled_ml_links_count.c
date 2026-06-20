__int64 __fastcall policy_mgr_get_disabled_ml_links_count(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4)
{
  __int64 context; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  bool v25; // zf
  int v26; // w25
  unsigned int v27; // w23

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v16 = context;
    qdf_mutex_acquire(context + 56);
    if ( a2 )
      v25 = a3 == 0;
    else
      v25 = 1;
    v26 = !v25;
    if ( pm_disabled_ml_links == 1 )
    {
      if ( v26 )
      {
        if ( a4 )
        {
          v27 = 1;
          *(_DWORD *)a2 = dword_8D4FC8;
          *(_BYTE *)a3 = byte_8D4FCC;
          goto LABEL_16;
        }
      }
      else
      {
        if ( !(a2 | a3) )
        {
          v27 = 1;
LABEL_16:
          if ( byte_8D4FD0 == 1 )
          {
            if ( (v26 & 1) != 0 )
            {
              if ( v27 < a4 )
              {
                *(_DWORD *)(a2 + 4LL * v27) = dword_8D4FD8;
                *(_BYTE *)(a3 + v27) = byte_8D4FDC;
LABEL_22:
                ++v27;
              }
            }
            else
            {
              if ( !(a2 | a3) )
                goto LABEL_22;
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: freq list or vdev list null",
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                "policy_mgr_get_disabled_ml_links_count");
            }
          }
          qdf_mutex_release(v16 + 56);
          return v27;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: freq list or vdev list null",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "policy_mgr_get_disabled_ml_links_count");
      }
    }
    v27 = 0;
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid pm_ctx",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "policy_mgr_get_disabled_ml_links_count");
  return 0;
}
