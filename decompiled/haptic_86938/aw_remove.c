__int64 __fastcall aw_remove(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  unsigned int v4; // w0
  __int64 result; // x0
  unsigned __int64 v12; // x10

  v2 = *(_QWORD *)(a1 + 184);
  printk(&unk_14A18, "haptic_hv", 4569, "aw_remove");
  cancel_delayed_work_sync(v2 + 960);
  cancel_work_sync(v2 + 1376);
  hrtimer_cancel(v2 + 1312);
  cancel_work_sync(v2 + 928);
  cancel_work_sync(v2 + 1064);
  hrtimer_cancel(v2 + 816);
  v3 = gpio_to_desc(*(unsigned int *)(v2 + 80));
  v4 = gpiod_to_irq(v3);
  devm_free_irq(a1 + 32, v4, v2);
  if ( (*(_DWORD *)(v2 + 80) & 0x80000000) == 0 )
    gpio_free();
  cancel_work_sync(v2 + 1608);
  kfree(*(_QWORD *)(v2 + 1544));
  _X8 = (unsigned __int64 *)((((unsigned __int64)(((__int64)(*(_QWORD *)(v2 + 1552) << 8) >> 8) + 0x8000000000LL) >> 6)
                            & 0x3FFFFFFFFFFFFC0LL)
                           - 0x140000000LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 & 0xFFFFFFFFFFFFBFFFLL, _X8) );
  free_pages(*(_QWORD *)(v2 + 1552), 2);
  misc_deregister(&richtap_misc);
  result = *(unsigned int *)(v2 + 92);
  if ( (result & 0x80000000) == 0 )
    return gpio_free();
  return result;
}
