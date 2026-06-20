__int64 __fastcall _set_threshold_registers(__int64 a1)
{
  __int64 result; // x0
  int v2; // w8
  unsigned int v3; // w19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x8

  result = _read_register(a1, 0xB0000u);
  if ( WORD1(result) == 12355 )
  {
    result = qcom_scm_set_remote_state(2, 26);
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    {
      v3 = result;
      printk(&unk_82354, "core", 2, (unsigned int)result);
      result = v3;
      if ( !v3 )
        return result;
    }
    else if ( !(_DWORD)result )
    {
      return result;
    }
    v2 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      result = printk(&unk_86A4F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v2 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 1) == 0 )
        return result;
    }
    else if ( (msm_cvp_debug & 1) == 0 )
    {
      return result;
    }
    if ( !v2 )
    {
      v5 = _ReadStatusReg(SP_EL0);
      return printk(&unk_94DDD, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
    }
  }
  return result;
}
