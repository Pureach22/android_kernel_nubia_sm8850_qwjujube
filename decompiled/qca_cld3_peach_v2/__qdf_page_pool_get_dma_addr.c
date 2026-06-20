__int64 __fastcall _qdf_page_pool_get_dma_addr(__int64 a1)
{
  return *(_QWORD *)((a1 & 0xFFFFFFFFFFFFFFFELL) + 32);
}
