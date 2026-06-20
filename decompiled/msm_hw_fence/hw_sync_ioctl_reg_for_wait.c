__int64 __fastcall hw_sync_ioctl_reg_for_wait(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x4
  __int64 v4; // x19
  unsigned int v5; // w5
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x2
  __int64 result; // x0
  unsigned __int64 v12; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  __int64 v21; // x4
  int v24; // w8
  unsigned int v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = -22;
    goto LABEL_30;
  }
  v3 = *(unsigned int *)(a1 + 8);
  v4 = v2;
  v25 = 0;
  v5 = *(_DWORD *)(hw_fence_drv_data + 744);
  if ( (unsigned int)v3 < v5 || (unsigned int)v3 >= v5 + 11 )
  {
    printk(&unk_29FBA, "_is_valid_client", 137, v2, v3);
    result = -22;
    goto LABEL_30;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v8 <= 0x7FFFFFFFFCLL )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v17 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v17);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v9 = _arch_copy_from_user(&v25, a2 & 0xFF7FFFFFFFFFFFFFLL, 4);
    v18 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v20 - 4096);
    _WriteStatusReg(TTBR1_EL1, v20);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v18);
    if ( !v9 )
    {
      v21 = v25;
      if ( (v25 & 0x80000000) == 0 )
      {
        v26[0] = sync_file_get_fence(v25);
        if ( v26[0] )
        {
          LODWORD(v4) = msm_hw_fence_wait_update(*(unsigned int **)(a1 + 16), (__int64)v26, 1);
          if ( !v26[0] )
          {
LABEL_29:
            result = (int)v4;
            goto LABEL_30;
          }
          _X0 = (unsigned int *)(v26[0] + 56LL);
LABEL_24:
          __asm { PRFM            #0x11, [X0] }
          do
            v24 = __ldxr(_X0);
          while ( __stlxr(v24 - 1, _X0) );
          if ( v24 == 1 )
          {
            __dmb(9u);
            dma_fence_release(_X0);
          }
          else if ( v24 <= 0 )
          {
            refcount_warn_saturate(_X0, 3);
          }
          goto LABEL_29;
        }
        v21 = v25;
      }
      printk(&unk_233E3, "hw_sync_ioctl_reg_for_wait", 431, v4, v21);
      result = -22;
      goto LABEL_30;
    }
  }
  else
  {
    v9 = 4;
  }
  if ( v9 >= 5 )
  {
    _X0 = (unsigned int *)_fortify_panic(15, 0, v9);
    goto LABEL_24;
  }
  result = -14;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
