__int64 __fastcall msm_ps_hold_restart(__int64 a1)
{
  __int64 v1; // x19

  writel(0, (unsigned int *)(*(_QWORD *)(a1 + 248) + 2080LL));
  v1 = -1000;
  do
    _const_udelay(4295000);
  while ( !__CFADD__(v1++, 1) );
  return 0;
}
