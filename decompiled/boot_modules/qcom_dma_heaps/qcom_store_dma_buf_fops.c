__int64 __fastcall qcom_store_dma_buf_fops(__int64 result)
{
  if ( dma_buf_cached_fops == -22 )
    dma_buf_cached_fops = *(_QWORD *)(result + 16);
  return result;
}
