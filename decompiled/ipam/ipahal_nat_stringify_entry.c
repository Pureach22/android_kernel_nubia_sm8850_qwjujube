__int64 __fastcall ipahal_nat_stringify_entry(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v7; // w24
  __int64 ipc_logbuf; // x23
  const char *v10; // x0
  long double v11; // q0
  __int64 ipc_logbuf_low; // x23
  const char *v13; // x0
  __int64 (__fastcall *v14)(__int64, __int64, __int64, long double); // x8
  unsigned int v15; // w19
  __int64 v16; // x0
  __int64 v17; // x0

  if ( !a2 || !a3 )
  {
    _warn_printk("NULL pointer received\n");
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( !a4 )
  {
    _warn_printk("The output buff size is zero\n");
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( a1 >= 4 )
  {
    _warn_printk("requested NAT type %d is invalid\n", a1);
    __break(0x800u);
    return (unsigned int)-22;
  }
  v7 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
    goto LABEL_22;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v10 = ipahal_nat_type_str(a1);
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Create the string for the entry of NAT type=%s\n",
      "ipahal_nat_stringify_entry",
      510,
      v10);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v13 = ipahal_nat_type_str(a1);
    v11 = ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d Create the string for the entry of NAT type=%s\n",
            "ipahal_nat_stringify_entry",
            510,
            v13);
  }
  if ( 48LL * a1 + 192 * (unsigned __int64)v7 > 0x1368 )
  {
LABEL_22:
    __break(1u);
    JUMPOUT(0x479F470);
  }
  v14 = (__int64 (__fastcall *)(__int64, __int64, __int64, long double))ipahal_nat_objs[24 * v7 + 3 + 6 * a1];
  if ( *((_DWORD *)v14 - 1) != -1112914037 )
    __break(0x8228u);
  v15 = v14(a2, a3, a4, v11);
  if ( ipa3_get_ipc_logbuf() )
  {
    v16 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v16,
      "ipahal %s:%d The string successfully created with length %d\n",
      "ipahal_nat_stringify_entry",
      515,
      v15);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v17 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v17,
      "ipahal %s:%d The string successfully created with length %d\n",
      "ipahal_nat_stringify_entry",
      515,
      v15);
  }
  return v15;
}
