__int64 __fastcall wma_stats_ext_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  _QWORD *context; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x24
  __int64 v29; // x5
  unsigned int v30; // w4
  unsigned int *v31; // x23
  unsigned int v32; // w9
  __int64 v33; // x13
  int v34; // w11
  __int64 v35; // x8
  __int64 v36; // x10
  int v37; // w11
  int v38; // w12
  int *v39; // x13
  __int64 v40; // x14
  int v41; // w15
  int v42; // t1
  int *v43; // x10
  int v44; // w8
  int v45; // t1
  const char *v46; // x2
  __int64 result; // x0
  _DWORD *v48; // x0
  const void *v49; // x22
  __int64 v50; // x20
  size_t v51; // x2
  _DWORD *v52; // x23
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  _DWORD *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int v71; // w8
  __int64 v72; // x9
  unsigned int v73; // w21
  unsigned int *v74; // x25
  int v75; // t1
  __int64 v76; // x8
  __int64 v77; // x8
  unsigned int v78; // w21
  unsigned int *v79; // x22
  unsigned int v80; // t1
  __int64 v81; // x21
  __int64 v82; // x8
  unsigned int v83; // w22
  __int64 v84; // x21
  unsigned int *v85; // x23
  unsigned int v86; // t1
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // [xsp+0h] [xbp-50h] BYREF
  unsigned __int16 v96; // [xsp+18h] [xbp-38h] BYREF
  int v97; // [xsp+1Ch] [xbp-34h]
  __int64 v98; // [xsp+20h] [xbp-30h]
  __int64 v99; // [xsp+48h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(71, (__int64)"wma_stats_ext_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Posting stats ext event to SME",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_stats_ext_event_handler",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    v99);
  if ( !a10 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid stats ext event buf",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_stats_ext_event_handler");
LABEL_21:
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( *((_DWORD *)a10 + 10) )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: number of partner link stats:%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_stats_ext_event_handler");
    v28 = *a10;
    v29 = *((unsigned int *)a10 + 10);
    v31 = (unsigned int *)(*a10 + 8);
    v30 = *v31;
    v32 = *v31 + 32;
    if ( (_DWORD)v29 )
    {
      v33 = a10[4];
      if ( v33 )
      {
        if ( (_DWORD)v29 == 1 )
        {
          v34 = 0;
          LODWORD(v35) = 0;
          v36 = a10[4];
        }
        else
        {
          v35 = (unsigned int)v29 & 0xFFFFFFFE;
          v37 = 0;
          v38 = 0;
          v36 = v33 + 16 * v35;
          v39 = (int *)(v33 + 24);
          v40 = v35;
          do
          {
            v41 = *(v39 - 4);
            v42 = *v39;
            v39 += 8;
            v40 -= 2;
            v37 += v41;
            v38 += v42;
          }
          while ( v40 );
          v34 = v38 + v37;
          if ( v35 == v29 )
            goto LABEL_14;
        }
        v43 = (int *)(v36 + 8);
        v44 = v29 - v35;
        do
        {
          v45 = *v43;
          v43 += 4;
          --v44;
          v34 += v45;
        }
        while ( v44 );
LABEL_14:
        v32 += 24 * v29 + v34;
      }
    }
  }
  else
  {
    v28 = *a10;
    LODWORD(v29) = 0;
    v31 = (unsigned int *)(*a10 + 8);
    v30 = *v31;
    v32 = *v31 + 32;
  }
  if ( v30 > 0x5EC || v30 > *((_DWORD *)a10 + 6) )
  {
    v46 = "%s: Excess data_len:%d, num_data:%d";
    goto LABEL_20;
  }
  if ( (unsigned int)(v29 + 1) < *((_DWORD *)a10 + 18) )
  {
    v46 = "%s: Invalid num_stats_ext2_data:%d num_partner_link_stats %d";
LABEL_20:
    qdf_trace_msg(0x36u, 2u, v46, v20, v21, v22, v23, v24, v25, v26, v27, "wma_stats_ext_event_handler");
    goto LABEL_21;
  }
  v48 = (_DWORD *)_qdf_mem_malloc(v32, "wma_stats_ext_event_handler", 874);
  if ( v48 )
  {
    v49 = (const void *)a10[2];
    v50 = (__int64)v48;
    *v48 = *(_DWORD *)(v28 + 4);
    v51 = *v31;
    v52 = v48 + 2;
    v48[1] = v51;
    qdf_mem_copy(v48 + 2, v49, v51);
    if ( context && *context && (v61 = *(_QWORD *)(*context + 64LL)) != 0 )
    {
      v62 = *(_DWORD **)(v61 + 232);
      if ( v62 )
      {
        if ( *(v62 - 1) != 2126128437 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64 *))v62)(context, 0, &v95);
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "cdp_txrx_ext_stats_request");
    }
    qdf_mem_copy((char *)v52 + *(unsigned int *)(v50 + 4), &v95, 0x18u);
    v71 = *(_DWORD *)(v50 + 4) + 24;
    *(_DWORD *)(v50 + 4) = v71;
    if ( *((_DWORD *)a10 + 10) )
    {
      v72 = a10[4];
      if ( v72 )
      {
        v73 = 0;
        v74 = (unsigned int *)(v72 + 8);
        do
        {
          qdf_mem_copy((char *)v52 + v71, (const void *)(a10[6] + v74[1]), *v74);
          v75 = *v74;
          v74 += 4;
          v76 = (unsigned int)(*(_DWORD *)(v50 + 4) + v75);
          *(_DWORD *)(v50 + 4) = v76;
          qdf_mem_copy((char *)v52 + v76, &v95, 0x18u);
          ++v73;
          v71 = *(_DWORD *)(v50 + 4) + 24;
          *(_DWORD *)(v50 + 4) = v71;
        }
        while ( v73 < *((_DWORD *)a10 + 10) );
      }
    }
    if ( *(_DWORD *)(v28 + 12) == 1 )
    {
      wma_stats_ext_print(v49);
      if ( *((_DWORD *)a10 + 10) )
      {
        v77 = a10[4];
        if ( v77 )
        {
          v78 = 0;
          v79 = (unsigned int *)(v77 + 12);
          do
          {
            v80 = *v79;
            v79 += 4;
            wma_stats_ext_print(a10[6] + v80);
            ++v78;
          }
          while ( v78 < *((_DWORD *)a10 + 10) );
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Legacy data structure",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wma_stats_ext_event_handler");
    }
    if ( *((_DWORD *)a10 + 18) )
    {
      v81 = a10[8];
      wma_stats_vdev_ext2_print(v81, *(unsigned int *)(v28 + 4));
      if ( *((_DWORD *)a10 + 10) )
      {
        v82 = a10[4];
        if ( v82 )
        {
          v83 = 0;
          v84 = v81 + 356;
          v85 = (unsigned int *)(v82 + 4);
          do
          {
            v86 = *v85;
            v85 += 4;
            wma_stats_vdev_ext2_print(v84, v86);
            ++v83;
            v84 += 356;
          }
          while ( v83 < *((_DWORD *)a10 + 10) );
        }
      }
    }
    v98 = v50;
    v96 = 5209;
    v97 = 0;
    if ( (unsigned int)scheduler_post_message_debug(
                         0x36u,
                         0x34u,
                         52,
                         &v96,
                         0x3C2u,
                         (__int64)"wma_stats_ext_event_handler") )
    {
      _qdf_mem_free(v50);
      result = 4294967282LL;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: stats ext event Posted to SME",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wma_stats_ext_event_handler");
      result = 0;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
