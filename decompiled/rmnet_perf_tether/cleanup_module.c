__int64 __fastcall cleanup_module(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_7328, "rmnet_perf_tether_exit", a3);
  return unregister_netdevice_notifier(&rmnet_perf_tether_state_notifier_block);
}
