__int64 __fastcall ipa_adpl_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v5; // x8
  __int64 v6; // x0
  __int16 v7; // w9
  unsigned __int64 StatusReg; // x8
  char v9; // w10
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  __int64 result; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int16 v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_WORD *)(ipa3_odl_ctx + 692) & 0x80) != 0 )
  {
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Calling adpl ioctl\n", "ipa_adpl_ioctl", 647);
        v5 = ipa3_ctx;
      }
      a1 = *(_QWORD *)(v5 + 34160);
      if ( a1 )
        a1 = ipc_log_string(a1, "ipa %s:%d Calling adpl ioctl\n", "ipa_adpl_ioctl", 647);
    }
    if ( a2 == -1073557698 )
    {
      v7 = *(_WORD *)(ipa3_odl_ctx + 536);
      StatusReg = _ReadStatusReg(SP_EL0);
      v9 = *(_BYTE *)(StatusReg + 70);
      v25 = v7 << 10;
      if ( (v9 & 0x20) != 0 || (v10 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v10 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v10 > 0x7FFFFFFFFELL )
        goto LABEL_13;
      v11 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v17 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v17);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v11);
      result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v25, 2);
      v19 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v21 - 4096);
      _WriteStatusReg(TTBR1_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v19);
      if ( result )
LABEL_13:
        result = -14;
      else
        *(_WORD *)(ipa3_odl_ctx + 692) |= 8u;
    }
    else
    {
      print_ipa_odl_state_bit_mask(a1);
      result = -515;
    }
  }
  else
  {
    v22 = printk(&unk_3D5CF0, "ipa_adpl_ioctl");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d ODL config in progress not allowed ioctl\n", "ipa_adpl_ioctl", 642);
        v23 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v23 + 34160);
      if ( v22 )
        v22 = ipc_log_string(v22, "ipa %s:%d ODL config in progress not allowed ioctl\n", "ipa_adpl_ioctl", 642);
    }
    print_ipa_odl_state_bit_mask(v22);
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
