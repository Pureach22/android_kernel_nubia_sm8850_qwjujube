__int64 __fastcall msm_hw_fence_create(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x4
  __int64 v15; // x0
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x30
  void *v19; // x0
  __int64 v20; // x2
  unsigned __int64 v21; // x0
  __int64 v22; // x19
  __int64 v23; // x30
  __int64 v24; // x21
  __int64 v25; // x4
  unsigned __int64 v26; // x19
  unsigned __int64 v33; // x9

  v8 = v5;
  result = hw_fence_check_valid_fctl(hw_fence_drv_data, (unsigned __int64)a1, a3, a4, a5);
  if ( !(_DWORD)result )
  {
    if ( !a2 || !*(_QWORD *)(a2 + 8) )
    {
      v18 = v8;
      v19 = &unk_2516F;
      v20 = 260;
      goto LABEL_21;
    }
    if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
    {
      v12 = *(_QWORD *)(a2 + 16);
      if ( v12 )
        goto LABEL_6;
    }
    else
    {
      printk(&unk_2B058, "msm_hw_fence_create", 264, v10, v11);
      v12 = *(_QWORD *)(a2 + 16);
      if ( v12 )
      {
LABEL_6:
        if ( *(_UNKNOWN **)(v12 + 8) == &dma_fence_array_ops )
        {
          v18 = v8;
          v19 = &unk_25DBE;
          v20 = 285;
        }
        else
        {
          if ( (*(_QWORD *)(v12 + 48) & 0x80000000) == 0 )
          {
            v13 = hw_fence_create(
                    hw_fence_drv_data,
                    (__int64)a1,
                    v12,
                    *(_QWORD *)(v12 + 32),
                    *(_QWORD *)(v12 + 40),
                    *(__int64 **)(a2 + 8));
            if ( (_DWORD)v13 )
            {
              v22 = v13;
              printk(&unk_2391F, "msm_hw_fence_create", 299, v8, v14);
              return v22;
            }
            v15 = hw_fence_add_callback(hw_fence_drv_data, (_QWORD *)v12, **(_QWORD **)(a2 + 8));
            if ( (_DWORD)v15 )
            {
              v23 = v8;
              v24 = v15;
              printk(&unk_20D66, "msm_hw_fence_create", 306, v23, *a1);
              hw_fence_destroy_refcount(hw_fence_drv_data, **(_QWORD **)(a2 + 8), 0x80000000);
              hw_fence_destroy_with_hash(hw_fence_drv_data, a1, **(_QWORD **)(a2 + 8));
              return v24;
            }
            _X8 = (unsigned __int64 *)(v12 + 48);
            __asm { PRFM            #0x11, [X8] }
            do
              v33 = __ldxr(_X8);
            while ( __stxr(v33 | 0x80000000, _X8) );
            if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
              printk(&unk_2388F, "msm_hw_fence_create", 318, v16, v17);
            return 0;
          }
          v18 = v8;
          v19 = &unk_28DF4;
          v20 = 291;
        }
LABEL_21:
        printk(v19, "msm_hw_fence_create", v20, v18, v11);
        return 4294967274LL;
      }
    }
    v21 = hw_fence_internal_dma_fence_create(hw_fence_drv_data, a1, *(__int64 **)(a2 + 8));
    if ( !v21 || v21 >= 0xFFFFFFFFFFFFF001LL )
    {
      v25 = *a1;
      v26 = v21;
      printk(&unk_26094, "msm_hw_fence_create", 275, v8, v25);
      return v26;
    }
    return 0;
  }
  return result;
}
