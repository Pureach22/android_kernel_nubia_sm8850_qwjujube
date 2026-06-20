unsigned __int64 __fastcall cam_align_dma_buf_size(__int64 a1)
{
  return (a1 + 0x1FFFFF) & 0xFFFFFFFFFFE00000LL;
}
