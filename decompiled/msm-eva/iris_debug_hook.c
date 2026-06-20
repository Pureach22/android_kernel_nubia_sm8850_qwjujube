__int64 __fastcall iris_debug_hook(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x8

  if ( a1 )
  {
    _read_register(a1, 0xB0088u);
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_86C96, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 0;
    }
  }
  else
  {
    result = 4294967277LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v3 = _ReadStatusReg(SP_EL0);
      printk(&unk_94F45, *(unsigned int *)(v3 + 1800), *(unsigned int *)(v3 + 1804), &unk_8E7CE);
      return 4294967277LL;
    }
  }
  return result;
}
