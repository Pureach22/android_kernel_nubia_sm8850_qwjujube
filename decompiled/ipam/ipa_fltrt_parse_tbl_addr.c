void __fastcall ipa_fltrt_parse_tbl_addr(unsigned __int64 a1, unsigned __int64 *a2, bool *a3)
{
  __int64 ipc_logbuf_low; // x0
  unsigned __int64 v7; // x8
  __int64 ipc_logbuf; // x0
  long double v9; // q0
  __int64 v10; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Parsing hwaddr 0x%llx\n", "ipa_fltrt_parse_tbl_addr", 69, a1);
  }
  v11[0] = a1 & 0xFFFFFFFFFFFFFFFELL;
  *a3 = !(a1 & 1);
  if ( (a1 & 0x7E) != 0 )
  {
    printk(&unk_3BCF12, "ipa_fltrt_parse_tbl_addr");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d sys addr is not aligned accordingly addr=0x%pad\n",
        "ipa_fltrt_parse_tbl_addr",
        76,
        v11);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      v9 = ipc_log_string(
             v10,
             "ipahal %s:%d sys addr is not aligned accordingly addr=0x%pad\n",
             "ipa_fltrt_parse_tbl_addr",
             76,
             v11);
    }
    ((void (__fastcall *)(long double))ipa_assert)(v9);
  }
  else
  {
    if ( (a1 & 1) != 0 )
      v7 = a1 >> 4;
    else
      v7 = a1 & 0xFFFFFFFFFFFFFFFELL;
    *a2 = v7;
  }
  _ReadStatusReg(SP_EL0);
}
