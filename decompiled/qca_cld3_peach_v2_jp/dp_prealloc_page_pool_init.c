__int64 __fastcall dp_prealloc_page_pool_init(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  unsigned int v20; // w1
  const char *v21; // x2
  int *v22; // x22
  __int64 v23; // x8
  int v24; // w5
  __int64 v25; // x8
  unsigned __int64 v26; // x19
  unsigned __int64 v27; // x2
  __int64 v28; // x1
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  __int64 v39; // x25
  __int64 v40; // x21
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x28
  unsigned int v51; // w26
  __int64 v52; // x27
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w24
  __int64 v62; // x1
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  __int64 v75; // x8
  __int64 v76; // x5
  __int64 v77; // x6
  __int64 v78; // [xsp+10h] [xbp-30h]
  unsigned __int64 v79; // [xsp+18h] [xbp-28h]
  char v80[4]; // [xsp+20h] [xbp-20h] BYREF
  char v81[4]; // [xsp+24h] [xbp-1Ch] BYREF
  unsigned __int64 v82; // [xsp+28h] [xbp-18h] BYREF
  int v83; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v84; // [xsp+38h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(64, (__int64)"dp_prealloc_page_pool_init", a2, a3, a4, a5, a6, a7, a8, a9);
  v82 = 0;
  v81[0] = 0;
  v80[0] = 0;
  v78 = result;
  if ( result )
  {
    wlan_cfg_get_tx_pp_cfg(a1, v80);
    result = wlan_cfg_get_rx_pp_cfg(a1, v81, &v82);
    v19 = 0;
    v82 = (v82 + 447) & 0xFFFFFFFFFFFFFFC0LL;
    do
    {
      v22 = &g_dp_page_pool_allocs[12 * v19];
      v23 = *((_QWORD *)v22 + 1);
      v24 = *v22;
      *((_BYTE *)v22 + 40) = 0;
      if ( v23 )
      {
        v20 = 5;
        v21 = "%s: page pool %d type %d already initialized";
LABEL_4:
        result = qdf_trace_msg(
                   0x45u,
                   v20,
                   v21,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   "dp_prealloc_page_pool_init",
                   (unsigned int)v19);
        goto LABEL_5;
      }
      if ( v24 == 1 )
      {
        if ( (v80[0] & 1) == 0 )
          goto LABEL_5;
        v25 = 2048;
      }
      else
      {
        if ( v24 )
        {
          v20 = 2;
          v21 = "%s: invalid page pool %d type %d";
          goto LABEL_4;
        }
        if ( v81[0] != 1 )
          goto LABEL_5;
        v25 = v82;
      }
      v79 = v25;
      v26 = (unsigned int)v22[4];
      v27 = 0x8000;
      *((_QWORD *)v22 + 4) = 0x8000;
      while ( 1 )
      {
        if ( v26 % (v27 / v79) )
          v28 = v26 / (v27 / v79) + 1;
        else
          v28 = v26 / (v27 / v79);
        *((_QWORD *)v22 + 3) = v28;
        v29 = _qdf_page_pool_create(v78);
        if ( !v29 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Failed to create Tx page pool",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "dp_prealloc_page_pool_create");
LABEL_36:
          v72 = (unsigned int)*v22;
          v73 = (unsigned int)v22[4];
          *((_QWORD *)v22 + 1) = 0;
          result = qdf_trace_msg(
                     0x45u,
                     2u,
                     "%s: failed to pre-allocate pool %d type %d size %u",
                     v63,
                     v64,
                     v65,
                     v66,
                     v67,
                     v68,
                     v69,
                     v70,
                     "dp_prealloc_page_pool_init",
                     (unsigned int)v19,
                     v72,
                     v73);
          *((_QWORD *)v22 + 3) = 0;
          *((_QWORD *)v22 + 4) = 0;
          goto LABEL_5;
        }
        v39 = *((_QWORD *)v22 + 3);
        v38 = *((_QWORD *)v22 + 4);
        v40 = v29;
        v83 = 0;
        v41 = _qdf_mem_malloc(8LL * (unsigned int)v39, "dp_page_pool_check_pages_availability", 604);
        if ( !v41 )
          goto LABEL_31;
        v50 = v41;
        if ( !(_DWORD)v39 )
          break;
        v51 = 0;
        while ( 1 )
        {
          v52 = _qdf_page_pool_alloc_frag(v40, &v83, v38);
          *(_QWORD *)(v50 + 8LL * (int)v51) = v52;
          if ( !v52 )
            break;
          if ( (_DWORD)v39 == ++v51 )
            goto LABEL_26;
        }
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: page alloc failed for idx:%u",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "dp_page_pool_check_pages_availability",
          v51);
LABEL_26:
        v61 = 0;
        do
        {
          v62 = *(_QWORD *)(v50 + 8LL * v61);
          if ( v62 )
            _qdf_page_pool_put_page(v40, v62, 0);
          ++v61;
        }
        while ( (_DWORD)v39 != v61 );
        _qdf_mem_free(v50);
        if ( v52 )
          goto LABEL_38;
LABEL_31:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Tx page pool resource not available for page_size:%lu",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "dp_prealloc_page_pool_create",
          *((_QWORD *)v22 + 4));
        _qdf_page_pool_destroy(v40);
        v71 = *((_QWORD *)v22 + 4);
        if ( v71 == 0x4000 )
        {
          v27 = 4096;
          *((_QWORD *)v22 + 4) = 4096;
        }
        else
        {
          if ( v71 != 0x8000 )
            goto LABEL_36;
          v27 = 0x4000;
          *((_QWORD *)v22 + 4) = 0x4000;
        }
      }
      _qdf_mem_free(v41);
LABEL_38:
      v74 = *((_QWORD *)v22 + 3);
      v75 = *((_QWORD *)v22 + 4);
      v76 = (unsigned int)*v22;
      v77 = (unsigned int)v22[4];
      *((_QWORD *)v22 + 1) = v40;
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: page pool %d type %d pre-alloc succ pool_size %u pp_size %zu page_size %zu",
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 "dp_prealloc_page_pool_init",
                 (unsigned int)v19,
                 v76,
                 v77,
                 v74,
                 v75);
LABEL_5:
      ++v19;
    }
    while ( v19 != 5 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
