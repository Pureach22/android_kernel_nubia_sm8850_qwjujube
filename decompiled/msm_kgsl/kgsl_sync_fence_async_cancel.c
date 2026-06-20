__int64 __fastcall kgsl_sync_fence_async_cancel(__int64 result)
{
  if ( result )
    return dma_fence_remove_callback(*(_QWORD *)(result + 24), result);
  return result;
}
