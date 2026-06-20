__int64 __fastcall ipa_imm_cmd_construct_ip_v6_routing_init(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  int v8; // w8
  int v9; // w10
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x10
  unsigned __int64 v14; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 28);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *(_DWORD *)(a2 + 16);
    v9 = *(_DWORD *)(a2 + 20);
    v10 = *(unsigned __int8 *)(v6 + 19);
    *(_WORD *)(v6 + 2) = opcode;
    v11 = v8 & 0xFFF | (unsigned __int64)(v10 << 56);
    LOWORD(v10) = *(_DWORD *)(a2 + 24);
    v12 = v11 & 0xFFFFFFFFF0000FFFLL | ((unsigned __int64)(unsigned __int16)v9 << 12);
    *(_WORD *)v6 = 24;
    v13 = *(_QWORD *)(a2 + 8);
    v14 = v12 & 0xFFFFFF000FFFFFFFLL
        | ((unsigned __int64)(v10 & 0xFFF) << 28)
        | ((unsigned __int64)*(unsigned __int16 *)(a2 + 28) << 40);
    *(_QWORD *)(v6 + 4) = *(_QWORD *)a2;
    *(_QWORD *)(v6 + 20) = v13;
    *(_QWORD *)(v6 + 12) = v14;
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_ip_v6_routing_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_v6_routing_init", 761);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_v6_routing_init", 761);
    }
  }
  return v6;
}
