__int64 __fastcall gpi_mark_stale_events(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x20
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 result; // x0
  __int64 v13; // x22
  __int64 v14; // x8
  __int64 v15; // x24

  v7 = *(_QWORD *)(a1 + 280);
  v9 = *(_QWORD *)(v7 + 960);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_123DE, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_mark_stale_events", a5, a6, a7);
    v10 = *(_QWORD *)(v7 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  else
  {
    v10 = *(_QWORD *)(v7 + 1056);
    if ( !v10 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v10, "ch:%u %s: Enter\n", *(_DWORD *)(a1 + 256), "gpi_mark_stale_events");
LABEL_5:
  v11 = (unsigned int)readl_relaxed(*(_QWORD *)(v7 + 848));
  result = readl_relaxed(*(_QWORD *)(v7 + 848) + 4LL);
  v13 = *(_QWORD *)(v9 + 48);
  v14 = *(_QWORD *)(v9 + 32);
  if ( *(_QWORD *)(v9 + 16) + v13 - v14 != (v11 | (result << 32)) )
  {
    do
    {
      if ( *(_DWORD *)(a1 + 256) == *(unsigned __int8 *)(v13 + 15) )
      {
        *(_BYTE *)(v13 + 14) = -1;
        v14 = *(_QWORD *)(v9 + 32);
      }
      if ( v13 + (unsigned __int64)*(unsigned int *)(v9 + 60) >= v14 + (unsigned __int64)*(unsigned int *)(v9 + 56) )
        v13 = v14;
      else
        v13 += *(unsigned int *)(v9 + 60);
      v15 = (unsigned int)readl_relaxed(*(_QWORD *)(v7 + 848));
      result = readl_relaxed(*(_QWORD *)(v7 + 848) + 4LL);
      v14 = *(_QWORD *)(v9 + 32);
    }
    while ( *(_QWORD *)(v9 + 16) + v13 - v14 != (v15 | (result << 32)) );
  }
  return result;
}
