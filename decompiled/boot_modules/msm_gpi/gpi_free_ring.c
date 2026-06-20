__int64 __fastcall gpi_free_ring(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0

  result = dma_free_attrs(*(_QWORD *)(*(_QWORD *)(a2 + 792) + 392LL), a1[1], *a1, a1[3], 0);
  a1[7] = 0;
  a1[8] = 0;
  a1[5] = 0;
  a1[6] = 0;
  a1[3] = 0;
  a1[4] = 0;
  a1[1] = 0;
  a1[2] = 0;
  *a1 = 0;
  return result;
}
