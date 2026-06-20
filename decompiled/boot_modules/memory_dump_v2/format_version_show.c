__int64 __fastcall format_version_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return -14;
  mutex_lock(*(_QWORD *)(a1 + 152));
  LODWORD(a3) = scnprintf(a3, 4096, "%u\n", *(_DWORD *)(**(_QWORD **)(v3 + 56) + 4LL));
  mutex_unlock(v3);
  return (int)a3;
}
