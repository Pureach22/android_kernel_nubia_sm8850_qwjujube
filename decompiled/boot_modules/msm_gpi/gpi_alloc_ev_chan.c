__int64 __fastcall gpi_alloc_ev_chan(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x25
  unsigned int *v9; // x21
  __int64 v10; // x26
  unsigned int v11; // w24
  int v12; // w27
  unsigned int v13; // w22
  unsigned int v14; // w23
  __int64 v15; // x0
  __int64 v16; // x6
  unsigned int v17; // w20
  __int64 v18; // x0
  __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x21

  v7 = *(_QWORD *)(a1 + 960);
  v9 = *(unsigned int **)(a1 + 824);
  v10 = *(_QWORD *)(a1 + 832);
  v11 = *(_DWORD *)(v7 + 56);
  v12 = *(_DWORD *)(v7 + 60);
  v14 = *(_DWORD *)(v7 + 16);
  v13 = *(_DWORD *)(v7 + 20);
  if ( *(_DWORD *)(a1 + 1068) >= 3u )
  {
    printk(&unk_128D8, a1 + 1076, 99, "gpi_alloc_ev_chan", a5, a6, a7);
    v15 = *(_QWORD *)(a1 + 1056);
    if ( !v15 )
      goto LABEL_5;
  }
  else
  {
    v15 = *(_QWORD *)(a1 + 1056);
    if ( !v15 )
      goto LABEL_5;
  }
  if ( *(_DWORD *)(a1 + 1064) >= 3u )
    ipc_log_string(v15, "ch:%u %s: enter\n", 99, "gpi_alloc_ev_chan");
LABEL_5:
  v17 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))gpi_send_cmd)(a1, 0, 10);
  if ( v17 )
  {
    if ( *(_DWORD *)(a1 + 1068) >= 2u )
    {
      printk(&unk_12D99, a1 + 1076, 99, "gpi_alloc_ev_chan", "EV ALLOCATE", v17, v16);
      v18 = *(_QWORD *)(a1 + 1056);
      if ( !v18 )
        return v17;
    }
    else
    {
      v18 = *(_QWORD *)(a1 + 1056);
      if ( !v18 )
        return v17;
    }
    if ( *(_DWORD *)(a1 + 1064) >= 2u )
      ipc_log_string(v18, "ch:%u %s: error with cmd:%s ret:%d\n", 99, "gpi_alloc_ev_chan", "EV ALLOCATE", v17);
  }
  else
  {
    if ( v9 )
    {
      writel_relaxed((v12 << 24) | 0x10002, v9);
      writel_relaxed(v11, v9 + 1);
      writel_relaxed(v14, v9 + 2);
      writel_relaxed(v13, v9 + 3);
      if ( v10 )
      {
        writel_relaxed(v13, (unsigned int *)(v10 + 4));
        writel_relaxed(0, v9 + 8);
        writel_relaxed(0, v9 + 10);
        writel_relaxed(0, v9 + 11);
        writel_relaxed(0, v9 + 8);
        writel_relaxed(0, v9 + 12);
        writel_relaxed(0, v9 + 13);
      }
    }
    *(_QWORD *)(v7 + 40) = *(_QWORD *)(v7 + 32) + *(unsigned int *)(v7 + 56) - *(unsigned int *)(v7 + 60);
    __dsb(0xEu);
    raw_write_lock_irq(a1 + 948);
    *(_DWORD *)(a1 + 944) = 3;
    raw_write_unlock_irq(a1 + 948);
    v19 = *(_QWORD *)(v7 + 16);
    v20 = *(_QWORD *)(v7 + 40) - *(_QWORD *)(v7 + 32);
    v21 = v20 + v19;
    writel_relaxed(v20 + v19, *(unsigned int **)(a1 + 832));
    writel_relaxed(HIDWORD(v21), (unsigned int *)(*(_QWORD *)(a1 + 832) + 4LL));
  }
  return v17;
}
