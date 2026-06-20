__int64 __fastcall sme_reset_power_debug_stats_cb(__int64 a1)
{
  __int64 result; // x0

  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a1 + 13048) = 0;
    *(_QWORD *)(a1 + 13040) = 0;
    return qdf_mutex_release(a1 + 12848);
  }
  return result;
}
