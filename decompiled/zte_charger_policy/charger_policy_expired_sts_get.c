__int64 __fastcall charger_policy_expired_sts_get(char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int16 v4; // w8

  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 539) == 1 )
      v4 = 49;
    else
      v4 = 48;
    *(_WORD *)a1 = v4;
    return 1;
  }
  else
  {
    printk(&unk_9AE6, "charger_policy_expired_sts_get", a3, a4);
    strcpy(a1, "arg is null");
    return 11;
  }
}
