__int64 __fastcall hw_fence_rm_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  int v9; // w8
  __int64 v10; // x3
  __int64 v11; // x4
  int v12; // w8
  __int64 v13; // x4
  __int64 v14; // x22
  _WORD v16[2]; // [xsp+0h] [xbp-10h] BYREF
  __int16 v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v6 = v5;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v16[0] = 0;
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
  {
    v14 = a2;
    printk(&unk_22124, "hw_fence_rm_cb", 1147, a2, a5);
    a2 = v14;
  }
  if ( a2 == 1443889160 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      printk(&unk_2296A, "hw_fence_rm_cb", 1152, *(unsigned __int8 *)(a3 + 4), a5);
    v9 = *(unsigned __int8 *)(a3 + 4);
    if ( (v9 == 11 || v9 == 2)
      && !(unsigned int)ghd_rm_get_vmid(*(unsigned int *)(a1 - 4), &v17)
      && !(unsigned int)ghd_rm_get_vmid(1, v16)
      && v17 == *(_WORD *)a3 )
    {
      v12 = *(unsigned __int8 *)(a3 + 4);
      if ( v12 == 11 )
      {
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
          printk(&unk_23CF6, "hw_fence_rm_cb", 1197, v10, v11);
      }
      else if ( v12 == 2 )
      {
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
          printk(&unk_26020, "hw_fence_rm_cb", 1178, 4294967274LL, v11);
        if ( (unsigned int)hw_fence_gunyah_share_mem() )
          printk(&unk_2385A, "hw_fence_rm_cb", 1180, v6, v13);
        else
          *(_BYTE *)(a1 + 304) = 1;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
