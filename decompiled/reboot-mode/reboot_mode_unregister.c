__int64 __fastcall reboot_mode_unregister(__int64 a1)
{
  _QWORD *v2; // x19
  _QWORD *i; // x20
  _QWORD *v4; // t1

  unregister_reboot_notifier(a1 + 32);
  v4 = *(_QWORD **)(a1 + 8);
  v2 = (_QWORD *)(a1 + 8);
  for ( i = v4; i != v2; i = (_QWORD *)*i )
    kfree_const(*(i - 2));
  return 0;
}
