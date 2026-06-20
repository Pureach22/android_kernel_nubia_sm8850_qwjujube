__int64 __fastcall dp_txrx_get_pdev_stats(__int64 a1, char a2, void *a3)
{
  __int64 v3; // x20

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 16;
  dp_aggregate_pdev_stats(*(_QWORD **)(a1 + 72));
  qdf_mem_copy(a3, (const void *)(v3 + 384), 0x16F38u);
  return 0;
}
