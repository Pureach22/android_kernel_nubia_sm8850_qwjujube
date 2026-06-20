__int64 __fastcall ipahal_parse_stats_drop(_DWORD *a1, __int64 a2, char *s)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x8
  int v8; // w9
  _DWORD *v9; // x10
  unsigned __int64 v10; // x11

  memset(s, 0, 0x120u);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_drop", 882);
  }
  v7 = 0;
  v8 = 0;
  v9 = s + 4;
  do
  {
    if ( ((*a1 >> v7) & 1) != 0 )
    {
      *v9 = *(_QWORD *)(a2 + 8LL * v8);
      v10 = *(_QWORD *)(a2 + 8LL * v8++);
      *(v9 - 1) = v10 >> 40;
    }
    ++v7;
    v9 += 2;
  }
  while ( v7 != 32 );
  return 0;
}
