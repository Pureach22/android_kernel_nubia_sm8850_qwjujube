__int64 __fastcall _dma_buf_unmap_attachment_wrap(__int64 a1, __int64 a2)
{
  return dma_buf_unmap_attachment_unlocked(a1, a2, 0);
}
