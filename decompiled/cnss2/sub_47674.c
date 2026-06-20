void sub_47674()
{
  __int64 v0; // x24
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(v0 + 80);
  v2 = of_find_compatible_node;
  *(_QWORD *)(v0 + 80) = &cnss_wlfw_cal_done_ind_cb__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 4);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x47658);
  JUMPOUT(0x475F0);
}
