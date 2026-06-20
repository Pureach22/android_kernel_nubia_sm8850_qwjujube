__int64 __fastcall slim_stream_allocate(__int64 a1, const char *a2)
{
  __int64 *v4; // x20
  __int64 v5; // x0
  _QWORD *v6; // x0
  __int64 v7; // x2
  _QWORD *v8; // x1

  v4 = (__int64 *)_kmalloc_cache_noprof(alt_cb_patch_nops, 3520, 64);
  if ( !v4 )
    return -12;
  v5 = kasprintf(3264, "slim-%s", a2);
  *v4 = v5;
  if ( !v5 )
  {
    kfree(v4);
    return -12;
  }
  v4[1] = a1;
  raw_spin_lock(a1 + 952);
  v6 = v4 + 6;
  v7 = a1 + 936;
  v8 = *(_QWORD **)(a1 + 944);
  if ( v4 + 6 == (__int64 *)(a1 + 936) || v8 == v6 || *v8 != v7 )
  {
    _list_add_valid_or_report();
  }
  else
  {
    *(_QWORD *)(a1 + 944) = v6;
    v4[6] = v7;
    v4[7] = (__int64)v8;
    *v8 = v6;
  }
  raw_spin_unlock(a1 + 952);
  return (__int64)v4;
}
