__int64 __fastcall gpr_probe(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w0
  unsigned int variable_u32_array; // w0
  __int64 v9; // x25
  __int64 next_child; // x0
  _QWORD *v11; // x2
  int v12; // w3
  unsigned int v13; // w20
  const char **v14; // x20
  __int64 v15; // x23
  __int64 v16; // x0
  __int64 v17; // x24
  __int16 v18; // w8
  int v19; // w10
  const char *v20; // x28
  size_t v21; // x0
  unsigned __int64 v22; // x2
  int v23; // w0
  int v24; // w28
  const char *v25; // x2
  int v26; // [xsp+30h] [xbp-20h]
  unsigned int v27; // [xsp+34h] [xbp-1Ch] BYREF
  __int64 v28; // [xsp+38h] [xbp-18h]
  __int64 v29; // [xsp+40h] [xbp-10h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (audio_notifier_probe_status() & 1) == 0 )
  {
    printk(&unk_7385, "gpr_probe");
    result = 4294966779LL;
    goto LABEL_4;
  }
  v2 = devm_kmalloc(a1, 104, 3520);
  gpr_priv = v2;
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_4;
  }
  *(_DWORD *)(v2 + 16) = 0;
  _mutex_init(&unk_7178, "&q6.lock", &gpr_probe___key);
  raw_spin_lock(gpr_priv + 16);
  v4 = gpr_priv + 16;
  *(_BYTE *)(gpr_priv + 20) = 1;
  raw_spin_unlock(v4);
  v5 = gpr_priv;
  v6 = a1[121];
  a1[19] = gpr_priv;
  *(_QWORD *)v5 = v6;
  *(_QWORD *)(v5 + 8) = a1;
  *(_DWORD *)(v5 + 24) = 0;
  *(_QWORD *)(v5 + 32) = 0x1000000400000000LL;
  *(_QWORD *)(v5 + 40) = 0;
  *(_QWORD *)(v5 + 48) = 0;
  v7 = snd_event_client_register(a1, &gpr_ssr_ops, 0);
  if ( v7 )
    dev_err(a1, "%s: Registration with SND event fwk failed ret = %d\n", "gpr_probe", v7);
  variable_u32_array = of_property_read_variable_u32_array(a1[93], "reg", gpr_priv + 56, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v13 = variable_u32_array;
    dev_err(a1, "GPR Domain ID not specified in DT\n");
    result = v13;
    goto LABEL_4;
  }
  v9 = a1[19];
  next_child = of_get_next_child(a1[93], 0);
  if ( next_child )
  {
    v14 = (const char **)next_child;
    _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v28 = 0;
      v29 = 0;
      v27 = 0;
      if ( (of_property_read_variable_u32_array(v14, "reg", &v27, 1, 0) & 0x80000000) == 0 )
      {
        v15 = a1[19];
        v26 = *(_DWORD *)(v9 + 56);
        v16 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 976);
        v17 = v16;
        if ( !v16 )
          goto LABEL_15;
        v18 = v27;
        v19 = v28;
        *(_DWORD *)(v16 + 952) = 0;
        *(_WORD *)(v16 + 912) = v18;
        *(_WORD *)(v16 + 914) = v26;
        *(_DWORD *)(v16 + 916) = v19;
        v20 = *v14;
        v21 = strnlen(*v14, 0x20u);
        if ( v21 == -1 )
          goto LABEL_34;
        if ( v21 == 32 )
          v22 = 32;
        else
          v22 = v21 + 1;
        if ( v22 >= 0x21 )
        {
          _fortify_panic(7, 32);
LABEL_34:
          _fortify_panic(2, -1);
        }
        sized_strscpy(v17 + 920, v20);
        dev_set_name(v17, "gprsvc:%s:%x:%x", (const char *)(v17 + 920), v26, v27);
        *(_QWORD *)(v17 + 808) = gpr_dev_release;
        *(_QWORD *)(v17 + 96) = a1;
        *(_QWORD *)(v17 + 744) = v14;
        *(_QWORD *)(v17 + 128) = &gprbus;
        *(_QWORD *)(v17 + 136) = 0;
        raw_spin_lock(v15 + 24);
        idr_alloc(v15 + 32, v17, v27, v27 + 1, 2080);
        raw_spin_unlock(v15 + 24);
        if ( (unsigned int)__ratelimit(&gpr_add_device__rs, "gpr_add_device") )
        {
          v25 = *(const char **)(v17 + 112);
          if ( !v25 )
            v25 = *(const char **)v17;
          dev_info(a1, "Adding GPR dev: %s\n", v25);
        }
        v23 = device_register(v17);
        if ( v23 )
          break;
      }
LABEL_17:
      v14 = (const char **)of_get_next_child(a1[93], v14);
      if ( !v14 )
        goto LABEL_10;
    }
    v24 = v23;
    if ( (unsigned int)__ratelimit(&gpr_add_device__rs_32, "gpr_add_device") )
      dev_err(a1, "device_register failed: %d\n", v24);
    put_device(v17);
LABEL_15:
    if ( (unsigned int)__ratelimit(&of_register_gpr_devices__rs, "of_register_gpr_devices") )
      dev_err(a1, "Failed to add gpr %d svc\n", v27);
    goto LABEL_17;
  }
LABEL_10:
  v11 = (_QWORD *)gpr_priv;
  *(_QWORD *)(gpr_priv + 64) = 0xFFFFFFFE00000LL;
  v11 += 8;
  v11[1] = v11 + 1;
  v11[2] = v11 + 1;
  v12 = *((_DWORD *)v11 - 2);
  v11[3] = gpr_notifier_register;
  if ( (unsigned int)(v12 - 1) > 1 )
  {
    dev_err(a1, "%s: invalid dest_domain_id %d\n", "gpr_probe", v12);
    result = 4294967274LL;
  }
  else
  {
    queue_work_on(32, system_wq);
    *(_QWORD *)(gpr_priv + 96) = wakeup_source_register(*(_QWORD *)(gpr_priv + 8), "audio-gpr");
    dev_info(a1, "%s: gpr-lite probe success\n", "gpr_probe");
    result = 0;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
