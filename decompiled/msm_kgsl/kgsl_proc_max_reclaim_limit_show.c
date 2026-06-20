__int64 __fastcall kgsl_proc_max_reclaim_limit_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%d\n", kgsl_reclaim_max_page_limit);
}
