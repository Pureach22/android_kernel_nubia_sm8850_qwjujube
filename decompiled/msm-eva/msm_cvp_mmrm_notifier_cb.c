__int64 __fastcall msm_cvp_mmrm_notifier_cb(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x8

  if ( !a1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_95194, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    return 4294967274LL;
  }
  if ( *(_DWORD *)a1 != 1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    v4 = _ReadStatusReg(SP_EL0);
    printk(&unk_86EF3, *(unsigned int *)(v4 + 1800), *(unsigned int *)(v4 + 1804), "warn");
    return 4294967274LL;
  }
  result = 0;
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8C95F, &unk_8DA84, "msm_cvp_mmrm_notifier_cb", *(_QWORD *)(a1 + 24) + 2232LL);
    return 0;
  }
  return result;
}
