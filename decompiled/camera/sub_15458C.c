void sub_15458C()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cpas_subdev_cmd__alloc_tag;
  v3 = _kvmalloc_node_noprof(*(unsigned int *)(v0 + 4), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x153EE4);
  JUMPOUT(0x153AF4);
}
