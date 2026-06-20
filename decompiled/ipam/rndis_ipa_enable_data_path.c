void __fastcall rndis_ipa_enable_data_path(_QWORD *a1)
{
  void (*v1)(void); // x8
  unsigned __int64 v9; // x10

  v1 = (void (*)(void))a1[11];
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -440107680 )
      __break(0x8228u);
    v1();
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d USB device_ready_notify() was called\n",
        "rndis_ipa_enable_data_path",
        1558);
  }
  else if ( ipa_rndis_logbuf )
  {
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d device_ready_notify() not supplied\n",
      "rndis_ipa_enable_data_path",
      1560);
  }
  HIWORD(qmap_template_hdr) = bswap32(*(unsigned __int16 *)(*a1 + 56LL) - 8) >> 16;
  _X8 = (unsigned __int64 *)(*(_QWORD *)(*a1 + 24LL) + 336LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  if ( ipa_rndis_logbuf )
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d netif_start_queue() was called\n",
      "rndis_ipa_enable_data_path",
      1566);
}
