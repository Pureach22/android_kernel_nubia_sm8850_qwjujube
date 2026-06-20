void __fastcall rndis_ipa_xmit_error_aftercare_wq(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  unsigned __int64 v10; // x10

  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_xmit_error_aftercare_wq", 1611);
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d Starting queue after xmit error\n",
        "rndis_ipa_xmit_error_aftercare_wq",
        1613);
  }
  if ( *(_DWORD *)(a1 - 24) != 4 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_xmit_error_aftercare_wq__rs, "rndis_ipa_xmit_error_aftercare_wq") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3D1C94, "rndis_ipa_xmit_error_aftercare_wq");
      v3 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        return;
    }
    else
    {
      v3 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        return;
    }
    ipc_log_string(
      v3,
      "RNDIS_IPA %s:%d error aftercare handling in bad state (%d)",
      "rndis_ipa_xmit_error_aftercare_wq",
      1623,
      *(_DWORD *)(a1 - 24));
    return;
  }
  v2 = *(_QWORD *)(a1 - 96);
  *(_BYTE *)(a1 - 69) = 0;
  _X8 = (unsigned __int64 *)(*(_QWORD *)(v2 + 24) + 336LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d netif_start_queue() was called\n",
      "rndis_ipa_xmit_error_aftercare_wq",
      1630);
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_xmit_error_aftercare_wq", 1632);
  }
}
