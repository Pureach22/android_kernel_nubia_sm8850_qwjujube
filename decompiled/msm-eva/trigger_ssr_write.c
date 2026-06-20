__int64 __fastcall trigger_ssr_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x20
  int v6; // w23
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v8; // x8
  size_t v9; // x2
  unsigned __int64 v10; // x1
  __int64 result; // x0
  unsigned __int64 v12; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x0
  __int64 v23; // [xsp+0h] [xbp-20h] BYREF
  _BYTE v24[16]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  v23 = 0;
  memset(v24, 0, 11);
  if ( !a2 )
  {
    result = -22;
LABEL_26:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( !a3 )
  {
    result = 0;
    goto LABEL_26;
  }
  if ( a3 >= 0xA )
    v5 = 10;
  else
    v5 = a3;
  v6 = a3;
  _check_object_size(v24, v5, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( 0x8000000000LL - v5 >= v8 )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v9 = _arch_copy_from_user(v24, a2 & 0xFF7FFFFFFFFFFFFFLL, v5);
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
    if ( !v9 )
    {
      if ( (unsigned int)kstrtoull(v24, 0, &v23) )
      {
        result = -22;
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_91AE1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
          result = -22;
        }
      }
      else
      {
        msm_cvp_trigger_ssr(v3, v23);
        result = v6;
      }
      goto LABEL_26;
    }
  }
  else
  {
    v9 = v5;
  }
  if ( v5 - v9 <= 0xB )
    v10 = 11 - (v5 - v9);
  else
    v10 = 0;
  if ( v10 >= v9 )
  {
    memset(&v24[v5 - v9], 0, v9);
    result = -14;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_85B9C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      result = -14;
    }
    goto LABEL_26;
  }
  v22 = _fortify_panic(15);
  return trigger_ssr_open(v22);
}
