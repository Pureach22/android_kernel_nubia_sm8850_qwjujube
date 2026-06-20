__int64 __fastcall timestamp_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x21

  rt_mutex_lock(a1 + 11088);
  v4 = *(_QWORD *)(a1 + 11240);
  if ( v4 )
    v5 = *(_QWORD *)(v4 + 104);
  else
    v5 = 0;
  rt_mutex_unlock(a1 + 11088);
  return (int)scnprintf(a2, 4096, "%lu\n", v5);
}
