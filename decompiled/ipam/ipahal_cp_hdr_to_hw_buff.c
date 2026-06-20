void __fastcall ipahal_cp_hdr_to_hw_buff(const void *a1, unsigned int a2, const void *a3, unsigned int a4)
{
  __int64 ipc_logbuf_low; // x0
  __int64 ipc_logbuf; // x0
  long double v10; // q0
  __int64 v11; // x0
  void *v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_cp_hdr_to_hw_buff", 2449);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d base %pK, offset %d, hdr %pK, hdr_len %d\n",
      "ipahal_cp_hdr_to_hw_buff",
      2451,
      a1,
      a2,
      a3,
      a4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v11 = ipa3_get_ipc_logbuf_low();
    v10 = ipc_log_string(
            v11,
            "ipahal %s:%d base %pK, offset %d, hdr %pK, hdr_len %d\n",
            "ipahal_cp_hdr_to_hw_buff",
            2451,
            a1,
            a2,
            a3,
            a4);
  }
  if ( a1 && a3 )
  {
    v12 = hdr_funcs_0;
    if ( *((_DWORD *)hdr_funcs_0 - 1) != -1840470514 )
      __break(0x8228u);
    ((void (__fastcall *)(const void *, _QWORD, const void *, _QWORD, long double))v12)(a1, a2, a3, a4, v10);
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipahal %s:%d Exit\n", "ipahal_cp_hdr_to_hw_buff", 2459);
    }
  }
  else
  {
    printk(&unk_3DD2A4, "ipahal_cp_hdr_to_hw_buff");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipahal %s:%d failed on validating params\n", "ipahal_cp_hdr_to_hw_buff", 2453);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipahal %s:%d failed on validating params\n", "ipahal_cp_hdr_to_hw_buff", 2453);
    }
  }
}
