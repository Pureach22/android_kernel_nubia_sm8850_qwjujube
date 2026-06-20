__int64 cvp_dsp_resume()
{
  unsigned __int64 StatusReg; // x8

  if ( dword_6C668 == 4 || (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
    return 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  printk(&unk_8520B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  return 0;
}
