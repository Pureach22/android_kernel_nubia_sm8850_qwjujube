__int64 __fastcall ipa_imm_cmd_construct_ip_v4_nat_init(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  int v8; // w8
  char v9; // w9
  int v10; // w10
  unsigned int v11; // w8
  __int16 v12; // w9
  __int64 v13; // x11
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(ipc_log_string, v5, 44);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *(_DWORD *)(v6 + 36);
    v9 = *(_BYTE *)(a2 + 22);
    v10 = *(unsigned __int16 *)(a2 + 18);
    *(_WORD *)(v6 + 2) = opcode;
    v11 = v8 & 0xFFF00008
        | v9 & 7
        | (16 * *(unsigned __int8 *)(a2 + 16))
        | (32 * *(unsigned __int8 *)(a2 + 17))
        | (*(unsigned __int8 *)(a2 + 40) << 6)
        | (*(unsigned __int8 *)(a2 + 41) << 7);
    *(_WORD *)v6 = 40;
    v12 = *(_WORD *)(a2 + 20);
    v13 = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(v6 + 4) = *(_QWORD *)a2;
    v14 = (v11 | (v10 << 8)) & 0xC00FFFFF | ((unsigned __int64)(v12 & 0x3FF) << 20);
    v15 = *(unsigned int *)(a2 + 44);
    *(_QWORD *)(v6 + 12) = v13;
    v16 = *(_QWORD *)(a2 + 32);
    *(_QWORD *)(v6 + 20) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v6 + 28) = v16;
    *(_QWORD *)(v6 + 36) = v14 | (v15 << 32);
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_ip_v4_nat_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_v4_nat_init", 815);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_v4_nat_init", 815);
    }
  }
  return v6;
}
