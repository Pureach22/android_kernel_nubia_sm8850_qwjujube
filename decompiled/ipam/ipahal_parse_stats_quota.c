__int64 __fastcall ipahal_parse_stats_quota(_DWORD *a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x21
  int v8; // w22
  _QWORD *v9; // x25
  __int64 v10; // x8
  __int64 v11; // x0

  memset(s, 0, 0x480u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_quota", 120);
  }
  v7 = 0;
  v8 = 0;
  v9 = s + 16;
  do
  {
    if ( ((*a1 >> v7) & 1) != 0 )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v11, "ipahal %s:%d pipe %d stat_idx %d\n", "ipahal_parse_stats_quota", 123, v7, v8);
      }
      v10 = a2 + 24LL * v8++;
      *(v9 - 2) = *(_QWORD *)v10;
      *v9 = *(unsigned int *)(v10 + 8);
      v9[1] = *(unsigned int *)(v10 + 12);
      *(v9 - 1) = *(_QWORD *)(v10 + 16);
    }
    ++v7;
    v9 += 4;
  }
  while ( v7 != 32 );
  return 0;
}
