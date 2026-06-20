void sub_17103C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_soc_bus_client_register__alloc_tag;
  v2 = _kvmalloc_node_noprof(16, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x170D90);
  JUMPOUT(0x170C7C);
}
