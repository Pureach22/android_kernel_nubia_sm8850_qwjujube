__int64 __fastcall kgsl_get_stats(int a1)
{
  __int64 *v1; // x0
  __int64 v2; // x19

  if ( a1 < 0 )
    return qword_3A8B8;
  v1 = kgsl_process_private_find(a1);
  if ( !v1 )
    return 0;
  v2 = v1[26];
  kgsl_process_private_put((unsigned int *)v1);
  return v2;
}
