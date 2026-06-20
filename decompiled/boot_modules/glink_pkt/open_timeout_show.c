__int64 __fastcall open_timeout_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x19

  mutex_lock(a1 + 1048);
  v5 = (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(a1 + 1528));
  mutex_unlock(a1 + 1048);
  return v5;
}
