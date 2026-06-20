__int64 __fastcall iris_hfi_resume(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  unsigned int v8; // w19
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    {
      v10 = a1;
      printk(&unk_89D4D, "core", a3, a4);
      a1 = v10;
    }
    v4 = a1;
    mutex_lock(a1 + 80);
    v8 = _resume(v4, v5, v6, v7);
    mutex_unlock(v4 + 80);
  }
  else
  {
    v8 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_861CC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  return v8;
}
