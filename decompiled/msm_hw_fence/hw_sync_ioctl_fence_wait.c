__int64 __fastcall hw_sync_ioctl_fence_wait(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x4
  __int64 v4; // x19
  __int64 v5; // x20
  unsigned int v6; // w5
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x2
  __int64 result; // x0
  unsigned __int64 v12; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  unsigned int v21; // w22
  __int64 fence; // x0
  unsigned int *v23; // x23
  __int64 v24; // x21
  int v27; // w8
  int v28; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = -22;
    goto LABEL_32;
  }
  v3 = *(unsigned int *)(a1 + 8);
  v4 = v2;
  v5 = a1;
  v29 = 0;
  v30 = 0;
  v28 = 0;
  v6 = *(_DWORD *)(hw_fence_drv_data + 744);
  if ( (unsigned int)v3 < v6 || (unsigned int)v3 >= v6 + 11 )
  {
    printk(&unk_29FBA, "_is_valid_client", 137, v2, v3);
    result = -22;
    goto LABEL_32;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v9 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v9 <= 0x7FFFFFFFF0LL )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v10 = _arch_copy_from_user(&v29, a2 & 0xFF7FFFFFFFFFFFFFLL, 16);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v10 )
    {
      v21 = v29;
      if ( (v29 & 0x80000000) != 0 || (fence = sync_file_get_fence((unsigned int)v29)) == 0 )
      {
        printk(&unk_233E3, "hw_sync_ioctl_fence_wait", 503, v4, v21);
        result = -22;
        goto LABEL_32;
      }
      v23 = *(unsigned int **)(v5 + 16);
      v24 = fence;
      if ( !v23 )
      {
        printk(&unk_257C2, "hw_sync_ioctl_fence_wait", 509, v4, v21);
        dma_fence_put_0(v24);
        result = -22;
        goto LABEL_32;
      }
      LODWORD(v5) = hw_fence_debug_wait_val(hw_fence_drv_data, *(unsigned int **)(v5 + 16), fence, 0, 0, v30, &v28);
      if ( (_DWORD)v5 )
        printk(&unk_27C92, "hw_sync_ioctl_fence_wait", 519, v4, *v23);
      _X0 = (unsigned int *)(v24 + 56);
      goto LABEL_26;
    }
  }
  else
  {
    v10 = 16;
  }
  if ( v10 < 0x11 )
  {
    result = -14;
    goto LABEL_32;
  }
  _X0 = (unsigned int *)_fortify_panic(15, 0, v10);
LABEL_26:
  __asm { PRFM            #0x11, [X0] }
  do
    v27 = __ldxr(_X0);
  while ( __stlxr(v27 - 1, _X0) );
  if ( v27 == 1 )
  {
    __dmb(9u);
    dma_fence_release(_X0);
  }
  else if ( v27 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  result = (int)v5;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
