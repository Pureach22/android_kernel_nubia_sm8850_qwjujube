__int64 __fastcall synx_handle_get_fence(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  unsigned __int64 fence; // x19
  unsigned int unused_fd_flags; // w20
  _QWORD *v8; // x0
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v12; // x8
  signed int v18; // w8
  bool v19; // cc
  __int64 v20; // x19
  unsigned __int64 v21; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v23; // x9
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  _QWORD v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) != 8 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  v3 = *(_QWORD *)(a1 + 16);
  v30[0] = 0;
  if ( inline_copy_from_user((int)v30, v3, 8u) )
  {
    result = 4294967282LL;
    goto LABEL_5;
  }
  fence = synx_get_fence(a2, LODWORD(v30[0]));
  result = 4294967274LL;
  if ( fence && fence <= 0xFFFFFFFFFFFFF000LL )
  {
    unused_fd_flags = get_unused_fd_flags(0x80000);
    if ( (unused_fd_flags & 0x80000000) == 0 )
    {
      v8 = (_QWORD *)sync_file_create(fence);
      if ( v8 && (unsigned __int64)v8 < 0xFFFFFFFFFFFFF001LL )
      {
        fd_install(unused_fd_flags, *v8);
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AA0B, &unk_29207, "synx_create_sync_fd", 180, v9, v10);
        put_unused_fd(unused_fd_flags);
        unused_fd_flags = -22;
      }
    }
    _X0 = (unsigned int *)(fence + 56);
    HIDWORD(v30[0]) = unused_fd_flags;
    __asm { PRFM            #0x11, [X0] }
    do
      v18 = __ldxr(_X0);
    while ( __stlxr(v18 - 1, _X0) );
    if ( v18 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else
    {
      v19 = v18 <= 0;
      v12 = a1;
      if ( !v19 )
      {
LABEL_21:
        v20 = *(unsigned int *)(v12 + 4);
        if ( (unsigned int)v20 >= 9 )
        {
          _copy_overflow(8, *(unsigned int *)(v12 + 4));
          result = 4294967282LL;
        }
        else
        {
          v21 = *(_QWORD *)(v12 + 16);
          _check_object_size(v30, *(unsigned int *)(v12 + 4), 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = v21, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v23 = v21 & ((__int64)(v21 << 8) >> 8);
          if ( 0x8000000000LL - v20 >= v23 )
          {
            v24 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v26 = *(_QWORD *)(StatusReg + 8);
            _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
            _WriteStatusReg(TTBR0_EL1, v26);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v24);
            v20 = _arch_copy_to_user(v21 & 0xFF7FFFFFFFFFFFFFLL, v30, v20);
            v27 = _ReadStatusReg(DAIF);
            __asm { MSR             DAIFSet, #3 }
            v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
            _WriteStatusReg(TTBR0_EL1, v29 - 4096);
            _WriteStatusReg(TTBR1_EL1, v29);
            __isb(0xFu);
            _WriteStatusReg(DAIF, v27);
          }
          if ( v20 )
            result = 4294967282LL;
          else
            result = 0;
        }
        goto LABEL_5;
      }
      refcount_warn_saturate(_X0, 3);
    }
    v12 = a1;
    goto LABEL_21;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
