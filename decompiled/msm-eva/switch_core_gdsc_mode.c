__int64 __fastcall switch_core_gdsc_mode(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x19
  unsigned __int64 v6; // x8
  __int64 result; // x0
  int v8; // w20
  unsigned __int64 StatusReg; // x8
  unsigned int v10; // w19
  const char *v11; // x2

  v4 = *(_QWORD *)(a1 + 2208);
  v5 = *(_QWORD *)(v4 + 472);
  v6 = v5 + 24LL * *(unsigned int *)(v4 + 480);
  if ( v5 >= v6 )
    return 0;
  while ( *(_BYTE *)(v5 + 8) != 1 )
  {
    v5 += 24LL;
    if ( v5 >= v6 )
      return 0;
  }
  v8 = a2;
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    if ( a2 )
      v11 = "HW control";
    else
      v11 = "SW control";
    printk(&unk_87478, "core", v11, a4);
    a2 = v8;
  }
  result = dev_pm_genpd_set_hwmode(*(_QWORD *)v5, a2 != 0);
  if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = result;
    printk(&unk_90858, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return v10;
  }
  return result;
}
