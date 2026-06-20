__int64 histtimer_fn()
{
  *(_DWORD *)&lpm_cpu_data[_ReadStatusReg(TPIDR_EL1) + 72] = 1;
  return 0;
}
