__int64 __fastcall charger_policy_demo_sts_get(char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int16 v7; // w8

  if ( a2 )
  {
    printk(&unk_AEC1, "charger_policy_demo_sts_get", *(unsigned __int8 *)(a2 + 537), a4);
    if ( *(_BYTE *)(a2 + 537) == 1 )
      v7 = 49;
    else
      v7 = 48;
    *(_WORD *)a1 = v7;
    return 1;
  }
  else
  {
    printk(&unk_9AE6, "charger_policy_demo_sts_get", a3, a4);
    strcpy(a1, "arg is null");
    return 11;
  }
}
