__int64 __fastcall zte_misc_probe(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 node_opts_by_path; // x0
  __int64 v5; // x2
  void *v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x20
  __int64 result; // x0
  char *v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  _BOOL8 v15; // x1
  __int64 next_child; // x0
  __int64 v17; // x2
  __int64 v18; // x21
  unsigned int v19; // w27
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 property; // x0
  __int64 v23; // x0
  char *v24; // x28
  unsigned int named_gpio; // w0
  __int64 v26; // x2
  char *haystack; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v28[17]; // [xsp+8h] [xbp-88h] BYREF

  v28[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_7F2F, "zte_misc_probe", a3);
  haystack = nullptr;
  memset(v28, 0, 128);
  node_opts_by_path = of_find_node_opts_by_path("/chosen", 0);
  if ( node_opts_by_path )
  {
    if ( (of_property_read_string(node_opts_by_path, "bootargs", &haystack) & 0x80000000) == 0 )
    {
      v11 = strstr(haystack, "kmparam.mode=");
      if ( v11 )
      {
        sscanf(v11, "kmparam.mode=%s", v28);
        v15 = LODWORD(v28[0]) == 1918986339 && *(_DWORD *)((char *)v28 + 3) == 1919248242;
        zte_poweroff_charging_param = v15;
        printk(&unk_7E60, v15, v28);
      }
      else
      {
        printk(&unk_7C3E, v12, v13);
      }
      goto LABEL_6;
    }
    v6 = &unk_7E02;
  }
  else
  {
    v6 = &unk_7D98;
  }
  printk(v6, "zte_poweroff_charging_handle_init", v5);
LABEL_6:
  printk(&unk_7EA9, v7, v8);
  v9 = *(_QWORD *)(a1 + 760);
  if ( !v9 )
  {
    result = 4294967277LL;
    goto LABEL_8;
  }
  next_child = of_get_next_child(*(_QWORD *)(a1 + 760), 0);
  if ( !next_child )
    goto LABEL_28;
  v18 = next_child;
  v19 = -1;
  while ( !of_find_property(v18, "label", 0) )
  {
    dev_warn(a1 + 16, "Found without labels\n");
LABEL_21:
    v18 = of_get_next_child(v9, v18);
    if ( !v18 )
      goto LABEL_28;
  }
  if ( v19 != 15 )
  {
    ++v19;
    property = of_get_property(v18, "label", 0);
    v23 = kstrdup(property, 3264);
    if ( ((16LL * v19) | 8uLL) > 0x100
      || (v24 = (char *)&zte_gpios + 16 * v19,
          *((_QWORD *)v24 + 1) = v23,
          named_gpio = of_get_named_gpio(v18, "zte-misc", 0),
          v19 == 16) )
    {
      __break(1u);
    }
    v26 = *((_QWORD *)v24 + 1);
    *(_DWORD *)v24 = named_gpio;
    printk(&unk_7C63, named_gpio, v26);
    goto LABEL_21;
  }
  printk(&unk_7EE3, v20, v21);
LABEL_28:
  printk(&unk_7E4D, "zte_misc_probe", v17);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
