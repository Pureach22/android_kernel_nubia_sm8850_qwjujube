__int64 __fastcall qdf_timer_mod_0(__int64 a1, unsigned int a2)
{
  __int64 v4; // x22
  unsigned int multiplier; // w21
  __int64 v6; // x0

  v4 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  v6 = _msecs_to_jiffies(a2);
  return mod_timer(a1, v4 + v6 * multiplier);
}
