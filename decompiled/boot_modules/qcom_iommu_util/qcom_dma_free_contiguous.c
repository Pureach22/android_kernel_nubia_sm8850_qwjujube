__int64 __fastcall qcom_dma_free_contiguous(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w9
  __int64 v8; // x1

  if ( !a1 || (v5 = *(_QWORD *)(a1 + 704)) == 0 )
    v5 = qcom_dma_contiguous_default_area;
  result = cma_release(v5, a2, (unsigned __int64)(a3 + 4095) >> 12);
  if ( (result & 1) == 0 )
  {
    v7 = 64 - __clz((unsigned __int64)(a3 - 1) >> 12);
    if ( (unsigned __int64)(a3 - 1) >= 0x1000 )
      v8 = v7;
    else
      v8 = 0;
    return _free_pages(a2, v8);
  }
  return result;
}
