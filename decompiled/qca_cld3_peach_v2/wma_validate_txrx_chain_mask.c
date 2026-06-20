__int64 __fastcall wma_validate_txrx_chain_mask(
        unsigned int a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w19
  const char *v40; // x2
  __int64 result; // x0
  int v42; // w8
  unsigned int v43; // w9
  _DWORD *v44; // x8
  __int64 v45; // x9
  __int64 v46; // x9
  _DWORD *v47; // x8

  context = _cds_get_context(54, (__int64)"wma_validate_txrx_chain_mask", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 16;
  v21 = context[3];
  if ( !v21 )
    return 16;
  v22 = *(_QWORD *)(v21 + 2800);
  if ( !v22 )
    return 16;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: pdev pid %d pval %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wma_validate_txrx_chain_mask",
    a1,
    a2);
  if ( a1 != 2 )
  {
    if ( a1 != 1 )
      return 0;
    if ( (unsigned int)wma_check_txrx_chainmask(*(_DWORD *)(v22 + 688), a2, v23, v24, v25, v26, v27, v28, v29, v30) )
    {
LABEL_7:
      v39 = 16;
      v40 = "%s: failed in validating tx chainmask";
LABEL_12:
      qdf_trace_msg(0x36u, 2u, v40, v31, v32, v33, v34, v35, v36, v37, v38, "wma_validate_txrx_chain_mask");
      return v39;
    }
    v43 = *(_DWORD *)(v22 + 504);
    v44 = (_DWORD *)(v22 + 1072);
    if ( v43 <= 0xA )
    {
      if ( *v44 == v43 )
      {
        v45 = 0;
      }
      else if ( *(_DWORD *)(v22 + 1328) == v43 )
      {
        v45 = 1;
      }
      else if ( *(_DWORD *)(v22 + 1584) == v43 )
      {
        v45 = 2;
      }
      else if ( *(_DWORD *)(v22 + 1840) == v43 )
      {
        v45 = 3;
      }
      else if ( *(_DWORD *)(v22 + 2096) == v43 )
      {
        v45 = 4;
      }
      else if ( *(_DWORD *)(v22 + 2352) == v43 )
      {
        v45 = 5;
      }
      else if ( *(_DWORD *)(v22 + 2608) == v43 )
      {
        v45 = 6;
      }
      else
      {
        if ( *(_DWORD *)(v22 + 2864) != v43 )
          goto LABEL_38;
        v45 = 7;
      }
      v44 += 64 * v45;
    }
    if ( v44 )
    {
      v46 = *(unsigned __int8 *)(v22 + 486);
      if ( !*(_BYTE *)(v22 + 486) )
        goto LABEL_7;
      v47 = v44 + 24;
      v40 = "%s: failed in validating tx chainmask";
      while ( (*v47 & a2) == 0 )
      {
        --v46;
        v47 += 64;
        if ( !v46 )
        {
          v39 = 16;
          goto LABEL_12;
        }
      }
      return 0;
    }
LABEL_38:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid MAC PHY capabilities handle",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wma_tx_is_chainmask_valid");
    goto LABEL_7;
  }
  v42 = wma_check_txrx_chainmask(*(_DWORD *)(v22 + 688), a2, v23, v24, v25, v26, v27, v28, v29, v30);
  result = 0;
  if ( v42 )
  {
    v39 = 0;
    v40 = "%s: failed in validating rtx chainmask";
    goto LABEL_12;
  }
  return result;
}
