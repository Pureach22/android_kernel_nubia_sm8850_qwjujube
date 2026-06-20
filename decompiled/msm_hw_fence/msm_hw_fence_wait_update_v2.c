__int64 __fastcall msm_hw_fence_wait_update_v2(unsigned __int64 a1, _QWORD *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v8; // x19
  int v9; // w24
  __int64 result; // x0
  __int64 v13; // x4
  _BOOL4 client_data_id; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x27
  __int64 v18; // x2
  __int64 v19; // x4
  unsigned int v20; // w0
  unsigned int v21; // w0
  __int64 v22; // x30
  unsigned int v23; // w28
  void *v24; // x0
  __int64 v25; // x2
  __int64 v26; // x23
  __int64 v27; // x4
  __int64 v28; // x9
  __int64 v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v8 = v5;
  v9 = a5;
  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hw_fence_check_valid_fctl(hw_fence_drv_data, a1, a3, a4, a5);
  if ( (_DWORD)result )
    goto LABEL_26;
  if ( !a2 || !*a2 )
  {
    printk(&unk_28919, "msm_hw_fence_wait_update_v2", 425, v8, v13);
    result = 4294967274LL;
    goto LABEL_26;
  }
  client_data_id = hw_fence_get_client_data_id(*(_DWORD *)(a1 + 4));
  if ( a4 && client_data_id )
  {
    printk(&unk_2AA27, "msm_hw_fence_wait_update_v2", 433, v8, *(unsigned int *)(a1 + 4));
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    printk(&unk_2B058, "msm_hw_fence_wait_update_v2", 437, v15, v16);
    if ( v9 )
      goto LABEL_8;
LABEL_23:
    if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
      printk(&unk_2388F, "msm_hw_fence_wait_update_v2", 470, v15, v16);
    result = 0;
    goto LABEL_26;
  }
  if ( !v9 )
    goto LABEL_23;
LABEL_8:
  v17 = 0;
  while ( 1 )
  {
    v18 = a2[(int)v17];
    v29[0] = 0;
    if ( !a4 )
      break;
    v19 = *(_QWORD *)(a4 + 8LL * (int)v17);
    if ( v18 )
      goto LABEL_14;
LABEL_15:
    v20 = hw_fence_process_fence(hw_fence_drv_data, (unsigned int *)a1, (_QWORD *)v18, (unsigned __int64 *)v29, v19);
    if ( v20 )
    {
      v22 = v8;
      v23 = v20;
      v24 = &unk_2B071;
      v25 = 461;
      goto LABEL_28;
    }
LABEL_18:
    if ( a3 )
      *(_QWORD *)(a3 + 8LL * (int)v17) = v29[0];
    if ( v9 == (_DWORD)++v17 )
      goto LABEL_23;
  }
  v19 = 0;
  if ( !v18 )
    goto LABEL_15;
LABEL_14:
  if ( *(_UNKNOWN **)(v18 + 8) != &dma_fence_array_ops )
    goto LABEL_15;
  v21 = hw_fence_process_fence_array(hw_fence_drv_data, (unsigned int *)a1, v18, v29, v19);
  if ( !v21 )
    goto LABEL_18;
  v22 = v8;
  v23 = v21;
  v24 = &unk_246B9;
  v25 = 453;
LABEL_28:
  printk(v24, "msm_hw_fence_wait_update_v2", v25, v22, v16);
  if ( (int)v17 >= 1 )
  {
    v26 = 0;
    do
    {
      if ( (unsigned int)hw_fence_destroy_with_hash(hw_fence_drv_data, (unsigned int *)a1, *(_QWORD *)(a3 + 8 * v26)) )
      {
        v28 = a2[v26];
        if ( v28 )
          v27 = *(_QWORD *)(v28 + 32);
        else
          v27 = -1;
        printk(&unk_2AA88, "msm_hw_fence_wait_update_v2", 480, v8, v27);
      }
      --v17;
      ++v26;
    }
    while ( v17 );
  }
  result = v23;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
