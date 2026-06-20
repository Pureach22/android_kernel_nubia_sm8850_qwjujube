__int64 __fastcall ipahal_nat_construct_entry(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 ipc_logbuf; // x22
  const char *v7; // x0
  long double v8; // q0
  __int64 ipc_logbuf_low; // x22
  const char *v10; // x0
  unsigned int v11; // w8
  void (__fastcall *v12)(__int64, __int64, long double); // x8

  if ( !a2 || !a3 )
  {
    _warn_printk("NULL pointer received\n");
    __break(0x800u);
    return 4294967274LL;
  }
  if ( a1 >= 4 )
  {
    _warn_printk("requested NAT type %d is invalid\n", a1);
    __break(0x800u);
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v7 = ipahal_nat_type_str(a1);
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Create %s entry using given fields\n",
      "ipahal_nat_construct_entry",
      533,
      v7);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v10 = ipahal_nat_type_str(a1);
    v8 = ipc_log_string(
           ipc_logbuf_low,
           "ipahal %s:%d Create %s entry using given fields\n",
           "ipahal_nat_construct_entry",
           533,
           v10);
  }
  v11 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
    goto LABEL_17;
  }
  if ( (192LL * v11 + 48 * (unsigned __int64)a1) >> 5 > 0x9A )
  {
LABEL_17:
    __break(1u);
    MEMORY[0xFFFFFFFFFAA4061C](v8);
    JUMPOUT(0x19C434);
  }
  v12 = (void (__fastcall *)(__int64, __int64, long double))ipahal_nat_objs[24 * v11 + 4 + 6 * a1];
  if ( *((_DWORD *)v12 - 1) != -148866526 )
    __break(0x8228u);
  v12(a2, a3, v8);
  return 0;
}
