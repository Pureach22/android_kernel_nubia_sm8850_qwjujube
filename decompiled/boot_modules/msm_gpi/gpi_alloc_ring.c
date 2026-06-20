__int64 __fastcall gpi_alloc_ring(__int64 *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x6
  unsigned int v10; // w8
  int v11; // w24
  unsigned int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 v21; // x10
  void *v22; // x0
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w23

  v6 = 16 * a2;
  v10 = 31 - __clz(v6);
  if ( !(_DWORD)v6 )
    LOBYTE(v10) = 32;
  if ( ((unsigned int)v6 & ~(-1 << v10)) != 0 )
    LOBYTE(v10) = v10 + 1;
  v11 = 1 << v10;
  v12 = 1 << v10;
  a1[1] = 2LL * (1 << v10) - 1;
  if ( *(_DWORD *)(a3 + 1068) >= 3u )
  {
    v26 = 16 * a2;
    printk(&unk_12809, a3 + 1076, 99, "gpi_alloc_ring", a2, 16, v6);
    v6 = v26;
    v13 = *(_QWORD *)(a3 + 1056);
    if ( !v13 )
      goto LABEL_9;
  }
  else
  {
    v13 = *(_QWORD *)(a3 + 1056);
    if ( !v13 )
      goto LABEL_9;
  }
  if ( *(_DWORD *)(a3 + 1064) >= 3u )
    ipc_log_string(
      v13,
      "ch:%u %s: #el:%u el_size:%u len:%u actual_len:%llu alloc_size:%lu\n",
      99,
      "gpi_alloc_ring",
      a2,
      16,
      v6,
      v11,
      a1[1]);
LABEL_9:
  v14 = *(_QWORD *)(a3 + 792);
  if ( *(_BYTE *)(v14 + 497) == 1 )
  {
    v15 = *(_QWORD *)(v14 + 504) + v11;
    if ( v15 > *(_QWORD *)(v14 + 512) )
    {
      if ( *(_DWORD *)(a3 + 1068) >= 2u )
      {
        printk(&unk_143A2, a3 + 1076, 99, "gpi_alloc_ring", a5, a6, v6);
        v16 = *(_QWORD *)(a3 + 1056);
        if ( v16 )
        {
LABEL_13:
          if ( *(_DWORD *)(a3 + 1064) >= 2u )
            ipc_log_string(v16, "ch:%u %s: SMEM region exceeded for GPI driver\n", 99, "gpi_alloc_ring");
        }
      }
      else
      {
        v16 = *(_QWORD *)(a3 + 1056);
        if ( v16 )
          goto LABEL_13;
      }
      return 4294967284LL;
    }
    if ( v11 != 2048 && v11 != 1024 )
    {
      if ( *(_DWORD *)(a3 + 1068) >= 2u )
      {
        printk(&unk_12343, a3 + 1076, 99, "gpi_alloc_ring", v11, a6, v6);
        v25 = *(_QWORD *)(a3 + 1056);
        if ( !v25 )
          return 4294967284LL;
      }
      else
      {
        v25 = *(_QWORD *)(a3 + 1056);
        if ( !v25 )
          return 4294967284LL;
      }
      if ( *(_DWORD *)(a3 + 1064) >= 2u )
        ipc_log_string(v25, "ch:%u %s: request for valid dma memory len=%llu\r\n", 99, "gpi_alloc_ring", v11);
      return 4294967284LL;
    }
    *(_QWORD *)(v14 + 504) = v15;
  }
  else
  {
    *a1 = dma_alloc_attrs(*(_QWORD *)(v14 + 392), a1[1], a1 + 3, 3264, 0);
  }
  v17 = *(_QWORD *)(a3 + 792);
  if ( (*(_BYTE *)(v17 + 497) & 1) != 0 )
  {
    a1[2] = *(_QWORD *)(v17 + 520);
    a1[4] = *(_QWORD *)(*(_QWORD *)(a3 + 792) + 504LL) - v11;
    *(_QWORD *)(*(_QWORD *)(a3 + 792) + 520LL) += v11;
    v18 = a1[4];
  }
  else
  {
    v19 = *a1;
    if ( !*a1 )
    {
      if ( *(_DWORD *)(a3 + 1068) )
      {
        printk(&unk_11C6C, a3 + 1076, 99, "gpi_alloc_ring", a1[1], a6, v6);
        v24 = *(_QWORD *)(a3 + 1056);
        if ( !v24 )
          return 4294967284LL;
      }
      else
      {
        v24 = *(_QWORD *)(a3 + 1056);
        if ( !v24 )
          return 4294967284LL;
      }
      if ( *(_DWORD *)(a3 + 1064) )
        ipc_log_string(v24, "ch:%u %s: could not alloc size:%lu mem for ring\n", 99, "gpi_alloc_ring", a1[1]);
      return 4294967284LL;
    }
    v20 = a1[3];
    v21 = (v11 + v20 - 1) & -(__int64)v11;
    a1[2] = v21;
    v18 = v19 + v21 - v20;
    a1[4] = v18;
  }
  v22 = (void *)a1[4];
  a1[5] = v18;
  a1[6] = v18;
  *((_DWORD *)a1 + 14) = v11;
  *((_DWORD *)a1 + 15) = 16;
  *((_DWORD *)a1 + 16) = (unsigned int)v11 >> 4;
  memset(v22, 0, v12);
  *((_BYTE *)a1 + 68) = 1;
  __dmb(0xAu);
  if ( *(_DWORD *)(a3 + 1068) >= 3u )
  {
    printk(&unk_128EB, a3 + 1076, 99, "gpi_alloc_ring", a1[3], a1[2], *((unsigned int *)a1 + 14));
    result = *(_QWORD *)(a3 + 1056);
    if ( !result )
      return result;
  }
  else
  {
    result = *(_QWORD *)(a3 + 1056);
    if ( !result )
      return result;
  }
  if ( *(_DWORD *)(a3 + 1064) >= 3u )
    ipc_log_string(
      result,
      "ch:%u %s: phy_pre:0x%0llx phy_alig:0x%0llx len:%u el_size:%u elements:%u ring_base:%pK\n",
      99,
      "gpi_alloc_ring",
      a1[3],
      a1[2],
      *((_DWORD *)a1 + 14),
      *((_DWORD *)a1 + 15),
      *((_DWORD *)a1 + 16),
      (const void *)a1[4]);
  return 0;
}
