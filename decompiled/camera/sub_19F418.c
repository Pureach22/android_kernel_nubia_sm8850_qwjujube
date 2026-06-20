void __usercall sub_19F418(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sfe_top_apply_fcg_update__alloc_tag_127;
  v3 = _kvmalloc_node_noprof(4LL * *(unsigned int *)(a1 + 12), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x19E548);
  JUMPOUT(0x19E448);
}
