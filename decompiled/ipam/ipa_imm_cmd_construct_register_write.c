__int64 __fastcall ipa_imm_cmd_construct_register_write(unsigned int a1, unsigned int *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  unsigned int v8; // w3
  __int64 v9; // x9
  unsigned int v10; // w3
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v19; // x0
  __int64 v20; // x0

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 20);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *a2;
    *(_WORD *)(v6 + 2) = opcode;
    *(_WORD *)v6 = 16;
    if ( v8 >= 0x10000 )
    {
      printk(&unk_3CB4A1, "ipa_imm_cmd_construct_register_write");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
          "ipa_imm_cmd_construct_register_write",
          252,
          *a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
          "ipa_imm_cmd_construct_register_write",
          252,
          *a2);
      }
      __break(0x800u);
      v8 = *a2;
    }
    v9 = v8 << 16;
    v10 = a2[4];
    v11 = a2[2] | ((unsigned __int64)*(unsigned int *)(v6 + 16) << 32);
    v12 = v9 & 0xFFFFFFFFFFFF8000LL
        | *(_QWORD *)(v6 + 4) & 0x7FFFLL
        | ((unsigned __int64)a2[1] << 32)
        | ((unsigned __int64)*((unsigned __int8 *)a2 + 12) << 15);
    *(_QWORD *)(v6 + 12) = v11;
    *(_QWORD *)(v6 + 4) = v12;
    switch ( v10 )
    {
      case 2u:
        v13 = v11 & 0xFFFFFFFCFFFFFFFFLL | 0x200000000LL;
        goto LABEL_12;
      case 1u:
        v13 = v11 & 0xFFFFFFFCFFFFFFFFLL | 0x100000000LL;
        goto LABEL_12;
      case 0u:
        v13 = v11 & 0xFFFFFFFCFFFFFFFFLL;
LABEL_12:
        *(_QWORD *)(v6 + 12) = v13;
        return v6;
    }
    printk(&unk_3B3C22, "ipa_imm_cmd_construct_register_write");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v15,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_register_write",
        272,
        a2[4]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v16,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_register_write",
        272,
        a2[4]);
    }
    __break(0x800u);
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_register_write");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_register_write", 243);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_register_write", 243);
    }
  }
  return v6;
}
