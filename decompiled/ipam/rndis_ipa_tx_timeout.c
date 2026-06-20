void __fastcall rndis_ipa_tx_timeout(__int64 a1)
{
  int v1; // w20

  v1 = *(_DWORD *)(a1 + 2744);
  _ReadStatusReg(SP_EL0);
  printk(&unk_3DA7AB, "rndis_ipa_tx_timeout");
  if ( ipa_rndis_logbuf )
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d possible IPA stall was detected, %d outstanding\n",
      "rndis_ipa_tx_timeout",
      1207,
      v1);
  ++*(_QWORD *)(a1 + 592);
}
