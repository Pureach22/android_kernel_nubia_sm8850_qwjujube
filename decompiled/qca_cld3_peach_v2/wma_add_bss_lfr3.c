__int64 __fastcall wma_add_bss_lfr3(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *context; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 (*v30)(void); // x8
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  const char *v35; // x2
  unsigned int v36; // w1

  result = wma_update_iface_params(a1, (__int64)a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    context = _cds_get_context(71, (__int64)"wma_cdp_find_peer_by_addr", v12, v13, v14, v15, v16, v17, v18, v19);
    if ( context )
    {
      if ( *context && (v29 = *(_QWORD *)(*context + 72LL)) != 0 )
      {
        v30 = *(__int64 (**)(void))(v29 + 16);
        if ( v30 )
        {
          if ( *((_DWORD *)v30 - 1) != 454466150 )
            __break(0x8228u);
          if ( (v30() & 1) != 0 )
          {
            if ( a2 )
            {
              v31 = *a2;
              v32 = a2[1];
              v33 = a2[2];
              v34 = a2[5];
            }
            else
            {
              v33 = 0;
              v31 = 0;
              v32 = 0;
              v34 = 0;
            }
            v35 = "%s: LFR3: bssid %02x:%02x:%02x:**:**:%02x";
            v36 = 8;
            return qdf_trace_msg(
                     0x36u,
                     v36,
                     v35,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     "wma_add_bss_lfr3",
                     v31,
                     v32,
                     v33,
                     v34);
          }
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v21, v22, v23, v24, v25, v26, v27, v28, "cdp_find_peer_exist");
      }
      if ( a2 )
        goto LABEL_13;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get pdev/soc",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wma_cdp_find_peer_by_addr");
      if ( a2 )
      {
LABEL_13:
        v31 = *a2;
        v32 = a2[1];
        v33 = a2[2];
        v34 = a2[5];
LABEL_16:
        v35 = "%s: Failed to find peer %02x:%02x:%02x:**:**:%02x";
        v36 = 2;
        return qdf_trace_msg(
                 0x36u,
                 v36,
                 v35,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 "wma_add_bss_lfr3",
                 v31,
                 v32,
                 v33,
                 v34);
      }
    }
    v33 = 0;
    v31 = 0;
    v32 = 0;
    v34 = 0;
    goto LABEL_16;
  }
  return result;
}
