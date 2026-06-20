__int64 __fastcall dp_peer_find_attach(
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
  unsigned int v9; // w20
  size_t v11; // x20
  void *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  int v22; // w8
  int v23; // w9
  unsigned int v24; // w10
  bool v25; // cc
  int v26; // w20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x9
  unsigned int v37; // w8
  __int64 v38; // x8
  __int64 v39; // x10
  unsigned int (__fastcall *v40)(_QWORD); // x8
  unsigned int max_ast_idx; // w20
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w19
  __int64 v60; // x4
  __int64 v61; // x0
  void (__fastcall *v62)(_QWORD); // x8
  __int64 v63; // x0
  unsigned __int64 v64; // x8
  unsigned __int64 i; // x20
  __int64 v66; // x0

  v9 = *(_DWORD *)(a1 + 13324);
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: \n%pK:<=== cfg max peer id %d ====>",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_peer_find_map_attach",
    a1,
    v9);
  v11 = 8 * v9;
  v12 = (void *)_qdf_mem_malloc(v11, "dp_peer_find_map_attach", 458);
  *(_QWORD *)(a1 + 13136) = v12;
  if ( !v12 )
  {
    v60 = a1;
    v59 = 2;
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: peer map memory allocation failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_peer_find_map_attach",
      v60);
    return v59;
  }
  qdf_mem_set(v12, (unsigned int)v11, 0);
  v21 = *(_DWORD *)(a1 + 13320);
  *(_DWORD *)(a1 + 13304) = 0;
  *(_QWORD *)(a1 + 13312) = 0;
  v22 = 2 * v21;
  if ( v22 )
  {
    v23 = -1;
    v24 = v22;
    do
    {
      v25 = v24 > 1;
      ++v23;
      v24 >>= 1;
    }
    while ( v25 );
    if ( 1 << v23 == v22 )
      v26 = v23;
    else
      v26 = v23 + 1;
  }
  else
  {
    v26 = 0;
  }
  *(_DWORD *)(a1 + 13148) = v26;
  *(_DWORD *)(a1 + 13144) = (1 << v26) - 1;
  v27 = _qdf_mem_malloc(16LL * (1 << v26), "dp_peer_find_hash_attach", 577);
  *(_QWORD *)(a1 + 13152) = v27;
  if ( v27 )
  {
    if ( v26 != 31 )
    {
      v36 = 0;
      if ( 1 << v26 <= 1 )
        v37 = 1;
      else
        v37 = 1 << v26;
      v38 = 16LL * v37;
      do
      {
        *(_QWORD *)(*(_QWORD *)(a1 + 13152) + v36) = 0;
        v39 = *(_QWORD *)(a1 + 13152) + v36;
        v36 += 16;
        *(_QWORD *)(v39 + 8) = v39;
      }
      while ( v38 != v36 );
    }
    v40 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 1512);
    *(_DWORD *)(a1 + 13288) = 0;
    *(_QWORD *)(a1 + 13296) = 0;
    if ( !v40 )
      goto LABEL_19;
    if ( *((_DWORD *)v40 - 1) != -1941278151 )
      __break(0x8228u);
    if ( !v40(a1) )
    {
LABEL_19:
      max_ast_idx = wlan_cfg_get_max_ast_idx(*(_QWORD *)(a1 + 40));
      qdf_trace_msg(
        0x81u,
        5u,
        "%s: \n%pK:<=== cfg max ast idx %d ====>",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dp_peer_ast_table_attach",
        a1,
        max_ast_idx);
      v50 = _qdf_mem_malloc(8LL * max_ast_idx, "dp_peer_ast_table_attach", 348);
      *(_QWORD *)(a1 + 17608) = v50;
      if ( v50 )
        return 0;
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: ast_table memory allocation failed",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "dp_peer_ast_table_attach",
        a1);
    }
    v61 = *(_QWORD *)(a1 + 13152);
    if ( v61 )
    {
      _qdf_mem_free(v61);
      *(_QWORD *)(a1 + 13152) = 0;
    }
    v62 = *(void (__fastcall **)(_QWORD))(a1 + 1504);
    if ( v62 )
    {
      if ( *((_DWORD *)v62 - 1) != -1093861181 )
        __break(0x8228u);
      v62(a1);
    }
  }
  v63 = *(_QWORD *)(a1 + 13136);
  if ( v63 )
  {
    v64 = *(unsigned int *)(a1 + 13324);
    if ( (_DWORD)v64 )
    {
      for ( i = 0; i < v64; ++i )
      {
        v66 = *(_QWORD *)(*(_QWORD *)(a1 + 13136) + 8 * i);
        if ( v66 )
        {
          dp_peer_unref_delete(v66, 0xCu, v28, v29, v30, v31, v32, v33, v34, v35);
          v64 = *(unsigned int *)(a1 + 13324);
        }
      }
      v63 = *(_QWORD *)(a1 + 13136);
    }
    _qdf_mem_free(v63);
    *(_QWORD *)(a1 + 13136) = 0;
  }
  return 2;
}
