__int64 __fastcall charger_policy_notifier_switch(__int64 a1, __int64 a2, const char ***a3)
{
  __int64 v4; // x19
  const char *v6; // x20

  if ( a2 )
    return 0;
  v4 = a1 + 152;
  if ( (*(_QWORD *)(a1 + 152) & 1) == 0 )
  {
    v6 = **a3;
    if ( !strcmp(v6, *(const char **)(a1 + 424)) || !strcmp(v6, "usb") )
      queue_delayed_work_on(32, *(_QWORD *)(a1 + 144), v4, 50);
  }
  return 1;
}
