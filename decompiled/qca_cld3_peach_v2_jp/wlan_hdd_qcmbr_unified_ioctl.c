__int64 __fastcall wlan_hdd_qcmbr_unified_ioctl(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9

  v2 = *(_QWORD *)(a1 + 24);
  result = _wlan_hdd_validate_context(v2, "wlan_hdd_qcmbr_ioctl");
  if ( !(_DWORD)result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v6 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v6 = a2 & ((__int64)(a2 << 8) >> 8);
    result = 16;
    if ( v6 <= 0x7FFFFFFFFCLL )
    {
      _X9 = a2 & 0xFF7FFFFFFFFFFFFFLL;
      v8 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v14 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v14);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v8);
      __asm { LDTR            W1, [X9] }
      v16 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v18 - 4096);
      _WriteStatusReg(TTBR1_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v16);
      return wlan_ioctl_ftm_testmode_cmd(*(_QWORD *)(v2 + 8), _X1, a2 + 4);
    }
  }
  return result;
}
