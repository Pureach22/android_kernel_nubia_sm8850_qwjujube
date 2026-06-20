__int64 __fastcall hw_fence_interop_share_handle_status(
        unsigned __int64 a1,
        __int64 a2,
        unsigned int *a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x19
  unsigned int v9; // w22
  __int64 result; // x0
  __int64 v11; // x4
  __int64 v12; // x0
  _QWORD *v13; // x23
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int64 v15; // x0
  unsigned __int64 v16; // x0
  __int64 v17; // x4
  unsigned int v18; // w8
  unsigned int flags_error; // w0
  unsigned int v20; // w23
  __int64 v21; // x30
  unsigned int v22; // w21
  unsigned int updated; // w0
  unsigned int v24; // w20
  __int64 v25; // x30
  void *v26; // x0
  unsigned __int64 v27; // x4
  __int64 v28; // x2
  unsigned int v29; // [xsp+0h] [xbp-20h] BYREF
  char v30[4]; // [xsp+4h] [xbp-1Ch] BYREF
  unsigned __int64 v31; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v7 = v5;
  v9 = a2;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32[0] = 0;
  v30[0] = 0;
  v29 = 0;
  result = hw_fence_check_hw_fence_driver(hw_fence_drv_data, a2, (__int64)a3, a4, a5);
  if ( (_DWORD)result )
    goto LABEL_2;
  v12 = hw_fence_drv_data;
  if ( (*(_BYTE *)(hw_fence_drv_data + 736) & 1) == 0 )
  {
    printk(&unk_280DF, "hw_fence_interop_share_handle_status", 298, v7, v11);
    result = 4294967285LL;
    goto LABEL_2;
  }
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL )
  {
    v21 = v7;
    goto LABEL_40;
  }
  if ( !*(_QWORD *)a1
    || *(_QWORD *)a1 > 0xFFFFFFFFFFFFF000LL
    || (*(_DWORD *)(a1 + 8) & 0xC) != 8
    || (v13 = *(_QWORD **)(a1 + 16)) == nullptr
    || (unsigned __int64)v13 > 0xFFFFFFFFFFFFF000LL )
  {
    v21 = v7;
LABEL_40:
    printk(&unk_29514, "hw_fence_interop_share_handle_status", 308, v21, a1);
    result = 4294967274LL;
    goto LABEL_2;
  }
  if ( (v13[6] & 0x80000000) == 0 && (v13[6] & 1) == 0 )
  {
    v14 = *(__int64 (__fastcall **)(_QWORD))(v13[1] + 32LL);
    if ( !v14 )
      goto LABEL_43;
    v15 = *(_QWORD *)(a1 + 16);
    if ( *((_DWORD *)v14 - 1) != 1879296680 )
      __break(0x8228u);
    if ( (v14(v15) & 1) == 0 )
    {
LABEL_43:
      printk(&unk_23DCA, "hw_fence_interop_share_handle_status", 315, v7, v13[4]);
      result = 4294967274LL;
      goto LABEL_2;
    }
    dma_fence_signal(v13);
    v12 = hw_fence_drv_data;
  }
  v16 = hw_fence_find_with_dma_fence(v12, nullptr, v13, &v31, v30, 0);
  if ( v30[0] == 1 )
  {
    v18 = hw_fence_interop_from_dma_fence_to_synx_signal_status();
    result = 0;
    *a3 = v18;
    goto LABEL_2;
  }
  if ( !v16 )
  {
    printk(&unk_283D6, "hw_fence_interop_share_handle_status", 328, v7, v13[4]);
    result = 4294967274LL;
    goto LABEL_2;
  }
  flags_error = hw_fence_get_flags_error(hw_fence_drv_data, v31, v32, &v29, v17);
  if ( flags_error )
  {
    v25 = v7;
    v22 = flags_error;
    v26 = &unk_24D4A;
    v27 = v31;
    v28 = 334;
  }
  else
  {
    if ( (v32[0] & 1) != 0 )
    {
      if ( v29 )
      {
        if ( v29 == 1 )
          v20 = 6;
        else
          v20 = v29;
      }
      else
      {
        v20 = 2;
      }
    }
    else
    {
      v20 = 1;
    }
    if ( (~msm_hw_fence_debug_level & 0x10002) == 0 )
      printk(&unk_252B9, "hw_fence_interop_to_synx_signal_status", 93, LODWORD(v32[0]), v29);
    *a3 = v20;
    if ( v20 > 1 )
    {
      v22 = 0;
      goto LABEL_37;
    }
    updated = hw_fence_update_hsynx(hw_fence_drv_data, v31, v9, 1);
    if ( !updated )
    {
      v22 = 0;
      **(_DWORD **)a1 = v31;
      goto LABEL_37;
    }
    v25 = v7;
    v22 = updated;
    v26 = &unk_252F0;
    v27 = v31;
    v28 = 345;
  }
  printk(v26, "hw_fence_interop_share_handle_status", v28, v25, v27);
LABEL_37:
  v24 = hw_fence_destroy_with_hash(hw_fence_drv_data, nullptr, v31);
  result = v22;
  if ( v24 )
  {
    printk(&unk_26EE8, "hw_fence_interop_share_handle_status", 354, v7, v31);
    result = v24;
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
