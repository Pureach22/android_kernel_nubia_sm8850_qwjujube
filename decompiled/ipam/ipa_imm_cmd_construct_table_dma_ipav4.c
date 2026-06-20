__int64 __fastcall ipa_imm_cmd_construct_table_dma_ipav4(unsigned int a1, unsigned int *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  __int64 v8; // x8
  char v9; // w9
  unsigned __int64 v10; // x8
  char v11; // w9
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
    v8 = *(_QWORD *)(v6 + 4);
    v9 = *((_BYTE *)a2 + 6);
    *(_WORD *)(v6 + 2) = opcode;
    v10 = v8 & 0xFF00000000000088LL | v9 & 7;
    v11 = *((_BYTE *)a2 + 7);
    *(_WORD *)v6 = 8;
    *(_QWORD *)(v6 + 4) = v10 & 0xFFFFFFFFFFFFFF8FLL
                        | (16LL * (v11 & 7))
                        | ((unsigned __int64)*a2 << 8)
                        | ((unsigned __int64)*((unsigned __int16 *)a2 + 2) << 40);
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_table_dma_ipav4");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_table_dma_ipav4", 685);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_table_dma_ipav4", 685);
    }
  }
  return v6;
}
