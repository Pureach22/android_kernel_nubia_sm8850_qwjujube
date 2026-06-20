__int64 __fastcall carveout_heap_allocate(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 drvdata; // x0

  drvdata = dma_heap_get_drvdata(a1);
  return _carveout_heap_allocate(drvdata, a2, a3, carveout_heap_free);
}
