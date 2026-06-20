__int64 __fastcall msm_vidc_memory_free_ext(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x0
  __int64 result; // x0

  if ( a1 && *(_QWORD *)(a1 + 32) )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      buf_name(*(_DWORD *)(a1 + 16));
      printk(&unk_89347, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_free_ext");
    }
    buf_name(*(_DWORD *)(a1 + 16));
    if ( *(_QWORD *)(a1 + 56) )
    {
      dma_buf_vunmap_unlocked(*(_QWORD *)(a1 + 32), a1 + 40);
      v4 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(a1 + 56) = 0;
      dma_buf_end_cpu_access(v4, 0);
    }
    result = *(_QWORD *)(a1 + 32);
    if ( result )
    {
      dma_heap_buffer_free(result, v2, v3);
      *(_QWORD *)(a1 + 32) = 0;
      return 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_free_ext");
    return 4294967274LL;
  }
  return result;
}
