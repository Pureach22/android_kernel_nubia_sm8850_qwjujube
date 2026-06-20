__int64 __fastcall coresight_build_path(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  _QWORD *v6; // x19
  int v7; // w0
  int v8; // w20

  if ( !a2 )
    return -22;
  v4 = (_QWORD *)_kmalloc_cache_noprof(_pm_runtime_idle, 3520, 16);
  if ( !v4 )
    return -12;
  *v4 = v4;
  v4[1] = v4;
  v5 = a2;
  v6 = v4;
  v7 = coresight_build_path(a1, a1, v5);
  if ( !v7 )
    return (__int64)v6;
  v8 = v7;
  kfree(v6);
  return v8;
}
