__int64 __fastcall icnss_do_host_ramdump(__int64 a1, __int64 a2, __int64 a3)
{
  void *v5; // x0
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x23
  __int64 v9; // x24
  unsigned int *v10; // x26
  _QWORD *v11; // x0
  _QWORD *v12; // x27
  unsigned int v13; // w28
  __int64 v14; // x25
  __int64 v15; // x8
  __int64 v16; // x9
  const char *wlan_str; // x0
  _QWORD *v18; // x1
  _QWORD *v19; // x0
  _QWORD *v20; // x2
  __int64 v21; // x10
  bool v22; // w8
  unsigned int v23; // w20
  _QWORD *i; // x0
  _QWORD *v25; // x8
  __int64 v26; // x9
  _QWORD *v27; // x9
  __int64 v29; // [xsp+18h] [xbp-598h]
  _QWORD *v31; // [xsp+28h] [xbp-588h] BYREF
  _QWORD **v32; // [xsp+30h] [xbp-580h]
  _QWORD s[175]; // [xsp+38h] [xbp-578h] BYREF

  s[173] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = memset(s, 0, 0x568u);
  v31 = nullptr;
  v32 = nullptr;
  if ( (dump_enabled(v5) & 1) != 0 )
  {
    v6 = _kmalloc_cache_noprof(kfree, 3520, 912);
    v7 = v6;
    if ( v6 )
    {
      *(_QWORD *)(v6 + 808) = icnss_host_ramdump_dev_release;
      device_initialize(v6);
      dev_set_name(v7, "wlan_driver");
      if ( (unsigned int)device_add(v7) )
      {
        printk("%sicnss2: Failed to add new device\n", byte_130B32);
        ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to add new device\n", (const char *)&unk_12DBF3);
        v23 = 0;
      }
      else
      {
        v29 = v7;
        v31 = &v31;
        v32 = &v31;
        if ( a3 )
        {
          v8 = 0;
          _ReadStatusReg(SP_EL0);
          do
          {
            if ( v8 == 114 )
              goto LABEL_41;
            v9 = 12 * v8;
            if ( (unsigned __int64)(12 * v8 - 1368) < 0xFFFFFFFFFFFFFA98LL )
              goto LABEL_40;
            v10 = (unsigned int *)((char *)&s[2] + v9);
            *((_DWORD *)&s[2] + 3 * v8) = -1;
            v11 = (_QWORD *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 40);
            v12 = v11;
            if ( v11 )
            {
              v13 = 0;
              v14 = a2 + 48 * v8;
              v15 = *(_QWORD *)(v14 + 32);
              v16 = *(_QWORD *)(v14 + 40);
              v11[2] = v15;
              v11[3] = v15;
              v11[4] = v16;
              do
              {
                wlan_str = icnss_get_wlan_str(v13);
                if ( !strcmp((const char *)(a2 + 48 * v8), wlan_str) )
                  *v10 = v13;
                ++v13;
              }
              while ( v13 != 114 );
              if ( (unsigned __int64)(v9 - 1364) < 0xFFFFFFFFFFFFFA98LL
                || (++v8, v10[1] = v8, (unsigned __int64)(v9 - 1360) < 0xFFFFFFFFFFFFFA98LL) )
              {
LABEL_40:
                __break(1u);
LABEL_41:
                __break(0x5512u);
              }
              v18 = v32;
              ++v10[2];
              if ( v18 == v12 || (_QWORD **)*v18 != &v31 )
              {
                _list_add_valid_or_report(v12, v18);
              }
              else
              {
                v32 = (_QWORD **)v12;
                *v12 = &v31;
                v12[1] = v18;
                *v18 = v12;
              }
            }
            else
            {
              printk("%sicnss2: Failed to alloc seg entry %d\n", byte_130B32, v8);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: Failed to alloc seg entry %d\n",
                (const char *)&unk_12DBF3,
                v8++);
            }
          }
          while ( v8 != a3 );
        }
        v19 = (_QWORD *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 40);
        v7 = v29;
        if ( v19 )
        {
          v20 = v31;
          v21 = *(_QWORD *)(a1 + 304);
          v19[2] = s;
          v19[3] = s;
          s[1] = __PAIR64__(a3, v21);
          v19[4] = 1384;
          v22 = v20[1] == (_QWORD)&v31;
          s[0] = 1464615246;
          if ( v20 == v19 || !v22 )
          {
            _list_add_valid_or_report(v19, &v31);
          }
          else
          {
            v20[1] = v19;
            *v19 = v20;
            v19[1] = &v31;
            v31 = v19;
          }
          v23 = qcom_elf_dump(&v31, v29, 2);
        }
        else
        {
          printk("%sicnss2: %s: Failed to allocate mem for host dump seg\n", byte_130B32, "icnss_do_host_ramdump");
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: %s: Failed to allocate mem for host dump seg\n",
            (const char *)&unk_12DBF3,
            "icnss_do_host_ramdump");
          v23 = 0;
        }
        for ( i = v31; v31 != &v31; i = v31 )
        {
          v25 = (_QWORD *)i[1];
          if ( (_QWORD *)*v25 == i && (v26 = *i, *(_QWORD **)(*i + 8LL) == i) )
          {
            *(_QWORD *)(v26 + 8) = v25;
            *v25 = v26;
          }
          else
          {
            _list_del_entry_valid_or_report();
            i = v27;
          }
          *i = 0xDEAD000000000100LL;
          i[1] = 0xDEAD000000000122LL;
          kfree(i);
        }
        device_del(v29);
      }
      put_device(v7);
      ipc_log_string(icnss_ipc_log_context, "icnss2: host ramdump result %d\n", v23);
    }
    else
    {
      printk("%sicnss2: Failed to alloc device mem\n", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to alloc device mem\n", (const char *)&unk_12DBF3);
      v23 = -12;
    }
  }
  else
  {
    printk("%sicnss2: Dump collection is not enabled\n", byte_13289B);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Dump collection is not enabled\n", (const char *)&unk_12DBF3);
    v23 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
