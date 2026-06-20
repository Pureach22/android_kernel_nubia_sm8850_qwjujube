__int64 __fastcall ipahal_free_dma_mem(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    result = dma_free_attrs(
               *(_QWORD *)(ipahal_ctx + 32),
               *(unsigned int *)(result + 16),
               *(_QWORD *)result,
               *(_QWORD *)(result + 8),
               0);
    *(_DWORD *)(v1 + 16) = 0;
    *(_QWORD *)v1 = 0;
    *(_QWORD *)(v1 + 8) = 0;
  }
  return result;
}
