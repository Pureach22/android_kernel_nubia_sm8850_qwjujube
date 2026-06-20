__int64 __fastcall dp_prealloc_init(
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
  _QWORD *context; // x20
  __int64 result; // x0
  __int64 v12; // x21
  char *v13; // x23
  unsigned int v14; // w8
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  unsigned int v33; // w21
  __int64 v34; // x26
  int v35; // w8
  unsigned int *v36; // x24
  int v37; // w8
  int *v38; // x9
  bool v39; // zf
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w21
  __int64 v59; // x25
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x5
  __int64 v69; // x6
  char *v70; // x24
  int v71; // w8
  int v72; // w8
  int v73; // w8
  _QWORD *v74; // x0
  __int64 v75; // x0
  char *v76; // x28
  int v77; // w5
  unsigned int v78; // w21
  __int64 v79; // x25
  int *v80; // x26
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w1
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // [xsp+18h] [xbp-58h] BYREF
  __int64 v108; // [xsp+20h] [xbp-50h]
  __int64 v109; // [xsp+28h] [xbp-48h]
  __int64 v110; // [xsp+30h] [xbp-40h]
  __int64 v111; // [xsp+38h] [xbp-38h]
  __int64 v112; // [xsp+40h] [xbp-30h]
  __int64 v113; // [xsp+48h] [xbp-28h] BYREF
  int v114; // [xsp+50h] [xbp-20h] BYREF
  unsigned __int64 v115; // [xsp+58h] [xbp-18h] BYREF
  _QWORD v116[2]; // [xsp+60h] [xbp-10h] BYREF

  v116[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(64, (__int64)"dp_prealloc_init", a2, a3, a4, a5, a6, a7, a8, a9);
  result = 16;
  v114 = 0;
  v112 = 0;
  v113 = 0;
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v107 = 0;
  if ( !a1 || !context )
    goto LABEL_73;
  wlan_cfg_get_prealloc_cfg(a1, &v107);
  v12 = 0;
  v13 = (char *)&unk_17491;
  do
  {
    if ( *(_DWORD *)(v13 - 9) == 13 )
    {
      v14 = 32 * HIDWORD(v113);
      *(_DWORD *)(v13 - 5) = 32 * HIDWORD(v113);
    }
    else
    {
      v14 = *(_DWORD *)(v13 - 5);
    }
    v15 = _qdf_mem_malloc(v14, "dp_prealloc_init", 1215);
    *(_QWORD *)(v13 + 7) = v15;
    if ( !v15 && (*v13 & 1) != 0 )
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: i %d: unable to preallocate %d bytes memory!",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "dp_prealloc_init",
        (unsigned int)v12,
        *(unsigned int *)(v13 - 5));
      v32 = "%s: unable to allocate context memory!";
LABEL_77:
      v98 = 2;
      goto LABEL_78;
    }
    ++v12;
    v13 += 24;
  }
  while ( v12 != 9 );
  v33 = 0;
  v34 = -1344;
  do
  {
    v35 = *(_DWORD *)((char *)&g_dp_consistent_allocs + v34 + 1344);
    v36 = (unsigned int *)((char *)&g_dp_consistent_allocs + v34 + 1348);
    *((_BYTE *)&g_dp_consistent_allocs + v34 + 1352) = 0;
    if ( v35 <= 13 )
    {
      if ( v35 > 4 )
      {
        switch ( v35 )
        {
          case 5:
            v37 = 32 * v107;
            break;
          case 12:
            v37 = 32 * v108;
            break;
          case 13:
            v37 = 32 * HIDWORD(v107);
            break;
          default:
            goto LABEL_40;
        }
      }
      else if ( v35 )
      {
        if ( v35 == 1 )
        {
          v37 = 32 * v109;
        }
        else
        {
          if ( v35 != 4 )
            goto LABEL_40;
          v37 = 112 * HIDWORD(v112);
        }
      }
      else
      {
        v37 = 32 * v111;
      }
      goto LABEL_39;
    }
    if ( v35 <= 23 )
    {
      switch ( v35 )
      {
        case 14:
          v37 = 8 * v112;
          break;
        case 15:
          v37 = 32 * HIDWORD(v108);
          break;
        case 17:
          v37 = 8 * v113;
          break;
        default:
          goto LABEL_40;
      }
      goto LABEL_39;
    }
    v38 = (int *)&v113 + 1;
    if ( v35 == 24 )
      goto LABEL_38;
    if ( v35 == 25 )
    {
      v38 = &v114;
LABEL_38:
      v37 = 16 * *v38;
LABEL_39:
      *v36 = v37;
      goto LABEL_40;
    }
    v39 = v35 == 28;
    v37 = 0;
    if ( v39 )
      goto LABEL_39;
LABEL_40:
    v40 = qdf_aligned_mem_alloc_consistent_fl(
            (__int64)context,
            (unsigned int *)((char *)&g_dp_consistent_allocs + v34 + 1348),
            (__int64 *)((char *)&g_dp_consistent_allocs + v34 + 1360),
            (__int64 *)((char *)&g_dp_consistent_allocs + v34 + 1376),
            (__int64 *)((char *)&g_dp_consistent_allocs + v34 + 1384),
            0x20u,
            (__int64)"dp_prealloc_init",
            0x4D7u);
    v49 = *(_QWORD *)((char *)&g_dp_consistent_allocs + v34 + 1360);
    *(_QWORD *)((char *)&g_dp_consistent_allocs + v34 + 1368) = v40;
    if ( !v49 )
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: i %d: unable to preallocate %d bytes memory!",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "dp_prealloc_init",
        v33,
        *(unsigned int *)((char *)&g_dp_consistent_allocs + v34 + 1348));
      v32 = "%s: unable to allocate consistent memory!";
      goto LABEL_77;
    }
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: i %d: va aligned %pK pa aligned %pK size %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "dp_prealloc_init",
      v33,
      v40,
      *(_QWORD *)((char *)&g_dp_consistent_allocs + v34 + 1384),
      *v36);
    v34 += 48;
    ++v33;
  }
  while ( v34 );
  v58 = 0;
  v59 = -2112;
  do
  {
    v70 = (char *)&g_dp_multi_page_allocs + v59;
    v71 = *(_DWORD *)((char *)&g_dp_multi_page_allocs + v59 + 2112);
    if ( v71 == 16 )
    {
      v116[0] = 0;
      LOBYTE(v115) = 0;
      wlan_cfg_get_rx_pp_cfg(a1, &v115, v116);
      if ( (unsigned __int8)v115 != 1 )
        goto LABEL_45;
      v71 = *((_DWORD *)v70 + 528);
    }
    v70[2132] = 0;
    if ( v71 <= 6 )
    {
      if ( (unsigned int)(v71 - 3) >= 4 )
      {
        if ( !v71 )
        {
          *((_DWORD *)v70 + 532) = HIDWORD(v109);
          *((_QWORD *)v70 + 265) = 256;
        }
        goto LABEL_67;
      }
      v72 = v110;
      goto LABEL_66;
    }
    if ( v71 > 10 )
    {
      if ( v71 != 11 )
      {
        if ( v71 == 16 )
        {
          v74 = _cds_get_context(
                  64,
                  (__int64)"dp_prealloc_update_rx_iova_refcnt_elems",
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57);
          *((_DWORD *)v70 + 532) = 0;
          if ( v74 )
          {
            v75 = v74[5];
            v115 = 0;
            v116[0] = 0;
            if ( !(unsigned int)pld_get_iova_info(v75, (__int64)v116, (__int64)&v115) )
              *((_DWORD *)v70 + 532) = v115 >> 12;
          }
        }
        goto LABEL_67;
      }
      v73 = HIDWORD(v110);
      goto LABEL_65;
    }
    if ( v71 == 7 )
    {
      v72 = HIDWORD(v110);
LABEL_66:
      *((_DWORD *)v70 + 532) = v72;
      goto LABEL_67;
    }
    if ( v71 == 10 )
    {
      v73 = HIDWORD(v109);
LABEL_65:
      v72 = v73 >> 9;
      goto LABEL_66;
    }
LABEL_67:
    v76 = (char *)&g_dp_multi_page_allocs + v59;
    v77 = *((unsigned __int8 *)&g_dp_multi_page_allocs + v59 + 2133);
    if ( v77 == 1 )
      *((_QWORD *)v76 + 270) = 4096;
    qdf_mem_multi_pages_alloc(
      (__int64)context,
      (__int64)(v76 + 2136),
      *((_QWORD *)v70 + 265),
      *((_DWORD *)v70 + 532),
      0,
      v77);
    if ( !*((_WORD *)v76 + 1069) )
    {
      qdf_trace_msg(
        0x45u,
        3u,
        "%s: i %d: preallocate %d bytes multi-pages failed!",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "dp_prealloc_init",
        v58,
        (unsigned int)(*(_DWORD *)((char *)&g_dp_multi_page_allocs + v59 + 2128)
                     * *(_DWORD *)((char *)&g_dp_multi_page_allocs + v59 + 2120)));
      v32 = "%s: unable to allocate multi-pages memory!";
      goto LABEL_77;
    }
    v68 = *(_QWORD *)((char *)&g_dp_multi_page_allocs + v59 + 2152);
    v69 = *(_QWORD *)((char *)&g_dp_multi_page_allocs + v59 + 2144);
    *((_BYTE *)&g_dp_multi_page_allocs + v59 + 2168) = 1;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: i %d: cacheable_pages %pK dma_pages %pK num_pages %d",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_prealloc_init",
      v58,
      v68,
      v69);
LABEL_45:
    v59 += 64;
    ++v58;
  }
  while ( v59 );
  v78 = 0;
  v79 = 0x3FFFFFFFFFFFFFB8LL;
  while ( 1 )
  {
    v80 = &g_dp_consistent_unaligned_allocs[v79];
    LOBYTE(g_dp_consistent_unaligned_allocs[v79 + 74]) = 0;
    v81 = _qdf_mem_alloc_consistent(
            (__int64)context,
            context[5],
            (unsigned int)g_dp_consistent_unaligned_allocs[v79 + 73],
            (__int64)&g_dp_consistent_unaligned_allocs[v79 + 78],
            "dp_prealloc_init",
            1296);
    *(_QWORD *)&g_dp_consistent_unaligned_allocs[v79 + 76] = v81;
    if ( !v81 )
      break;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: i %d: va unalign %pK pa unalign %pK size %d",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "dp_prealloc_init",
      v78,
      v81,
      *((_QWORD *)v80 + 39),
      (unsigned int)v80[73]);
    v79 += 8;
    ++v78;
    if ( !(v79 * 4) )
    {
      dp_prealloc_page_pool_init(a1, v90, v91, v92, v93, v94, v95, v96, v97);
      result = 0;
      goto LABEL_73;
    }
  }
  qdf_trace_msg(
    0x45u,
    3u,
    "%s: i %d: fail to prealloc unaligned %d bytes!",
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    "dp_prealloc_init",
    v78,
    (unsigned int)v80[73]);
  v32 = "%s: unable to allocate unaligned memory!";
  v98 = 5;
LABEL_78:
  qdf_trace_msg(0x45u, v98, v32, v24, v25, v26, v27, v28, v29, v30, v31, "dp_prealloc_init");
  dp_prealloc_deinit(v99, v100, v101, v102, v103, v104, v105, v106);
  result = 16;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
