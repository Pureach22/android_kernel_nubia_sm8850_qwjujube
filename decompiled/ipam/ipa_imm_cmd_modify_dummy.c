__int64 __fastcall ipa_imm_cmd_modify_dummy(unsigned int a1)
{
  __int64 ipc_logbuf; // x20
  const char *v3; // x0
  __int64 ipc_logbuf_low; // x20
  const char *v5; // x0

  ipahal_imm_cmd_name_str(a1);
  printk(&unk_3BFB11, "ipa_imm_cmd_modify_dummy");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    v3 = ipahal_imm_cmd_name_str(a1);
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d no modify function for IMM_CMD=%s, IPA ver %d\n",
      "ipa_imm_cmd_modify_dummy",
      945,
      v3,
      *(_DWORD *)ipahal_ctx);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v5 = ipahal_imm_cmd_name_str(a1);
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d no modify function for IMM_CMD=%s, IPA ver %d\n",
      "ipa_imm_cmd_modify_dummy",
      945,
      v5,
      *(_DWORD *)ipahal_ctx);
  }
  __break(0x800u);
  return 4294967274LL;
}
