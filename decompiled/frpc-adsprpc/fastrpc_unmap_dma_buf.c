__int64 __fastcall fastrpc_unmap_dma_buf(__int64 a1, __int64 a2, unsigned int a3)
{
  return dma_unmap_sg_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)a2, *(unsigned int *)(a2 + 12), a3, 0);
}
