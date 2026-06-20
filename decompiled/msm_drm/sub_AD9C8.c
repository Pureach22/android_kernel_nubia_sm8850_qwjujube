void sub_AD9C8()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = wake_up_process;
  *(_QWORD *)(StatusReg + 80) = &usb_switch_dp_probe__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xAD944);
}
