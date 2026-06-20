__int64 __fastcall cvp_unblocked_ioctl(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && *(_QWORD *)(a1 + 32) )
    return cvp_ioctl();
  result = -22;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_912BD, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    return -22;
  }
  return result;
}
