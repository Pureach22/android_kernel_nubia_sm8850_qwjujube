__int64 __fastcall msm_geni_serial_align_tx_buf(__int64 a1, void *src, size_t n)
{
  unsigned int v3; // w21
  unsigned __int64 v6; // x3
  const void *v7; // x2

  v3 = n;
  if ( (unsigned int)n > 0x1000 )
  {
    v3 = 4096;
    ipc_log_string(*(_QWORD *)(a1 + 960), "Warning: xmit size greater than max buffer size, using size %lu\n", 4096);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "Warning: xmit size greater than max buffer size, using size %lu\n");
  }
  if ( !*(_QWORD *)(a1 + 2016) )
  {
    v6 = *(_QWORD *)(a1 + 2024);
    v7 = *(const void **)(a1 + 2008);
    *(_QWORD *)(a1 + 2016) = v7;
    *(_QWORD *)(a1 + 2032) = v6;
    if ( (v6 & 0xF) != 0 )
    {
      v6 = (v6 + 15) & 0xFFFFFFFFFFFFFFF0LL;
      v7 = (const void *)(((unsigned __int64)v7 + 15) & 0xFFFFFFFFFFFFFFF0LL);
      *(_QWORD *)(a1 + 2024) = v6;
      *(_QWORD *)(a1 + 2008) = v7;
    }
    ipc_log_string(*(_QWORD *)(a1 + 960), "SERIAL aligned tx_buf addr:0x%p, dma addr:0x%p\n", v7, (const void *)v6);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "SERIAL aligned tx_buf addr:0x%p, dma addr:0x%p\n");
    if ( !*(_QWORD *)(a1 + 2016) )
      return 4294967284LL;
  }
  memcpy(*(void **)(a1 + 2008), src, v3);
  return 0;
}
