__int64 __fastcall zte_power_supply_unregister(__int64 a1)
{
  unsigned int v9; // w8
  unsigned int v10; // w8

  _X9 = (unsigned int *)(a1 + 1112);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v9 = __ldxr(_X9);
    v10 = v9 - 1;
  }
  while ( __stlxr(v10, _X9) );
  __dmb(0xBu);
  if ( v10 )
    __break(0x800u);
  *(_BYTE *)(a1 + 1110) = 1;
  cancel_work_sync(a1 + 968);
  cancel_delayed_work_sync(a1 + 1000);
  sysfs_remove_link(a1 + 56, "powers");
  device_wakeup_disable(a1 + 56);
  device_set_wakeup_capable(a1 + 56, 0);
  return device_unregister(a1 + 56);
}
