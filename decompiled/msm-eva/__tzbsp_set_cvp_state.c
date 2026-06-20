__int64 __fastcall _tzbsp_set_cvp_state(__int64 a1)
{
  unsigned int v1; // w19
  __int64 result; // x0
  unsigned int v3; // w20
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w19

  v1 = a1;
  result = qcom_scm_set_remote_state(a1, 26);
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    v3 = result;
    printk(&unk_82354, "core", v1, (unsigned int)result);
    result = v3;
    if ( !v3 )
      return result;
  }
  else if ( !(_DWORD)result )
  {
    return result;
  }
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = result;
    printk(&unk_86A4F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return v5;
  }
  return result;
}
