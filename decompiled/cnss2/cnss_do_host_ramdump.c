__int64 __fastcall cnss_do_host_ramdump(__int64 a1, __int64 a2, __int64 a3)
{
  void *v5; // x0
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x22
  __int64 v11; // x6
  __int64 v12; // x7
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  unsigned __int64 v15; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  unsigned int v19; // w20
  const char *v20; // x1
  __int64 v21; // x24
  _DWORD *v22; // x21
  _QWORD *v23; // x0
  __int64 v24; // x7
  _QWORD *v25; // x26
  __int64 v26; // x22
  __int64 v27; // x27
  __int64 v28; // x8
  __int64 v29; // x9
  _QWORD *v30; // x1
  _QWORD *v31; // x0
  __int64 v32; // x7
  __int64 v33; // x8
  _QWORD *v34; // x2
  bool v35; // w8
  __int16 v36; // w9
  const char *v37; // x8
  unsigned __int64 v38; // x19
  __int64 v39; // x21
  unsigned __int64 v40; // x8
  const char *v41; // x1
  __int16 v42; // w9
  const char *v43; // x8
  unsigned __int64 v44; // x8
  const char *v45; // x1
  __int16 v46; // w9
  const char *v47; // x8
  _QWORD *i; // x0
  _QWORD *v49; // x8
  __int64 v50; // x9
  _QWORD *v51; // x9
  __int64 v52; // x7
  unsigned __int64 v53; // x8
  const char *v54; // x1
  __int16 v55; // w9
  const char *v56; // x8
  char v58; // [xsp+0h] [xbp-5B0h]
  __int64 v59; // [xsp+8h] [xbp-5A8h]
  __int64 v60; // [xsp+10h] [xbp-5A0h]
  unsigned __int64 v61; // [xsp+18h] [xbp-598h]
  _QWORD *v63; // [xsp+28h] [xbp-588h] BYREF
  _QWORD **v64; // [xsp+30h] [xbp-580h]
  _QWORD s[175]; // [xsp+38h] [xbp-578h] BYREF

  s[173] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = memset(s, 0, 0x568u);
  v63 = nullptr;
  v64 = nullptr;
  if ( (dump_enabled(v5) & 1) != 0 )
  {
    v10 = _kmalloc_cache_noprof(memcpy, 3520, 912);
    if ( v10 )
    {
      while ( 1 )
      {
        *(_QWORD *)(v10 + 808) = cnss_host_ramdump_dev_release;
        device_initialize(v10);
        dev_set_name(v10, "wlan_driver");
        if ( (unsigned int)device_add(v10) )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v14 = "irq";
          }
          else
          {
            v36 = *(_DWORD *)(StatusReg + 16);
            v37 = (const char *)(StatusReg + 2320);
            if ( (v36 & 0xFF00) != 0 )
              v14 = "soft_irq";
            else
              v14 = v37;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v14,
            "cnss_do_host_ramdump",
            3u,
            3u,
            "Failed to add new device\n",
            v11,
            v12,
            v58);
          v19 = 0;
          goto LABEL_65;
        }
        v59 = a1;
        v60 = v10;
        v63 = &v63;
        v64 = &v63;
        if ( !a3 )
          break;
        a1 = 0;
        v61 = _ReadStatusReg(SP_EL0);
        while ( a1 != 114 )
        {
          v21 = 12 * a1;
          if ( (unsigned __int64)(12 * a1 - 1368) < 0xFFFFFFFFFFFFFA98LL )
            goto LABEL_43;
          v22 = (_DWORD *)((char *)&s[2] + v21);
          *((_DWORD *)&s[2] + 3 * a1) = -1;
          v23 = (_QWORD *)_kmalloc_cache_noprof(of_get_property, 3520, 40);
          v25 = v23;
          if ( v23 )
          {
            v26 = 0;
            v27 = a2 + 48 * a1;
            v28 = *(_QWORD *)(v27 + 32);
            v29 = *(_QWORD *)(v27 + 40);
            v23[2] = v28;
            v23[3] = v28;
            v23[4] = v29;
            do
            {
              if ( !strcmp((const char *)v27, cnss_do_host_ramdump_wlan_str[v26]) )
                *v22 = v26;
              ++v26;
            }
            while ( v26 != 114 );
            if ( (unsigned __int64)(v21 - 1364) < 0xFFFFFFFFFFFFFA98LL
              || (++a1, v22[1] = a1, (unsigned __int64)(v21 - 1360) < 0xFFFFFFFFFFFFFA98LL) )
            {
LABEL_43:
              __break(1u);
              break;
            }
            v30 = v64;
            ++v22[2];
            if ( v30 == v25 || (_QWORD **)*v30 != &v63 )
            {
              _list_add_valid_or_report(v25, v30);
            }
            else
            {
              v64 = (_QWORD **)v25;
              *v25 = &v63;
              v25[1] = v30;
              *v30 = v25;
            }
          }
          else
          {
            v20 = "irq";
            if ( (*(_DWORD *)(v61 + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(v61 + 16) & 0xFF00) != 0 )
                v20 = "soft_irq";
              else
                v20 = (const char *)(v61 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v20,
              "cnss_do_host_ramdump",
              3u,
              3u,
              "Failed to alloc seg entry %d\n",
              (unsigned int)a1++,
              v24,
              v58);
          }
          if ( a1 == a3 )
            goto LABEL_33;
        }
        __break(0x5512u);
        v38 = _ReadStatusReg(SP_EL0);
        v39 = *(_QWORD *)(v38 + 80);
        *(_QWORD *)(v38 + 80) = &cnss_do_host_ramdump__alloc_tag;
        v10 = _kmalloc_cache_noprof(memcpy, 3520, 912);
        *(_QWORD *)(v38 + 80) = v39;
        if ( !v10 )
          goto LABEL_45;
      }
LABEL_33:
      v31 = (_QWORD *)_kmalloc_cache_noprof(of_get_property, 3520, 40);
      v10 = v60;
      if ( v31 )
      {
        v33 = *(_QWORD *)(v59 + 528);
        v34 = v63;
        v31[4] = 1384;
        s[1] = __PAIR64__(a3, v33);
        v31[2] = s;
        v31[3] = s;
        v35 = v34[1] == (_QWORD)&v63;
        s[0] = 1464615246;
        if ( v34 == v31 || !v35 )
        {
          _list_add_valid_or_report(v31, &v63);
        }
        else
        {
          v34[1] = v31;
          *v31 = v34;
          v31[1] = &v63;
          v63 = v31;
        }
        v19 = qcom_elf_dump(&v63, v60, 2);
      }
      else
      {
        v44 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v44 + 16) & 0xF0000) != 0 )
        {
          v45 = "irq";
        }
        else
        {
          v46 = *(_DWORD *)(v44 + 16);
          v47 = (const char *)(v44 + 2320);
          if ( (v46 & 0xFF00) != 0 )
            v45 = "soft_irq";
          else
            v45 = v47;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v45,
          "cnss_do_host_ramdump",
          3u,
          3u,
          "%s: Failed to allocate mem for host dump seg\n",
          (__int64)"cnss_do_host_ramdump",
          v32,
          v58);
        v19 = 0;
      }
      for ( i = v63; v63 != &v63; i = v63 )
      {
        v49 = (_QWORD *)i[1];
        if ( (_QWORD *)*v49 == i && (v50 = *i, *(_QWORD **)(*i + 8LL) == i) )
        {
          *(_QWORD *)(v50 + 8) = v49;
          *v49 = v50;
        }
        else
        {
          _list_del_entry_valid_or_report();
          i = v51;
        }
        *i = 0xDEAD000000000100LL;
        i[1] = 0xDEAD000000000122LL;
        kfree(i);
      }
      device_del(v60);
LABEL_65:
      put_device(v10);
      v53 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v53 + 16) & 0xF0000) != 0 )
      {
        v54 = "irq";
      }
      else
      {
        v55 = *(_DWORD *)(v53 + 16);
        v56 = (const char *)(v53 + 2320);
        if ( (v55 & 0xFF00) != 0 )
          v54 = "soft_irq";
        else
          v54 = v56;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v54,
        "cnss_do_host_ramdump",
        7u,
        7u,
        "host ramdump result %d\n",
        v19,
        v52,
        v58);
    }
    else
    {
LABEL_45:
      v40 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v40 + 16) & 0xF0000) != 0 )
      {
        v41 = "irq";
      }
      else
      {
        v42 = *(_DWORD *)(v40 + 16);
        v43 = (const char *)(v40 + 2320);
        if ( (v42 & 0xFF00) != 0 )
          v41 = "soft_irq";
        else
          v41 = v43;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v41,
        "cnss_do_host_ramdump",
        3u,
        3u,
        "Failed to alloc device mem\n",
        v8,
        v9,
        v58);
      v19 = -12;
    }
  }
  else
  {
    v15 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v15 + 16);
      v18 = (const char *)(v15 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_do_host_ramdump",
      6u,
      6u,
      "Dump collection is not enabled\n",
      v6,
      v7,
      v58);
    v19 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v19;
}
