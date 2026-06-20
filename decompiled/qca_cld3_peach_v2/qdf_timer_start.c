__int64 __fastcall qdf_timer_start(__int64 a1, unsigned int a2)
{
  __int64 v4; // x22
  unsigned int multiplier; // w21

  v4 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  *(_QWORD *)(a1 + 16) = v4 + _msecs_to_jiffies(a2) * multiplier;
  return add_timer(a1);
}
