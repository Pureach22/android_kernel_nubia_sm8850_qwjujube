__int64 __fastcall ipa_pm_register(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  const char *v8; // x22
  __int64 v9; // x26
  __int64 v10; // x21
  unsigned __int64 v11; // x27
  const char *v13; // x23
  size_t v14; // x24
  size_t ep_reg_idx; // x0
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x8
  const char *v20; // x22
  unsigned __int64 v21; // x2
  __int64 v22; // x0
  __int64 v23; // x20
  __int64 v24; // x26
  __int64 v25; // x27
  __int64 v26; // x28
  __int64 v27; // x24
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  int ep_bit; // w24
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 ipc_logbuf; // x0
  __int64 v55; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x2

  if ( !ipa_pm_ctx )
  {
    v53 = printk(&unk_3F575E, "ipa_pm_register");
    ipc_logbuf = ipa3_get_ipc_logbuf(v53);
    if ( ipc_logbuf )
    {
      v55 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v55, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_register", 746);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v57 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v57, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_register", 746);
      goto LABEL_70;
    }
LABEL_71:
    LODWORD(v10) = -22;
    return (unsigned int)v10;
  }
  if ( !a1 || !a2 || !*(_QWORD *)a1 )
  {
    v43 = printk(&unk_3C724A, "ipa_pm_register");
    v44 = ipa3_get_ipc_logbuf(v43);
    if ( v44 )
    {
      v45 = ipa3_get_ipc_logbuf(v44);
      v44 = ipc_log_string(v45, "ipa_pm %s:%d Invalid Params\n", "ipa_pm_register", 751);
    }
    v46 = ipa3_get_ipc_logbuf_low(v44);
    if ( v46 )
    {
      v47 = ipa3_get_ipc_logbuf_low(v46);
      ipc_log_string(v47, "ipa_pm %s:%d Invalid Params\n", "ipa_pm_register", 751);
LABEL_70:
      LODWORD(v10) = -22;
      return (unsigned int)v10;
    }
    goto LABEL_71;
  }
  v4 = ipa3_get_ipc_logbuf(a1);
  if ( v4 )
  {
    v5 = ipa3_get_ipc_logbuf(v4);
    v4 = ipc_log_string(v5, "ipa_pm %s:%d IPA PM registering client\n", "ipa_pm_register", 755);
  }
  v6 = ipa3_get_ipc_logbuf_low(v4);
  if ( v6 )
  {
    v7 = ipa3_get_ipc_logbuf_low(v6);
    ipc_log_string(v7, "ipa_pm %s:%d IPA PM registering client\n", "ipa_pm_register", 755);
  }
  mutex_lock(ipa_pm_ctx + 1152);
  v8 = *(const char **)a1;
  v9 = ipa_pm_ctx;
  v10 = 4294967191LL;
  v11 = 35;
  do
  {
    v13 = *(const char **)(v9 + 8 * v11);
    if ( v13 )
    {
      v14 = strlen(v8);
      ep_reg_idx = strnlen(v13, 0x40u);
      if ( ep_reg_idx >= 0x41 )
        goto LABEL_89;
      if ( ep_reg_idx == 64 )
        goto LABEL_88;
      if ( v14 == ep_reg_idx && !strcmp(v8, v13) )
      {
        LODWORD(v10) = -17;
        *a2 = -17;
LABEL_62:
        mutex_unlock(v9 + 1152);
        v48 = printk(&unk_3BB668, "ipa_pm_register");
        v49 = ipa3_get_ipc_logbuf(v48);
        if ( v49 )
        {
          v50 = ipa3_get_ipc_logbuf(v49);
          v49 = ipc_log_string(
                  v50,
                  "ipa_pm %s:%d client already registered or full array elem=%d\n",
                  "ipa_pm_register",
                  764,
                  v10);
        }
        v51 = ipa3_get_ipc_logbuf_low(v49);
        if ( v51 )
        {
          v52 = ipa3_get_ipc_logbuf_low(v51);
          ipc_log_string(
            v52,
            "ipa_pm %s:%d client already registered or full array elem=%d\n",
            "ipa_pm_register",
            764,
            v10);
        }
        return (unsigned int)v10;
      }
    }
    else
    {
      v10 = (unsigned int)v11;
    }
  }
  while ( v11-- > 1 );
  *a2 = v10;
  if ( (unsigned int)v10 >= 0x25 )
    goto LABEL_62;
  ep_reg_idx = _kmalloc_cache_noprof(scnprintf, 3520, 280);
  v16 = *a2;
  if ( (unsigned int)v16 >= 0x24
    || (v17 = ipa_pm_ctx, *(_QWORD *)(ipa_pm_ctx + 8 * v16) = ep_reg_idx, v18 = *a2, (unsigned int)v18 > 0x23) )
  {
    while ( 1 )
    {
LABEL_91:
      __break(0x5512u);
LABEL_92:
      _fortify_panic(2, -1, ep_reg_idx + 1);
LABEL_93:
      _fortify_panic(7, 64, v21);
LABEL_94:
      v73 = v10 + 1;
LABEL_90:
      ep_reg_idx = _fortify_panic(2, 64, v73);
    }
  }
  v10 = *(_QWORD *)(v17 + 8 * v18);
  ep_reg_idx = mutex_unlock(v17 + 1152);
  if ( v10 )
  {
    v19 = *a2;
    if ( (unsigned int)v19 > 0x23 )
      goto LABEL_91;
    v10 = *(_QWORD *)(ipa_pm_ctx + 8 * v19);
    *(_DWORD *)(v10 + 100) = 0;
    *(_QWORD *)(v10 + 136) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v10 + 144) = v10 + 144;
    *(_QWORD *)(v10 + 152) = v10 + 144;
    *(_QWORD *)(v10 + 160) = delayed_deferred_deactivate_work_func;
    init_timer_key(v10 + 168, &delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v10 + 104) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v10 + 112) = v10 + 112;
    *(_QWORD *)(v10 + 120) = v10 + 112;
    *(_QWORD *)(v10 + 128) = activate_work_func;
    v20 = *(const char **)a1;
    ep_reg_idx = strnlen(*(const char **)a1, 0x40u);
    if ( ep_reg_idx == -1 )
      goto LABEL_92;
    if ( ep_reg_idx == 64 )
      v21 = 64;
    else
      v21 = ep_reg_idx + 1;
    if ( v21 >= 0x41 )
      goto LABEL_93;
    sized_strscpy(v10, v20);
    *(_QWORD *)(v10 + 64) = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(v10 + 72) = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(v10 + 88) = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(v10 + 92) = *a2;
    *(_BYTE *)(v10 + 84) = *(_BYTE *)(a1 + 28);
    v22 = wakeup_source_register(0, v10);
    *(_QWORD *)(v10 + 272) = v22;
    if ( v22 )
    {
      *(_DWORD *)(v10 + 240) = 0;
      _init_swait_queue_head(v10 + 248, "&x->wait", &init_completion___key_2);
      v23 = *a2;
      ep_reg_idx = mutex_lock(ipa_pm_ctx + 1152);
      if ( (unsigned int)v23 < 0x24 )
      {
        v24 = ipa_pm_ctx;
        ep_reg_idx = strnlen(*(const char **)(ipa_pm_ctx + 8 * v23), 0x40u);
        v10 = ep_reg_idx;
        if ( ep_reg_idx >= 0x41 )
          goto LABEL_94;
        if ( ep_reg_idx != 64 )
        {
          if ( *(int *)(v24 + 1116) < 1 )
          {
LABEL_48:
            v33 = ipa3_get_ipc_logbuf(ep_reg_idx);
            if ( v33 )
            {
              v34 = ipa3_get_ipc_logbuf(v33);
              v33 = ipc_log_string(
                      v34,
                      "ipa_pm %s:%d %s added to exception list\n",
                      "add_client_to_exception_list",
                      570,
                      *(const char **)(ipa_pm_ctx + 8 * v23));
            }
            v35 = ipa3_get_ipc_logbuf_low(v33);
            if ( v35 )
            {
              v36 = ipa3_get_ipc_logbuf_low(v35);
              ipc_log_string(
                v36,
                "ipa_pm %s:%d %s added to exception list\n",
                "add_client_to_exception_list",
                570,
                *(const char **)(ipa_pm_ctx + 8 * v23));
            }
            v37 = mutex_unlock(ipa_pm_ctx + 1152);
            v38 = ipa3_get_ipc_logbuf(v37);
            if ( v38 )
            {
              v39 = ipa3_get_ipc_logbuf(v38);
              v38 = ipc_log_string(
                      v39,
                      "ipa_pm %s:%d IPA PM client registered with handle %d\n",
                      "ipa_pm_register",
                      810,
                      *a2);
            }
            v40 = ipa3_get_ipc_logbuf_low(v38);
            if ( v40 )
            {
              v41 = ipa3_get_ipc_logbuf_low(v40);
              ipc_log_string(v41, "ipa_pm %s:%d IPA PM client registered with handle %d\n", "ipa_pm_register", 810, *a2);
            }
            LODWORD(v10) = 0;
            return (unsigned int)v10;
          }
          v25 = 0;
          v26 = 656;
          while ( 1 )
          {
            if ( v25 == 6 )
              goto LABEL_91;
            ep_reg_idx = strnstr(v24 + v26 - 68, *(_QWORD *)(v24 + 8 * v23), v10);
            if ( ep_reg_idx )
            {
              ep_reg_idx = strnlen((const char *)(v24 + v26 - 68), 0x40u);
              if ( ep_reg_idx >= 0x41 )
                goto LABEL_89;
              if ( ep_reg_idx == 64 )
                break;
              if ( ep_reg_idx == v10 )
              {
                v27 = v24 + v26;
                --*(_DWORD *)(v24 + v26 - 4);
                v28 = ipa3_get_ipc_logbuf(ep_reg_idx);
                if ( v28 )
                {
                  v29 = ipa3_get_ipc_logbuf(v28);
                  v28 = ipc_log_string(
                          v29,
                          "ipa_pm %s:%d Pending: %d\n",
                          "add_client_to_exception_list",
                          557,
                          *(_DWORD *)(v27 - 4));
                }
                v30 = ipa3_get_ipc_logbuf_low(v28);
                if ( v30 )
                {
                  v31 = ipa3_get_ipc_logbuf_low(v30);
                  ipc_log_string(
                    v31,
                    "ipa_pm %s:%d Pending: %d\n",
                    "add_client_to_exception_list",
                    557,
                    *(_DWORD *)(v27 - 4));
                }
                if ( (*(_DWORD *)(v27 - 4) & 0x80000000) != 0 )
                {
                  __break(0x800u);
                  *(_DWORD *)(v24 + v26 - 4) = 0;
                  mutex_unlock(ipa_pm_ctx + 1152);
                  ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*a2);
                  v68 = printk(&unk_3A3D85, "ipa_pm_register");
                  v69 = ipa3_get_ipc_logbuf(v68);
                  if ( v69 )
                  {
                    v70 = ipa3_get_ipc_logbuf(v69);
                    v69 = ipc_log_string(
                            v70,
                            "ipa_pm %s:%d Fail to add client to exception_list\n",
                            "ipa_pm_register",
                            806);
                  }
                  v71 = ipa3_get_ipc_logbuf_low(v69);
                  if ( v71 )
                  {
                    v72 = ipa3_get_ipc_logbuf_low(v71);
                    ipc_log_string(v72, "ipa_pm %s:%d Fail to add client to exception_list\n", "ipa_pm_register", 806);
                  }
                  LODWORD(v10) = -1;
                  return (unsigned int)v10;
                }
                ep_bit = ipahal_get_ep_bit((unsigned int)v23);
                ep_reg_idx = ipahal_get_ep_reg_idx((unsigned int)v23);
                if ( (unsigned int)ep_reg_idx > 1 )
                  goto LABEL_91;
                *(_DWORD *)(v24 + 4LL * (unsigned int)ep_reg_idx + v26) |= ep_bit;
              }
            }
            v24 = ipa_pm_ctx;
            ++v25;
            v26 += 96;
            if ( v25 >= *(int *)(ipa_pm_ctx + 1116) )
              goto LABEL_48;
          }
        }
LABEL_88:
        ep_reg_idx = _fortify_panic(4, 64, 65);
LABEL_89:
        v73 = ep_reg_idx + 1;
        goto LABEL_90;
      }
      goto LABEL_91;
    }
    v63 = printk(&unk_3FB7FF, "ipa_pm_register");
    v64 = ipa3_get_ipc_logbuf(v63);
    if ( v64 )
    {
      v65 = ipa3_get_ipc_logbuf(v64);
      v64 = ipc_log_string(
              v65,
              "ipa_pm %s:%d IPA wakeup source register failed %s\n",
              "ipa_pm_register",
              796,
              (const char *)v10);
    }
    v66 = ipa3_get_ipc_logbuf_low(v64);
    if ( v66 )
    {
      v67 = ipa3_get_ipc_logbuf_low(v66);
      ipc_log_string(
        v67,
        "ipa_pm %s:%d IPA wakeup source register failed %s\n",
        "ipa_pm_register",
        796,
        (const char *)v10);
    }
    ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*a2);
    LODWORD(v10) = -12;
  }
  else
  {
    v58 = printk(&unk_3E3F71, "ipa_pm_register");
    v59 = ipa3_get_ipc_logbuf(v58);
    if ( v59 )
    {
      v60 = ipa3_get_ipc_logbuf(v59);
      v59 = ipc_log_string(v60, "ipa_pm %s:%d :kzalloc err.\n", "ipa_pm_register", 772);
    }
    v61 = ipa3_get_ipc_logbuf_low(v59);
    if ( v61 )
    {
      v62 = ipa3_get_ipc_logbuf_low(v61);
      ipc_log_string(v62, "ipa_pm %s:%d :kzalloc err.\n", "ipa_pm_register", 772);
    }
    LODWORD(v10) = -12;
  }
  return (unsigned int)v10;
}
