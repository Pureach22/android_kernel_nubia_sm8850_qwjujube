void sub_7014()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &alloc_usb_qdss__alloc_tag;
  v2 = _kmalloc_cache_noprof(wait_for_completion, 3520, 560);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x6FD8);
  JUMPOUT(0x6E84);
}
