void sub_44FA8()
{
  __int64 v0; // x23
  __int64 v1; // x21
  __int64 v2; // x0

  v1 = *(_QWORD *)(v0 + 80);
  *(_QWORD *)(v0 + 80) = &cnss_wlfw_host_cap_send_sync__alloc_tag;
  v2 = _kmalloc_cache_noprof(memcpy, 3520, 1000);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x44F60);
  JUMPOUT(0x44870);
}
