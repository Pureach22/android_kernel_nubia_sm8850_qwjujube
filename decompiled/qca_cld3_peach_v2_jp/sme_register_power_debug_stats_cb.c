__int64 __fastcall sme_register_power_debug_stats_cb(__int64 a1)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 12984) = sme_power_debug_stats_cb;
    return qdf_mutex_release(a1 + 12776);
  }
  return result;
}
