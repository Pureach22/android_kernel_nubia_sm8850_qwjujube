__int64 __fastcall _disable_hw_power_collapse(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v8; // w19
  _QWORD *v9; // x20

  if ( !msm_cvp_fw_low_power_mode )
  {
    result = 0;
    if ( (msm_cvp_debug & 0x400) == 0 || msm_cvp_debug_out )
      return result;
    printk(&unk_8A57C, &unk_8DA84, a3, a4);
    return 0;
  }
  v4 = *(_QWORD *)(a1 + 2208);
  if ( *(_DWORD *)(v4 + 464) )
  {
    result = switch_core_gdsc_mode(a1, 0, a3, a4);
    if ( !(_DWORD)result )
      return result;
    goto LABEL_4;
  }
  v9 = *(_QWORD **)(v4 + 264);
  if ( v9 >= &v9[3 * *(unsigned int *)(v4 + 272)] )
    return 0;
  while ( 1 )
  {
    result = _acquire_regulator(v9, a1);
    if ( (_DWORD)result )
      break;
    v9 += 3;
    if ( (unsigned __int64)v9 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 264LL)
                               + 24 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 272LL) )
      return 0;
  }
LABEL_4:
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = result;
    printk(&unk_92E0D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    return v8;
  }
  return result;
}
