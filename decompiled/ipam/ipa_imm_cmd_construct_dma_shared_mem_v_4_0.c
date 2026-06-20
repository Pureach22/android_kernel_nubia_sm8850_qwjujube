__int64 __fastcall ipa_imm_cmd_construct_dma_shared_mem_v_4_0(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x20
  __int16 opcode; // w0
  __int64 v8; // x10
  int v9; // w3
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x11
  unsigned __int64 v13; // x10
  __int16 v14; // w8
  __int16 v15; // w8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v21; // x0
  __int64 v22; // x0

  if ( *(_DWORD *)(a2 + 8) >= 0x10000u )
  {
    printk(&unk_3AE790, "ipa_imm_cmd_construct_dma_shared_mem_v_4_0");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Size is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        188,
        *(_DWORD *)(a2 + 8));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipahal %s:%d Size is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        188,
        *(_DWORD *)(a2 + 8));
    }
    goto LABEL_23;
  }
  if ( *(_DWORD *)(a2 + 12) >= 0x10000u )
  {
    printk(&unk_3D1758, "ipa_imm_cmd_construct_dma_shared_mem_v_4_0");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v21,
        "ipahal %s:%d Local addr is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        194,
        *(_DWORD *)(a2 + 12));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v22,
        "ipahal %s:%d Local addr is bigger than 16bit width 0x%x\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        194,
        *(_DWORD *)(a2 + 12));
    }
LABEL_23:
    v6 = 0;
    __break(0x800u);
    return v6;
  }
  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 20);
  if ( !v6 )
    goto LABEL_18;
  opcode = ipahal_imm_cmd_get_opcode(a1);
  v8 = *(unsigned __int8 *)(a2 + 16);
  v9 = *(_DWORD *)(a2 + 20);
  v10 = *(_QWORD *)(v6 + 4) & 0xFFFE000000007FFFLL | ((unsigned __int64)*(unsigned __int8 *)(a2 + 17) << 48);
  v11 = (unsigned int)(*(_DWORD *)(a2 + 8) << 16);
  v12 = *(unsigned __int16 *)(a2 + 12);
  *(_QWORD *)(v6 + 12) = *(_QWORD *)a2;
  *(_WORD *)v6 = 16;
  v13 = v10 | (v8 << 15) | v11 | (v12 << 32);
  v14 = opcode | (*(unsigned __int8 *)(a2 + 18) << 8);
  *(_QWORD *)(v6 + 4) = v13;
  *(_WORD *)(v6 + 2) = v14;
  if ( v9 )
  {
    if ( v9 == 2 )
    {
      v15 = v14 | 0x400;
      goto LABEL_12;
    }
    if ( v9 == 1 )
    {
      v15 = v14 | 0x200;
LABEL_12:
      *(_WORD *)(v6 + 2) = v15;
      return v6;
    }
    printk(&unk_3B3C22, "ipa_imm_cmd_construct_dma_shared_mem_v_4_0");
    if ( ipa3_get_ipc_logbuf() )
    {
      v17 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v17,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        226,
        *(_DWORD *)(a2 + 20));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v18,
        "ipahal %s:%d unsupported pipline clear option %d\n",
        "ipa_imm_cmd_construct_dma_shared_mem_v_4_0",
        226,
        *(_DWORD *)(a2 + 20));
    }
LABEL_18:
    __break(0x800u);
  }
  return v6;
}
