void sub_CC94()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &qrtr_ns_worker__alloc_tag;
  v2 = _kmalloc_cache_noprof(down_write, 3520, 4096);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0xBE80);
  JUMPOUT(0xBE48);
}
