__int64 __fastcall charger_policy_probe(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 v7; // x3
  _QWORD *v8; // x0
  unsigned int v9; // w19
  void *v10; // x0
  __int64 v11; // x21
  _DWORD *v12; // x20
  _QWORD *v13; // x19
  int variable_u32_array; // w0
  __int64 v15; // x3
  __int64 v16; // x2
  int v17; // w0
  __int64 v18; // x3
  __int64 v19; // x2
  int v20; // w0
  __int64 v21; // x3
  __int64 v22; // x2
  int v23; // w0
  __int64 v24; // x3
  __int64 v25; // x2
  int v26; // w0
  __int64 v27; // x3
  __int64 v28; // x2
  int v29; // w0
  __int64 v30; // x3
  __int64 v31; // x2
  int v32; // w0
  __int64 v33; // x3
  __int64 v34; // x2
  int v35; // w0
  __int64 v36; // x3
  __int64 v37; // x2
  int v38; // w0
  __int64 v39; // x3
  __int64 v40; // x2
  int v41; // w0
  __int64 v42; // x3
  __int64 v43; // x2
  int v44; // w0
  __int64 v45; // x3
  __int64 v46; // x2
  unsigned int string; // w0
  __int64 v48; // x3
  unsigned int v49; // w22
  const char *v50; // x2
  unsigned int v51; // w0
  const char *v52; // x2
  void *v53; // x0
  unsigned int v54; // w0
  const char *v55; // x2
  unsigned int v56; // w0
  const char *v57; // x2
  unsigned int v58; // w0
  const char *v59; // x2
  __int64 v60; // x2
  __int64 v61; // x3
  void *v62; // x0

  v5 = printk(&unk_A131, "charger_policy_probe", a3, a4);
  if ( (unsigned int)zte_poweroff_charging_status(v5) )
  {
    v9 = 0;
    v10 = &unk_93A2;
    goto LABEL_81;
  }
  v8 = (_QWORD *)devm_kmalloc(a1 + 16, 544, 3520);
  if ( v8 )
  {
    v11 = *(_QWORD *)(a1 + 760);
    *v8 = a1 + 16;
    v12 = v8 + 48;
    v13 = v8;
    *(_QWORD *)(a1 + 168) = v8;
    variable_u32_array = of_property_read_variable_u32_array(v11, "policy,enable", v8 + 48, 1, 0);
    v16 = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
    if ( (variable_u32_array & (variable_u32_array >> 31)) != 0 )
    {
      if ( (_DWORD)v16 == -22 )
        *v12 = 0;
      else
        printk(&unk_A8CB, "charger_policy_parse_dt", v16, v15);
    }
    printk(&unk_9D0A, "charger_policy_parse_dt", *((unsigned int *)v13 + 96), v15);
    v17 = of_property_read_variable_u32_array(v11, "policy,retry-times", v13 + 50, 1, 0);
    v19 = v17 & (unsigned int)(v17 >> 31);
    if ( (v17 & (v17 >> 31)) != 0 )
    {
      if ( (_DWORD)v19 == -22 )
        *((_DWORD *)v13 + 100) = 10;
      else
        printk(&unk_99D4, "charger_policy_parse_dt", v19, v18);
    }
    printk(&unk_A904, "charger_policy_parse_dt", *((unsigned int *)v13 + 100), v18);
    v20 = of_property_read_variable_u32_array(v11, "policy,expired-mode-enable", (char *)v13 + 388, 1, 0);
    v22 = v20 & (unsigned int)(v20 >> 31);
    if ( (v20 & (v20 >> 31)) != 0 )
    {
      if ( (_DWORD)v22 == -22 )
        *((_DWORD *)v13 + 97) = 1;
      else
        printk(&unk_92F2, "charger_policy_parse_dt", v22, v21);
    }
    printk(&unk_8F5A, "charger_policy_parse_dt", *((unsigned int *)v13 + 97), v21);
    v23 = of_property_read_variable_u32_array(v11, "policy,low-temp-enable", v13 + 49, 1, 0);
    v25 = v23 & (unsigned int)(v23 >> 31);
    if ( (v23 & (v23 >> 31)) != 0 )
    {
      if ( (_DWORD)v25 == -22 )
        *((_DWORD *)v13 + 98) = 0;
      else
        printk(&unk_A93A, "charger_policy_parse_dt", v25, v24);
    }
    printk(&unk_AF1B, "charger_policy_parse_dt", *((unsigned int *)v13 + 98), v24);
    v26 = of_property_read_variable_u32_array(v11, "policy,have-power-path", (char *)v13 + 396, 1, 0);
    v28 = v26 & (unsigned int)(v26 >> 31);
    if ( (v26 & (v26 >> 31)) != 0 )
    {
      if ( (_DWORD)v28 == -22 )
        *((_DWORD *)v13 + 99) = 1;
      else
        printk(&unk_A529, "charger_policy_parse_dt", v28, v27);
    }
    printk(&unk_A56B, "charger_policy_parse_dt", *((unsigned int *)v13 + 99), v27);
    v29 = of_property_read_variable_u32_array(v11, "policy,timeout-seconds", (char *)v13 + 404, 1, 0);
    v31 = v29 & (unsigned int)(v29 >> 31);
    if ( (v29 & (v29 >> 31)) != 0 )
    {
      if ( (_DWORD)v31 == -22 )
        *((_DWORD *)v13 + 101) = 86400;
      else
        printk(&unk_A7E0, "charger_policy_parse_dt", v31, v30);
    }
    printk(&unk_948D, "charger_policy_parse_dt", *((unsigned int *)v13 + 101), v30);
    v32 = of_property_read_variable_u32_array(v11, "policy,expired-max-capacity", v13 + 51, 1, 0);
    v34 = v32 & (unsigned int)(v32 >> 31);
    if ( (v32 & (v32 >> 31)) != 0 )
    {
      if ( (_DWORD)v34 == -22 )
        *((_DWORD *)v13 + 102) = 70;
      else
        printk(&unk_957D, "charger_policy_parse_dt", v34, v33);
    }
    printk(&unk_9F92, "charger_policy_parse_dt", *((unsigned int *)v13 + 102), v33);
    v35 = of_property_read_variable_u32_array(v11, "policy,expired-min-capacity", (char *)v13 + 412, 1, 0);
    v37 = v35 & (unsigned int)(v35 >> 31);
    if ( (v35 & (v35 >> 31)) != 0 )
    {
      if ( (_DWORD)v37 == -22 )
        *((_DWORD *)v13 + 103) = 50;
      else
        printk(&unk_9C73, "charger_policy_parse_dt", v37, v36);
    }
    printk(&unk_AAEF, "charger_policy_parse_dt", *((unsigned int *)v13 + 103), v36);
    v38 = of_property_read_variable_u32_array(v11, "policy,demo-max-capacity", v13 + 52, 1, 0);
    v40 = v38 & (unsigned int)(v38 >> 31);
    if ( (v38 & (v38 >> 31)) != 0 )
    {
      if ( (_DWORD)v40 == -22 )
        *((_DWORD *)v13 + 104) = 70;
      else
        printk(&unk_96B8, "charger_policy_parse_dt", v40, v39);
    }
    printk(&unk_94C7, "charger_policy_parse_dt", *((unsigned int *)v13 + 104), v39);
    v41 = of_property_read_variable_u32_array(v11, "policy,demo-min-capacity", (char *)v13 + 420, 1, 0);
    v43 = v41 & (unsigned int)(v41 >> 31);
    if ( (v41 & (v41 >> 31)) != 0 )
    {
      if ( (_DWORD)v43 == -22 )
        *((_DWORD *)v13 + 105) = 50;
      else
        printk(&unk_A5A5, "charger_policy_parse_dt", v43, v42);
    }
    printk(&unk_A41F, "charger_policy_parse_dt", *((unsigned int *)v13 + 105), v42);
    v44 = of_property_read_variable_u32_array(v11, "policy,no-powerpath-delta-capacity", v13 + 53, 1, 0);
    v46 = v44 & (unsigned int)(v44 >> 31);
    if ( (v44 & (v44 >> 31)) != 0 )
    {
      if ( (_DWORD)v46 == -22 )
        *((_DWORD *)v13 + 106) = 10;
      else
        printk(&unk_9B83, "charger_policy_parse_dt", v46, v45);
    }
    printk(&unk_9A12, "charger_policy_parse_dt", *((unsigned int *)v13 + 106), v45);
    string = of_property_read_string(v11, "policy,battery-phy-name", v13 + 55);
    if ( string == -22 )
    {
      v50 = "battery";
      v13[55] = "battery";
    }
    else
    {
      v49 = string;
      if ( string )
      {
        v53 = &unk_A2C5;
        goto LABEL_75;
      }
      v50 = (const char *)v13[55];
    }
    printk(&unk_9C16, "charger_policy_parse_dt", v50, v48);
    v51 = of_property_read_string(v11, "policy,zte-battery-phy-name", v13 + 56);
    if ( v51 == -22 )
    {
      v52 = "zte_battery";
      v13[56] = "zte_battery";
    }
    else
    {
      v49 = v51;
      if ( v51 )
      {
        v53 = &unk_96FC;
        goto LABEL_75;
      }
      v52 = (const char *)v13[56];
    }
    printk(&unk_9E31, "charger_policy_parse_dt", v52, v48);
    v54 = of_property_read_string(v11, "policy,zte-usb-phy-name", v13 + 57);
    if ( v54 == -22 )
    {
      v55 = "zte_usb";
      v13[57] = "zte_usb";
    }
    else
    {
      v49 = v54;
      if ( v54 )
      {
        v53 = &unk_A65B;
        goto LABEL_75;
      }
      v55 = (const char *)v13[57];
    }
    printk(&unk_9FD1, "charger_policy_parse_dt", v55, v48);
    v56 = of_property_read_string(v11, "policy,interface-phy-name", v13 + 54);
    if ( v56 == -22 )
    {
      v57 = "interface";
      v13[54] = "interface";
    }
    else
    {
      v49 = v56;
      if ( v56 )
      {
        v53 = &unk_974B;
        goto LABEL_75;
      }
      v57 = (const char *)v13[54];
    }
    printk(&unk_9A58, "charger_policy_parse_dt", v57, v48);
    v58 = of_property_read_string(v11, "policy,cas-phy-name", v13 + 58);
    if ( v58 == -22 )
    {
      v59 = "cas";
      v13[58] = "cas";
      goto LABEL_73;
    }
    v49 = v58;
    if ( !v58 )
    {
      v59 = (const char *)v13[58];
LABEL_73:
      printk(&unk_93F8, "charger_policy_parse_dt", v59, v48);
      goto LABEL_77;
    }
    v53 = &unk_9503;
LABEL_75:
    printk(v53, "charger_policy_parse_dt", v49, v48);
    if ( (v49 & 0x80000000) != 0 )
    {
      v62 = &unk_AC00;
LABEL_79:
      printk(v62, "charger_policy_probe", v60, v61);
      devm_kfree(*v13, v13);
      v9 = 0;
      v10 = &unk_91AD;
      goto LABEL_81;
    }
LABEL_77:
    if ( *v12 )
    {
      v13[34] = alloc_workqueue(&unk_9B64, 393226, 1, "policy_probe_wq");
      v13[35] = 0xFFFFFFFE00000LL;
      v13[36] = v13 + 36;
      v13[37] = v13 + 36;
      v13[38] = charger_policy_probe_work;
      init_timer_key(v13 + 39, &delayed_work_timer_fn, 0x200000, 0, 0);
      queue_delayed_work_on(32, v13[34], v13 + 35, 1250);
      v9 = 0;
      v10 = &unk_A7AB;
      goto LABEL_81;
    }
    v62 = &unk_998F;
    goto LABEL_79;
  }
  v9 = -12;
  v10 = &unk_AA9E;
LABEL_81:
  printk(v10, "charger_policy_probe", v6, v7);
  return v9;
}
