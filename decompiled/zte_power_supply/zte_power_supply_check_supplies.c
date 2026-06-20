__int64 __fastcall zte_power_supply_check_supplies(_QWORD *a1)
{
  unsigned int v2; // w20
  __int64 v3; // x0
  int v4; // w0
  int v5; // w8
  unsigned int v6; // w20
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD *v9; // x8
  __int64 result; // x0
  _QWORD v11[11]; // [xsp+8h] [xbp-58h] BYREF

  v11[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1[3] && a1[4] || !a1[5] )
  {
LABEL_20:
    result = 0;
  }
  else
  {
    v2 = 0;
    while ( 1 )
    {
      v3 = a1[5];
      memset(v11, 0, 80);
      if ( (unsigned int)_of_parse_phandle_with_args(v3, "power-supplies", 0, 0, v2, v11) || !v11[0] )
        break;
      ++v2;
      v4 = class_for_each_device(zte_power_supply_class, 0, v11[0], _zte_power_supply_find_supply_from_node);
      if ( v4 == 1 )
        v5 = 0;
      else
        v5 = v4;
      if ( !v4 )
        v5 = -517;
      if ( v5 )
      {
        v6 = v5;
        dev_info(a1 + 7, "Failed to find supply!\n");
        goto LABEL_23;
      }
    }
    if ( !v2 )
      goto LABEL_20;
    v7 = devm_kmalloc(a1 + 7, 8, 3520);
    a1[3] = v7;
    if ( !v7
      || ((v2 & 0x80000000) != 0
        ? (_QWORD *)(v9 = (_QWORD *)v7, v8 = 0)
        : (v8 = devm_kmalloc(a1 + 7, 8LL * v2, 3520), v9 = (_QWORD *)a1[3]),
          *v9 = v8,
          !*(_QWORD *)a1[3]) )
    {
      result = 4294967284LL;
      goto LABEL_21;
    }
    v6 = class_for_each_device(zte_power_supply_class, 0, a1, _zte_power_supply_populate_supplied_from);
    dev_info(a1 + 7, "%s %d\n", "zte_power_supply_populate_supplied_from", v6);
LABEL_23:
    result = v6;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
