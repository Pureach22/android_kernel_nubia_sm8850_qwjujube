__int64 __fastcall ipa_imm_cmd_construct_ip_packet_init_ex(unsigned int a1, unsigned __int8 *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x13
  int v12; // w12
  unsigned __int64 v13; // x8
  __int16 v14; // w14
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
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
    v8 = a2[7];
    v9 = a2[8];
    v10 = a2[9];
    v11 = a2[10];
    v12 = a2[1];
    v13 = *(_QWORD *)(v6 + 8) & 0xFFFFFFFFFF000000LL;
    v14 = *(_DWORD *)(v6 + 16);
    *(_WORD *)(v6 + 2) = opcode;
    v15 = v13 & 0xFFFFFE0001FFFFFFLL | v8 | (v9 << 8) | (v10 << 16);
    LODWORD(v8) = *(_DWORD *)(v6 + 4) & 0xFF80FFFF
                | (*a2 << 16)
                | (v12 << 17)
                | (a2[2] << 18)
                | (a2[3] << 19)
                | (a2[4] << 20)
                | (a2[5] << 21)
                | (a2[6] << 22);
    v16 = (v15 | (v11 << 25) | ((unsigned __int64)a2[11] << 36)) & 0x81F003FFFFFFLL
        | ((unsigned __int64)(a2[12] & 0xF) << 41)
        | ((unsigned __int64)a2[13] << 45)
        | ((unsigned __int64)a2[14] << 46)
        | ((unsigned __int64)a2[15] << 48)
        | ((unsigned __int64)a2[16] << 56);
    LODWORD(v9) = v14 & 0x100
                | a2[17]
                | (a2[18] << 9) & 0xE00FFFFF
                | ((*((_WORD *)a2 + 10) & 0x1FF) << 20)
                | (a2[22] << 29)
                | (a2[23] << 30)
                | (a2[24] << 31);
    *(_WORD *)v6 = 16;
    *(_DWORD *)(v6 + 4) = v8;
    *(_QWORD *)(v6 + 8) = v16 | 0xFFC000000LL;
    *(_DWORD *)(v6 + 16) = v9 | 0xFFC00;
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_ip_packet_init_ex");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init_ex", 438);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init_ex", 438);
    }
  }
  return v6;
}
