__int64 __fastcall get_pool_size_bytes_0(__int64 a1)
{
  _DWORD ***drvdata; // x19
  __int64 v2; // x20
  int v3; // w0

  drvdata = (_DWORD ***)dma_heap_get_drvdata(a1);
  v2 = (int)dynamic_page_pool_total(**drvdata, 1);
  v3 = dynamic_page_pool_total((*drvdata)[1], 1);
  return (v2 + v3 + (int)dynamic_page_pool_total((*drvdata)[2], 1)) << 12;
}
