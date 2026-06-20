__int64 __fastcall ipa_imm_cmd_construct_register_read(unsigned int a1, unsigned int *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x20
  __int16 opcode; // w0
  unsigned int v8; // w3
  unsigned __int64 v9; // x9
  __int16 v10; // w8
  __int16 v11; // w8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( *a2 >= 0x10000 )
  {
    printk(&unk_3CB4A1, "ipa_imm_cmd_construct_register_read");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_register_read",
        337,
        *a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_register_read",
        337,
        *a2);
    }
    v6 = 0;
    __break(0x800u);
  }
  else
  {
    if ( (a3 & 1) != 0 )
      v5 = 2336;
    else
      v5 = 3520;
    v6 = _kmalloc_cache_noprof(kfree, v5, 12);
    if ( !v6 )
      goto LABEL_17;
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = a2[3];
    v9 = *(_QWORD *)(v6 + 4) & 0x87FFLL
       | (*a2 << 16)
       | ((unsigned __int64)*a2 >> 5) & 0x7800
       | ((unsigned __int64)a2[1] << 32);
    v10 = opcode | (*((unsigned __int8 *)a2 + 8) << 8);
    *(_WORD *)v6 = 8;
    *(_QWORD *)(v6 + 4) = v9;
    *(_WORD *)(v6 + 2) = v10;
    if ( v8 )
    {
      if ( v8 == 2 )
      {
        v11 = v10 | 0x400;
        goto LABEL_11;
      }
      if ( v8 == 1 )
      {
        v11 = v10 | 0x200;
LABEL_11:
        *(_WORD *)(v6 + 2) = v11;
        return v6;
      }
      printk(&unk_3B3C22, "ipa_imm_cmd_construct_register_read");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipahal %s:%d unsupported pipline clear option %d\n",
          "ipa_imm_cmd_construct_register_read",
          367,
          a2[3]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v14,
          "ipahal %s:%d unsupported pipline clear option %d\n",
          "ipa_imm_cmd_construct_register_read",
          367,
          a2[3]);
      }
LABEL_17:
      __break(0x800u);
    }
  }
  return v6;
}
