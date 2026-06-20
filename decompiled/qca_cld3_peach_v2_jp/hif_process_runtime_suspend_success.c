void hif_process_runtime_suspend_success()
{
  __int64 v0; // x9
  unsigned __int64 StatusReg; // x9

  v0 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 5;
  ++*(_DWORD *)(v0 + 212);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  *(_QWORD *)(gp_hif_rtpm_ctx + 232) = StatusReg;
}
