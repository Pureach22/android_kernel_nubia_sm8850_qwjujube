__int64 __fastcall ipahal_read_reg_n(unsigned int a1, int a2)
{
  __int64 v4; // x0
  long double v5; // q0
  __int64 v6; // x21
  const char *v7; // x0
  unsigned __int64 v8; // x9
  int v9; // w12
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x20
  const char *v14; // x0
  __int64 v15; // x20
  const char *v16; // x0

  if ( a1 >= 0xA6 )
  {
    printk(&unk_3DD61D, "ipahal_read_reg_n");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d Invalid register reg=%u\n", "ipahal_read_reg_n", 5459, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Invalid register reg=%u\n", "ipahal_read_reg_n", 5459, a1);
    }
    __break(0x800u);
    return 4294967274LL;
  }
  else
  {
    v4 = ipa3_get_ipc_logbuf_low();
    if ( v4 )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      v7 = ipahal_reg_name_str(a1);
      v5 = ipc_log_string(v6, "ipahal %s:%d read from %s n=%u\n", "ipahal_read_reg_n", 5465, v7, a2);
    }
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_21;
    v8 = 6640LL * *(unsigned int *)ipahal_ctx + 40LL * a1;
    if ( v8 > 0x2A24F )
    {
LABEL_20:
      __break(1u);
LABEL_21:
      __break(0x5512u);
      return ipahal_reg_init(v4);
    }
    v9 = *(_DWORD *)((char *)&ipahal_reg_objs + v8 + 16);
    if ( v9 != -1 )
    {
      if ( v8 <= 0x2A24C )
        return readl_2(
                 *(_QWORD *)(ipahal_ctx + 8) + (unsigned int)(v9 + *(_DWORD *)((char *)&ipahal_reg_objs + v8 + 20) * a2),
                 v5);
      goto LABEL_20;
    }
    ipahal_reg_name_str(a1);
    printk(&unk_3ABB60, "ipahal_read_reg_n");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      v14 = ipahal_reg_name_str(a1);
      ipc_log_string(v13, "ipahal %s:%d Read access to obsolete reg=%s\n", "ipahal_read_reg_n", 5470, v14);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      v16 = ipahal_reg_name_str(a1);
      ipc_log_string(v15, "ipahal %s:%d Read access to obsolete reg=%s\n", "ipahal_read_reg_n", 5470, v16);
    }
    __break(0x800u);
    return 0xFFFFFFFFLL;
  }
}
