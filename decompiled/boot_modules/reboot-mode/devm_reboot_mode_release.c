__int64 __fastcall devm_reboot_mode_release(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  _QWORD *v4; // x19
  _QWORD *i; // x20
  _QWORD *v6; // t1

  v2 = *a2;
  result = unregister_reboot_notifier(*a2 + 32);
  v6 = *(_QWORD **)(v2 + 8);
  v4 = (_QWORD *)(v2 + 8);
  for ( i = v6; i != v4; i = (_QWORD *)*i )
    result = kfree_const(*(i - 2));
  return result;
}
