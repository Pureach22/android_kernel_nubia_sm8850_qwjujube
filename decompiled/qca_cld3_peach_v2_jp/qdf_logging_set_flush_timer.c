__int64 __fastcall qdf_logging_set_flush_timer(__int64 a1)
{
  return 16 * (unsigned int)((unsigned int)wlan_logging_set_flush_timer(a1) != 0);
}
