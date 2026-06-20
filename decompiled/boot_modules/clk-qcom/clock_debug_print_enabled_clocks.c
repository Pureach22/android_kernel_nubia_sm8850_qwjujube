__int64 __fastcall clock_debug_print_enabled_clocks(__int64 a1)
{
  _QWORD *v2; // x22
  int v3; // w20
  int v4; // w8
  __int64 v5; // x21
  char v6; // w23
  __int64 hw; // x0
  __int64 v8; // x25
  char v9; // w23
  __int64 rate; // x21
  int vdd_level; // w26
  char is_enabled; // w23
  char is_prepared; // w28
  const char *name; // x3
  int v15; // w4
  int v16; // w5
  __int64 parent; // x0
  __int64 v18; // x21
  __int64 v19; // x0
  __int64 v20; // x25
  __int64 v21; // x21
  int v22; // w26
  __int64 v23; // x0
  char v24; // w23
  char v25; // w28
  const char *v26; // x3
  int v27; // w4
  int v28; // w5

  if ( a1 )
    seq_printf(a1, "Enabled clocks:\n");
  else
    printk(&unk_291C2);
  v2 = clk_hw_debug_list;
  if ( clk_hw_debug_list == (_UNKNOWN *)&clk_hw_debug_list )
    goto LABEL_48;
  v3 = 0;
  do
  {
    if ( !v2 || !v2[2] )
    {
      printk(&unk_282F6);
LABEL_6:
      v4 = 0;
      goto LABEL_7;
    }
    if ( (((__int64 (*)(void))clk_hw_is_prepared)() & 1) == 0 )
      goto LABEL_6;
    if ( a1 )
      seq_printf(a1, "    ");
    else
      printk(&unk_286E0);
    v5 = *(_QWORD *)(v2[2] + 8LL);
    v6 = debug_suspend_atomic;
    hw = _clk_get_hw(v5);
    if ( hw )
    {
      v8 = hw;
      v9 = (a1 == 0) & v6;
      if ( (v9 & 1) != 0 )
      {
        clk_hw_get_rate(hw);
        goto LABEL_43;
      }
      rate = clk_get_rate(v5);
      if ( (clk_is_regmap_clk(v8) & 1) != 0 && *(_QWORD *)(v8 + 48) )
      {
        vdd_level = clk_find_vdd_level(v8, v8 + 48, (unsigned int)rate);
        if ( !a1 )
          goto LABEL_18;
      }
      else
      {
        vdd_level = 0;
        if ( !a1 )
        {
LABEL_18:
          if ( vdd_level )
          {
            clk_hw_get_name(v8);
            printk(&unk_28F73);
            goto LABEL_24;
          }
LABEL_43:
          clk_hw_get_name(v8);
          printk(&unk_28DFF);
          if ( (v9 & 1) != 0 )
          {
LABEL_44:
            printk(&unk_293C2);
            goto LABEL_40;
          }
          goto LABEL_24;
        }
      }
      is_enabled = clk_hw_is_enabled(v8);
      is_prepared = clk_hw_is_prepared(v8);
      name = (const char *)clk_hw_get_name(v8);
      v15 = is_enabled & 1;
      v16 = is_prepared & 1;
      if ( vdd_level )
        seq_printf(a1, "%s%s:%u:%u [%ld, %d]", "\t", name, v15, v16, rate, vdd_level);
      else
        seq_printf(a1, "%s%s:%u:%u [%ld]", "\t", name, v15, v16, rate);
LABEL_24:
      parent = clk_get_parent(*(_QWORD *)(v8 + 8));
      if ( parent )
      {
        v18 = parent;
        do
        {
          v19 = _clk_get_hw(v18);
          if ( !v19 )
            break;
          v20 = v19;
          v21 = clk_get_rate(v18);
          if ( (clk_is_regmap_clk(v20) & 1) != 0 && *(_QWORD *)(v20 + 48) )
          {
            v22 = clk_find_vdd_level(v20, v20 + 48, (unsigned int)v21);
            v23 = v20;
            if ( a1 )
              goto LABEL_35;
          }
          else
          {
            v22 = 0;
            v23 = v20;
            if ( a1 )
            {
LABEL_35:
              v24 = clk_hw_is_enabled(v23);
              v25 = clk_hw_is_prepared(v20);
              v26 = (const char *)clk_hw_get_name(v20);
              v27 = v24 & 1;
              v28 = v25 & 1;
              if ( v22 )
                seq_printf(a1, "%s%s:%u:%u [%ld, %d]", " -> ", v26, v27, v28, v21, v22);
              else
                seq_printf(a1, "%s%s:%u:%u [%ld]", " -> ", v26, v27, v28, v21);
              goto LABEL_27;
            }
          }
          clk_hw_get_name(v23);
          if ( v22 )
            printk(&unk_28F73);
          else
            printk(&unk_28DFF);
LABEL_27:
          v18 = clk_get_parent(*(_QWORD *)(v20 + 8));
        }
        while ( v18 );
      }
    }
    if ( !a1 )
      goto LABEL_44;
    seq_printf(a1, "\n");
LABEL_40:
    v4 = 1;
LABEL_7:
    v2 = (_QWORD *)*v2;
    v3 += v4;
  }
  while ( v2 != &clk_hw_debug_list );
  if ( v3 )
  {
    if ( a1 )
      return seq_printf(a1, "Enabled clock count: %d\n", v3);
    else
      return printk(&unk_2826D);
  }
LABEL_48:
  if ( a1 )
    return seq_printf(a1, "No clocks enabled.\n");
  else
    return printk(&unk_2899F);
}
