__int64 __fastcall get_pkt_hdr_from_user(__int64 a1, _DWORD *a2)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x9
  unsigned __int64 v4; // x10
  unsigned __int64 v6; // x10
  unsigned __int64 v12; // x11
  unsigned __int64 v14; // x10
  unsigned __int64 v16; // x11
  __int64 v17; // x9
  unsigned __int64 v18; // x10
  unsigned __int64 v20; // x9
  unsigned __int64 v22; // x10
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x10
  __int64 result; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a1 + 16;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v4 = a1 + 16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v4 = v3 & (v3 << 8 >> 8);
  if ( v4 >= 0x7FFFFFFFFDLL )
  {
    *a2 = 0;
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
  __asm { LDTR            W9, [X9] }
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v16 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v16 - 4096);
  _WriteStatusReg(TTBR1_EL1, v16);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  *a2 = _X9;
  v17 = a1 + 20;
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = a1 + 20, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v18 = v17 & (v17 << 8 >> 8);
  if ( v18 >= 0x7FFFFFFFFDLL )
  {
    a2[1] = 0;
    return 4294967282LL;
  }
  _X8 = v17 & 0xFF7FFFFFFFFFFFFFLL;
  v20 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v22 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v22);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v20);
  __asm { LDTR            W8, [X8] }
  v24 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v26 - 4096);
  _WriteStatusReg(TTBR1_EL1, v26);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v24);
  a2[1] = _X8;
  if ( (get_pkt_index(a2) & 0x80000000) != 0 )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_9298C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    *a2 = get_msg_size((__int64)a2);
    return 0;
  }
  else if ( *a2 < 0x961u )
  {
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8E52A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
