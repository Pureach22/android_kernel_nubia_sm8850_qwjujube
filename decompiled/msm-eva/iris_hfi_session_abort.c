__int64 __fastcall iris_hfi_session_abort(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    v2 = a1;
    mutex_lock(v1 + 80);
    LODWORD(v2) = _send_session_cmd(v2, 17829903);
    mutex_unlock(v1 + 80);
    return (unsigned int)v2;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_9434F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
