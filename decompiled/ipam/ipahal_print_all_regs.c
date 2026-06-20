void __fastcall ipahal_print_all_regs(char a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x20
  __int64 v6; // x28
  __int64 v7; // x5
  __int64 v8; // x9
  char *v9; // x22
  int v10; // w10
  unsigned int v11; // w26
  __int64 v12; // x27
  __int64 v13; // x27
  __int64 v14; // x27
  __int64 v15; // x27
  __int64 v16; // x27
  __int64 v17; // x28
  __int64 reg_n; // x5
  __int64 v19; // x0
  __int64 v20; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Printing all registers for ipa_hw_type %d\n",
      "ipahal_print_all_regs",
      5334,
      *(_DWORD *)ipahal_ctx);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(
           ipc_logbuf_low,
           "ipahal %s:%d Printing all registers for ipa_hw_type %d\n",
           "ipahal_print_all_regs",
           5334,
           *(_DWORD *)ipahal_ctx);
  }
  if ( (unsigned int)(*(_DWORD *)ipahal_ctx - 26) < 0xFFFFFFF4 )
  {
    printk(&unk_3AE767, "ipahal_print_all_regs");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v19,
        "ipahal %s:%d invalid IPA HW type (%d)\n",
        "ipahal_print_all_regs",
        5338,
        *(_DWORD *)ipahal_ctx);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v20,
        "ipahal %s:%d invalid IPA HW type (%d)\n",
        "ipahal_print_all_regs",
        5338,
        *(_DWORD *)ipahal_ctx);
    }
  }
  else
  {
    v5 = 0;
    while ( *(_DWORD *)ipahal_ctx < 0x1Au )
    {
      v8 = 40 * v5 + 6640LL * *(unsigned int *)ipahal_ctx;
      if ( (unsigned __int64)(v8 - 172624) < 0xFFFFFFFFFFFD5DA0LL )
        goto LABEL_37;
      v9 = (char *)&ipahal_reg_objs + v8;
      if ( *(_DWORD *)((char *)&ipahal_reg_objs + v8 + 16) == -1 )
        goto LABEL_8;
      if ( (unsigned __int64)(v8 - 172608) < 0xFFFFFFFFFFFD5DA0LL )
        goto LABEL_37;
      if ( v9[32] != 1 )
        goto LABEL_8;
      if ( (unsigned __int64)(v8 - 172616) < 0xFFFFFFFFFFFD5DA0LL
        || (unsigned __int64)(v8 - 172613) < 0xFFFFFFFFFFFD5D9FLL )
      {
LABEL_37:
        __break(1u);
        break;
      }
      v11 = *((_DWORD *)v9 + 6);
      v10 = *((_DWORD *)v9 + 7);
      if ( v11 == v10 )
      {
        if ( (unsigned __int64)(v8 - 172621) < 0xFFFFFFFFFFFD5D9FLL )
          goto LABEL_37;
        if ( !*((_DWORD *)v9 + 5) )
        {
          if ( (a1 & 1) != 0 )
          {
            v15 = ipahal_reg_name_str(v3);
            ipahal_read_reg_n((unsigned int)v5, v11);
            printk(&unk_3F6B6A, v15);
            v16 = *(_QWORD *)(ipahal_ctx + 64);
            if ( v16 )
            {
              v17 = ipahal_reg_name_str(v3);
              reg_n = (unsigned int)ipahal_read_reg_n((unsigned int)v5, v11);
              v3 = ipc_log_string(v16, " %s:%d %s=0x%x\n", "ipahal_print_all_regs", 5358, v17, reg_n);
            }
          }
          else
          {
            v14 = *(_QWORD *)(ipahal_ctx + 64);
            if ( v14 )
            {
              v6 = ipahal_reg_name_str(v3);
              v7 = (unsigned int)ipahal_read_reg_n((unsigned int)v5, v11);
              v3 = ipc_log_string(v14, " %s:%d %s=0x%x\n", "ipahal_print_all_regs", 5362, v6, v7);
            }
          }
          goto LABEL_8;
        }
      }
      if ( (int)v11 <= v10 )
      {
        do
        {
          if ( (a1 & 1) != 0 )
          {
            v13 = ipahal_reg_name_str(v3);
            ipahal_read_reg_n((unsigned int)v5, v11);
            printk(&unk_3D1A24, v13);
            v12 = *(_QWORD *)(ipahal_ctx + 64);
            if ( v12 )
            {
LABEL_26:
              ipahal_reg_name_str(v3);
              ipahal_read_reg_n((unsigned int)v5, v11);
              v3 = ipc_log_string(v12, " %s:%d %s_%u=0x%x\n");
            }
          }
          else
          {
            v12 = *(_QWORD *)(ipahal_ctx + 64);
            if ( v12 )
              goto LABEL_26;
          }
          ++v11;
        }
        while ( (signed int)v11 <= *((_DWORD *)v9 + 7) );
      }
LABEL_8:
      if ( ++v5 == 166 )
        return;
    }
    __break(0x5512u);
    ipahal_reg_name_str(v3);
  }
}
