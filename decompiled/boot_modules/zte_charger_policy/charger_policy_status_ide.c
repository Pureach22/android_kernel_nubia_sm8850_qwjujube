__int64 __fastcall charger_policy_status_ide(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x3
  __int64 v8; // x21
  int v9; // w8
  __int64 v10; // x3
  __int64 v11; // x20
  __int64 v12; // x20
  int v13; // w8

  if ( *(_BYTE *)(a1 + 541) == 1 )
    printk(&unk_ACDD, "charger_policy_status_ide", *(unsigned __int8 *)(a1 + 537), *(unsigned __int8 *)(a1 + 538));
  v2 = ktime_get_with_offset(1);
  v3 = ns_to_timespec64(v2);
  if ( *(_BYTE *)(a1 + 537) == 1 )
  {
    v8 = v3;
    printk(&unk_A261, "charger_policy_status_ide", v4, v5);
    charger_policy_disable_cas(a1, 1);
    v9 = *(_DWORD *)(a1 + 492);
    *(_DWORD *)(a1 + 492) = 1;
    *(_DWORD *)(a1 + 496) = v9;
    *(_QWORD *)(a1 + 520) = v8;
    printk(&unk_9DBE, "charger_policy_status_ide", v8, v10);
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 520);
    if ( !v6 )
    {
      v11 = v3;
      *(_QWORD *)(a1 + 520) = v3;
      printk(&unk_9463, "charger_policy_status_ide", v3, 0);
      v6 = *(_QWORD *)(a1 + 520);
      v3 = v11;
    }
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      v12 = v3;
      printk(&unk_A08E, "charger_policy_status_ide", v3, v6);
      v6 = *(_QWORD *)(a1 + 520);
      v3 = v12;
    }
    if ( v3 - v6 >= *(unsigned int *)(a1 + 500) )
    {
      printk(&unk_9A95, "charger_policy_status_ide", v4, v6);
      charger_policy_disable_cas(a1, 1);
      v13 = *(_DWORD *)(a1 + 492);
      *(_BYTE *)(a1 + 539) = 1;
      *(_DWORD *)(a1 + 492) = 1;
      *(_DWORD *)(a1 + 496) = v13;
    }
  }
  return 0;
}
