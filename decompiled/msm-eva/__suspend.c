__int64 __fastcall _suspend(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  __int64 result; // x0
  int v7; // w9
  unsigned __int64 v8; // x8
  unsigned int v9; // w19
  unsigned int v10; // w20
  unsigned __int64 StatusReg; // x8
  unsigned int v12; // w19

  v4 = (msm_cvp_debug_out == 0) & (BYTE1(msm_cvp_debug) >> 2);
  if ( (*(_BYTE *)(a1 + 72) & 1) == 0 )
  {
    if ( v4 )
      printk(&unk_96DAA, &unk_8DA84, a3, a4);
    return 0;
  }
  if ( v4 )
    printk(&unk_881FC, &unk_8DA84, a3, a4);
  result = qcom_scm_set_remote_state(0, 26);
  if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
  {
    if ( (_DWORD)result )
      goto LABEL_7;
    goto LABEL_17;
  }
  v10 = result;
  printk(&unk_82354, "core", 0, (unsigned int)result);
  result = v10;
  if ( !v10 )
  {
LABEL_17:
    _disable_subcaches(a1);
    power_off_iris2(a1);
    if ( *(_DWORD *)(a1 + 2696) && *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 400LL) )
      cvp_pm_qos_update(a1, 0);
    return 0;
  }
LABEL_7:
  v7 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = result;
    printk(&unk_86A4F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    v7 = msm_cvp_debug_out;
    result = v12;
    if ( (msm_cvp_debug & 2) == 0 )
      return result;
  }
  else if ( (msm_cvp_debug & 2) == 0 )
  {
    return result;
  }
  if ( !v7 )
  {
    v8 = _ReadStatusReg(SP_EL0);
    v9 = result;
    printk(&unk_96DD2, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), "warn");
    return v9;
  }
  return result;
}
