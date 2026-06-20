__int64 __fastcall mhi_unmap_single_use_bb(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 48) == 2 )
    memcpy(*(void **)a2, *(const void **)(a2 + 8), *(_QWORD *)(a2 + 40));
  return dma_free_attrs(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 40), *(_QWORD *)(a2 + 8), *(_QWORD *)(a2 + 32), 0);
}
