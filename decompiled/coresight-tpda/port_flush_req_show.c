__int64 __fastcall port_flush_req_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v4; // x21
  unsigned int v5; // w0
  __int64 v6; // x20

  v4 = *(_QWORD **)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v4 + 3);
  if ( !*(_DWORD *)(v4[2] + 976LL) )
  {
    v6 = -1;
    if ( v4 == (_QWORD *)-24LL )
      return v6;
    goto LABEL_3;
  }
  v5 = readl_relaxed((unsigned int *)(*v4 + 144LL));
  v6 = (int)sysfs_emit(a3, "%lx\n", v5);
  if ( v4 != (_QWORD *)-24LL )
LABEL_3:
    raw_spin_unlock(v4 + 3);
  return v6;
}
