__int64 __fastcall dp_peer_ast_table_attach(__int64 a1)
{
  unsigned int max_ast_idx; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  __int64 v21; // x4

  max_ast_idx = wlan_cfg_get_max_ast_idx(*(_QWORD *)(a1 + 40));
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: \n%pK:<=== cfg max ast idx %d ====>",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "dp_peer_ast_table_attach",
    a1,
    max_ast_idx);
  v11 = _qdf_mem_malloc(8LL * max_ast_idx, "dp_peer_ast_table_attach", 348);
  *(_QWORD *)(a1 + 17608) = v11;
  if ( v11 )
  {
    return 0;
  }
  else
  {
    v21 = a1;
    v20 = 2;
    qdf_trace_msg(
      0x81u,
      2u,
      "%s: %pK: ast_table memory allocation failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "dp_peer_ast_table_attach",
      v21);
  }
  return v20;
}
