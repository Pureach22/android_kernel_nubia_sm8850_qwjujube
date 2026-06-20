__int64 __fastcall cam_subdev_compat_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v6; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x0
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  _QWORD v25[4]; // [xsp+0h] [xbp-20h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v25[3] = *(_QWORD *)(StatusReg + 1808);
  LOBYTE(StatusReg) = *(_BYTE *)(v4 + 70);
  memset(v25, 0, 24);
  if ( (StatusReg & 0x20) != 0 || (v6 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
    v6 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v6 >= 0x7FFFFFFFE9LL )
    JUMPOUT(0x12FA18);
  v9 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v15 = *(_QWORD *)(v4 + 8);
  _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v15);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v9);
  v16 = _arch_copy_from_user(v25, a3 & 0xFF7FFFFFFFFFFFFFLL, 24);
  v17 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v19 - 4096);
  _WriteStatusReg(TTBR1_EL1, v19);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v17);
  if ( v16 )
    JUMPOUT(0x12FA1C);
  if ( (unsigned int)cam_subdev_ioctl(a1, a2, (int *)v25) )
    JUMPOUT(0x12FA68);
  if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v20 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
    v20 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v20 >= 0x7FFFFFFFE9LL )
    JUMPOUT(0x12F9F4);
  v21 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v23 = *(_QWORD *)(v4 + 8);
  _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v23);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v21);
  return sub_12F9B8();
}
