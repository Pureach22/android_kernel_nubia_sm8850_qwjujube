__int64 __fastcall reg_debug_consumers_show(__int64 a1)
{
  __int64 v1; // x21
  __int64 *i; // x23
  const char *v4; // x2
  __int64 v5; // x3

  v1 = *(_QWORD *)(a1 + 128);
  ww_mutex_lock(v1 + 152, 0);
  if ( *(_DWORD *)(v1 + 16) )
    seq_printf(a1, "%-32s EN    Min_uV   Max_uV  load_uA\n", "Device-Supply");
  for ( i = *(__int64 **)(v1 + 40); i != (__int64 *)(v1 + 40); i = (__int64 *)*i )
  {
    if ( i[9] )
      v4 = (const char *)i[9];
    else
      v4 = "(null)-(null)";
    if ( *((_DWORD *)i + 6) )
      v5 = 89;
    else
      v5 = 78;
    seq_printf(
      a1,
      "%-32s %c   %8d %8d %8d\n",
      v4,
      v5,
      *((unsigned int *)i + 8),
      *((unsigned int *)i + 9),
      *((unsigned int *)i + 5));
  }
  ww_mutex_unlock(v1 + 152);
  return 0;
}
