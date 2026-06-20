__int64 __fastcall adreno_hwsched_snapshot_context_queue(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = adreno_hwsched_context_queue_enabled(a1);
  if ( (result & 1) != 0 )
  {
    raw_read_lock(a1 + 11208);
    idr_for_each(a1 + 11184, snapshot_context_queue, a2);
    return raw_read_unlock(a1 + 11208);
  }
  return result;
}
