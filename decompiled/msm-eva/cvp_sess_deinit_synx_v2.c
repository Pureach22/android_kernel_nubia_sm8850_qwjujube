__int64 __fastcall cvp_sess_deinit_synx_v2(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  if ( a1 )
  {
    synx_uninitialize(*(_QWORD *)(a1 + 15264));
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8C2ED, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
