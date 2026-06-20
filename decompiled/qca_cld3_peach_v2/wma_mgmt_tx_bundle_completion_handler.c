__int64 __fastcall wma_mgmt_tx_bundle_completion_handler(
        _QWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned int *v12; // x21
  unsigned int *v13; // x22
  unsigned int v15; // w1
  unsigned int v16; // t1
  unsigned int v17; // t1

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid mgmt Tx completion event",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_mgmt_tx_bundle_completion_handler");
    return 4294967274LL;
  }
  v10 = *(unsigned int *)(*(_QWORD *)a2 + 4LL);
  if ( (unsigned int)v10 >= 0xC0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: excess wmi buffer: num_reports %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_mgmt_tx_bundle_completion_handler",
      (unsigned int)v10);
    return 4294967274LL;
  }
  if ( (unsigned int)v10 > *(_DWORD *)(a2 + 24) || (unsigned int)v10 > *(_DWORD *)(a2 + 40) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid num_reports %d, num_desc_ids %d, num_status %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_mgmt_tx_bundle_completion_handler",
      (unsigned int)v10);
    return 4294967274LL;
  }
  if ( (_DWORD)v10 )
  {
    v12 = *(unsigned int **)(a2 + 16);
    v13 = *(unsigned int **)(a2 + 32);
    do
    {
      v16 = *v12++;
      v15 = v16;
      v17 = *v13++;
      wma_process_mgmt_tx_completion(a1, v15, v17, 0xFFu, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10);
      --v10;
    }
    while ( v10 );
  }
  return 0;
}
