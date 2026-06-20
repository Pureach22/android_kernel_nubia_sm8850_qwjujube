__int64 __fastcall get_power_uw(__int64 a1, __int64 *a2)
{
  mutex_lock(a1 + 1200);
  _get_power_uw(a1, a2);
  mutex_unlock(a1 + 1200);
  return 0;
}
