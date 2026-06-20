double __fastcall timer_multiplier_get_handler(__int64 a1)
{
  int multiplier; // w0

  multiplier = qdf_timer_get_multiplier();
  return scnprintf(a1, 4096, "%u", multiplier);
}
