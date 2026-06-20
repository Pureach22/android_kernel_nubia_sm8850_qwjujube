__int64 __fastcall hif_napi_create(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  char v17; // w23
  unsigned int v18; // w0
  __int64 v19; // x24
  unsigned __int64 v20; // x8
  __int64 v21; // x25
  __int64 v22; // x26
  __int64 v23; // x0
  __int64 result; // x0
  unsigned int v25; // w9
  __int64 v26; // x23
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x9
  __int64 v36; // x28
  unsigned int irq; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  char v46; // w8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  unsigned int v56; // w20
  __int64 v57; // x8
  __int64 v58; // x8
  __int64 v59; // x8
  __int64 v60; // x8
  __int64 v61; // x8
  __int64 v62; // x8
  __int64 v63; // x8
  __int64 v64; // x8
  __int64 v65; // x8
  __int64 v66; // x8
  __int64 v67; // x0

  if ( (*(_BYTE *)(a1 + 768) & 1) == 0 )
  {
    v17 = a5;
    memset((void *)(a1 + 744), 0, 0x6A8u);
    *(_BYTE *)(a1 + 2440) = v17;
    *(_DWORD *)(a1 + 768) = 1;
    v18 = hif_napi_cpu_init(a1);
    if ( v18 != -114 )
    {
      a5 = v18;
      if ( v18 )
        goto LABEL_62;
    }
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: NAPI structures initialized, rc=%d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "hif_napi_create",
      0);
  }
  if ( *(_DWORD *)(a1 + 656) )
  {
    v19 = 0;
    while ( v19 != 12 )
    {
      v21 = a1 + 8 * v19;
      v22 = *(_QWORD *)(v21 + 480);
      if ( (ce_srng_based(a1) & 1) == 0 && *(_BYTE *)(v22 + 273) == 1 )
      {
        v23 = _qdf_mem_malloc(0x21C0u, "hif_napi_create", 226);
        *(_QWORD *)(v21 + 784) = v23;
        if ( !v23 )
        {
          result = 4294967284LL;
          v25 = *(_DWORD *)(a1 + 656);
          if ( v25 )
            goto LABEL_25;
          return result;
        }
      }
      v20 = *(unsigned int *)(a1 + 656);
      if ( ++v19 >= v20 )
      {
        if ( !*(_DWORD *)(a1 + 656) )
          goto LABEL_22;
        v26 = 0;
        while ( v26 != 12 )
        {
          v35 = a1 + 8 * v26;
          v36 = *(_QWORD *)(v35 + 784);
          if ( v36 )
          {
            memset(*(void **)(v35 + 784), 0, 0x21C0u);
            *(_BYTE *)(v36 + 3128) = a4;
            *(_BYTE *)(v36 + 3129) = v26 + 1;
            *(_QWORD *)(v36 + 2688) = a1;
            irq = pld_get_irq(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
            *(_DWORD *)(v36 + 3132) = irq;
            if ( (irq & 0x80000000) != 0 )
              qdf_trace_msg(
                0x3Du,
                3u,
                "%s: bad IRQ value for CE %d: %d",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "hif_napi_create",
                (unsigned int)v26,
                irq);
            init_dummy_netdev(v36);
            qdf_status_from_os_return(0);
            netif_napi_add_weight(v36, v36 + 2696, a2, a3);
            init_dummy_netdev(v36 + 5888);
            qdf_status_from_os_return(0);
            netif_napi_add_weight(v36 + 5888, v36 + 5456, hif_rxthread_napi_poll, 64);
            napi_enable(v36 + 5456);
            *(_QWORD *)(v36 + 8576) = 0;
            *(_DWORD *)(a1 + 772) |= 1 << v26;
            qdf_trace_msg(
              0x3Du,
              8u,
              "%s: NAPI id %d created for pipe %d",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "hif_napi_create",
              *(unsigned __int8 *)(v36 + 3129),
              (unsigned int)v26);
            v20 = *(unsigned int *)(a1 + 656);
          }
          if ( ++v26 >= v20 )
            goto LABEL_22;
        }
        goto LABEL_61;
      }
    }
    goto LABEL_61;
  }
LABEL_22:
  v46 = ce_srng_based(a1);
  result = *(unsigned int *)(a1 + 772);
  if ( (v46 & 1) == 0 && !(_DWORD)result )
  {
    qdf_trace_msg(
      0x3Du,
      3u,
      "%s: no napis created for copy engines",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "hif_napi_create");
    result = 4294967282LL;
    v25 = *(_DWORD *)(a1 + 656);
    if ( v25 )
    {
LABEL_25:
      v55 = *(_QWORD *)(a1 + 784);
      v56 = result;
      *(_QWORD *)(a1 + 784) = 0;
      if ( v55 )
      {
        _qdf_mem_free(v55);
        v25 = *(_DWORD *)(a1 + 656);
        result = v56;
      }
      if ( v25 >= 2 )
      {
        v57 = *(_QWORD *)(a1 + 792);
        *(_QWORD *)(a1 + 792) = 0;
        if ( v57 )
        {
          _qdf_mem_free(v57);
          v25 = *(_DWORD *)(a1 + 656);
          result = v56;
        }
        if ( v25 >= 3 )
        {
          v58 = *(_QWORD *)(a1 + 800);
          *(_QWORD *)(a1 + 800) = 0;
          if ( v58 )
          {
            _qdf_mem_free(v58);
            v25 = *(_DWORD *)(a1 + 656);
            result = v56;
          }
          if ( v25 >= 4 )
          {
            v59 = *(_QWORD *)(a1 + 808);
            *(_QWORD *)(a1 + 808) = 0;
            if ( v59 )
            {
              _qdf_mem_free(v59);
              v25 = *(_DWORD *)(a1 + 656);
              result = v56;
            }
            if ( v25 >= 5 )
            {
              v60 = *(_QWORD *)(a1 + 816);
              *(_QWORD *)(a1 + 816) = 0;
              if ( v60 )
              {
                _qdf_mem_free(v60);
                v25 = *(_DWORD *)(a1 + 656);
                result = v56;
              }
              if ( v25 >= 6 )
              {
                v61 = *(_QWORD *)(a1 + 824);
                *(_QWORD *)(a1 + 824) = 0;
                if ( v61 )
                {
                  _qdf_mem_free(v61);
                  v25 = *(_DWORD *)(a1 + 656);
                  result = v56;
                }
                if ( v25 >= 7 )
                {
                  v62 = *(_QWORD *)(a1 + 832);
                  *(_QWORD *)(a1 + 832) = 0;
                  if ( v62 )
                  {
                    _qdf_mem_free(v62);
                    v25 = *(_DWORD *)(a1 + 656);
                    result = v56;
                  }
                  if ( v25 >= 8 )
                  {
                    v63 = *(_QWORD *)(a1 + 840);
                    *(_QWORD *)(a1 + 840) = 0;
                    if ( v63 )
                    {
                      _qdf_mem_free(v63);
                      v25 = *(_DWORD *)(a1 + 656);
                      result = v56;
                    }
                    if ( v25 >= 9 )
                    {
                      v64 = *(_QWORD *)(a1 + 848);
                      *(_QWORD *)(a1 + 848) = 0;
                      if ( v64 )
                      {
                        _qdf_mem_free(v64);
                        v25 = *(_DWORD *)(a1 + 656);
                        result = v56;
                      }
                      if ( v25 >= 0xA )
                      {
                        v65 = *(_QWORD *)(a1 + 856);
                        *(_QWORD *)(a1 + 856) = 0;
                        if ( v65 )
                        {
                          _qdf_mem_free(v65);
                          v25 = *(_DWORD *)(a1 + 656);
                          result = v56;
                        }
                        if ( v25 >= 0xB )
                        {
                          v66 = *(_QWORD *)(a1 + 864);
                          *(_QWORD *)(a1 + 864) = 0;
                          if ( v66 )
                          {
                            _qdf_mem_free(v66);
                            v25 = *(_DWORD *)(a1 + 656);
                            result = v56;
                          }
                          if ( v25 >= 0xC )
                          {
                            v67 = *(_QWORD *)(a1 + 872);
                            *(_QWORD *)(a1 + 872) = 0;
                            if ( v67 )
                            {
                              _qdf_mem_free(v67);
                              v25 = *(_DWORD *)(a1 + 656);
                            }
                            result = v56;
                            if ( v25 > 0xC )
                            {
LABEL_61:
                              __break(0x5512u);
LABEL_62:
                              qdf_trace_msg(
                                0x3Du,
                                2u,
                                "%s: NAPI_initialization failed(rc=%d)",
                                a6,
                                a7,
                                a8,
                                a9,
                                a10,
                                a11,
                                a12,
                                a13,
                                "hif_napi_create",
                                a5);
                              return *(unsigned int *)(a1 + 772);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
