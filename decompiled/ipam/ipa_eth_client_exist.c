__int64 __fastcall ipa_eth_client_exist(unsigned int a1, unsigned int a2)
{
  unsigned __int64 v2; // x27
  char v3; // w8

  v3 = ipa_eth_ctx;
  if ( !ipa_eth_ctx )
    return v3 & 1;
  if ( a1 <= 5 && a2 < 2 )
  {
    v3 = *(_BYTE *)(ipa_eth_ctx + 24LL * a1 + 12LL * a2 + 56);
    return v3 & 1;
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
  return ipa_eth_uc_rdy_cb();
}
