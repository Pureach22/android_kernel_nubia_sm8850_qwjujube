__int64 __fastcall show_cpucp_log_level(__int64 a1, __int64 a2, __int64 a3)
{
  mutex_lock(&memlat_lock);
  LODWORD(a3) = scnprintf(a3, 4096, "%d\n", *(_DWORD *)(memlat_data + 332));
  mutex_unlock(&memlat_lock);
  return (int)a3;
}
