__int64 __fastcall dma_set_mask_and_coherent(__int64 a1)
{
  __int64 result; // x0

  result = dma_set_mask(a1, -1);
  if ( !(_DWORD)result )
  {
    dma_set_coherent_mask(a1, -1);
    return 0;
  }
  return result;
}
