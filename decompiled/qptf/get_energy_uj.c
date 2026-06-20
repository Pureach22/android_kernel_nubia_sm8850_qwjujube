__int64 __fastcall get_energy_uj(__int64 a1, __int64 *a2)
{
  mutex_lock(a1 + 1200);
  _get_energy_uj(a1, a2);
  mutex_unlock(a1 + 1200);
  return 0;
}
