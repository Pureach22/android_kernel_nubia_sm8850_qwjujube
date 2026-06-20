__int64 __fastcall wma_update_target_ext_eht_cap(__int64 a1, _BYTE *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w9
  _DWORD *v13; // x21
  unsigned int v14; // w10
  __int64 v15; // x9
  __int64 v16; // x9
  unsigned __int64 v17; // x22
  int *v18; // x24
  __int64 v19; // x23
  int v20; // w25
  const char *v21; // x2
  unsigned int v22; // w1
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _QWORD v48[11]; // [xsp+8h] [xbp-68h] BYREF
  int v49; // [xsp+60h] [xbp-10h]
  __int64 v50; // [xsp+68h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  memset(v48, 0, sizeof(v48));
  qdf_mem_set(a2 + 556, 0x5Cu, 0);
  qdf_mem_set(a2 + 648, 0x5Cu, 0);
  if ( !a1 )
    goto LABEL_49;
  v12 = *(_DWORD *)(a1 + 504);
  v13 = (_DWORD *)(a1 + 3120);
  if ( v12 <= 0xA )
  {
    if ( *v13 == v12 )
    {
      v14 = 0;
    }
    else if ( *(_DWORD *)(a1 + 3304) == v12 )
    {
      v14 = 1;
    }
    else if ( *(_DWORD *)(a1 + 3488) == v12 )
    {
      v14 = 2;
    }
    else if ( *(_DWORD *)(a1 + 3672) == v12 )
    {
      v14 = 3;
    }
    else if ( *(_DWORD *)(a1 + 3856) == v12 )
    {
      v14 = 4;
    }
    else if ( *(_DWORD *)(a1 + 4040) == v12 )
    {
      v14 = 5;
    }
    else if ( *(_DWORD *)(a1 + 4224) == v12 )
    {
      v14 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 4408) != v12 )
      {
        v13 = nullptr;
LABEL_22:
        if ( *(_DWORD *)(a1 + 1072) == v12 )
        {
          v16 = 0;
        }
        else if ( *(_DWORD *)(a1 + 1328) == v12 )
        {
          v16 = 1;
        }
        else if ( *(_DWORD *)(a1 + 1584) == v12 )
        {
          v16 = 2;
        }
        else if ( *(_DWORD *)(a1 + 1840) == v12 )
        {
          v16 = 3;
        }
        else if ( *(_DWORD *)(a1 + 2096) == v12 )
        {
          v16 = 4;
        }
        else if ( *(_DWORD *)(a1 + 2352) == v12 )
        {
          v16 = 5;
        }
        else if ( *(_DWORD *)(a1 + 2608) == v12 )
        {
          v16 = 6;
        }
        else
        {
          if ( *(_DWORD *)(a1 + 2864) != v12 )
            goto LABEL_49;
          v16 = 7;
        }
        v15 = a1 + 1072 + (v16 << 8);
        if ( v13 )
          goto LABEL_39;
LABEL_49:
        v21 = "%s: Invalid MAC PHY capabilities handle";
LABEL_50:
        v22 = 2;
LABEL_51:
        result = qdf_trace_msg(0x36u, v22, v21, v4, v5, v6, v7, v8, v9, v10, v11, "wma_update_target_ext_eht_cap");
        a2[464] = 0;
        goto LABEL_52;
      }
      v14 = 7;
    }
    v13 += 46 * v14;
    goto LABEL_22;
  }
  v15 = a1 + 1072;
  if ( a1 == -3120 )
    goto LABEL_49;
LABEL_39:
  if ( !v15 )
    goto LABEL_49;
  if ( !*(_DWORD *)(a1 + 824) )
  {
    v21 = "%s: No extended EHT cap for current SOC";
    goto LABEL_50;
  }
  if ( a2[84] != 1 )
  {
    v21 = "%s: Target does not support 11BE";
    v22 = 4;
    goto LABEL_51;
  }
  if ( *(_BYTE *)(a1 + 486) )
  {
    v17 = 0;
    v18 = (int *)(v15 + 24);
    v19 = 184LL * *(unsigned __int8 *)(a1 + 486);
    do
    {
      v20 = *v18;
      if ( (*v18 & 1) != 0 )
      {
        qdf_mem_set(v48, 0x5Cu, 0);
        wma_convert_eht_cap(v48, &v13[v17 / 4 + 6], &v13[v17 / 4 + 10], &v13[v17 / 4 + 17], 1);
        wma_aggregate_eht_cap(a2 + 556, v48);
        wma_aggregate_eht_cap(a2 + 464, v48);
      }
      if ( (v20 & 2) != 0 )
      {
        qdf_mem_set(v48, 0x5Cu, 0);
        wma_convert_eht_cap(v48, &v13[v17 / 4 + 8], &v13[v17 / 4 + 13], &v13[v17 / 4 + 19], 2);
        wma_aggregate_eht_cap(a2 + 648, v48);
        wma_aggregate_eht_cap(a2 + 464, v48);
      }
      v17 += 184LL;
      v18 += 64;
    }
    while ( v19 != v17 );
  }
  wma_update_eht_cap_support_for_320mhz(a1, a2 + 464);
  wma_update_eht_cap_support_for_320mhz(a1, a2 + 648);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Aggregated 2g/5g caps",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wma_update_target_ext_eht_cap");
  wma_print_eht_cap(a2 + 464);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Aggregated 2g caps",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wma_update_target_ext_eht_cap");
  wma_print_eht_cap(a2 + 556);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Aggregated 5g caps",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wma_update_target_ext_eht_cap");
  result = wma_print_eht_cap(a2 + 648);
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
