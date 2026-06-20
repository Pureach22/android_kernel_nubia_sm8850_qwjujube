__int64 __fastcall show_subsampling_enabled(__int64 a1, __int64 a2, __int64 a3)
{
  mutex_lock(&memlat_lock);
  LODWORD(a3) = scnprintf(a3, 4096, "%u\n", *(unsigned __int8 *)(memlat_data + 328));
  mutex_unlock(&memlat_lock);
  return (int)a3;
}
