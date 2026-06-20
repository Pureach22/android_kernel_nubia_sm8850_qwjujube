__int64 __fastcall ipa_imm_cmd_construct_register_write_v_4_0(unsigned int a1, unsigned int *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x20
  __int16 opcode; // w0
  unsigned __int64 v8; // x8
  __int64 v9; // x9
  unsigned int v10; // w3
  __int64 v11; // x11
  __int64 v12; // x8
  __int64 v13; // x9
  __int16 v14; // w8
  __int16 v15; // w8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( *a2 >= 0x10000 )
  {
    printk(&unk_3CB4A1, "ipa_imm_cmd_construct_register_write_v_4_0");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_register_write_v_4_0",
        289,
        *a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d Offset is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_register_write_v_4_0",
        289,
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
    v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 20);
    if ( !v6 )
      goto LABEL_17;
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *a2;
    v9 = a2[1];
    v10 = a2[4];
    v11 = *(_QWORD *)(v6 + 4) & 0x87FFLL;
    *(_WORD *)v6 = 16;
    v12 = v11 | (unsigned int)((_DWORD)v8 << 16) | (v8 >> 5) & 0x7800;
    LOWORD(v11) = *((unsigned __int8 *)a2 + 12);
    v13 = v12 | (v9 << 32);
    *(_DWORD *)(v6 + 12) = a2[2];
    v14 = opcode | ((_WORD)v11 << 8);
    *(_QWORD *)(v6 + 4) = v13;
    *(_WORD *)(v6 + 2) = v14;
    if ( v10 )
    {
      if ( v10 == 2 )
      {
        v15 = v14 | 0x400;
        goto LABEL_11;
      }
      if ( v10 == 1 )
      {
        v15 = v14 | 0x200;
LABEL_11:
        *(_WORD *)(v6 + 2) = v15;
        return v6;
      }
      printk(&unk_3B3C22, "ipa_imm_cmd_construct_register_write_v_4_0");
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v17,
          "ipahal %s:%d unsupported pipline clear option %d\n",
          "ipa_imm_cmd_construct_register_write_v_4_0",
          320,
          a2[4]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v18,
          "ipahal %s:%d unsupported pipline clear option %d\n",
          "ipa_imm_cmd_construct_register_write_v_4_0",
          320,
          a2[4]);
      }
LABEL_17:
      __break(0x800u);
    }
  }
  return v6;
}
