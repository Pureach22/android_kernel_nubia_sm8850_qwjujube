__int64 ipa3_perform_loopback()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  unsigned int ep_mapping; // w0
  unsigned int v4; // w19
  __int64 v5; // x19
  __int64 v6; // x20
  size_t v7; // x0
  unsigned __int64 v8; // x2
  int v9; // w24
  int v10; // w21
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v34; // x21
  __int64 (__fastcall *v35)(_QWORD); // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  int v41; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v42[4]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v43; // [xsp+30h] [xbp-10h]
  __int64 v44; // [xsp+38h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  memset(v42, 0, sizeof(v42));
  v41 = 0;
  printk(&unk_3C985C, "ipa3_perform_loopback");
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Adding rules to perform loopback on IPA\n", "ipa3_perform_loopback", 3448);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d Adding rules to perform loopback on IPA\n", "ipa3_perform_loopback", 3448);
      v0 = ipa3_ctx;
    }
  }
  *(_BYTE *)(v0 + 32262) = 0;
  ep_mapping = ipa_get_ep_mapping(34);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3C9891, "ipa3_perform_loopback");
    v23 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_70;
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d failed to get idx", "ipa3_perform_loopback", 3455);
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d failed to get idx", "ipa3_perform_loopback", 3455);
      result = -1;
    }
    else
    {
LABEL_70:
      result = -1;
    }
  }
  else
  {
    if ( ep_mapping >= 0x24 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v34 = *(_QWORD *)(StatusReg + 80);
      v35 = raw_spin_lock_irqsave;
      *(_QWORD *)(StatusReg + 80) = &ipa3_perform_loopback__alloc_tag;
      v5 = _kmalloc_cache_noprof(v35, 3520, 224);
      *(_QWORD *)(StatusReg + 80) = v34;
      if ( v5 )
      {
LABEL_9:
        v6 = _kmalloc_cache_noprof(scnprintf, 3520, 388);
        if ( !v6 )
        {
          printk(&unk_3CF6DE, "ipa3_perform_loopback");
          v38 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v39 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v39 )
            {
              ipc_log_string(v39, "ipa %s:%d no mem\n", "ipa3_perform_loopback", 3474);
              v38 = ipa3_ctx;
            }
            v40 = *(_QWORD *)(v38 + 34160);
            if ( v40 )
              ipc_log_string(v40, "ipa %s:%d no mem\n", "ipa3_perform_loopback", 3474);
          }
          goto LABEL_67;
        }
        *(_BYTE *)v5 = 1;
        *(_DWORD *)(v5 + 4) = 0;
        LODWORD(v42[0]) = 0;
        strcpy((char *)(v5 + 8), "V4_RT_TO_APPS_WAN_CONS");
        v7 = strnlen((const char *)(v5 + 8), 0x20u);
        if ( v7 < 0x21 )
        {
          if ( v7 == 32 )
            v8 = 32;
          else
            v8 = v7 + 1;
          if ( v8 >= 0x21 )
          {
LABEL_71:
            v7 = _fortify_panic(7, 32, v8);
            goto LABEL_72;
          }
          sized_strscpy((char *)v42 + 4, v5 + 8);
          *(_BYTE *)(v5 + 40) = 1;
          *(_DWORD *)(v5 + 44) = 35;
          *(_BYTE *)(v5 + 209) = 1;
          *(_BYTE *)(v5 + 211) = 1;
          if ( (unsigned int)ipa_add_rt_rule(v5) || *(_DWORD *)(v5 + 220) )
          {
            printk(&unk_3A9964, "ipa3_perform_loopback");
            v14 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v15 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v15 )
              {
                ipc_log_string(v15, "ipa %s:%d failed to install V4 rules\n", "ipa3_perform_loopback", 3491);
                v14 = ipa3_ctx;
              }
              v16 = *(_QWORD *)(v14 + 34160);
              if ( v16 )
                ipc_log_string(v16, "ipa %s:%d failed to install V4 rules\n", "ipa3_perform_loopback", 3491);
            }
            goto LABEL_66;
          }
          if ( (unsigned int)ipa3_get_rt_tbl(v42) )
          {
            printk(&unk_3FB051, "ipa3_perform_loopback");
            v27 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v28 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v28 )
              {
                ipc_log_string(v28, "ipa %s:%d failed to query V4 rules\n", "ipa3_perform_loopback", 3495);
                v27 = ipa3_ctx;
              }
              v29 = *(_QWORD *)(v27 + 34160);
              if ( v29 )
                ipc_log_string(v29, "ipa %s:%d failed to query V4 rules\n", "ipa3_perform_loopback", 3495);
            }
            goto LABEL_66;
          }
          *(_QWORD *)v5 = 0;
          v9 = HIDWORD(v43);
          *(_BYTE *)v5 = 1;
          *(_DWORD *)(v5 + 4) = 1;
          LODWORD(v42[0]) = 1;
          *(_DWORD *)(v5 + 40) = 0;
          *(_QWORD *)(v5 + 24) = 0;
          *(_QWORD *)(v5 + 32) = 0;
          *(_QWORD *)(v5 + 8) = 0;
          *(_QWORD *)(v5 + 16) = 0;
          strcpy((char *)(v5 + 8), "V6_RT_TO_APPS_WAN_CONS");
          v7 = strlen((const char *)(v5 + 8));
          if ( v7 != -1 || (v7 = strnlen((const char *)(v5 + 8), 0x20u), v7 < 0x21) )
          {
            if ( v7 == 32 )
              v8 = 32;
            else
              v8 = v7 + 1;
            if ( v8 < 0x21 )
            {
              sized_strscpy((char *)v42 + 4, v5 + 8);
              *(_BYTE *)(v5 + 40) = 1;
              *(_DWORD *)(v5 + 44) = 35;
              *(_BYTE *)(v5 + 209) = 1;
              *(_BYTE *)(v5 + 211) = 1;
              if ( (unsigned int)ipa_add_rt_rule(v5) || *(_DWORD *)(v5 + 220) )
              {
                printk(&unk_3D54D9, "ipa3_perform_loopback");
                v17 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v18 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v18 )
                  {
                    ipc_log_string(v18, "ipa %s:%d failed to install V6 rules\n", "ipa3_perform_loopback", 3514);
                    v17 = ipa3_ctx;
                  }
                  v19 = *(_QWORD *)(v17 + 34160);
                  if ( v19 )
                    ipc_log_string(v19, "ipa %s:%d failed to install V6 rules\n", "ipa3_perform_loopback", 3514);
                }
              }
              else if ( (unsigned int)ipa3_get_rt_tbl(v42) )
              {
                printk(&unk_3BADF8, "ipa3_perform_loopback");
                v30 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v31 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v31 )
                  {
                    ipc_log_string(v31, "ipa %s:%d failed to query V6 rules\n", "ipa3_perform_loopback", 3518);
                    v30 = ipa3_ctx;
                  }
                  v32 = *(_QWORD *)(v30 + 34160);
                  if ( v32 )
                    ipc_log_string(v32, "ipa %s:%d failed to query V6 rules\n", "ipa3_perform_loopback", 3518);
                }
              }
              else
              {
                v10 = HIDWORD(v43);
                *(_QWORD *)v6 = 0;
                *(_QWORD *)(v6 + 8) = 0;
                *(_BYTE *)v6 = 1;
                *(_DWORD *)(v6 + 8) = 34;
                *(_BYTE *)(v6 + 13) = 1;
                *(_BYTE *)(v6 + 376) = 1;
                *(_DWORD *)(v6 + 20) = 0;
                *(_DWORD *)(v6 + 24) = v9;
                *(_BYTE *)(v6 + 370) = 1;
                if ( (unsigned int)ipa3_add_flt_rule(v6) || *(_DWORD *)(v6 + 384) )
                {
                  printk(&unk_3A9964, "ipa3_perform_loopback");
                  v20 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v21 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v21 )
                    {
                      ipc_log_string(v21, "ipa %s:%d failed to install V4 rules\n", "ipa3_perform_loopback", 3533);
                      v20 = ipa3_ctx;
                    }
                    v22 = *(_QWORD *)(v20 + 34160);
                    if ( v22 )
                      ipc_log_string(v22, "ipa %s:%d failed to install V4 rules\n", "ipa3_perform_loopback", 3533);
                  }
                }
                else
                {
                  *(_QWORD *)v6 = 0;
                  *(_QWORD *)(v6 + 8) = 0;
                  *(_BYTE *)v6 = 1;
                  *(_DWORD *)(v6 + 4) = 1;
                  *(_DWORD *)(v6 + 8) = 34;
                  *(_BYTE *)(v6 + 13) = 1;
                  *(_BYTE *)(v6 + 376) = 1;
                  *(_DWORD *)(v6 + 20) = 0;
                  *(_DWORD *)(v6 + 24) = v10;
                  *(_BYTE *)(v6 + 370) = 1;
                  if ( (unsigned int)ipa3_add_flt_rule(v6) || *(_DWORD *)(v6 + 384) )
                  {
                    printk(&unk_3D54D9, "ipa3_perform_loopback");
                    v11 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v12 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v12 )
                      {
                        ipc_log_string(v12, "ipa %s:%d failed to install V6 rules\n", "ipa3_perform_loopback", 3547);
                        v11 = ipa3_ctx;
                      }
                      v13 = *(_QWORD *)(v11 + 34160);
                      if ( v13 )
                        ipc_log_string(v13, "ipa %s:%d failed to install V6 rules\n", "ipa3_perform_loopback", 3547);
                    }
                  }
                }
              }
LABEL_66:
              kfree(v6);
LABEL_67:
              kfree(v5);
LABEL_68:
              result = 0;
              goto LABEL_69;
            }
            goto LABEL_71;
          }
        }
LABEL_72:
        _fortify_panic(2, 32, v7 + 1);
      }
    }
    else
    {
      v4 = ep_mapping;
      *(_DWORD *)(ipa3_ctx + 480LL * ep_mapping + 332) = 1;
      ipa3_cfg_ep_hdr();
      ipa3_cfg_ep_status(v4, &v41);
      v5 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 224);
      if ( v5 )
        goto LABEL_9;
    }
    printk(&unk_3CF6DE, "ipa3_perform_loopback");
    v36 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_68;
    v37 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v37 )
    {
      ipc_log_string(v37, "ipa %s:%d no mem\n", "ipa3_perform_loopback", 3467);
      v36 = ipa3_ctx;
    }
    result = *(_QWORD *)(v36 + 34160);
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d no mem\n", "ipa3_perform_loopback", 3467);
      goto LABEL_68;
    }
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}
