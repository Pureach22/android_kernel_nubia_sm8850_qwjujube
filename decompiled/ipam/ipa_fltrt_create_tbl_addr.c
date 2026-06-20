__int64 __fastcall ipa_fltrt_create_tbl_addr(char a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = a2;
  if ( (a1 & 1) != 0 )
  {
    if ( (a2 & 0x7F) != 0 )
    {
      printk(&unk_3BCF12, "ipa_fltrt_create_tbl_addr");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d sys addr is not aligned accordingly addr=0x%pad\n",
          "ipa_fltrt_create_tbl_addr",
          42,
          v9);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        v3 = ipc_log_string(
               ipc_logbuf_low,
               "ipahal %s:%d sys addr is not aligned accordingly addr=0x%pad\n",
               "ipa_fltrt_create_tbl_addr",
               42,
               v9);
      }
LABEL_14:
      ((void (__fastcall *)(long double))ipa_assert)(v3);
      a2 = 0;
    }
  }
  else
  {
    if ( (a2 & 7) != 0 )
    {
      v6 = a2;
      printk(&unk_3D47CF, "ipa_fltrt_create_tbl_addr");
      if ( ipa3_get_ipc_logbuf() )
      {
        v7 = ipa3_get_ipc_logbuf();
        ipc_log_string(v7, "ipahal %s:%d addr/ofst isn't lcl addr aligned %llu\n", "ipa_fltrt_create_tbl_addr", 49, v6);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        v3 = ipc_log_string(
               v8,
               "ipahal %s:%d addr/ofst isn't lcl addr aligned %llu\n",
               "ipa_fltrt_create_tbl_addr",
               49,
               v6);
      }
      goto LABEL_14;
    }
    a2 = (16 * a2) | 1;
  }
  _ReadStatusReg(SP_EL0);
  return a2;
}
