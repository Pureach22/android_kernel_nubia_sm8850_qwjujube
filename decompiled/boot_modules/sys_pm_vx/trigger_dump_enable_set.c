__int64 __fastcall trigger_dump_enable_set(__int64 a1, __int64 a2)
{
  mutex_lock(a1 + 48);
  *(_BYTE *)(a1 + 136) = a2 != 0;
  mutex_unlock(a1 + 48);
  return 0;
}
