__int64 __fastcall ipa_odl_ctl_fops_read(__int64 a1, unsigned __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w10
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x8
  char v12; // w11
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  unsigned __int64 v20; // x8
  __int64 v21; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(ipa3_odl_ctx + 692);
  *(_BYTE *)(ipa3_odl_ctx + 696) = 0;
  if ( (v2 & 0x104) == 0 )
  {
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Failed to send data odl pipe already disconnected\n", "ipa_odl_ctl_fops_read", 98);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d Failed to send data odl pipe already disconnected\n", "ipa_odl_ctl_fops_read", 98);
    }
    goto LABEL_25;
  }
  if ( (v2 & 0x110) == 0 )
  {
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Failed to send data odl already running\n", "ipa_odl_ctl_fops_read", 108);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d Failed to send data odl already running\n", "ipa_odl_ctl_fops_read", 108);
    }
    goto LABEL_25;
  }
  v3 = (v2 >> 4) & 1;
  if ( (unsigned __int8)ipa_odl_ctl_fops_read_old_state == v3 )
  {
    result = 0;
    goto LABEL_26;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_BYTE *)(StatusReg + 70);
  ipa_odl_ctl_fops_read_old_state = v3;
  v28[0] = v3;
  if ( (v12 & 0x20) != 0 || (v13 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v13 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( v13 >> 39 )
    goto LABEL_20;
  v14 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v20 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v20);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v14);
  v21 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v28, 1);
  v22 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v24 - 4096);
  _WriteStatusReg(TTBR1_EL1, v24);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v22);
  if ( v21 )
  {
LABEL_20:
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d Cpoying data to user failed\n", "ipa_odl_ctl_fops_read", 123);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d Cpoying data to user failed\n", "ipa_odl_ctl_fops_read", 123);
    }
LABEL_25:
    result = -14;
    goto LABEL_26;
  }
  if ( v28[0] == 1 )
    *(_WORD *)(ipa3_odl_ctx + 692) |= 0x20u;
  result = 1;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
