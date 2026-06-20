void sub_268BC()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dfc_tx_link_status_ind_cb__alloc_tag;
  v2 = _kmalloc_cache_noprof(netdev_rx_handler_register, 2336, 800);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x26880);
  JUMPOUT(0x26810);
}
