__int64 __fastcall sub_22848(long double a1, long double a2, long double a3)
{
  __asm { FMLAL2          V3.2D, V24.2S, V9.2S }
  return sched_get_group_id(a1, a2, a3, _Q3);
}
