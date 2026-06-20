__int64 hw_fence_interop_add_cb()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_2B798;
  if ( !off_2B798 )
    return dma_fence_add_callback();
  if ( *((_DWORD *)off_2B798 - 1) != 103874292 )
    __break(0x8228u);
  return v0();
}
