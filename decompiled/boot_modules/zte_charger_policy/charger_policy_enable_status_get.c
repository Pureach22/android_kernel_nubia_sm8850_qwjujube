__int64 __fastcall charger_policy_enable_status_get(char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( a2 )
    return snprintf(a1, 0x1000u, "%u", *(_DWORD *)(a2 + 488) == 0);
  printk(&unk_9AE6, "charger_policy_enable_status_get", a3, a4);
  strcpy(a1, "arg is null");
  return 11;
}
