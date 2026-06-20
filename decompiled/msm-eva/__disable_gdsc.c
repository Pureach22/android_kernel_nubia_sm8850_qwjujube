__int64 __fastcall _disable_gdsc(__int64 a1, char *s1)
{
  int v3; // w20
  int v4; // w0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  void *v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned int v16; // w19
  unsigned __int64 v17; // x8
  unsigned int v18; // w19

  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 464LL);
  v4 = strcmp(s1, "controller");
  if ( !v3 )
  {
    if ( v4 )
    {
      result = _disable_regulator(a1, "cvp-core");
      if ( !(_DWORD)result || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = *(unsigned int *)(StatusReg + 1800);
      v11 = *(unsigned int *)(StatusReg + 1804);
      v12 = &unk_8CE76;
    }
    else
    {
      result = _disable_regulator(a1, "cvp");
      if ( !(_DWORD)result || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        return result;
      v15 = _ReadStatusReg(SP_EL0);
      v10 = *(unsigned int *)(v15 + 1800);
      v11 = *(unsigned int *)(v15 + 1804);
      v12 = &unk_8A5C0;
    }
LABEL_26:
    v16 = result;
    printk(v12, v10, v11, &unk_8E7CE);
    return v16;
  }
  if ( !v4 )
  {
    result = _disable_power_domain(a1, "controller_pd");
    if ( !(_DWORD)result || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v13 = _ReadStatusReg(SP_EL0);
    v10 = *(unsigned int *)(v13 + 1800);
    v11 = *(unsigned int *)(v13 + 1804);
    v12 = &unk_8C453;
    goto LABEL_26;
  }
  result = _disable_hw_power_collapse(a1, v5, v6, v7);
  if ( !(_DWORD)result )
  {
    result = _disable_power_domain(a1, "core_pd");
    if ( !(_DWORD)result || (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      return result;
    v14 = _ReadStatusReg(SP_EL0);
    v10 = *(unsigned int *)(v14 + 1800);
    v11 = *(unsigned int *)(v14 + 1804);
    v12 = &unk_92056;
    goto LABEL_26;
  }
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 2208) + 376LL) )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v17 = _ReadStatusReg(SP_EL0);
      v18 = result;
      printk(&unk_8E7D2, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
      result = v18;
    }
    __break(0x800u);
  }
  return result;
}
