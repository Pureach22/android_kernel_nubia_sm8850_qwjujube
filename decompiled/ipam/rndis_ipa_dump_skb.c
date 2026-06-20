long double __fastcall rndis_ipa_dump_skb(__int64 a1)
{
  long double result; // q0
  unsigned __int64 v3; // x4
  unsigned __int64 v4; // x20

  if ( ipa_rndis_logbuf )
    result = ipc_log_string(
               ipa_rndis_logbuf,
               "RNDIS_IPA %s:%d packet dump start for skb->len=%d\n",
               "rndis_ipa_dump_skb",
               2336,
               *(_DWORD *)(a1 + 112));
  LODWORD(v3) = *(_DWORD *)(a1 + 112);
  if ( (unsigned int)v3 >= 4 )
  {
    v4 = 0;
    do
    {
      printk(&unk_3A5D96, (unsigned int)v4);
      v3 = *(unsigned int *)(a1 + 112);
      ++v4;
    }
    while ( v4 < v3 >> 2 );
  }
  if ( ipa_rndis_logbuf )
    return ipc_log_string(
             ipa_rndis_logbuf,
             "RNDIS_IPA %s:%d packet dump ended for skb->len=%d\n",
             "rndis_ipa_dump_skb",
             2346,
             v3);
  return result;
}
