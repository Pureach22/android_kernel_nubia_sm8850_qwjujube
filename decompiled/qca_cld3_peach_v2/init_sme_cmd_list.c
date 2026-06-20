__int64 __fastcall init_sme_cmd_list(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x1
  __int64 v14; // x0
  unsigned __int64 v15; // x20

  *(_DWORD *)(a1 + 12912) = 105;
  v2 = csr_ll_open(a1 + 12928);
  if ( v2 )
    goto LABEL_15;
  v11 = _qdf_mem_malloc((unsigned int)(8 * *(_DWORD *)(a1 + 12912)), "init_sme_cmd_list", 330);
  *(_QWORD *)(a1 + 12920) = v11;
  if ( !v11 )
  {
LABEL_14:
    v2 = 2;
LABEL_15:
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to initialize sme command list: %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "init_sme_cmd_list",
      v2);
    return v2;
  }
  if ( *(_DWORD *)(a1 + 12912) )
  {
    v12 = 0;
    while ( 1 )
    {
      v13 = _qdf_mem_malloc(0x78u, "init_sme_cmd_list", 347);
      v14 = *(_QWORD *)(a1 + 12920);
      if ( !v13 )
        break;
      *(_QWORD *)(v14 + 8 * v12) = v13;
      csr_ll_insert_tail(a1 + 12928);
      if ( ++v12 >= (unsigned __int64)*(unsigned int *)(a1 + 12912) )
        return 0;
    }
    if ( v14 )
    {
      if ( *(_DWORD *)(a1 + 12912) )
      {
        v15 = 0;
        do
          _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(a1 + 12920) + 8 * v15++));
        while ( v15 < *(unsigned int *)(a1 + 12912) );
        v14 = *(_QWORD *)(a1 + 12920);
      }
      _qdf_mem_free(v14);
      *(_QWORD *)(a1 + 12920) = 0;
    }
    goto LABEL_14;
  }
  return 0;
}
