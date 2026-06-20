__int64 __fastcall kgsl_get_gpu_secure_va_inuse(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x9
  char v3; // w11
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x10
  unsigned __int64 v6; // x10
  unsigned __int64 v12; // x9
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x9
  __int64 result; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a2 + 16) == 8 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v3 = *(_BYTE *)(StatusReg + 70);
    v4 = *(_QWORD *)(a2 + 8);
    v18[0] = qword_3A8D8;
    if ( (v3 & 0x20) != 0 || (v5 = v4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v5 = v4 & ((__int64)(v4 << 8) >> 8);
    if ( v5 > 0x7FFFFFFFF8LL )
    {
      result = -14;
    }
    else
    {
      v6 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v12 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v12);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v6);
      v13 = _arch_copy_to_user(v4 & 0xFF7FFFFFFFFFFFFFLL, v18, 8);
      v14 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v16 - 4096);
      _WriteStatusReg(TTBR1_EL1, v16);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v14);
      if ( v13 )
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
