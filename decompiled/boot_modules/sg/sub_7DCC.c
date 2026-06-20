void sub_7DCC()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x26
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_write_unlock_irqrestore;
  *(_QWORD *)(StatusReg + 80) = &sg_ioctl_common__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 384);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x7818);
  JUMPOUT(0x767C);
}
