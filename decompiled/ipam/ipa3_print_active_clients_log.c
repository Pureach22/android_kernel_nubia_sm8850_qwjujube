__int64 __fastcall ipa3_print_active_clients_log(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int active; // w22
  int v8; // w23
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0

  if ( active_clients_buf )
  {
    memset((void *)active_clients_buf, 0, 0x3D00u);
    mutex_lock(ipa3_ctx + 30504);
    active = ipa3_active_clients_log_print_buffer(active_clients_buf, 11520);
    v8 = ipa3_active_clients_log_print_table(active_clients_buf + active, 4096);
    mutex_unlock(ipa3_ctx + 30504);
    return simple_read_from_buffer(a2, a3, a4, active_clients_buf, v8 + active);
  }
  printk(&unk_3C6987, "ipa3_print_active_clients_log");
  v10 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v11 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v11 )
  {
    ipc_log_string(v11, "ipa %s:%d Active Clients buffer is not allocated", "ipa3_print_active_clients_log", 3130);
    v10 = ipa3_ctx;
  }
  result = *(_QWORD *)(v10 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d Active Clients buffer is not allocated", "ipa3_print_active_clients_log", 3130);
    return 0;
  }
  return result;
}
