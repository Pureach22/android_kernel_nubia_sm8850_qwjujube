void sub_25E00()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dfc_qmi_query_flow__alloc_tag_14;
  v2 = _kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 800);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x25D70);
  JUMPOUT(0x25C10);
}
