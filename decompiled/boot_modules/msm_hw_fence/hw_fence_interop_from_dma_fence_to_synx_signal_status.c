__int64 hw_fence_interop_from_dma_fence_to_synx_signal_status()
{
  __int64 v0; // x30
  __int64 v1; // x19
  unsigned int status; // w0
  unsigned int v3; // w8
  unsigned int v4; // w19
  __int64 v6; // x30

  v1 = v0;
  status = dma_fence_get_status();
  v3 = status + 6;
  if ( status + 6 < 8 && ((0xCDu >> v3) & 1) != 0 )
  {
    v4 = dword_2D530[v3];
  }
  else if ( status <= 0xFFFFFFBF )
  {
    if ( (status & 0x80000000) != 0 )
    {
      v4 = -status;
    }
    else
    {
      v6 = v1;
      v4 = status;
      printk(&unk_26944, "hw_fence_interop_from_dma_fence_to_synx_signal_status", 155, v6, status);
      status = v4;
    }
  }
  else
  {
    v4 = 5;
  }
  if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
    printk(&unk_223D7, "hw_fence_interop_from_dma_fence_to_synx_signal_status", 160, status, v4);
  return v4;
}
