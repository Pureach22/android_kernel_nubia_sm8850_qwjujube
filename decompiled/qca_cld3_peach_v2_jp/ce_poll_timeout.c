__int64 __fastcall ce_poll_timeout(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x20
  unsigned int multiplier; // w0

  if ( *(_BYTE *)(result + 212) == 1 )
  {
    v1 = result;
    v2 = ce_per_engine_service(*(_QWORD *)result, *(unsigned int *)(result + 8));
    v3 = jiffies;
    multiplier = qdf_timer_get_multiplier(v2);
    return mod_timer(v1 + 216, 3LL * multiplier + v3);
  }
  return result;
}
