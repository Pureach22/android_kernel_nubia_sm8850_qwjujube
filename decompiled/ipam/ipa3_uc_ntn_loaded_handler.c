void ipa3_uc_ntn_loaded_handler()
{
  void (__fastcall *v0)(_QWORD); // x8
  __int64 v1; // x0
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  if ( ipa3_ctx )
  {
    v0 = *(void (__fastcall **)(_QWORD))(ipa3_ctx + 43208);
    if ( v0 )
    {
      v1 = *(_QWORD *)(ipa3_ctx + 43200);
      if ( *((_DWORD *)v0 - 1) != 251140989 )
        __break(0x8228u);
      v0(v1);
      v2 = ipa3_ctx + 43200;
      *(_QWORD *)(ipa3_ctx + 43200) = 0;
      *(_QWORD *)(v2 + 8) = 0;
    }
  }
  else
  {
    printk(&unk_3A437D, "ipa3_uc_ntn_loaded_handler");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d IPA ctx is null\n", "ipa3_uc_ntn_loaded_handler", 157);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d IPA ctx is null\n", "ipa3_uc_ntn_loaded_handler", 157);
    }
  }
}
