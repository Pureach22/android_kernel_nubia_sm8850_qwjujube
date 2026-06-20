__int64 __fastcall hif_process_runtime_resume_success(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x19
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 result; // x0
  unsigned __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x9

  v2 = v1;
  v3 = gp_hif_rtpm_ctx;
  *(_DWORD *)(gp_hif_rtpm_ctx + 188) = 1;
  ++*(_DWORD *)(v3 + 208);
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v5 = gp_hif_rtpm_ctx;
  v6 = *(_QWORD *)(gp_hif_rtpm_ctx + 8);
  *(_QWORD *)(gp_hif_rtpm_ctx + 224) = StatusReg;
  *(_QWORD *)(v5 + 248) = StatusReg;
  result = ktime_get_mono_fast_ns(a1);
  *(_QWORD *)(v6 + 520) = result;
  __isb(0xFu);
  v8 = _ReadStatusReg(CNTVCT_EL0);
  v9 = gp_hif_rtpm_ctx;
  *(_QWORD *)(gp_hif_rtpm_ctx + 248) = v8;
  *(_DWORD *)(v9 + 256) = 0;
  v10 = *(_QWORD *)(v9 + 56);
  *(_QWORD *)(v9 + 264) = v2;
  if ( v10 )
  {
    ++*(_DWORD *)(v10 + 20);
    *(_QWORD *)(*(_QWORD *)(v9 + 56) + 40LL) = *(_QWORD *)(v9 + 248);
  }
  return result;
}
