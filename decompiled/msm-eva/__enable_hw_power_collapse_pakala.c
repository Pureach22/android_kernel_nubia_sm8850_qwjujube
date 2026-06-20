__int64 __fastcall _enable_hw_power_collapse_pakala(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w19
  unsigned __int64 v8; // x8

  if ( msm_cvp_fw_low_power_mode )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 2208) + 464LL) )
    {
      result = switch_core_gdsc_mode(a1, 1, a3, a4);
      if ( (_DWORD)result )
        goto LABEL_4;
    }
    else
    {
      result = _hand_off_regulators(a1);
      if ( (_DWORD)result )
      {
LABEL_4:
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v7 = result;
          printk(&unk_8CD6F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
          return v7;
        }
        return result;
      }
    }
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (_read_register(a1, 0xF8068u) & 0x80000000) == 0 )
      return 0;
    usleep_range_state(100, 200, 2);
    if ( (msm_cvp_debug & 1) != 0 )
    {
      result = 4294967274LL;
      if ( msm_cvp_debug_out )
        return result;
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_835CD, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
    }
    return 4294967274LL;
  }
  result = 0;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8A57C, &unk_8DA84, a3, a4);
    return 0;
  }
  return result;
}
