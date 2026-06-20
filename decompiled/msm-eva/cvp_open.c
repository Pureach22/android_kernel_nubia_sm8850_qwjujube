__int64 __fastcall cvp_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x0
  __int64 result; // x0

  if ( (msm_cvp_debug & 0x2000) != 0 && !msm_cvp_debug_out )
    printk(&unk_94187, "sess", "cvp_open", a4);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = msm_cvp_open(1, StatusReg);
  if ( v6 )
  {
    *(_QWORD *)(a2 + 32) = v6;
    return 0;
  }
  else
  {
    result = 4294967284LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_87441, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967284LL;
    }
  }
  return result;
}
