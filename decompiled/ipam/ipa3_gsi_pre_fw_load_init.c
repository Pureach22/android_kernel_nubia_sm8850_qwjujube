__int64 ipa3_gsi_pre_fw_load_init()
{
  __int64 result; // x0
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0

  result = gsi_configure_regs((unsigned int)dword_1F7DAC, *(unsigned int *)(ipa3_ctx + 32252));
  if ( (_DWORD)result )
  {
    printk(&unk_3E0845, "ipa3_gsi_pre_fw_load_init");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d Failed to configure GSI registers\n", "ipa3_gsi_pre_fw_load_init", 7757);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d Failed to configure GSI registers\n", "ipa3_gsi_pre_fw_load_init", 7757);
    }
    return 4294967274LL;
  }
  return result;
}
