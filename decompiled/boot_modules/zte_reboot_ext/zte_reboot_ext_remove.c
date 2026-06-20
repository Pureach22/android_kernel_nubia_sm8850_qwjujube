__int64 __fastcall zte_reboot_ext_remove(__int64 a1)
{
  __int64 v1; // x1
  __int64 v2; // x2

  atomic_notifier_chain_unregister(&panic_notifier_list, *(_QWORD *)(a1 + 168) + 104LL);
  unregister_kretprobe(&panic_probe);
  return printk(&unk_75ED, v1, v2);
}
