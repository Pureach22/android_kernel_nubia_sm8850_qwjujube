__int64 __fastcall ipahal_parse_stats_flt_rt_v4_5(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned int v3; // w21
  unsigned int v4; // w22
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x8
  __int64 v9; // x9

  v3 = a3[1];
  v4 = *a3;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d \n", "ipahal_parse_stats_flt_rt_v4_5", 643);
  }
  if ( v3 >= v4 )
  {
    v8 = 0;
    v9 = v3 - v4 + 1;
    do
    {
      --v9;
      *(_QWORD *)(*((_QWORD *)a3 + 2) + v8 + 8) = *(_QWORD *)(a2 + v8 + 8);
      *(_DWORD *)(*((_QWORD *)a3 + 2) + v8 + 4) = *(_QWORD *)(a2 + v8);
      *(_DWORD *)(*((_QWORD *)a3 + 2) + v8) = *(_DWORD *)(a2 + v8 + 4);
      v8 += 16;
    }
    while ( v9 );
  }
  return 0;
}
