unsigned __int64 __fastcall register_qcom_clks_pm(unsigned __int64 result, char a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x19

  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = *(_QWORD *)(result + 152);
    if ( (a2 & 1) == 0 )
    {
      *(_QWORD *)(v3 + 120) = &clock_pm_ops;
      *(_QWORD *)(result + 168) = a3;
      return 0;
    }
    *(_QWORD *)(v3 + 120) = &clock_pm_rt_ops;
    v4 = result;
    result = qcom_cc_runtime_init(result, a3);
    if ( !(_DWORD)result )
    {
      result = _pm_runtime_resume(v4 + 16, 4);
      if ( !(_DWORD)result )
        return 0;
    }
  }
  return result;
}
