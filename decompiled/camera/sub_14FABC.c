void sub_14FABC()
{
  __int64 v0; // x19
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x25
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cpas_soc_init_resources__alloc_tag_134;
  v4 = _kvmalloc_node_noprof(16LL * *(unsigned int *)(v0 + 104), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v1 + 1656) = v4;
  if ( !v4 )
    JUMPOUT(0x14F7AC);
  JUMPOUT(0x14F72C);
}
