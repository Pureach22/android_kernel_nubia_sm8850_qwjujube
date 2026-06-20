__int64 __fastcall get_client_id(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x9
  unsigned __int64 v6; // x2
  __int64 result; // x0
  __int64 v8; // x20
  unsigned __int64 v9; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  unsigned int v19; // w5
  __int64 v20; // x0
  unsigned int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v5 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v5 = a2 & ((__int64)(a2 << 8) >> 8);
  v21 = 0;
  if ( v5 <= 0x7FFFFFFFFCLL )
  {
    v8 = v2;
    v9 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v9);
    v6 = _arch_copy_from_user(&v21, a2 & 0xFF7FFFFFFFFFFFFFLL, 4);
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    if ( !v6 )
    {
      if ( a1 )
      {
        result = v21;
        v19 = *(_DWORD *)(hw_fence_drv_data + 744);
        if ( v19 && (v21 < v19 || v21 >= v19 + 11) )
        {
          printk(&unk_29FBA, "_get_client_id", 159, v8, *(unsigned int *)(a1 + 8));
          result = 0;
        }
      }
      else
      {
        result = 4294967274LL;
      }
      goto LABEL_15;
    }
  }
  else
  {
    v6 = 4;
  }
  if ( v6 < 5 )
  {
    result = 4294967282LL;
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v20 = _fortify_panic(15, 0, v6);
  return dma_fence_put_0(v20);
}
