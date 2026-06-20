__int64 __fastcall wma_get_rx_chainmask(
        unsigned __int8 a1,
        unsigned int *a2,
        unsigned int *a3,
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
  __int64 v23; // x8
  __int64 v24; // x10
  __int64 v25; // x4
  unsigned int v26; // w9
  unsigned int v27; // w11
  unsigned int v29; // w8
  _DWORD *v30; // x9
  __int64 v31; // x10
  int v33; // w10

  context = _cds_get_context(54, (__int64)"wma_get_rx_chainmask", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
    return 4;
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
      "wma_get_rx_chainmask");
    return 4;
  }
  v25 = *(unsigned __int8 *)(v24 + 486);
  if ( (unsigned int)v25 <= a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: mac phy cnt %d, pdev id %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wma_get_rx_chainmask");
    return 16;
  }
  v26 = *((_DWORD *)context + 729);
  v27 = *(_DWORD *)(v24 + 504);
  if ( v26 > *(_DWORD *)(v24 + 824) || v26 == 0xFFFF )
    v29 = 0;
  else
    v29 = *((_DWORD *)context + 729);
  v30 = (_DWORD *)(v24 + 1072);
  if ( v27 <= 0xA )
  {
    if ( *v30 == v27 )
    {
      v31 = 0;
    }
    else if ( *(_DWORD *)(v24 + 1328) == v27 )
    {
      v31 = 1;
    }
    else if ( *(_DWORD *)(v24 + 1584) == v27 )
    {
      v31 = 2;
    }
    else if ( *(_DWORD *)(v24 + 1840) == v27 )
    {
      v31 = 3;
    }
    else if ( *(_DWORD *)(v24 + 2096) == v27 )
    {
      v31 = 4;
    }
    else if ( *(_DWORD *)(v24 + 2352) == v27 )
    {
      v31 = 5;
    }
    else if ( *(_DWORD *)(v24 + 2608) == v27 )
    {
      v31 = 6;
    }
    else
    {
      if ( *(_DWORD *)(v24 + 2864) != v27 )
      {
LABEL_34:
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid MAC PHY capabilities handle",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wma_get_rx_chainmask");
        return 16;
      }
      v31 = 7;
    }
    v30 += 64 * v31;
  }
  if ( !v30 )
    goto LABEL_34;
  do
  {
    if ( *v30 == v29 )
    {
      v33 = v30[6];
      if ( (v33 & 1) != 0 )
      {
        *a2 = v30[16];
        v33 = v30[6];
      }
      if ( (v33 & 2) != 0 )
        *a3 = v30[25];
    }
    --v25;
    v30 += 64;
  }
  while ( v25 );
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: pdev id: %d, hw_mode_idx: %d, rx chainmask 2g:%d, 5g:%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wma_get_rx_chainmask",
    a1,
    v29,
    *a2,
    *a3);
  return 0;
}
