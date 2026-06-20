__int64 __fastcall cma_heap_free(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x23
  _QWORD *drvdata; // x22

  v2 = a1 + 80;
  v3 = *(_QWORD *)(a1 + 72) >> 12;
  v4 = **(_QWORD **)(a1 + 80);
  drvdata = (_QWORD *)dma_heap_get_drvdata(*(_QWORD *)a1);
  sg_free_table(v2);
  cma_release(*drvdata, v4 & 0xFFFFFFFFFFFFFFFCLL, v3);
  return kfree(a1);
}
