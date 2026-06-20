__int64 __fastcall kgsl_get_gpu_secure_va_size(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v5; // x8
  unsigned __int64 v6; // x10
  unsigned __int64 v7; // x10
  unsigned __int64 v13; // x9
  __int64 v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  __int64 result; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 16);
  v3 = 4294963200LL;
  if ( (*(_QWORD *)(*(_QWORD *)a1 + 104LL) & 1LL) == 0 )
    v3 = 0x10000000;
  v19[0] = v3;
  if ( v2 == 8 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(_QWORD *)(a2 + 8);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = *(_QWORD *)(a2 + 8), (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v6 = v5 & (v5 << 8 >> 8);
    if ( v6 > 0x7FFFFFFFF8LL )
    {
      result = -14;
    }
    else
    {
      v7 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v13 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v13);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v7);
      v14 = _arch_copy_to_user(v5 & 0xFF7FFFFFFFFFFFFFLL, v19, 8);
      v15 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v17 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v17 - 4096);
      _WriteStatusReg(TTBR1_EL1, v17);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v15);
      if ( v14 )
        result = -14;
      else
        result = 0;
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
