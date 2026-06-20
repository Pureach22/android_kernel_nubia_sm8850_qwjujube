__int64 __fastcall _zte_power_supply_register(__int64 a1, const char **a2, _QWORD *a3, char a4)
{
  const char *v4; // x8
  const char *v5; // x9
  unsigned __int64 v6; // x11
  int v7; // w10
  __int64 v8; // x23
  unsigned __int64 *v9; // x19
  const char **v10; // x22
  char v11; // w21
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 v14; // x9
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  const char **v18; // x20
  _QWORD *v19; // x21
  char v20; // w22
  void *v22; // x10
  unsigned __int64 v23; // x9
  int inited; // w19
  int v25; // w0
  __int64 v26; // x1
  unsigned int v33; // w10

  if ( !a1 )
  {
    v18 = a2;
    v19 = a3;
    v20 = a4;
    printk(&unk_9645, "__zte_power_supply_register", *a2);
    a1 = 0;
    a3 = v19;
    a2 = v18;
    a4 = v20;
    if ( v18 )
      goto LABEL_3;
    return -22;
  }
  if ( !a2 )
    return -22;
LABEL_3:
  if ( !*a2 )
    return -22;
  v4 = a2[4];
  if ( !v4 )
    return -22;
  v5 = a2[5];
  if ( !v5 )
    return -22;
  v6 = 0;
  v7 = 1;
  do
  {
    if ( *(_DWORD *)&v4[4 * v6] == 65 && (!a2[2] || !a2[3]) )
      return -22;
    v6 = v7++;
  }
  while ( (unsigned __int64)v5 > v6 );
  v8 = a1;
  v9 = a3;
  v10 = a2;
  v11 = a4;
  v12 = _kmalloc_cache_noprof(dev_info, 3520, 1216);
  if ( !v12 )
    return -12;
  v13 = v12;
  device_initialize(v12 + 56);
  v14 = zte_power_supply_class;
  *(_QWORD *)(v13 + 176) = &zte_power_supply_dev_type;
  *(_QWORD *)(v13 + 152) = v8;
  *(_QWORD *)(v13 + 864) = zte_power_supply_dev_release;
  *(_QWORD *)(v13 + 848) = v14;
  *(_QWORD *)(v13 + 208) = v13;
  *(_QWORD *)v13 = v10;
  if ( v9 )
  {
    v15 = v9[2];
    v16 = v9[1];
    *(_QWORD *)(v13 + 856) = v9[3];
    *(_QWORD *)(v13 + 48) = v15;
    if ( v16 )
    {
      if ( v16 <= 0xFFFFFFFFFFFFF000LL )
      {
        v22 = *(void **)(v16 + 8);
        v17 = v16 - 24;
        if ( v22 != &of_fwnode_ops )
          v17 = 0;
      }
      else
      {
        v17 = 0;
      }
    }
    else
    {
      v17 = *v9;
    }
    *(_QWORD *)(v13 + 40) = v17;
    v23 = v9[5];
    *(_QWORD *)(v13 + 8) = v9[4];
    *(_QWORD *)(v13 + 16) = v23;
  }
  inited = dev_set_name(v13 + 56, "%s", *v10);
  if ( inited )
  {
LABEL_30:
    put_device(v13 + 56);
    return inited;
  }
  *(_QWORD *)(v13 + 968) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v13 + 976) = v13 + 976;
  *(_QWORD *)(v13 + 984) = v13 + 976;
  *(_QWORD *)(v13 + 1000) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v13 + 992) = zte_power_supply_changed_work;
  *(_QWORD *)(v13 + 1008) = v13 + 1008;
  *(_QWORD *)(v13 + 1016) = v13 + 1008;
  *(_QWORD *)(v13 + 1024) = zte_power_supply_deferred_register_work;
  init_timer_key(v13 + 1032, &delayed_work_timer_fn, 0x200000, 0, 0);
  v25 = zte_power_supply_check_supplies(v13);
  if ( v25 )
  {
    inited = v25;
    dev_info(v13 + 56, "Not all required supplies found, defer probe\n");
    goto LABEL_30;
  }
  *(_DWORD *)(v13 + 1104) = 0;
  inited = device_add(v13 + 56);
  if ( inited )
    goto LABEL_30;
  inited = device_init_wakeup(v13 + 56, v11 & 1);
  if ( inited )
    goto LABEL_30;
  _X9 = (unsigned int *)(v13 + 1112);
  __asm { PRFM            #0x11, [X9] }
  do
    v33 = __ldxr(_X9);
  while ( __stxr(v33 + 1, _X9) );
  v26 = system_power_efficient_wq;
  *(_BYTE *)(v13 + 1109) = 1;
  queue_delayed_work_on(32, v26, v13 + 1000, 3);
  return v13;
}
