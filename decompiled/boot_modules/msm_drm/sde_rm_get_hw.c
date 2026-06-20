__int64 __fastcall sde_rm_get_hw(__int64 a1, __int64 a2)
{
  mutex_lock(a1 + 280);
  LOBYTE(a2) = sde_rm_get_hw_locked(a1, a2, 1);
  mutex_unlock(a1 + 280);
  return a2 & 1;
}
