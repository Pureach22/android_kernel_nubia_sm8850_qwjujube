void sub_13F960()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_evtlog_dump_all__alloc_tag;
  v3 = _kvmalloc_node_noprof(0x400000, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 32) = v3;
  if ( !v3 )
    JUMPOUT(0x13F894);
  JUMPOUT(0x13F75C);
}
