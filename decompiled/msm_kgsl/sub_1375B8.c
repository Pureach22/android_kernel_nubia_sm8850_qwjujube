void sub_1375B8()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &global_get_offset__alloc_tag;
  _kmalloc_cache_noprof(socinfo_get_partinfo_vulkan_id, 3520, 2880);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1374D8);
}
