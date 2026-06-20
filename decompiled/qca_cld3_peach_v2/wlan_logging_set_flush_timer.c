__int64 __fastcall wlan_logging_set_flush_timer(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x21
  unsigned int multiplier; // w20
  __int64 v12; // x0

  if ( a1 > 0x36EE80 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: ERROR! value should be (0 - %d)\n",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_logging_set_flush_timer",
      3600000);
    return 4294967274LL;
  }
  if ( (word_826C80 & 1) == 0 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: WLAN-Logging not active",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_logging_set_flush_timer");
    return 4294967274LL;
  }
  raw_spin_lock(&dword_826D00);
  if ( (byte_826CF8 & 1) == 0 )
  {
    raw_spin_unlock(&dword_826D00);
    return 4294967274LL;
  }
  dword_826CFC = a1;
  if ( a1 )
  {
    v10 = jiffies;
    multiplier = qdf_timer_get_multiplier();
    v12 = _msecs_to_jiffies(a1);
    mod_timer(&unk_826CC0, v10 + v12 * multiplier);
  }
  raw_spin_unlock(&dword_826D00);
  return 0;
}
