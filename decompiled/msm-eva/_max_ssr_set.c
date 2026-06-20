__int64 __fastcall max_ssr_set(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x8

  v2 = *(_QWORD *)(cvp_driver + 48);
  if ( !v2 )
    return 0;
  if ( a2 )
  {
    *(_DWORD *)(v2 + 856) = a2;
    return 0;
  }
  if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
    return 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  printk(&unk_9532E, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  return 0;
}
