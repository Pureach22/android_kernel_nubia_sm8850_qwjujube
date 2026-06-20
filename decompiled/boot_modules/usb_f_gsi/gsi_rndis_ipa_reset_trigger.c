__int64 __fastcall gsi_rndis_ipa_reset_trigger(__int64 a1)
{
  __int64 v2; // x0

  if ( a1 != 304 )
    ipc_log_string(*(_QWORD *)(a1 + 1040), "%s: setting net_ready_trigger\n", "gsi_rndis_ipa_reset_trigger");
  v2 = raw_spin_lock_irqsave(a1 + 268);
  *(_BYTE *)(a1 + 257) = 0;
  return raw_spin_unlock_irqrestore(a1 + 268, v2);
}
