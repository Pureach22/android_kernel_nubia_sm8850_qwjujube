__int64 __fastcall ipahal_read_reg_n_fields(unsigned int a1, int a2, __int64 a3)
{
  long double v6; // q0
  __int64 v7; // x22
  const char *v8; // x0
  unsigned __int64 v9; // x9
  int v10; // w11
  unsigned int v11; // w0
  unsigned int v12; // w8
  unsigned int v13; // w21
  _DWORD *v14; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x20
  const char *v21; // x0
  __int64 v22; // x20
  const char *v23; // x0

  if ( !a3 )
  {
    printk(&unk_3A8BDA, "ipahal_read_reg_n_fields");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d Input error fields\n", "ipahal_read_reg_n_fields", 5601);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Input error fields\n", "ipahal_read_reg_n_fields", 5601);
    }
    goto LABEL_19;
  }
  if ( a1 >= 0xA6 )
  {
    printk(&unk_3DD61D, "ipahal_read_reg_n_fields");
    if ( ipa3_get_ipc_logbuf() )
    {
      v18 = ipa3_get_ipc_logbuf();
      ipc_log_string(v18, "ipahal %s:%d Invalid register reg=%u\n", "ipahal_read_reg_n_fields", 5607, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v19 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v19, "ipahal %s:%d Invalid register reg=%u\n", "ipahal_read_reg_n_fields", 5607, a1);
    }
LABEL_19:
    __break(0x800u);
    return (unsigned int)-22;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    v8 = ipahal_reg_name_str(a1);
    v6 = ipc_log_string(v7, "ipahal %s:%d read from %s n=%u and parse it\n", "ipahal_read_reg_n_fields", 5613, v8, a2);
  }
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    goto LABEL_31;
  v9 = 6640LL * *(unsigned int *)ipahal_ctx + 40LL * a1;
  if ( v9 > 0x2A24F )
  {
LABEL_30:
    __break(1u);
    goto LABEL_31;
  }
  v10 = *(_DWORD *)((char *)&ipahal_reg_objs[2] + v9);
  if ( v10 != -1 )
  {
    if ( v9 <= 0x2A24C )
    {
      v11 = readl_2(
              *(_QWORD *)(ipahal_ctx + 8) + (unsigned int)(v10 + *(_DWORD *)((char *)&ipahal_reg_objs[2] + v9 + 4) * a2),
              v6);
      v12 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx <= 0x19u )
      {
        if ( 40LL * a1 + 6640 * (unsigned __int64)v12 <= 0x2A257 )
        {
          v13 = v11;
          v14 = (_DWORD *)ipahal_reg_objs[830 * v12 + 1 + 5 * a1];
          if ( *(v14 - 1) != -493346229 )
            __break(0x8228u);
          ((void (__fastcall *)(_QWORD, __int64, _QWORD))v14)(a1, a3, v11);
          return v13;
        }
        goto LABEL_30;
      }
LABEL_31:
      __break(0x5512u);
      JUMPOUT(0x19E0CC);
    }
    goto LABEL_30;
  }
  ipahal_reg_name_str(a1);
  printk(&unk_3ABB60, "ipahal_read_reg_n_fields");
  if ( ipa3_get_ipc_logbuf() )
  {
    v20 = ipa3_get_ipc_logbuf();
    v21 = ipahal_reg_name_str(a1);
    ipc_log_string(v20, "ipahal %s:%d Read access to obsolete reg=%s\n", "ipahal_read_reg_n_fields", 5617, v21);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v22 = ipa3_get_ipc_logbuf_low();
    v23 = ipahal_reg_name_str(a1);
    ipc_log_string(v22, "ipahal %s:%d Read access to obsolete reg=%s\n", "ipahal_read_reg_n_fields", 5617, v23);
  }
  __break(0x800u);
  return (unsigned int)-1;
}
