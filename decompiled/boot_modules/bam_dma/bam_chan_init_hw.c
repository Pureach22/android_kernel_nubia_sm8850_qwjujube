void __fastcall bam_chan_init_hw(__int64 a1, int a2)
{
  __int64 v2; // x21
  unsigned int *v5; // x8
  unsigned int *v6; // x8
  unsigned int *v7; // x8
  int v8; // w9
  unsigned int v9; // w10
  unsigned int v10; // w11
  unsigned int v11; // w13
  __int64 v12; // x8
  __int64 v13; // x10
  unsigned int v14; // w0
  unsigned int *v15; // x8
  int v16; // w0
  unsigned int *v17; // x8
  int v18; // w9
  __int64 v19; // x10
  __int64 v20; // x9
  __int64 v21; // x12
  __int64 v22; // x8
  unsigned int v23; // w0
  __int64 v24; // x0
  __int64 v25; // x3

  v2 = *(_QWORD *)(a1 + 256);
  writel_relaxed(
    1u,
    (unsigned int *)(*(_QWORD *)v2
                   + *(unsigned int *)(*(_QWORD *)(v2 + 440) + 224LL)
                   + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 440) + 228LL) * *(_DWORD *)(a1 + 264))
                   + (unsigned int)(*(_DWORD *)(*(_QWORD *)(v2 + 440) + 232LL) * *(_DWORD *)(a1 + 264))
                   + (unsigned __int64)(unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 236LL))));
  v5 = *(unsigned int **)(v2 + 440);
  writel_relaxed(
    0,
    (unsigned int *)(*(_QWORD *)v2
                   + v5[56]
                   + v5[57] * *(_DWORD *)(a1 + 264)
                   + v5[58] * *(_DWORD *)(a1 + 264)
                   + (unsigned __int64)(*(_DWORD *)(v2 + 424) * v5[59])));
  __dsb(0xEu);
  *(_DWORD *)(a1 + 364) = 0;
  v6 = *(unsigned int **)(v2 + 440);
  writel_relaxed(
    (*(_DWORD *)(a1 + 352) + 7) & 0xFFFFFFF8,
    (unsigned int *)(*(_QWORD *)v2
                   + v6[92]
                   + v6[93] * *(_DWORD *)(a1 + 264)
                   + v6[94] * *(_DWORD *)(a1 + 264)
                   + (unsigned __int64)(*(_DWORD *)(v2 + 424) * v6[95])));
  v7 = *(unsigned int **)(v2 + 440);
  v8 = *(_DWORD *)(a1 + 264);
  v9 = v7[101];
  v10 = v7[102];
  v11 = v7[103];
  v12 = v7[100];
  v13 = v9 * v8;
  if ( *(_BYTE *)(v2 + 532) )
    v14 = 256;
  else
    v14 = 0x8000;
  writel_relaxed(
    v14,
    (unsigned int *)(*(_QWORD *)v2 + v12 + v13 + v10 * v8 + (unsigned __int64)(*(_DWORD *)(v2 + 424) * v11)));
  v15 = *(unsigned int **)(v2 + 440);
  writel_relaxed(
    0x31u,
    (unsigned int *)(*(_QWORD *)v2
                   + v15[72]
                   + v15[73] * *(_DWORD *)(a1 + 264)
                   + v15[74] * *(_DWORD *)(a1 + 264)
                   + (unsigned __int64)(*(_DWORD *)(v2 + 424) * v15[75])));
  v16 = readl_relaxed((unsigned int *)(*(_QWORD *)v2
                                     + *(unsigned int *)(*(_QWORD *)(v2 + 440) + 192LL)
                                     + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 204LL))));
  writel_relaxed(
    v16 | (1LL << *(_DWORD *)(a1 + 264)),
    (unsigned int *)(*(_QWORD *)v2
                   + *(unsigned int *)(*(_QWORD *)(v2 + 440) + 192LL)
                   + (unsigned int)(*(_DWORD *)(v2 + 424) * *(_DWORD *)(*(_QWORD *)(v2 + 440) + 204LL))));
  __dsb(0xEu);
  v17 = *(unsigned int **)(v2 + 440);
  v18 = *(_DWORD *)(a1 + 264);
  v19 = v17[53] * v18;
  v20 = v17[54] * v18;
  v21 = *(_DWORD *)(v2 + 424) * v17[55];
  v22 = *(_QWORD *)v2 + v17[52];
  if ( a2 == 2 )
    v23 = 42;
  else
    v23 = 34;
  writel_relaxed(v23, (unsigned int *)(v22 + v19 + v20 + v21));
  *(_QWORD *)(a1 + 360) = 0x100000000LL;
  v24 = *(_QWORD *)(v2 + 536);
  if ( v24 )
  {
    if ( *(_BYTE *)(v2 + 532) )
      v25 = 256;
    else
      v25 = 0x8000;
    ipc_log_string(v24, "%s: bam_desc_fifo:%d\n", "bam_chan_init_hw", v25);
  }
  _ftrace_dbg(*(_QWORD *)(v2 + 8), "%s: bam_desc_fifo:%d\n");
}
