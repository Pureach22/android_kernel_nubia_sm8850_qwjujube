__int64 __fastcall wma_get_caps_for_phyidx_hwmode(
        _DWORD *a1,
        char a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  __int64 v24; // x22
  unsigned int v25; // w9
  int v26; // w25
  _DWORD *v27; // x23
  int v28; // w24
  __int64 v29; // x9
  const char *v31; // x2
  char is_dbs_enable; // w0
  __int64 v33; // x25
  __int64 v34; // x22
  _DWORD *v35; // x27
  char v36; // w28
  int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // [xsp+0h] [xbp-10h]

  context = _cds_get_context(54, (__int64)"wma_get_caps_for_phyidx_hwmode", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 16;
  v23 = context[3];
  if ( !v23 || (v24 = *(_QWORD *)(v23 + 2800)) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: target psoc info is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_get_caps_for_phyidx_hwmode");
    return 4294967274LL;
  }
  if ( !a1 )
  {
    v31 = "%s: Invalid caps pointer";
LABEL_41:
    qdf_trace_msg(0x36u, 2u, v31, v15, v16, v17, v18, v19, v20, v21, v22, "wma_get_caps_for_phyidx_hwmode");
    return 16;
  }
  v25 = *(_DWORD *)(v24 + 504);
  v26 = *(_DWORD *)(v24 + 692);
  v27 = (_DWORD *)(v24 + 1072);
  v28 = *(_DWORD *)(v24 + 696);
  if ( v25 <= 0xA )
  {
    if ( *v27 == v25 )
    {
      v29 = 0;
    }
    else if ( *(_DWORD *)(v24 + 1328) == v25 )
    {
      v29 = 1;
    }
    else if ( *(_DWORD *)(v24 + 1584) == v25 )
    {
      v29 = 2;
    }
    else if ( *(_DWORD *)(v24 + 1840) == v25 )
    {
      v29 = 3;
    }
    else if ( *(_DWORD *)(v24 + 2096) == v25 )
    {
      v29 = 4;
    }
    else if ( *(_DWORD *)(v24 + 2352) == v25 )
    {
      v29 = 5;
    }
    else if ( *(_DWORD *)(v24 + 2608) == v25 )
    {
      v29 = 6;
    }
    else
    {
      if ( *(_DWORD *)(v24 + 2864) != v25 )
      {
LABEL_40:
        v31 = "%s: Invalid MAC PHY capabilities handle";
        goto LABEL_41;
      }
      v29 = 7;
    }
    v27 += 64 * v29;
  }
  if ( !v27 )
    goto LABEL_40;
  if ( *(_BYTE *)(v24 + 824) )
  {
    is_dbs_enable = policy_mgr_is_dbs_enable(v23);
    v33 = *(unsigned __int8 *)(v24 + 486);
    if ( *(_BYTE *)(v24 + 486) )
    {
      v34 = 0;
      v35 = v27 + 15;
      v36 = (a2 != 1) | is_dbs_enable ^ 1;
      do
      {
        if ( v36 & 1 | ((*(v35 - 11) & 0xFB) == 1) )
        {
          if ( a3 <= 1 && (*(_BYTE *)(v35 - 9) & 1) != 0 && !a1[8] )
          {
            *a1 = *(v35 - 6);
            a1[2] = *(v35 - 5);
            qdf_mem_copy(a1 + 4, v35 - 3, 8u);
            v37 = a1[2];
            a1[8] = *v35;
            a1[9] = v35[1];
            LODWORD(v55) = v37;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Select 2G capable phyid[%d] chain %d %d ht 0x%x vht 0x%x",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wma_get_caps_for_phyidx_hwmode",
              (unsigned int)v34,
              v55);
          }
          if ( (a3 & 0xFFFFFFFD) == 0 && (*(_BYTE *)(v35 - 9) & 2) != 0 && !a1[10] )
          {
            a1[1] = v35[3];
            a1[3] = v35[4];
            qdf_mem_copy(a1 + 6, v35 + 6, 8u);
            v46 = a1[3];
            a1[10] = v35[9];
            a1[11] = v35[10];
            LODWORD(v55) = v46;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Select 5G capable phyid[%d] chain %d %d ht 0x%x vht 0x%x",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "wma_get_caps_for_phyidx_hwmode",
              (unsigned int)v34,
              v55);
          }
        }
        ++v34;
        v35 += 64;
      }
      while ( v33 != v34 );
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Invalid number of hw modes, use legacy HT/VHT caps",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_get_caps_for_phyidx_hwmode");
    *a1 = v26;
    a1[1] = v26;
    a1[2] = v28;
    a1[3] = v28;
    *((_QWORD *)a1 + 2) = 0;
    *((_QWORD *)a1 + 3) = 0;
    a1[8] = *(unsigned __int8 *)(v24 + 736);
    a1[9] = *(unsigned __int8 *)(v24 + 737);
    a1[10] = *(unsigned __int8 *)(v24 + 738);
    a1[11] = *(unsigned __int8 *)(v24 + 739);
    return 0;
  }
}
