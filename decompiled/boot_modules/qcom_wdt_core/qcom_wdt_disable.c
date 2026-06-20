__int64 __fastcall qcom_wdt_disable(__int64 a1)
{
  void (*v2)(void); // x8
  void (__fastcall *v3)(_QWORD); // x8

  v2 = *(void (**)(void))(*(_QWORD *)(a1 + 16) + 32LL);
  if ( *((_DWORD *)v2 - 1) != 2060914831 )
    __break(0x8228u);
  v2();
  if ( *(_BYTE *)(a1 + 39) == 1 )
  {
    disable_percpu_irq(*(unsigned int *)(a1 + 32));
    free_percpu_irq(*(unsigned int *)(a1 + 32), *(_QWORD *)(a1 + 104));
  }
  else
  {
    devm_free_irq(*(_QWORD *)(a1 + 8), *(unsigned int *)(a1 + 32), a1);
  }
  *(_BYTE *)(a1 + 208) = 0;
  __dmb(0xBu);
  atomic_notifier_chain_unregister(&panic_notifier_list, a1 + 112);
  unregister_die_notifier(a1 + 136);
  unregister_restart_handler(a1 + 184);
  timer_delete_sync(a1 + 224);
  if ( *(_BYTE *)(a1 + 209) == 1 )
    timer_delete_sync(a1 + 960);
  v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 16) + 32LL);
  if ( *((_DWORD *)v3 - 1) != 2060914831 )
    __break(0x8228u);
  v3(a1);
  return dev_err(*(_QWORD *)(a1 + 8), "QCOM Apps Watchdog deactivated\n");
}
