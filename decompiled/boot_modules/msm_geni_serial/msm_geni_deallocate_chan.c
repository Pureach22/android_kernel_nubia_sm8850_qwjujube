__int64 __fastcall msm_geni_deallocate_chan(__int64 a1)
{
  __int64 result; // x0

  dma_release_channel(*(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL));
  result = dma_release_channel(**(_QWORD **)(a1 + 1144));
  *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL) = 0;
  **(_QWORD **)(a1 + 1144) = 0;
  return result;
}
