void sub_28358()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  void *(*v2)(void *, int, size_t); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = memset;
  *(_QWORD *)(StatusReg + 80) = &qmi_rmnet_qos_init__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 344);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x28340);
  JUMPOUT(0x2831C);
}
