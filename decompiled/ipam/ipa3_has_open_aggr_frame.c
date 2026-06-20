__int64 __fastcall ipa3_has_open_aggr_frame(__int64 a1)
{
  unsigned int ep_mapping; // w0
  unsigned int v2; // w19
  __int64 reg_n; // x0
  char v4; // w0
  unsigned int v5; // w20
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0

  ep_mapping = ipa_get_ep_mapping(a1);
  if ( ep_mapping == -1 )
  {
    ((void (*)(void))ipa_assert)();
    v4 = 0;
  }
  else
  {
    v2 = ep_mapping;
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
      reg_n = ipahal_read_reg_n(29, 0);
    else
      reg_n = ipahal_read_ep_reg(132, ep_mapping);
    v5 = reg_n;
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(reg_n);
    if ( ipc_logbuf_low )
    {
      v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(
        v7,
        "ipa_mhi %s:%d IPA_STATE_AGGR_ACTIVE_OFST 0x%x, ep_idx %d\n",
        "ipa3_has_open_aggr_frame",
        795,
        v2,
        v5);
    }
    v4 = ipahal_test_ep_bit(v5, v2);
  }
  return v4 & 1;
}
