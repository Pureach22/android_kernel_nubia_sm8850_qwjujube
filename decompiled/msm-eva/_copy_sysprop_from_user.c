__int64 __fastcall copy_sysprop_from_user(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x9
  unsigned __int64 v4; // x10
  unsigned __int64 v6; // x10
  unsigned __int64 v12; // x11
  unsigned __int64 v14; // x9
  unsigned __int64 v16; // x10
  __int64 result; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a2 + 16;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a2 + 16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = v3 & (v3 << 8 >> 8);
  if ( v4 > 0x7FFFFFFFFCLL )
  {
    *(_DWORD *)(a1 + 16) = 0;
    return 4294967282LL;
  }
  _X9 = v3 & 0xFF7FFFFFFFFFFFFFLL;
  v6 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v12 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v12 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v12);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v6);
  __asm { LDTR            W4, [X9] }
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v16 - 4096);
  _WriteStatusReg(TTBR1_EL1, v16);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  *(_DWORD *)(a1 + 16) = _X4;
  if ( (unsigned int)(_X4 - 65) > 0xFFFFFFBF )
    return copy_pkt_from_user(a1, a2, 1u, 2 * (int)_X4);
  result = 4294967282LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8B82E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967282LL;
  }
  return result;
}
