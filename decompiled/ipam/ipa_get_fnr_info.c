__int64 __fastcall ipa_get_fnr_info(_BYTE *a1)
{
  unsigned int v1; // w19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v1 = *(unsigned __int8 *)(ipa3_ctx + 45387);
  if ( v1 == 1 )
  {
    *a1 = 1;
    a1[1] = *(_BYTE *)(ipa3_ctx + 45388);
    a1[2] = *(_BYTE *)(ipa3_ctx + 45389);
  }
  else
  {
    printk(&unk_3D8D77, "ipa_get_fnr_info");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d fnr_info not valid!\n", "ipa_get_fnr_info", 13751);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d fnr_info not valid!\n", "ipa_get_fnr_info", 13751);
    }
  }
  return v1;
}
