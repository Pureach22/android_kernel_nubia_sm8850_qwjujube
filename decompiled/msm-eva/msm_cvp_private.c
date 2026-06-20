__int64 __fastcall msm_cvp_private(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && a3 )
    return msm_cvp_handle_syscall(a1, a3);
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_95AEE, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
