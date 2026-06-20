void __fastcall ipa_rm_resource_producer_notify_clients(__int64 a1, unsigned int a2, char a3)
{
  __int64 ipc_logbuf_low; // x22
  const char *v7; // x0
  _QWORD *i; // x27
  long double v9; // q0
  __int64 v10; // x25
  const char *v11; // x0
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v7 = ipa_rm_resource_str(*(_DWORD *)a1);
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_rm %s:%d %s event: %d notify_registered_only: %d\n",
      "ipa_rm_resource_producer_notify_clients",
      284,
      v7,
      a2,
      a3 & 1);
  }
  for ( i = *(_QWORD **)(a1 + 32); i != (_QWORD *)(a1 + 32); i = (_QWORD *)*i )
  {
    if ( (a3 & 1) == 0 || *((_BYTE *)i - 8) == 1 )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        v11 = ipa_rm_resource_str(*(_DWORD *)a1);
        v9 = ipc_log_string(
               v10,
               "ipa_rm %s:%d Notifying %s event: %d\n",
               "ipa_rm_resource_producer_notify_clients",
               291,
               v11,
               a2);
      }
      v12 = *(i - 3);
      v13 = (_DWORD *)*(i - 2);
      if ( *(v13 - 1) != -1011657747 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, long double))v13)(v12, a2, 0, v9);
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v14, "ipa_rm %s:%d back from client CB\n", "ipa_rm_resource_producer_notify_clients", 295);
      }
    }
  }
}
