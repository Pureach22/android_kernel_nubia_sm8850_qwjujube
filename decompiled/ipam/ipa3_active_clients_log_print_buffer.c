__int64 __fastcall ipa3_active_clients_log_print_buffer(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x21
  unsigned int v7; // w22
  int v8; // w26
  unsigned int v9; // w25

  v4 = raw_spin_lock_irqsave(ipa3_ctx + 30560);
  v5 = ipa3_ctx;
  v6 = v4;
  v7 = 0;
  v8 = *(_DWORD *)(ipa3_ctx + 31528);
  v9 = (*(_DWORD *)(ipa3_ctx + 31532) + 1) % 120;
  if ( v9 == v8 )
  {
LABEL_8:
    raw_spin_unlock_irqrestore(v5 + 30560, v6);
    return v7;
  }
  else
  {
    while ( v9 < 0x78 )
    {
      v7 += scnprintf(a1 + (int)v7, (int)(a2 - v7), "%s\n", *(const char **)(ipa3_ctx + 8LL * v9 + 30568));
      if ( v9 == 119 )
        v9 = 0;
      else
        ++v9;
      if ( v9 == v8 )
      {
        v5 = ipa3_ctx;
        goto LABEL_8;
      }
    }
    __break(0x5512u);
    return ipa3_active_clients_log_print_table();
  }
}
