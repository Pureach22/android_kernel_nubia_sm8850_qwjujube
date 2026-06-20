__int64 __fastcall qcom_dma_release_from_contiguous(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x0

  if ( !a1 || (v3 = *(_QWORD *)(a1 + 704)) == 0 )
    v3 = qcom_dma_contiguous_default_area;
  return cma_release(v3, a2, a3) & 1;
}
