__int64 __fastcall qcom_pmu_idle_exit_notif(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x27
  __int64 v4; // x8
  __int64 result; // x0

  v4 = *(unsigned int *)(a3 + 4);
  if ( (unsigned int)v4 >= 0x20 )
  {
    __break(0x5512u);
    _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
    return memlat_pm_notif();
  }
  else
  {
    **(_BYTE **)((char *)&cpu_ev_data + _per_cpu_offset[v4]) = 0;
  }
  return result;
}
