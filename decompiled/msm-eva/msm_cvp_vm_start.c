__int64 __fastcall msm_cvp_vm_start(__int64 a1)
{
  __int64 v1; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 264)) != 0 )
  {
    dword_199A4 = *(_DWORD *)(v1 + 20);
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_92CD0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
