void sub_4024C()
{
  __int64 v0; // x20
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // [xsp+18h] [xbp+18h]

  v1 = platform_driver_unregister;
  v3 = *(_QWORD *)(v0 + 80);
  *(_QWORD *)(v0 + 80) = &cvp_alloc_fence_data__alloc_tag;
  v2 = _kmalloc_cache_noprof(v1, 3520, 320);
  *(_QWORD *)(v0 + 80) = v3;
  if ( !v2 )
    JUMPOUT(0x3F6E0);
  JUMPOUT(0x3F5D0);
}
