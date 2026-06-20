__int64 __fastcall hif_rtpm_check_and_request_resume(unsigned __int8 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x8
  int v5; // w21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x9

  v2 = gp_hif_rtpm_ctx;
  v3 = raw_spin_lock_irqsave(gp_hif_rtpm_ctx + 32);
  v4 = gp_hif_rtpm_ctx;
  *(_QWORD *)(v2 + 40) = v3;
  v5 = *(_DWORD *)(v4 + 188);
  result = raw_spin_unlock_irqrestore(v4 + 32, *(_QWORD *)(v4 + 40));
  if ( v5 == 5 || (a1 & (v5 == 4)) != 0 )
  {
    result = _pm_runtime_resume(*(_QWORD *)(gp_hif_rtpm_ctx + 8), 1);
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v8 = gp_hif_rtpm_ctx;
    *(_QWORD *)(gp_hif_rtpm_ctx + 272) = StatusReg;
    *(_QWORD *)(v8 + 280) = 0;
  }
  return result;
}
