__int64 __fastcall ipahal_imm_cmd_get_opcode(unsigned int a1)
{
  __int64 ipc_logbuf_low; // x20
  const char *v3; // x0
  unsigned int v4; // w8
  __int64 ipc_logbuf; // x0
  long double v7; // q0
  __int64 v8; // x0

  if ( a1 < 0x11 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v3 = ipahal_imm_cmd_name_str(a1);
      ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Get opcode of IMM_CMD=%s\n", "ipahal_imm_cmd_get_opcode", 1156, v3);
    }
    v4 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
    }
    else if ( (408LL * v4 + 24 * (unsigned __int64)a1) >> 5 <= 0x14A )
    {
      return LOWORD(ipahal_imm_cmd_objs[51 * v4 + 2 + 3 * a1]);
    }
    __break(1u);
    __asm { PRFM            #0x17, loc_16EAF0 }
    JUMPOUT(0x186E08);
  }
  printk(&unk_3A578F, "ipahal_imm_cmd_get_opcode");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Invalid immediate command imm_cmd=%u\n",
      "ipahal_imm_cmd_get_opcode",
      1150,
      a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    v7 = ipc_log_string(
           v8,
           "ipahal %s:%d Invalid immediate command imm_cmd=%u\n",
           "ipahal_imm_cmd_get_opcode",
           1150,
           a1);
  }
  ((void (__fastcall *)(long double))ipa_assert)(v7);
  return 65522;
}
