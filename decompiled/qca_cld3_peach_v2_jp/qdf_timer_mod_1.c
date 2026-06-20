__int64 __fastcall qdf_timer_mod_1(__int64 a1)
{
  __int64 v2; // x20
  unsigned int multiplier; // w0

  v2 = jiffies;
  multiplier = qdf_timer_get_multiplier();
  return mod_timer(a1, v2 + multiplier);
}
