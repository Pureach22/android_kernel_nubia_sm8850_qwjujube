void sub_25DC8()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dfc_qmi_query_flow__alloc_tag;
  v2 = _kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 648);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x25D78);
  JUMPOUT(0x25BF0);
}
