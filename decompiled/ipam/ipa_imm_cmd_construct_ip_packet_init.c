__int64 __fastcall ipa_imm_cmd_construct_ip_packet_init(unsigned int a1, unsigned int *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  unsigned int v8; // w3
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v12; // x0
  __int64 v13; // x0

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(kfree, v5, 12);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *a2;
    *(_WORD *)(v6 + 2) = opcode;
    *(_WORD *)v6 = 8;
    if ( v8 >= 0x20 )
    {
      printk(&unk_3E2969, "ipa_imm_cmd_construct_ip_packet_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d Dst pipe idx is bigger than 5bit width 0x%x\n",
          "ipa_imm_cmd_construct_ip_packet_init",
          393,
          *a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d Dst pipe idx is bigger than 5bit width 0x%x\n",
          "ipa_imm_cmd_construct_ip_packet_init",
          393,
          *a2);
      }
      __break(0x800u);
      v8 = *a2;
    }
    *(_QWORD *)(v6 + 4) = *(_QWORD *)(v6 + 4) & 0xFFFFFFFFFFFFFFE0LL | v8 & 0x1F;
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_ip_packet_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      v12 = ipa3_get_ipc_logbuf();
      ipc_log_string(v12, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init", 384);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init", 384);
    }
  }
  return v6;
}
