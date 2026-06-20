__int64 __fastcall ipa_imm_cmd_construct_dma_shared_mem(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x20
  __int16 opcode; // w0
  unsigned int v8; // w1
  unsigned int v9; // w1
  int v10; // w3
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

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
    if ( v8 >= 0x10000 )
    {
      _warn_printk("Size is bigger than 16bit width 0x%x\n", v8);
      __break(0x800u);
    }
    v9 = *(_DWORD *)(a2 + 12);
    if ( v9 >= 0x10000 )
    {
      _warn_printk("Local addr is bigger than 16bit width 0x%x\n", v9);
      __break(0x800u);
      LOWORD(v9) = *(_WORD *)(a2 + 12);
    }
    v10 = *(_DWORD *)(a2 + 20);
    v11 = *(_QWORD *)(v6 + 4) & 0xFFFC00000000FFFFLL
        | ((unsigned __int64)*(unsigned __int8 *)(a2 + 17) << 48)
        | (unsigned int)(*(_DWORD *)(a2 + 8) << 16)
        | ((unsigned __int64)(unsigned __int16)v9 << 32)
        | ((unsigned __int64)*(unsigned __int8 *)(a2 + 18) << 49);
    *(_QWORD *)(v6 + 12) = *(_QWORD *)a2;
    *(_QWORD *)(v6 + 4) = v11;
    switch ( v10 )
    {
      case 2:
        v12 = v11 & 0xFFF3FFFFFFFFFFFFLL | 0x8000000000000LL;
        goto LABEL_15;
      case 1:
        v12 = v11 & 0xFFF3FFFFFFFFFFFFLL | 0x4000000000000LL;
        goto LABEL_15;
      case 0:
        v12 = v11 & 0xFFF3FFFFFFFFFFFFLL;
LABEL_15:
        *(_QWORD *)(v6 + 4) = v12;
        return v6;
    }
    printk(&unk_3B3C22, "ipa_imm_cmd_construct_dma_shared_mem");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_dma_shared_mem",
        171,
        *(_DWORD *)(a2 + 20));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_dma_shared_mem",
        171,
        *(_DWORD *)(a2 + 20));
    }
    __break(0x800u);
  }
  return v6;
}
