__int64 __fastcall msm_hw_fence_destroy(unsigned int *a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  void *v12; // x8
  __int64 v13; // x4
  unsigned int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x30
  void *v18; // x0
  __int64 v19; // x2
  unsigned int v20; // w19
  unsigned __int64 v27; // x10

  v8 = v5;
  result = hw_fence_check_valid_client(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( a2 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
        printk(&unk_2B058, "msm_hw_fence_destroy", 341, v10, v11);
      v12 = (void *)a2[1];
      if ( v12 != &dma_fence_array_ops )
      {
        v13 = a2[6];
        if ( (v13 & 0x80000000) != 0 )
        {
          if ( v12 == &hw_fence_dbg_ops_1 )
          {
            printk(&unk_282C8, "msm_hw_fence_destroy", 358, v8, a2[4]);
            return 4294967274LL;
          }
          else
          {
            v14 = hw_fence_destroy(hw_fence_drv_data, a1, (__int64)a2, a2[4], a2[5]);
            if ( v14 )
            {
              v20 = v14;
              printk(&unk_28944, "msm_hw_fence_destroy", 366, v8, v16);
              return v20;
            }
            else
            {
              _X8 = a2 + 6;
              __asm { PRFM            #0x11, [X8] }
              do
                v27 = __ldxr(_X8);
              while ( __stxr(v27 & 0xFFFFFFFF7FFFFFFFLL, _X8) );
              if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
                printk(&unk_2388F, "msm_hw_fence_destroy", 373, v15, v16);
              return 0;
            }
          }
        }
        else
        {
          printk(&unk_28282, "msm_hw_fence_destroy", 352, v8, v13);
          return 4294967274LL;
        }
      }
      v17 = v8;
      v18 = &unk_2466C;
      v19 = 346;
    }
    else
    {
      v17 = v8;
      v18 = &unk_28919;
      v19 = 336;
    }
    printk(v18, "msm_hw_fence_destroy", v19, v17, v11);
    return 4294967274LL;
  }
  return result;
}
