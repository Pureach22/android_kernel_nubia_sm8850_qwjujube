__int64 __fastcall mhi_deinit_dev_ctxt(__int64 a1)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x21
  unsigned int v4; // w8
  unsigned int v5; // w21
  _BYTE *v6; // x22
  __int64 v7; // x1
  __int64 result; // x0

  v2 = *(_QWORD **)(a1 + 256);
  v1 = *(_QWORD **)(a1 + 264);
  dma_free_attrs(*(_QWORD *)(a1 + 8), v2[10], v2[3], *v2, 0);
  v2[4] = 0;
  v2[1] = 0;
  dma_free_attrs(*(_QWORD *)(a1 + 8), 44, v1[2], v1[5], 0);
  v4 = *(_DWORD *)(a1 + 212);
  if ( v4 )
  {
    v5 = 0;
    v6 = (_BYTE *)(*(_QWORD *)(a1 + 248) + 258LL);
    do
    {
      if ( (*v6 & 1) == 0 )
      {
        dma_free_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(v6 - 138), *(_QWORD *)(v6 - 194), *(_QWORD *)(v6 - 218), 0);
        *(_QWORD *)(v6 - 186) = 0;
        *(_QWORD *)(v6 - 210) = 0;
        v4 = *(_DWORD *)(a1 + 212);
      }
      ++v5;
      v6 += 264;
    }
    while ( v5 < v4 );
    v7 = 44LL * v4;
  }
  else
  {
    v7 = 0;
  }
  dma_free_attrs(*(_QWORD *)(a1 + 8), v7, *v1, v1[3], 0);
  dma_free_attrs(*(_QWORD *)(a1 + 8), 44LL * *(unsigned int *)(a1 + 208), v1[1], v1[4], 0);
  result = kfree(v1);
  *(_QWORD *)(a1 + 264) = 0;
  return result;
}
