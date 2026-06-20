__int64 __fastcall dp_pdev_get_rx_mon_stats(__int64 a1, char a2, void *a3)
{
  __int64 v3; // x8
  __int64 v4; // x8

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 16;
  v4 = *(_QWORD *)(v3 + 95560);
  if ( !v4 )
    return 16;
  qdf_mem_copy(a3, (const void *)(v4 + 60), 0xBECu);
  return 0;
}
