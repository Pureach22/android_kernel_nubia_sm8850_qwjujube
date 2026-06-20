__int64 __fastcall _read_gcc_register(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v5; // x19
  __int64 result; // x0
  unsigned int v7; // w21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_837CA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(a1 + 2208);
  if ( (mutex_is_locked(a1 + 80) & 1) == 0 && *(_BYTE *)(v3 + 376) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E7D2, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
    }
    __break(0x800u);
  }
  if ( (*(_BYTE *)(a1 + 72) & 1) == 0 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      printk(&unk_90890, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), "warn");
    }
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 376LL) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E7D2, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      }
      __break(0x800u);
    }
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 24LL);
  result = readl_relaxed((unsigned int *)(v5 + a2));
  __dsb(0xDu);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
  {
    v7 = result;
    printk(&unk_88044, &unk_8425A, v5, a2);
    return v7;
  }
  return result;
}
