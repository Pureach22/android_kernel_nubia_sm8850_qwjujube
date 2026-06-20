void __fastcall ipareg_construct_endp_init_cfg_n(unsigned int a1, unsigned __int8 *a2, int *a3)
{
  unsigned int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  __int64 ipc_logbuf; // x20
  const char *v9; // x0
  __int64 ipc_logbuf_low; // x20
  const char *v11; // x0

  v3 = *((_DWORD *)a2 + 1);
  if ( v3 >= 3 )
  {
    ipahal_reg_name_str(a1);
    printk(&unk_3B3FF0, "ipareg_construct_endp_init_cfg_n");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      v9 = ipahal_reg_name_str(a1);
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Invalid cs_offload_en value for %s\n",
        "ipareg_construct_endp_init_cfg_n",
        1988,
        v9);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v11 = ipahal_reg_name_str(a1);
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d Invalid cs_offload_en value for %s\n",
        "ipareg_construct_endp_init_cfg_n",
        1988,
        v11);
    }
    __break(0x800u);
  }
  else
  {
    v4 = *a2 | (2 * v3) | *a3;
    *a3 = v4;
    v5 = (8 * (a2[8] & 0xF)) | v4;
    *a3 = v5;
    v6 = ((a2[9] & 1) << 8) | v5;
    *a3 = v6;
    if ( *(_DWORD *)ipahal_ctx >= 0x18u )
      *a3 = v6 | (a2[11] << 9);
  }
}
