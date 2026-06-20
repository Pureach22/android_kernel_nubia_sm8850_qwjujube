__int64 __fastcall ipa_imm_cmd_construct_hdr_init_system(unsigned int a1, __int64 *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  __int64 v8; // x9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

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
    *(_QWORD *)(v6 + 4) = v8;
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_hdr_init_system");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_hdr_init_system", 710);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_hdr_init_system", 710);
    }
  }
  return v6;
}
