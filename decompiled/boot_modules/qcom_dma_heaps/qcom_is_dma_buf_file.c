bool __fastcall qcom_is_dma_buf_file(__int64 a1)
{
  return *(_QWORD *)(a1 + 16) == dma_buf_cached_fops;
}
