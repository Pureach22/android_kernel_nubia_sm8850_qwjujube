__int64 __fastcall charger_policy_status_rundischging(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x0
  __int64 v7; // x2
  __int64 v8; // x3
  int v9; // w8
  int v10; // w20
  int v11; // w21
  int v12; // w8
  int v13; // w20
  int v14; // w22
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // w8
  __int64 v21; // x20
  __int64 v22; // x2
  __int64 v23; // x3
  __int64 v24; // x3
  __int64 v25; // x20
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 540) == 1 )
  {
    v2 = ktime_get_with_offset(1);
    v3 = ns_to_timespec64(v2);
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      v25 = v3;
      printk(&unk_AE3E, "charger_policy_check_force_discharging", v3, *(_QWORD *)(a1 + 520));
      v3 = v25;
    }
    if ( v3 - *(_QWORD *)(a1 + 520) > *(unsigned int *)(a1 + 504) )
    {
      *(_DWORD *)(a1 + 496) = *(_DWORD *)(a1 + 492);
      *(_DWORD *)(a1 + 492) = 3;
      printk(&unk_A0D7, "charger_policy_status_rundischging", v4, v5);
      goto LABEL_26;
    }
  }
  v6 = *(_QWORD *)(a1 + 440);
  v26 = 0;
  if ( (charger_policy_get_prop_by_name(v6, 47, &v26) & 0x80000000) == 0 )
  {
    if ( *(_BYTE *)(a1 + 538) == 1 && *(_BYTE *)(a1 + 539) == 1 )
    {
      v9 = *(_DWORD *)(a1 + 408);
      v10 = v9;
      if ( (*(_BYTE *)(a1 + 540) & 1) == 0 )
        v10 = *(_DWORD *)(a1 + 424) + v9;
      v11 = (*(_DWORD *)(a1 + 412) + v9) / 2;
      if ( *(_BYTE *)(a1 + 541) == 1 )
        printk(&unk_98C9, "charger_policy_select_discharging_mode", v26, (unsigned int)v10);
    }
    else
    {
      v11 = 0;
      v10 = 0;
    }
    if ( (*(_BYTE *)(a1 + 537) & 1) != 0 )
    {
      v12 = *(_DWORD *)(a1 + 416);
      v13 = v12;
      if ( (*(_BYTE *)(a1 + 540) & 1) == 0 )
        v13 = *(_DWORD *)(a1 + 424) + v12;
      v14 = v26;
      v11 = (*(_DWORD *)(a1 + 420) + v12) / 2;
      if ( *(_BYTE *)(a1 + 541) == 1 )
        printk(&unk_A87F, "charger_policy_select_discharging_mode", v26, (unsigned int)v13);
      if ( v14 < v13 )
        goto LABEL_19;
    }
    else
    {
      v14 = v26;
      if ( (int)v26 < v10 )
      {
LABEL_19:
        if ( v14 <= v11 )
          charger_policy_ctrl_charging_enable(a1, 0, 1);
        goto LABEL_24;
      }
    }
    if ( (charger_policy_ctrl_charging_enable(a1, 0, 0) & 1) == 0 )
    {
      printk(&unk_9E0B, "charger_policy_select_discharging_mode", v15, v16);
      alarm_try_to_cancel(a1 + 40);
    }
    goto LABEL_24;
  }
  printk(&unk_9375, "charger_policy_select_discharging_mode", v7, v8);
LABEL_24:
  if ( (charger_policy_check_soc_reach_min(a1) & 1) != 0 )
  {
    v18 = ktime_get_with_offset(1);
    v19 = ns_to_timespec64(v18);
    v20 = *(_DWORD *)(a1 + 492);
    *(_DWORD *)(a1 + 492) = 1;
    v21 = v19;
    *(_DWORD *)(a1 + 496) = v20;
    printk(&unk_987D, "charger_policy_status_rundischging", v22, v23);
    charger_policy_ctrl_charging_enable(a1, 1, 1);
    *(_QWORD *)(a1 + 520) = v21;
    printk(&unk_9819, "charger_policy_status_rundischging", v21, v24);
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return 0;
}
