__int64 __fastcall _enable_power_domain(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x22
  __int64 result; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned __int64 v10; // x8
  unsigned int v11; // w19
  unsigned __int64 v12; // x8
  unsigned int v13; // w19
  unsigned __int64 StatusReg; // x8

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD *)(v2 + 472);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 480);
  if ( v4 >= v5 )
  {
LABEL_4:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_912E9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  else
  {
    while ( strcmp(*(const char **)(v4 + 16), s2) )
    {
      v4 += 24LL;
      if ( v4 >= v5 )
        goto LABEL_4;
    }
    result = _pm_runtime_resume(*(_QWORD *)v4, 4);
    if ( (result & 0x80000000) != 0 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v12 = _ReadStatusReg(SP_EL0);
        v13 = result;
        printk(&unk_9622D, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
        return v13;
      }
    }
    else
    {
      if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
        printk(&unk_96265, &unk_8DA84, *(_QWORD *)(v4 + 16), v9);
      if ( *(_BYTE *)(v4 + 8) == 1 )
      {
        result = switch_core_gdsc_mode(a1, 0, v8, v9);
        if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v10 = _ReadStatusReg(SP_EL0);
          v11 = result;
          printk(&unk_87571, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
          return v11;
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
