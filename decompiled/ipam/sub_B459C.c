void sub_B459C()
{
  __int64 v0; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  v0 = ipa3_ctx;
  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_alloc_rx_pkt_page__alloc_tag;
  v3 = kmem_cache_alloc_noprof(*(_QWORD *)(v0 + 29448), 527808);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0xB449C);
  JUMPOUT(0xB4384);
}
