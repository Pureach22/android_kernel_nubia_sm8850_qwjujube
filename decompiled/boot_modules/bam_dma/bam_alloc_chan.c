__int64 __fastcall bam_alloc_chan(__int64 a1)
{
  __int64 v2; // x20
  __int64 v4; // x0
  _QWORD *v5; // x9
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x0

  if ( *(_QWORD *)(a1 + 344) )
    return 0;
  v2 = *(_QWORD *)(a1 + 256);
  if ( *(_BYTE *)(v2 + 532) == 1 )
  {
    v4 = *(_QWORD *)(v2 + 512);
    *(_QWORD *)(a1 + 344) = v4;
    *(_QWORD *)(a1 + 352) = **(_QWORD **)(v2 + 504);
  }
  else
  {
    v4 = dma_alloc_attrs(*(_QWORD *)(v2 + 8), 0x8000, a1 + 352, 3264, 4);
    *(_QWORD *)(a1 + 344) = v4;
  }
  if ( *(_BYTE *)(v2 + 532) == 1 )
  {
    _memset_io(v4, 0);
    v5 = *(_QWORD **)(v2 + 504);
    *(_QWORD *)(v2 + 512) += 256LL;
    *v5 += 256LL;
    v6 = *(_QWORD *)(v2 + 536);
    if ( v6 )
      ipc_log_string(
        v6,
        "dma_bam:%s: r_mem_virt_base:%p r_mem_start:%llx\n",
        "bam_alloc_chan",
        *(const void **)(v2 + 512),
        **(_QWORD **)(v2 + 504));
    _ftrace_dbg(*(_QWORD *)(v2 + 8), "dma_bam:%s: r_mem_virt_base:%p r_mem_start:%llx\n");
    v4 = *(_QWORD *)(a1 + 344);
  }
  if ( v4 )
  {
    v7 = *(_DWORD *)(v2 + 432);
    *(_DWORD *)(v2 + 432) = v7 + 1;
    if ( !v7 && *(_BYTE *)(v2 + 429) == 1 )
      bam_reset(v2);
    v8 = *(_QWORD *)(v2 + 536);
    if ( v8 )
      ipc_log_string(v8, "%s chan id:%d\n", "bam_alloc_chan", *(_DWORD *)(a1 + 264));
    _ftrace_dbg(*(_QWORD *)(v2 + 8), "%s chan id:%d\n");
    return 0;
  }
  else
  {
    dev_err(*(_QWORD *)(v2 + 8), "Failed to allocate desc fifo\n");
    return 4294967284LL;
  }
}
