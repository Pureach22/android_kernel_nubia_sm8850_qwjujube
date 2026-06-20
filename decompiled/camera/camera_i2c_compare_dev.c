__int64 camera_i2c_compare_dev()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))dma_buf_unmap_attachment_unlocked;
  if ( *(_DWORD *)(dma_buf_unmap_attachment_unlocked - 4LL) != 810692157 )
    __break(0x8228u);
  return v0();
}
