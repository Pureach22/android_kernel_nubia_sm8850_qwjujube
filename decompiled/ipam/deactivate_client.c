__int64 __fastcall deactivate_client(__int64 a1)
{
  unsigned int v1; // w21
  signed int ep_reg_idx; // w19
  __int64 v3; // x20
  __int64 ep_bit; // x0
  __int64 v5; // x9
  int v6; // w10
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0

  v1 = a1;
  ep_reg_idx = ipahal_get_ep_reg_idx(a1);
  v3 = raw_spin_lock_irqsave(ipa_pm_ctx + 584);
  ep_bit = ipahal_get_ep_bit(v1);
  if ( (unsigned int)ep_reg_idx >= 2 )
  {
    __break(0x5512u);
    return do_clk_scaling(ep_bit);
  }
  else
  {
    v5 = ipa_pm_ctx + 4LL * ep_reg_idx;
    v6 = *(_DWORD *)(v5 + 1104) & ~(_DWORD)ep_bit;
    v7 = ipa_pm_ctx + 584;
    *(_DWORD *)(v5 + 1104) = v6;
    v8 = raw_spin_unlock_irqrestore(v7, v3);
    result = ipa3_get_ipc_logbuf_low(v8);
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(
               ipc_logbuf_low,
               "ipa_pm %s:%d active bitmask (%d): %x\n",
               "deactivate_client",
               298,
               ep_reg_idx,
               *(_DWORD *)(ipa_pm_ctx + 4LL * ep_reg_idx + 1104));
    }
  }
  return result;
}
