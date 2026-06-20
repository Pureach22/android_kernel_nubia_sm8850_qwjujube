__int64 __fastcall mem_buf_retrieve_mem_type_data_user(int a1, unsigned __int64 a2)
{
  unsigned __int64 StatusReg; // x19
  char v3; // w8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x2
  __int64 v13; // x3
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x0
  int v18; // w0
  __int64 result; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 == 2 )
  {
    result = 0;
    goto LABEL_18;
  }
  if ( a1 != 1 )
    goto LABEL_17;
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_BYTE *)(StatusReg + 70);
  v20[0] = 0;
  if ( (v3 & 0x20) != 0 || (v4 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v4 > 0x7FFFFFFFF8LL )
  {
    v12 = 8;
LABEL_14:
    if ( v12 >= 9 )
    {
      _fortify_panic(15, 0);
LABEL_16:
      kfree(StatusReg);
    }
LABEL_17:
    result = -22;
    goto LABEL_18;
  }
  v5 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v11 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v11 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v11);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v5);
  v12 = _arch_copy_from_user(v20, a2 & 0xFF7FFFFFFFFFFFFFLL, 8);
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v16 - 4096);
  _WriteStatusReg(TTBR1_EL1, v16);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  if ( v12 )
    goto LABEL_14;
  v17 = _kmalloc_cache_noprof(kstrdup, 3520, 128, v13);
  if ( !v17 )
  {
    result = -12;
    goto LABEL_18;
  }
  StatusReg = v17;
  v18 = strncpy_from_user(v17, v20[0], 128);
  if ( v18 < 0 || v18 == 128 )
    goto LABEL_16;
  result = StatusReg;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
