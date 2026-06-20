void sub_6C84()
{
  __int64 v0; // x20
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(v0 + 80);
  v2 = _mutex_init;
  *(_QWORD *)(v0 + 80) = &_start_alloc_tags;
  v3 = _kmalloc_cache_noprof(v2, 3520, 36);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6628);
  JUMPOUT(0x6A64);
}
