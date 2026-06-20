__int64 __fastcall iris_hfi_session_clean(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  unsigned __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x2
  void *v7; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 32);
    if ( v1 )
    {
      mutex_lock(v1 + 80);
      _session_clean(a1);
      mutex_unlock(v1 + 80);
      return 0;
    }
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v5 = *(unsigned int *)(StatusReg + 1800);
      v6 = *(unsigned int *)(StatusReg + 1804);
      v7 = &unk_8C63C;
      goto LABEL_10;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v4 = _ReadStatusReg(SP_EL0);
      v5 = *(unsigned int *)(v4 + 1800);
      v6 = *(unsigned int *)(v4 + 1804);
      v7 = &unk_9434F;
LABEL_10:
      printk(v7, v5, v6, &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
