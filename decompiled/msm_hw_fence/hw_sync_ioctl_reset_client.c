__int64 __fastcall hw_sync_ioctl_reset_client(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x4
  unsigned int v4; // w5
  unsigned __int64 v6; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x2
  __int64 result; // x0
  __int64 v12; // x19
  unsigned __int64 v13; // x9
  unsigned __int64 v18; // x8
  __int64 v19; // x3
  __int64 v20; // x4
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  int v24; // w0
  __int64 v25; // x4
  int v26; // w20
  __int64 v27; // x0
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = -22;
    goto LABEL_19;
  }
  v3 = *(unsigned int *)(a1 + 8);
  v28[0] = 0;
  v4 = *(_DWORD *)(hw_fence_drv_data + 744);
  if ( (unsigned int)v3 < v4 || (unsigned int)v3 >= v4 + 11 )
  {
    printk(&unk_29FBA, "_is_valid_client", 137, v2, v3);
    result = -22;
    goto LABEL_19;
  }
  v6 = *(_QWORD *)(a1 + 16);
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_238C1, "hw_sync_ioctl_reset_client", 535, v2, v3);
    result = -22;
    goto LABEL_19;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v8 <= 0x7FFFFFFFF8LL )
  {
    v12 = v2;
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    v9 = _arch_copy_from_user(v28, a2 & 0xFF7FFFFFFFFFFFFFLL, 8);
    v21 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v23 - 4096);
    _WriteStatusReg(TTBR1_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v21);
    if ( !v9 )
    {
      v24 = msm_hw_fence_reset_client(*(unsigned int **)(a1 + 16), SBYTE4(v28[0]), 0, v19, v20);
      if ( v24 )
      {
        v26 = v24;
        printk(&unk_22A91, "hw_sync_ioctl_reset_client", 544, v12, v25);
        result = v26;
      }
      else
      {
        result = 0;
      }
      goto LABEL_19;
    }
  }
  else
  {
    v9 = 8;
  }
  if ( v9 < 9 )
  {
    result = -14;
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v27 = _fortify_panic(15, 0, v9);
  return get_client_id(v27);
}
