__int64 __fastcall ipa_imm_cmd_construct_ip_packet_init_ex_v5_5(unsigned int a1, unsigned __int8 *a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x19
  __int16 opcode; // w0
  __int64 v8; // x13
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
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
    v8 = a2[32];
    v9 = a2[15]
       | ((unsigned __int64)*(unsigned __int8 *)(v6 + 27) << 56)
       | ((unsigned __int64)a2[16] << 8)
       | ((unsigned __int64)a2[17] << 16)
       | ((unsigned __int64)a2[29] << 24)
       | ((unsigned __int64)a2[18] << 25)
       | ((unsigned __int64)(*((_WORD *)a2 + 10) & 0x1FF) << 36)
       | ((unsigned __int64)a2[22] << 45)
       | ((unsigned __int64)a2[23] << 46)
       | ((unsigned __int64)a2[24] << 47)
       | ((unsigned __int64)a2[30] << 48)
       | ((unsigned __int64)(a2[31] & 0x3F) << 49);
    v10 = *(_QWORD *)(v6 + 4) & 0xFFFFFFFFFF00FFFFLL
        | ((unsigned __int64)*a2 << 16)
        | ((unsigned __int64)a2[1] << 17)
        | ((unsigned __int64)a2[2] << 18)
        | ((unsigned __int64)a2[3] << 19)
        | ((unsigned __int64)a2[4] << 20)
        | ((unsigned __int64)a2[5] << 21)
        | ((unsigned __int64)a2[6] << 22)
        | ((unsigned __int64)a2[25] << 23);
    v11 = *(_QWORD *)(v6 + 12) & 0xFF80800000000000LL
        | a2[7]
        | (unsigned __int16)(a2[8] << 8)
        | ((unsigned __int64)a2[9] << 16) & 0xFF8081F003FFFFFFLL
        | (a2[26] << 24) & 0x3FFFFFF
        | (a2[10] << 25) & 0x3FFFFFF
        | ((unsigned __int64)a2[11] << 36) & 0xFF8081F003FFFFFFLL
        | ((unsigned __int64)(a2[12] & 0xF) << 41)
        | ((unsigned __int64)a2[13] << 45)
        | ((unsigned __int64)a2[14] << 46)
        | ((unsigned __int64)a2[27] << 48)
        | ((unsigned __int64)(a2[28] & 0x3F) << 49);
    *(_WORD *)(v6 + 2) = opcode;
    *(_QWORD *)(v6 + 4) = v10;
    *(_WORD *)v6 = 24;
    *(_QWORD *)(v6 + 12) = v11 | 0xFFC000000LL;
    *(_QWORD *)(v6 + 20) = v9 | (v8 << 55) | 0xFFC000000LL;
  }
  else
  {
    printk(&unk_3C8A72, "ipa_imm_cmd_construct_ip_packet_init_ex_v5_5");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init_ex_v5_5", 492);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d kzalloc err\n", "ipa_imm_cmd_construct_ip_packet_init_ex_v5_5", 492);
    }
  }
  return v6;
}
