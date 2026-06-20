__int64 msm_ps_hold_poweroff()
{
  __int64 v0; // x19
  __int64 result; // x0

  writel(0, (unsigned int *)(*(_QWORD *)(poweroff_pctrl + 976) + 2080LL));
  v0 = -1000;
  do
    result = _const_udelay(4295000);
  while ( !__CFADD__(v0++, 1) );
  return result;
}
