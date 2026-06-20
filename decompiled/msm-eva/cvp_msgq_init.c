__int64 __fastcall cvp_msgq_init(__int64 a1)
{
  __int64 v1; // x0
  __int64 result; // x0
  __int64 v3; // x3
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w19

  *(_QWORD *)(a1 + 64) = cvp_msgq_cb;
  v1 = a1 + 64;
  *(_QWORD *)(v1 - 16) = 0x10700000002LL;
  *(_QWORD *)(v1 - 8) = 0;
  result = gh_rm_register_notifier();
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v5 = result;
      printk(&unk_91F60, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return v5;
    }
  }
  else if ( (msm_cvp_debug & 0x8000) != 0 && !msm_cvp_debug_out )
  {
    v5 = 0;
    printk(&unk_8928C, &unk_85102, "cvp_msgq_init", v3);
    return v5;
  }
  return result;
}
