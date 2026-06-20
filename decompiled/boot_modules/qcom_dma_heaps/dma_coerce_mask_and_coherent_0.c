__int64 __fastcall dma_coerce_mask_and_coherent_0(__int64 a1)
{
  __int64 result; // x0

  *(_QWORD *)(a1 + 640) = a1 + 648;
  result = dma_set_mask();
  if ( !(_DWORD)result )
    return dma_set_coherent_mask(a1, -1);
  return result;
}
