bool __fastcall chk_sram_offset_alignment(__int64 a1, int a2)
{
  __int64 v2; // x20
  __int64 v5; // x8
  __int64 v6; // x4
  __int64 v7; // x0
  __int64 v8; // x0

  v2 = a2 & (unsigned int)a1;
  if ( v2 )
  {
    printk(&unk_3E9BD2, "chk_sram_offset_alignment");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = a1;
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d sram addr(%luK) is not properly aligned\n", "chk_sram_offset_alignment", 991, a1);
        v5 = ipa3_ctx;
        v6 = a1;
      }
      v8 = *(_QWORD *)(v5 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d sram addr(%luK) is not properly aligned\n", "chk_sram_offset_alignment", 991, v6);
    }
  }
  return v2 == 0;
}
