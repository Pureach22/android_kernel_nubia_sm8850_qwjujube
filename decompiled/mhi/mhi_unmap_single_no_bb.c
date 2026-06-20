__int64 __fastcall mhi_unmap_single_no_bb(__int64 a1, __int64 a2)
{
  return dma_unmap_page_attrs(
           *(_QWORD *)(a1 + 8),
           *(_QWORD *)(a2 + 32),
           *(_QWORD *)(a2 + 40),
           *(unsigned int *)(a2 + 48),
           0);
}
