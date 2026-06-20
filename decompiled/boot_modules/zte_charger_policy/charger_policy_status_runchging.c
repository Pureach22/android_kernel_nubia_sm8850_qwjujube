__int64 __fastcall charger_policy_status_runchging(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x0
  int v7; // w20
  int v8; // w21
  void *v9; // x0
  void *v10; // x0
  const char *v11; // x1
  __int64 v12; // x20
  int v13; // w8
  int v14; // w8
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 540) == 1 )
  {
    v2 = ktime_get_with_offset(1);
    v3 = ns_to_timespec64(v2);
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      v12 = v3;
      printk(&unk_AE3E, "charger_policy_check_force_discharging", v3, *(_QWORD *)(a1 + 520));
      v3 = v12;
    }
    if ( v3 - *(_QWORD *)(a1 + 520) > *(unsigned int *)(a1 + 504) )
    {
      v13 = *(_DWORD *)(a1 + 492);
      v10 = &unk_A0D7;
      *(_DWORD *)(a1 + 492) = 3;
      *(_DWORD *)(a1 + 496) = v13;
LABEL_29:
      v11 = "charger_policy_status_runchging";
      goto LABEL_30;
    }
  }
  charger_policy_ctrl_charging_enable(a1, 1, 1);
  v6 = *(_QWORD *)(a1 + 440);
  v16 = 0;
  if ( (charger_policy_get_prop_by_name(v6, 47, &v16) & 0x80000000) != 0 )
  {
    v10 = &unk_9375;
    v11 = "charger_policy_check_soc_reach_max";
LABEL_30:
    printk(v10, v11, v4, v5);
    goto LABEL_31;
  }
  if ( *(_BYTE *)(a1 + 541) == 1 )
    printk(
      &unk_963B,
      "charger_policy_check_soc_reach_max",
      *(unsigned __int8 *)(a1 + 537),
      *(unsigned __int8 *)(a1 + 538));
  if ( *(_BYTE *)(a1 + 537) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 540) & 1) != 0 )
    {
      v7 = *(_DWORD *)(a1 + 416);
      if ( *(_DWORD *)(a1 + 496) )
        v7 = (*(_DWORD *)(a1 + 420) + v7) / 2;
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 424) + *(_DWORD *)(a1 + 416);
    }
    v8 = v16;
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      printk(&unk_8F07, "charger_policy_check_soc_reach_max", (unsigned int)v16, (unsigned int)v7);
      if ( v8 < v7 )
        goto LABEL_15;
    }
    else if ( v16 < v7 )
    {
      goto LABEL_15;
    }
    v9 = &unk_995E;
    goto LABEL_28;
  }
LABEL_15:
  if ( *(_BYTE *)(a1 + 538) == 1 && *(_BYTE *)(a1 + 539) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 540) & 1) != 0 )
    {
      v7 = *(_DWORD *)(a1 + 408);
      if ( *(_DWORD *)(a1 + 496) )
        v7 = (*(_DWORD *)(a1 + 412) + v7) / 2;
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 424) + *(_DWORD *)(a1 + 408);
    }
    v8 = v16;
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      printk(&unk_A762, "charger_policy_check_soc_reach_max", (unsigned int)v16, (unsigned int)v7);
      if ( v8 < v7 )
        goto LABEL_31;
      goto LABEL_23;
    }
    if ( v16 >= v7 )
    {
LABEL_23:
      v9 = &unk_9CD5;
LABEL_28:
      printk(v9, "charger_policy_check_soc_reach_max", (unsigned int)v8, (unsigned int)v7);
      v14 = *(_DWORD *)(a1 + 492);
      *(_DWORD *)(a1 + 492) = 2;
      *(_DWORD *)(a1 + 496) = v14;
      charger_policy_ctrl_charging_enable(a1, 0, 0);
      v10 = &unk_90AF;
      goto LABEL_29;
    }
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return 0;
}
