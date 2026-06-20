void sub_17261C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_usb_init__alloc_tag;
  _kmalloc_cache_noprof(__ratelimit, 3520, 1400);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1723FC);
}
