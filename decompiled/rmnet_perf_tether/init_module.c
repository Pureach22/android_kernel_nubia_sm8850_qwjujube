__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_7464, "rmnet_perf_tether_init", a3);
  return register_netdevice_notifier(&rmnet_perf_tether_state_notifier_block);
}
