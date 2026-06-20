__int64 __fastcall kgsl_proc_max_reclaim_limit_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  LODWORD(result) = kstrtouint(a3, 0, &kgsl_reclaim_max_page_limit);
  if ( (_DWORD)result )
    return (int)result;
  else
    return a4;
}
