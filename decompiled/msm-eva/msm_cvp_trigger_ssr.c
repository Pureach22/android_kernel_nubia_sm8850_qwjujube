__int64 __fastcall msm_cvp_trigger_ssr(__int64 a1, int a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    *(_DWORD *)(a1 + 1240) = a2;
    queue_work_on(32, system_wq, a1 + 1208);
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8A20D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      return 4294967274LL;
    }
  }
  return result;
}
