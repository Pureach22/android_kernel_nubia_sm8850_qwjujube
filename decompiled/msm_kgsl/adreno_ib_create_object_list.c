__int64 __fastcall adreno_ib_create_object_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 *a6)
{
  __int64 v11; // x24
  __int64 v12; // x0
  __int64 result; // x0

  if ( !a6 )
    return 4294967274LL;
  *a6 = 0;
  v11 = _kmalloc_cache_noprof(raw_read_lock, 3520, 16);
  if ( !v11 )
    return 4294967284LL;
  v12 = vmalloc_noprof(32000);
  *(_QWORD *)v11 = v12;
  if ( !v12 )
  {
    kfree(v11);
    return 4294967284LL;
  }
  result = adreno_ib_find_objs(a1, a2, a3, a4, 2, v11, 1);
  if ( *(_DWORD *)(v11 + 8) )
    *a6 = v11;
  return result;
}
