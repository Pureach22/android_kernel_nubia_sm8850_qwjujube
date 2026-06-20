__int64 __fastcall enable_source_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x19

  mutex_lock(&coresight_mutex);
  v5 = (int)scnprintf(a3, 4096, "%u\n", (unsigned int)*(_QWORD *)(a1 + 912) == 1);
  mutex_unlock(&coresight_mutex);
  return v5;
}
