__int64 __fastcall hw_sync_ioctl_create_fence(__int64 a1, unsigned __int64 a2)
{
  unsigned int unused_fd_flags; // w19
  unsigned __int64 v4; // x25
  unsigned int *v5; // x30
  __int64 v6; // x4
  __int64 *v7; // x20
  unsigned int v8; // w5
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x23
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x2
  __int64 result; // x0
  unsigned __int64 v14; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  unsigned __int64 v27; // x22
  unsigned int *v28; // x0
  __int64 v29; // x0
  unsigned __int64 v30; // x8
  __int64 v31; // x20
  signed int v33; // w8
  bool v34; // cc
  char v35; // w10
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x9
  unsigned __int64 v39; // x10
  __int64 v40; // x0
  unsigned __int64 v41; // x8
  unsigned __int64 v43; // x9
  int v45; // w8
  __int64 v46; // [xsp+8h] [xbp-48h] BYREF
  __int64 v47; // [xsp+10h] [xbp-40h] BYREF
  __int64 v48; // [xsp+18h] [xbp-38h]
  __int64 v49; // [xsp+20h] [xbp-30h]
  __int64 v50; // [xsp+28h] [xbp-28h] BYREF
  __int64 *v51; // [xsp+30h] [xbp-20h]
  unsigned __int64 v52; // [xsp+38h] [xbp-18h]
  __int64 v53; // [xsp+40h] [xbp-10h]
  __int64 v54; // [xsp+48h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = -22;
    goto LABEL_51;
  }
  v6 = *(unsigned int *)(a1 + 8);
  v7 = (__int64 *)a1;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = nullptr;
  v8 = *(_DWORD *)(hw_fence_drv_data + 744);
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  if ( (unsigned int)v6 < v8 || (unsigned int)v6 >= v8 + 11 )
  {
    printk(&unk_29FBA, "_is_valid_client", 137, v5, v6);
    result = -22;
    goto LABEL_51;
  }
  v9 = *(_QWORD *)(a1 + 16);
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_2939C, "hw_sync_ioctl_create_fence", 244, v5, v6);
    result = -22;
    goto LABEL_51;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v11 > 0x7FFFFFFFE8LL )
  {
    v12 = 24;
LABEL_11:
    if ( v12 < 0x19 )
    {
      result = -14;
      goto LABEL_51;
    }
    _fortify_panic(15, 0, v12);
    goto LABEL_32;
  }
  _X21 = v5;
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  v4 = a2;
  v12 = _arch_copy_from_user(&v47, a2 & 0xFF7FFFFFFFFFFFFFLL, 24);
  v21 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v23 - 4096);
  _WriteStatusReg(TTBR1_EL1, v23);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v21);
  if ( v12 )
    goto LABEL_11;
  v27 = hw_dma_fence_init((unsigned int *)v7[2], *v7, v47);
  result = -22;
  if ( v27 && v27 <= 0xFFFFFFFFFFFFF000LL )
  {
    v28 = (unsigned int *)v7[2];
    v51 = &v46;
    v52 = v27;
    if ( (unsigned int)msm_hw_fence_create(v28, (__int64)&v50, v24, v25, v26) )
    {
      printk(&unk_28479, "hw_sync_ioctl_create_fence", 263, _X21, *((unsigned int *)v7 + 2));
      dma_fence_put_0(v27);
      result = -22;
      goto LABEL_51;
    }
    _ZF = (unsigned __int8)v48 == 1;
    *(_QWORD *)(v27 + 128) = v7[2];
    if ( _ZF )
      *v7 = dma_fence_context_alloc(1);
    unused_fd_flags = get_unused_fd_flags(0);
    if ( (unused_fd_flags & 0x80000000) != 0 )
    {
      printk(&unk_24266, "hw_sync_ioctl_create_fence", 277, _X21, *((unsigned int *)v7 + 2));
      dma_fence_put_0(v27);
      result = (int)unused_fd_flags;
      goto LABEL_51;
    }
    v29 = sync_file_create(v27);
    if ( !v29 )
    {
      printk(&unk_24707, "hw_sync_ioctl_create_fence", 284, _X21, unused_fd_flags);
      dma_fence_put_0(v27);
      v31 = -22;
      goto LABEL_50;
    }
    v7 = (__int64 *)v29;
    _X21 = (unsigned int *)(v27 + 56);
LABEL_32:
    __asm { PRFM            #0x11, [X21] }
    do
      v33 = __ldxr(_X21);
    while ( __stlxr(v33 - 1, _X21) );
    if ( v33 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X21);
    }
    else
    {
      v34 = v33 <= 0;
      v30 = v4;
      if ( !v34 )
      {
LABEL_36:
        v35 = *(_BYTE *)(StatusReg + 70);
        HIDWORD(v48) = unused_fd_flags;
        v49 = v46;
        if ( (v35 & 0x20) != 0 || (v36 = v30, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v36 = v30 & ((__int64)(v30 << 8) >> 8);
        if ( v36 <= 0x7FFFFFFFE8LL )
        {
          v37 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v39 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v39 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v39);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v37);
          v40 = _arch_copy_to_user(v30 & 0xFF7FFFFFFFFFFFFFLL, &v47, 24);
          v41 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v43 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v43 - 4096);
          _WriteStatusReg(TTBR1_EL1, v43);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v41);
          if ( !v40 )
          {
            fd_install(unused_fd_flags, *v7);
            result = 0;
            goto LABEL_51;
          }
        }
        __asm { PRFM            #0x11, [X21] }
        do
          v45 = __ldxr(_X21);
        while ( __stlxr(v45 - 1, _X21) );
        if ( v45 == 1 )
        {
          __dmb(9u);
          dma_fence_release(_X21);
        }
        else if ( v45 <= 0 )
        {
          refcount_warn_saturate(_X21, 3);
        }
        fput(*v7);
        v31 = -14;
LABEL_50:
        put_unused_fd(unused_fd_flags);
        result = v31;
        goto LABEL_51;
      }
      refcount_warn_saturate(_X21, 3);
    }
    v30 = v4;
    goto LABEL_36;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
