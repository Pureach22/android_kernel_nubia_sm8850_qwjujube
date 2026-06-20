__int64 __fastcall hw_sync_ioctl_fence_signal(__int64 a1, unsigned __int64 a2)
{
  unsigned int v2; // w4
  unsigned int v3; // w5
  unsigned __int64 v5; // x23
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v13; // x8

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
    JUMPOUT(0x1CC50);
  v2 = *(_DWORD *)(a1 + 8);
  v3 = *(_DWORD *)(hw_fence_drv_data + 744);
  if ( v2 < v3 || v2 >= v3 + 11 )
    JUMPOUT(0x1CC84);
  v5 = *(_QWORD *)(a1 + 16);
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
    JUMPOUT(0x1CCAC);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v7 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v7 > 0x7FFFFFFFF0LL )
    JUMPOUT(0x1CB94);
  v8 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v13 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v13 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v13);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v8);
  return sub_1CBD4();
}
