__int64 __fastcall global_flush_req_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  unsigned int v5; // w0
  __int64 v6; // x20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 24);
  if ( !*(_DWORD *)(*(_QWORD *)(v4 + 16) + 976LL) )
  {
    v6 = -1;
    if ( v4 == -24 )
      return v6;
    goto LABEL_3;
  }
  v5 = readl_relaxed(*(unsigned int **)v4);
  v6 = (int)sysfs_emit(a3, "%lx\n", v5);
  if ( v4 != -24 )
LABEL_3:
    raw_spin_unlock(v4 + 24);
  return v6;
}
