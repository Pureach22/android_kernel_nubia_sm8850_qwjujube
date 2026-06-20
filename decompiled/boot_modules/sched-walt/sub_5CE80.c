void sub_5CE80()
{
  __int64 v0; // x22
  __int64 v1; // x21
  __int64 v2; // x0
  __int64 v3; // x0

  v1 = *(_QWORD *)(v0 + 80);
  v2 = root_task_group;
  *(_QWORD *)(v0 + 80) = &nbia_wakeup_new_task__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 8);
  *(_QWORD *)(v0 + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x5CCF0);
  JUMPOUT(0x5CDC8);
}
