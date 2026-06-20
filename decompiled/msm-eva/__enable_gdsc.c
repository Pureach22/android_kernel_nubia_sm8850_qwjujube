__int64 __fastcall _enable_gdsc(__int64 a1, char *s1)
{
  int v2; // w19
  int v3; // w20
  int v4; // w0
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x1
  __int64 v8; // x2
  void *v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned int v13; // w19

  v2 = a1;
  v3 = *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 464LL);
  v4 = strcmp(s1, "controller");
  if ( v3 )
  {
    if ( v4 )
    {
      result = _enable_power_domain(v2, "core_pd");
      if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v7 = *(unsigned int *)(StatusReg + 1800);
        v8 = *(unsigned int *)(StatusReg + 1804);
        v9 = &unk_84CAF;
LABEL_20:
        v13 = result;
        printk(v9, v7, v8, &unk_8E7CE);
        return v13;
      }
    }
    else
    {
      result = _enable_power_domain(v2, "controller_pd");
      if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        v7 = *(unsigned int *)(v11 + 1800);
        v8 = *(unsigned int *)(v11 + 1804);
        v9 = &unk_94BAE;
        goto LABEL_20;
      }
    }
  }
  else if ( v4 )
  {
    result = _enable_regulator(v2, "cvp-core");
    if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      v7 = *(unsigned int *)(v10 + 1800);
      v8 = *(unsigned int *)(v10 + 1804);
      v9 = &unk_880F6;
      goto LABEL_20;
    }
  }
  else
  {
    result = _enable_regulator(v2, "cvp");
    if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      v7 = *(unsigned int *)(v12 + 1800);
      v8 = *(unsigned int *)(v12 + 1804);
      v9 = &unk_94BEA;
      goto LABEL_20;
    }
  }
  return result;
}
