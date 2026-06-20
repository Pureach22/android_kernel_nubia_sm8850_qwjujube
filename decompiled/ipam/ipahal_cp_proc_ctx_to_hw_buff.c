__int64 __fastcall ipahal_cp_proc_ctx_to_hw_buff(
        unsigned int a1,
        const void *a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        const void *a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        char a10)
{
  __int64 ipc_logbuf; // x0
  long double v19; // q0
  __int64 ipc_logbuf_low; // x0
  void *v21; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  int v25; // [xsp+8h] [xbp-18h]

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d type %d, base %pK, offset %d, hdr_len %d, hdr_base_addr %llu, offset_entry %pK, bool %d\n",
      "ipahal_cp_proc_ctx_to_hw_buff",
      2486,
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a10 & 1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v19 = ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d type %d, base %pK, offset %d, hdr_len %d, hdr_base_addr %llu, offset_entry %pK, bool %d\n",
            "ipahal_cp_proc_ctx_to_hw_buff",
            2486,
            a1,
            a2,
            a3,
            a4,
            a5,
            a6,
            a10 & 1);
  }
  if ( a5 && a2 && a6 )
  {
    v21 = hdr_funcs_1;
    if ( *((_DWORD *)hdr_funcs_1 - 1) != -901014647 )
      __break(0x8228u);
    LOBYTE(v25) = a10 & 1;
    return ((__int64 (__fastcall *)(_QWORD, const void *, _QWORD, _QWORD, __int64, const void *, __int64, __int64, long double, __int64, int))v21)(
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             v19,
             a9,
             v25);
  }
  else
  {
    printk(&unk_3AB8A4, "ipahal_cp_proc_ctx_to_hw_buff");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v23,
        "ipahal %s:%d invalid input: hdr_len:%u hdr_base_addr:%llu offset_entry:%pK\n",
        "ipahal_cp_proc_ctx_to_hw_buff",
        2491,
        a4,
        a5,
        a6);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v24,
        "ipahal %s:%d invalid input: hdr_len:%u hdr_base_addr:%llu offset_entry:%pK\n",
        "ipahal_cp_proc_ctx_to_hw_buff",
        2491,
        a4,
        a5,
        a6);
    }
    return 4294967274LL;
  }
}
