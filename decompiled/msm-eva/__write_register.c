__int64 __fastcall _write_register(__int64 result, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 v4; // x22
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x8

  if ( result )
  {
    v3 = result;
    v4 = *(_QWORD *)(result + 2208);
    result = mutex_is_locked(result + 80);
    if ( (result & 1) == 0 && *(_BYTE *)(v4 + 376) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        result = printk(
                   &unk_8E7D2,
                   *(unsigned int *)(StatusReg + 1800),
                   *(unsigned int *)(StatusReg + 1804),
                   &unk_8E7CE);
      }
      __break(0x800u);
    }
    v7 = *(_QWORD *)(*(_QWORD *)(v3 + 2168) + 16LL);
    if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
    {
      result = printk(&unk_841CC, &unk_8425A, v7, a2);
      if ( (*(_BYTE *)(v3 + 72) & 1) != 0 )
        goto LABEL_11;
    }
    else if ( (*(_BYTE *)(v3 + 72) & 1) != 0 )
    {
LABEL_11:
      result = writel_relaxed(a3, v7 + a2);
      __dsb(0xEu);
      return result;
    }
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v9 = _ReadStatusReg(SP_EL0);
      result = printk(&unk_82312, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), "warn");
    }
    if ( *(_BYTE *)(*(_QWORD *)(v3 + 2208) + 376LL) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        result = printk(&unk_8E7D2, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      }
      __break(0x800u);
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    return printk(&unk_837CA, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
  }
  return result;
}
