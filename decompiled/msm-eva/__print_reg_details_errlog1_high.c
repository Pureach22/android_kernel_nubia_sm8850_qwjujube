__int64 _print_reg_details_errlog1_high()
{
  int v0; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v2; // x8
  __int64 result; // x0

  v0 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    result = printk(&unk_8CEF6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    v0 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) == 0 )
      return result;
  }
  else if ( (msm_cvp_debug & 1) == 0 )
  {
    return result;
  }
  if ( !v0 )
  {
    v2 = _ReadStatusReg(SP_EL0);
    return printk(&unk_91270, *(unsigned int *)(v2 + 1800), *(unsigned int *)(v2 + 1804), &unk_8E7CE);
  }
  return result;
}
