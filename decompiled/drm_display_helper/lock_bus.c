__int64 __fastcall lock_bus(__int64 a1)
{
  return mutex_lock(a1 + 1264);
}
