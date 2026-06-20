__int64 __fastcall inst_lock(__int64 a1)
{
  return mutex_lock(a1 + 16);
}
