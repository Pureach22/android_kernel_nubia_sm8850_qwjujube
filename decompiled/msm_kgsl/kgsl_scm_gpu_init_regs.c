__int64 __fastcall kgsl_scm_gpu_init_regs(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v5; // w21

  if ( !a2 )
    return 4294967201LL;
  result = qcom_scm_kgsl_init_regs(a2);
  if ( (_DWORD)result )
  {
    v5 = result;
    dev_err(a1, "Scm call for requests:0x%x failed with ret:: %d\n", a2, result);
    return v5;
  }
  return result;
}
