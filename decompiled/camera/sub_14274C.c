__int64 sub_14274C()
{
  __int16 v0; // w12

  if ( (v0 & 0x100) != 0 )
    JUMPOUT(0x142030);
  return cam_sync_dma_fence_cb();
}
