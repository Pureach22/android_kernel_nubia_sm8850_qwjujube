void sub_44FDC()
{
  __int64 v0; // x23
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(v0 + 80);
  v2 = of_find_compatible_node;
  *(_QWORD *)(v0 + 80) = &cnss_wlfw_host_cap_send_sync__alloc_tag_346;
  v3 = _kmalloc_cache_noprof(v2, 3520, 4);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x44F98);
  JUMPOUT(0x44890);
}
