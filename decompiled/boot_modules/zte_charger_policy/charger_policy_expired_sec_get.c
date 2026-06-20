__int64 __fastcall charger_policy_expired_sec_get(char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( a2 )
  {
    printk(&unk_A368, "charger_policy_expired_sec_get", *(unsigned int *)(a2 + 500), a4);
    return snprintf(a1, 0x1000u, "%u", *(_DWORD *)(a2 + 500));
  }
  else
  {
    printk(&unk_9AE6, "charger_policy_expired_sec_get", a3, a4);
    strcpy(a1, "arg is null");
    return 11;
  }
}
