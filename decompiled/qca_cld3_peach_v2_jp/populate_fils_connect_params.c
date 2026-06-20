void __fastcall populate_fils_connect_params(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x21
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  void *v24; // x0
  size_t v25; // x2
  size_t v26; // x2
  size_t v27; // x2
  size_t v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v11 = *(_QWORD *)(a10 + 9976);
  if ( *(_BYTE *)v11 == 1 )
  {
    if ( *(_BYTE *)(v11 + 696)
      && *(_BYTE *)(v11 + 922)
      && *(_BYTE *)(v11 + 1070)
      && *(_QWORD *)(v11 + 688)
      && *(_BYTE *)(v11 + 889) )
    {
      v14 = _qdf_mem_malloc(0x990u, "populate_fils_connect_params", 2144);
      *(_QWORD *)(a11 + 136) = v14;
      if ( v14 )
      {
        v23 = v14;
        v24 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(v11 + 696), "populate_fils_connect_params", 2151);
        *(_QWORD *)v23 = v24;
        if ( v24 )
        {
          *(_WORD *)(v23 + 2442) = *(_WORD *)(v11 + 68);
          v25 = *(unsigned __int8 *)(v11 + 696);
          *(_BYTE *)(v23 + 8) = v25;
          qdf_mem_copy(v24, *(const void **)(v11 + 688), v25);
          qdf_mem_copy((void *)(v23 + 9), (const void *)(v11 + 697), 0x10u);
          v26 = *(unsigned __int8 *)(v11 + 889);
          *(_BYTE *)(v23 + 89) = v26;
          qdf_mem_copy((void *)(v23 + 25), (const void *)(v11 + 825), v26);
          v27 = *(unsigned __int8 *)(v11 + 922);
          *(_BYTE *)(v23 + 122) = v27;
          qdf_mem_copy((void *)(v23 + 90), (const void *)(v11 + 890), v27);
          v28 = *(unsigned __int8 *)(v11 + 1070);
          *(_BYTE *)(v23 + 378) = v28;
          qdf_mem_copy((void *)(v23 + 123), (const void *)(v11 + 1071), v28);
          cds_copy_hlp_info(
            (int *)(v11 + 1589),
            (int *)(v11 + 1595),
            *(_WORD *)(v11 + 1602),
            *(const void **)(v11 + 1608),
            v23 + 379,
            v23 + 385,
            (unsigned __int16 *)(v23 + 2440),
            (void *)(v23 + 391),
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: FILS connect params copied lim",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "populate_fils_connect_params");
          return;
        }
        _qdf_mem_free(v23);
        *(_QWORD *)(a11 + 136) = 0;
      }
      pe_delete_fils_info(a10, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid FILS info pmk len %d kek len %d tk len %d gtk len %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "populate_fils_connect_params");
    }
  }
}
