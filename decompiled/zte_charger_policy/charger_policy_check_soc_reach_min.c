__int64 __fastcall charger_policy_check_soc_reach_min(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  signed int v8; // w20
  unsigned int v9; // w21
  int v10; // w8
  unsigned int v11; // w19
  __int64 result; // x0
  void *v13; // x0
  __int64 v14; // x2
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 440);
  v15 = 0;
  if ( (charger_policy_get_prop_by_name(v5, 0x2Fu, &v15, a4) & 0x80000000) != 0 )
  {
    printk(&unk_9375, "charger_policy_check_soc_reach_min", v6, v7);
    result = 0;
    goto LABEL_16;
  }
  if ( *(_BYTE *)(a1 + 541) == 1 )
    printk(
      &unk_963B,
      "charger_policy_check_soc_reach_min",
      *(unsigned __int8 *)(a1 + 537),
      *(unsigned __int8 *)(a1 + 538));
  if ( *(_BYTE *)(a1 + 537) == 1 )
  {
    v8 = *(_DWORD *)(a1 + 420);
    if ( (*(_BYTE *)(a1 + 540) & 1) == 0 )
      v8 -= *(_DWORD *)(a1 + 424);
    v9 = v15;
    if ( *(_BYTE *)(a1 + 541) == 1 )
    {
      printk(&unk_AD32, "charger_policy_check_soc_reach_min", v15, (unsigned int)v8);
      if ( (int)v9 > v8 )
        goto LABEL_9;
    }
    else if ( (int)v15 > v8 )
    {
      goto LABEL_9;
    }
    v13 = &unk_9F5F;
    v14 = v9;
LABEL_22:
    printk(v13, "charger_policy_check_soc_reach_min", v14, (unsigned int)v8);
    result = 1;
    goto LABEL_16;
  }
LABEL_9:
  if ( *(_BYTE *)(a1 + 538) != 1 || *(_BYTE *)(a1 + 539) != 1 )
    goto LABEL_15;
  v8 = *(_DWORD *)(a1 + 412);
  if ( (*(_BYTE *)(a1 + 540) & 1) == 0 )
    v8 -= *(_DWORD *)(a1 + 424);
  v10 = *(unsigned __int8 *)(a1 + 541);
  v11 = v15;
  if ( v10 == 1 )
  {
    printk(&unk_9684, "charger_policy_check_soc_reach_min", v15, (unsigned int)v8);
    if ( (int)v11 > v8 )
      goto LABEL_15;
    goto LABEL_21;
  }
  if ( (int)v15 <= v8 )
  {
LABEL_21:
    v13 = &unk_9B2F;
    v14 = v11;
    goto LABEL_22;
  }
LABEL_15:
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
