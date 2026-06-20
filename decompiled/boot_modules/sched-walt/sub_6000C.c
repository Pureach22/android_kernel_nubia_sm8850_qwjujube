void sub_6000C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _tracepoint_android_rvh_update_cpu_capacity;
  *(_QWORD *)(StatusReg + 80) = &createRingBuffer__alloc_tag;
  _kmalloc_cache_noprof(v2, 3264, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x5FEF4);
}
