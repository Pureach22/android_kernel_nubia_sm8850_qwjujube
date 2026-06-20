void sub_14D9B4()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_cpas_get_custom_dt_info__alloc_tag_89;
  v3 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 1616) = v3;
  if ( !v3 )
    JUMPOUT(0x14D074);
  JUMPOUT(0x14CED4);
}
