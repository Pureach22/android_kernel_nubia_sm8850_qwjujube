__int64 __fastcall trylock_bus(__int64 a1)
{
  return mutex_trylock(a1 + 1264);
}
