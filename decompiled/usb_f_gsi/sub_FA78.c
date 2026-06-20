void sub_FA78()
{
  unsigned int v0; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rndis_add_response__alloc_tag;
  v3 = _kmalloc_noprof(v0 + 32LL, 2080);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0xFA50);
  JUMPOUT(0xFA04);
}
