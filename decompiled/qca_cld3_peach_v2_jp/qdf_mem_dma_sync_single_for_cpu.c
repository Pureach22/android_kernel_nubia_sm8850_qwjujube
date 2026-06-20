__int64 __fastcall qdf_mem_dma_sync_single_for_cpu(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 40);
  if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
    return _dma_sync_single_for_cpu();
  return result;
}
