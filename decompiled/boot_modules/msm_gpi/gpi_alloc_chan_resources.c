__int64 __fastcall gpi_alloc_chan_resources(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x19
  __int64 v9; // x0
  __int64 v10; // x5
  __int64 v11; // x6
  unsigned int v12; // w21
  __int64 v13; // x0

  v7 = *(_QWORD *)(a1 + 280);
  if ( *(_DWORD *)(v7 + 1068) >= 3u )
  {
    printk(&unk_128D8, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_alloc_chan_resources", a5, a6, a7);
    v9 = *(_QWORD *)(v7 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  else
  {
    v9 = *(_QWORD *)(v7 + 1056);
    if ( !v9 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(v7 + 1064) >= 3u )
    ipc_log_string(v9, "ch:%u %s: enter\n", *(_DWORD *)(a1 + 256), "gpi_alloc_chan_resources");
LABEL_5:
  mutex_lock(v7 + 888);
  v12 = gpi_alloc_ring(*(_QWORD *)(a1 + 352), *(unsigned int *)(a1 + 344), v7);
  if ( v12 )
  {
    if ( *(_DWORD *)(v7 + 1068) >= 2u )
    {
      printk(&unk_146E0, v7 + 1076, *(unsigned int *)(a1 + 256), "gpi_alloc_chan_resources", v12, v10, v11);
      v13 = *(_QWORD *)(v7 + 1056);
      if ( !v13 )
        goto LABEL_10;
    }
    else
    {
      v13 = *(_QWORD *)(v7 + 1056);
      if ( !v13 )
        goto LABEL_10;
    }
    if ( *(_DWORD *)(v7 + 1064) >= 2u )
      ipc_log_string(
        v13,
        "ch:%u %s: error allocating xfer ring, ret:%d\n",
        *(_DWORD *)(a1 + 256),
        "gpi_alloc_chan_resources",
        v12);
  }
LABEL_10:
  mutex_unlock(v7 + 888);
  return v12;
}
