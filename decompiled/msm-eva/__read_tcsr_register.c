__int64 __fastcall _read_tcsr_register(__int64 a1, unsigned int a2)
{
  __int64 v3; // x21
  __int64 v5; // x20
  __int64 result; // x0
  unsigned int v7; // w21
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x1
  __int64 v10; // x2
  void *v11; // x0
  const char *v12; // x3
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    v9 = *(unsigned int *)(StatusReg + 1800);
    v10 = *(unsigned int *)(StatusReg + 1804);
    v11 = &unk_837CA;
    v12 = (const char *)&unk_8E7CE;
    goto LABEL_29;
  }
  v3 = *(_QWORD *)(a1 + 2208);
  if ( (mutex_is_locked(a1 + 80) & 1) == 0 && *(_BYTE *)(v3 + 376) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E7D2, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
    }
    __break(0x800u);
  }
  if ( (*(_BYTE *)(a1 + 72) & 1) == 0 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v14 = _ReadStatusReg(SP_EL0);
      printk(&unk_90890, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), "warn");
    }
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 376LL) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v16 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E7D2, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      }
      __break(0x800u);
    }
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 32LL);
  if ( !v5 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    v13 = _ReadStatusReg(SP_EL0);
    v9 = *(unsigned int *)(v13 + 1800);
    v10 = *(unsigned int *)(v13 + 1804);
    v11 = &unk_91FF1;
    v12 = "warn";
LABEL_29:
    printk(v11, v9, v10, v12);
    return 4294967274LL;
  }
  result = readl_relaxed(v5 + a2);
  __dsb(0xDu);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
  {
    v7 = result;
    printk(&unk_856B1, &unk_8425A, v5, a2);
    return v7;
  }
  return result;
}
