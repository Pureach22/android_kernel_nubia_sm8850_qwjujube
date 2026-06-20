__int64 __fastcall get_pool_size_bytes(__int64 a1)
{
  __int64 drvdata; // x19
  __int64 v2; // x20
  int v3; // w0

  drvdata = dma_heap_get_drvdata(a1);
  v2 = (int)dynamic_page_pool_total(**(_QWORD **)(drvdata + 8), 1);
  v3 = dynamic_page_pool_total(*(_QWORD *)(*(_QWORD *)(drvdata + 8) + 8LL), 1);
  return (v2 + v3 + (int)dynamic_page_pool_total(*(_QWORD *)(*(_QWORD *)(drvdata + 8) + 16LL), 1)) << 12;
}
