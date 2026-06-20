__int64 __fastcall synx_hwfence_initialize(unsigned __int64 a1)
{
  __int64 v1; // x30
  __int64 v3; // x21
  unsigned int hw_fence_client_id; // w0
  __int64 v5; // x4
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x22
  unsigned __int64 v12; // x0
  __int64 v13; // x3
  int v14; // w9
  unsigned int v16; // w20

  if ( hw_fence_driver_enable != 1 )
    return -22;
  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = v1;
    hw_fence_client_id = get_hw_fence_client_id(*(unsigned int *)(a1 + 16));
    v5 = *(unsigned int *)(a1 + 16);
    if ( (unsigned int)(v5 - 1024) > 0xBFF || (v6 = hw_fence_client_id, hw_fence_client_id == 1665) )
    {
      printk(&unk_28E4E, "synx_hwfence_initialize", 140, v3, v5);
      return -22;
    }
    else
    {
      v7 = _kmalloc_cache_noprof(dma_fence_init, 3520, 24);
      if ( v7 )
      {
        v11 = v7;
        v12 = msm_hw_fence_register(v6, *(_QWORD **)(a1 + 8), v8, v9, v10);
        if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
        {
          v13 = *(unsigned int *)(a1 + 16);
          v14 = msm_hw_fence_debug_level;
          *(_QWORD *)(v11 + 8) = v12;
          *(_DWORD *)v11 = v13;
          if ( (~v14 & 0x10008) == 0 )
            printk(&unk_293E9, "synx_hwfence_initialize", 165, v13, v6);
          return v11;
        }
        else
        {
          v16 = v12;
          kfree(v11);
          printk(&unk_2B0D7, "synx_hwfence_initialize", 160, v3, *(unsigned int *)(a1 + 16));
          return (int)hw_fence_interop_to_synx_status(v16);
        }
      }
      else
      {
        return -12;
      }
    }
  }
  else
  {
    printk(&unk_28A12, "synx_hwfence_initialize", 134, v1, a1);
    return -22;
  }
}
