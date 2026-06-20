__int64 __fastcall show_freq_scale_ceil_mhz(__int64 a1, __int64 a2, __int64 a3)
{
  mutex_lock(a1 + 104);
  LODWORD(a3) = scnprintf(a3, 4096, "%u\n", *(_DWORD *)(a1 - 28));
  mutex_unlock(a1 + 104);
  return (int)a3;
}
