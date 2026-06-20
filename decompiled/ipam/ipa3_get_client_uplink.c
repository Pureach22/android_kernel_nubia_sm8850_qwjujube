__int64 __fastcall ipa3_get_client_uplink(unsigned int a1)
{
  unsigned int v1; // w9
  __int64 v2; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  if ( (a1 & 0x80000000) != 0 || (*(_DWORD *)(ipa3_ctx + 32240) <= 0x14u ? (v1 = 31) : (v1 = 36), v1 <= a1) )
  {
    printk(&unk_3ECE97, "ipa3_get_client_uplink");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d invalid pipe idx %d\n", "ipa3_get_client_uplink", 8567, a1);
        v2 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v2 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d invalid pipe idx %d\n", "ipa3_get_client_uplink", 8567, a1);
      LOBYTE(v2) = 0;
    }
  }
  else
  {
    LOBYTE(v2) = *(_BYTE *)(ipa3_ctx + 8LL * a1 + 43352);
  }
  return v2 & 1;
}
