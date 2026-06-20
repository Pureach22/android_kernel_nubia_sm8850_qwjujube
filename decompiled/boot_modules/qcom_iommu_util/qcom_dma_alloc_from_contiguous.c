__int64 __fastcall qcom_dma_alloc_from_contiguous(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 v4; // x0
  __int64 v5; // x3

  if ( !a1 || (v4 = *(_QWORD *)(a1 + 704)) == 0 )
    v4 = qcom_dma_contiguous_default_area;
  v5 = a4 & 1;
  if ( (unsigned int)a3 >= 8 )
    a3 = 8;
  else
    a3 = (unsigned int)a3;
  return cma_alloc(v4, a2, a3, v5);
}
