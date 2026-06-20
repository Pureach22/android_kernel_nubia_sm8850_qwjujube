__int64 __fastcall ipa_imm_cmd_construct_hdr_init_local(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  unsigned int v8; // w3
  int v9; // w9
  unsigned int v10; // w8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v14; // x0
  __int64 v15; // x0

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 20);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *(_DWORD *)(a2 + 8);
    *(_WORD *)(v6 + 2) = opcode;
    *(_WORD *)v6 = 16;
    if ( v8 >= 0x1000 )
    {
      printk(&unk_3F6964, "ipa_imm_cmd_construct_hdr_init_local");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d Hdr tble size is bigger than 12bit width 0x%x\n",
          "ipa_imm_cmd_construct_hdr_init_local",
          741,
          *(_DWORD *)(a2 + 8));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d Hdr tble size is bigger than 12bit width 0x%x\n",
          "ipa_imm_cmd_construct_hdr_init_local",
          741,
          *(_DWORD *)(a2 + 8));
      }
      __break(0x800u);
      v8 = *(_DWORD *)(a2 + 8);
    }
    v9 = *(_DWORD *)(a2 + 12);
    v10 = *(_DWORD *)(v6 + 12) & 0xF0000000;
    *(_QWORD *)(v6 + 4) = *(_QWORD *)a2;
    *(_DWORD *)(v6 + 12) = v10 & 0xF0000000 | v8 & 0xFFF | ((unsigned __int16)v9 << 12);
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_hdr_init_local");
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_hdr_init_local", 732);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_hdr_init_local", 732);
    }
  }
  return v6;
}
