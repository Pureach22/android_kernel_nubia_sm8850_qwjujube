__int64 __fastcall sc_heap_allocate(__int64 a1, __int64 a2, int a3)
{
  __int64 drvdata; // x0

  drvdata = dma_heap_get_drvdata(a1);
  return _carveout_heap_allocate((_QWORD *)(drvdata + 8), a2, a3, (__int64)sc_heap_free);
}
