__int64 __fastcall wlan_hdd_del_tx_ptrn(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v12; // w20
  __int64 v15; // x8
  const char *v16; // x2
  __int64 v18; // x8
  unsigned int v19; // w22
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  __int16 v30; // w8
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7

  v11 = *(_QWORD *)(a3 + 16);
  if ( !v11 )
  {
    v16 = "%s: attr request id failed";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_del_tx_ptrn");
    return 4294967274LL;
  }
  v12 = *(_DWORD *)(v11 + 4);
  if ( v12 == -1 )
  {
    v16 = "%s: request_id cannot be MAX";
    goto LABEL_7;
  }
  mutex_lock(a2 + 1304);
  if ( *(_DWORD *)(a2 + 1256) == v12 )
  {
    v15 = 0;
  }
  else if ( *(_DWORD *)(a2 + 1264) == v12 )
  {
    v15 = 1;
  }
  else if ( *(_DWORD *)(a2 + 1272) == v12 )
  {
    v15 = 2;
  }
  else if ( *(_DWORD *)(a2 + 1280) == v12 )
  {
    v15 = 3;
  }
  else if ( *(_DWORD *)(a2 + 1288) == v12 )
  {
    v15 = 4;
  }
  else
  {
    if ( *(_DWORD *)(a2 + 1296) != v12 )
    {
      mutex_unlock(a2 + 1304);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: req id to pattern id failed (ret=%d)",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlan_hdd_del_tx_ptrn",
        4294967274LL);
      return 4294967274LL;
    }
    v15 = 5;
  }
  v18 = a2 + 1256 + 8 * v15;
  v19 = *(unsigned __int8 *)(v18 + 4);
  *(_DWORD *)v18 = -1;
  mutex_unlock(a2 + 1304);
  v20 = _qdf_mem_malloc(7u, "wlan_hdd_del_tx_ptrn", 18519);
  if ( !v20 )
    return 4294967284LL;
  v29 = *(_DWORD *)(a1 + 1617);
  v30 = *(_WORD *)(a1 + 1621);
  v31 = v20;
  *(_DWORD *)v20 = v29;
  *(_WORD *)(v20 + 4) = v30;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: %02x:%02x:%02x:**:**:%02x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_hdd_del_tx_ptrn",
    (unsigned __int8)v29,
    BYTE1(v29),
    BYTE2(v29),
    HIBYTE(v30));
  *(_BYTE *)(v31 + 6) = v19;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Request Id: %u Pattern id: %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wlan_hdd_del_tx_ptrn",
    v12,
    v19);
  v40 = sme_del_periodic_tx_ptrn(*(_QWORD *)(a2 + 16), v31);
  if ( !v40 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: exit", v41, v42, v43, v44, v45, v46, v47, v48, "wlan_hdd_del_tx_ptrn");
    _qdf_mem_free(v31);
    return 0;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: sme_del_periodic_tx_ptrn failed (err=%d)",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "wlan_hdd_del_tx_ptrn",
    v40);
  _qdf_mem_free(v31);
  return 4294967274LL;
}
