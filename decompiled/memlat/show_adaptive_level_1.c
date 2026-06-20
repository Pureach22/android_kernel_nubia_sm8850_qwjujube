__int64 __fastcall show_adaptive_level_1(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21

  v3 = a1 - 48;
  mutex_lock(a1 - 48);
  LODWORD(a3) = scnprintf(a3, 4096, "%u\n", *(_DWORD *)(a1 - 160));
  mutex_unlock(v3);
  return (int)a3;
}
