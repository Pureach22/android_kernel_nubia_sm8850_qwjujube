void sub_14D980()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cpas_parse_domain_id_mapping__alloc_tag_166;
  _kvmalloc_node_noprof(8LL * *(unsigned int *)(v0 + 1640), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x14C3A4);
}
