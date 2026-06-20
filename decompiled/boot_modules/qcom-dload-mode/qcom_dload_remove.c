__int64 __fastcall qcom_dload_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 168);
  atomic_notifier_chain_unregister(&panic_notifier_list, v1);
  unregister_restart_handler(v1 + 48);
  unregister_reboot_notifier(v1 + 24);
  result = *(_QWORD *)(v1 + 176);
  if ( result )
    return iounmap();
  return result;
}
