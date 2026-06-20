__int64 __fastcall hdd_update_link_state_cached_timestamp(__int64 a1)
{
  __int64 result; // x0

  result = jiffies_to_msecs(jiffies);
  *(_QWORD *)(a1 + 71136) = (unsigned int)result;
  return result;
}
