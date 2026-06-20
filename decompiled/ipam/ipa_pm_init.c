// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall ipa_pm_init(_DWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  const char *v6; // x22
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  int v11; // w10
  __int64 v12; // x25
  __int64 v13; // x26
  __int64 v14; // x27
  const char **v15; // x20
  const char *v16; // x24
  size_t v17; // x0
  unsigned __int64 v18; // x2
  _DWORD *v19; // x23
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x9
  __int64 *v35; // x1
  __int64 v36; // x2
  __int64 v38; // x0
  __int64 ipc_logbuf; // x0
  __int64 v40; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v42; // x0
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
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v64; // x21
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0

  if ( !a1 )
  {
    v38 = printk(&unk_3C724A, "ipa_pm_init");
    ipc_logbuf = ipa3_get_ipc_logbuf(v38);
    if ( ipc_logbuf )
    {
      v40 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v40, "ipa_pm %s:%d Invalid Params\n", "ipa_pm_init", 621);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( !ipc_logbuf_low )
      return 4294967274LL;
    v42 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v42, "ipa_pm %s:%d Invalid Params\n", "ipa_pm_init", 621);
    return 4294967274LL;
  }
  if ( (unsigned int)(a1[5] - 6) <= 0xFFFFFFFA )
  {
    v43 = printk(&unk_3C4505, "ipa_pm_init");
    v44 = ipa3_get_ipc_logbuf(v43);
    if ( v44 )
    {
      v45 = ipa3_get_ipc_logbuf(v44);
      v44 = ipc_log_string(v45, "ipa_pm %s:%d Invalid threshold size\n", "ipa_pm_init", 627);
    }
    v46 = ipa3_get_ipc_logbuf_low(v44);
    if ( !v46 )
      return 4294967274LL;
    v47 = ipa3_get_ipc_logbuf_low(v46);
    ipc_log_string(v47, "ipa_pm %s:%d Invalid threshold size\n", "ipa_pm_init", 627);
    return 4294967274LL;
  }
  if ( a1[46] >= 6u )
  {
    v48 = printk(&unk_3B28EE, "ipa_pm_init");
    v49 = ipa3_get_ipc_logbuf(v48);
    if ( v49 )
    {
      v50 = ipa3_get_ipc_logbuf(v49);
      v49 = ipc_log_string(v50, "ipa_pm %s:%d Invalid exception size\n", "ipa_pm_init", 633);
    }
    v51 = ipa3_get_ipc_logbuf_low(v49);
    if ( v51 )
    {
      v52 = ipa3_get_ipc_logbuf_low(v51);
      ipc_log_string(v52, "ipa_pm %s:%d Invalid exception size\n", "ipa_pm_init", 633);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v2 = ipa3_get_ipc_logbuf(a1);
  if ( v2 )
  {
    v3 = ipa3_get_ipc_logbuf(v2);
    v2 = ipc_log_string(v3, "ipa_pm %s:%d IPA PM initialization started\n", "ipa_pm_init", 637);
  }
  v4 = ipa3_get_ipc_logbuf_low(v2);
  if ( v4 )
  {
    v5 = ipa3_get_ipc_logbuf_low(v4);
    ipc_log_string(v5, "ipa_pm %s:%d IPA PM initialization started\n", "ipa_pm_init", 637);
  }
  v6 = (const char *)&unk_200000;
  if ( ipa_pm_ctx )
  {
    v53 = printk(&unk_3B85EA, "ipa_pm_init");
    v54 = ipa3_get_ipc_logbuf(v53);
    if ( v54 )
    {
      v55 = ipa3_get_ipc_logbuf(v54);
      v54 = ipc_log_string(v55, "ipa_pm %s:%d Already initialized\n", "ipa_pm_init", 640);
    }
    v56 = ipa3_get_ipc_logbuf_low(v54);
    if ( v56 )
    {
      v57 = ipa3_get_ipc_logbuf_low(v56);
      ipc_log_string(v57, "ipa_pm %s:%d Already initialized\n", "ipa_pm_init", 640);
    }
    return 0xFFFFFFFFLL;
  }
  ipa_pm_ctx = _kmalloc_cache_noprof(__ratelimit, 3520, 1216);
  if ( !ipa_pm_ctx )
    goto LABEL_84;
LABEL_10:
  v7 = alloc_workqueue("%s", (const char *)0x6000A);
  v8 = *((_QWORD *)v6 + 217);
  *(_QWORD *)(v8 + 576) = v7;
  if ( !v7 )
  {
    v58 = printk(&unk_3AFEBC, "ipa_pm_init");
    v59 = ipa3_get_ipc_logbuf(v58);
    if ( v59 )
    {
      v60 = ipa3_get_ipc_logbuf(v59);
      v59 = ipc_log_string(v60, "ipa_pm %s:%d create workqueue failed\n", "ipa_pm_init", 653);
    }
    v61 = ipa3_get_ipc_logbuf_low(v59);
    if ( v61 )
    {
      v62 = ipa3_get_ipc_logbuf_low(v61);
      ipc_log_string(v62, "ipa_pm %s:%d create workqueue failed\n", "ipa_pm_init", 653);
    }
    kfree(*((_QWORD *)v6 + 217));
    *((_QWORD *)v6 + 217) = 0;
    return 4294967284LL;
  }
  v9 = _mutex_init(v8 + 1152, "&ipa_pm_ctx->client_mutex", &ipa_pm_init___key);
  v10 = *((_QWORD *)v6 + 217);
  *(_DWORD *)(v10 + 584) = 0;
  *(_DWORD *)(v10 + 1112) = a1[5];
  v11 = a1[46];
  *(_QWORD *)(v10 + 1072) = 0xFFFFFFFE00000LL;
  *(_DWORD *)(v10 + 1116) = v11;
  *(_QWORD *)(v10 + 1080) = v10 + 1080;
  *(_QWORD *)(v10 + 1088) = v10 + 1080;
  *(_QWORD *)(v10 + 1096) = clock_scaling_func;
  if ( (int)a1[5] >= 1 )
  {
    *(_DWORD *)(v10 + 1124) = *a1;
    if ( (int)a1[5] >= 2 )
    {
      *(_DWORD *)(v10 + 1128) = a1[1];
      if ( (int)a1[5] > 2 )
      {
        *(_DWORD *)(v10 + 1132) = a1[2];
        if ( (int)a1[5] >= 4 )
        {
          *(_DWORD *)(v10 + 1136) = a1[3];
          if ( (int)a1[5] >= 5 )
          {
            *(_DWORD *)(v10 + 1140) = a1[4];
            if ( (int)a1[5] > 5 )
              goto LABEL_45;
          }
        }
      }
    }
  }
  if ( (int)a1[46] >= 1 )
  {
    v12 = v10 + 588;
    v13 = 0;
    v6 = "ipa_pm %s:%d Usecase: %s\n";
    v14 = v10 + 588;
    do
    {
      if ( v13 == 5 )
        goto LABEL_45;
      v15 = (const char **)&a1[8 * v13 + 6];
      v16 = *v15;
      v17 = strnlen(*v15, 0x40u);
      if ( v17 == -1 )
      {
        _fortify_panic(2, -1, 0);
LABEL_83:
        _fortify_panic(7, 64, v18);
        StatusReg = _ReadStatusReg(SP_EL0);
        v64 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &ipa_pm_init__alloc_tag;
        v65 = _kmalloc_cache_noprof(__ratelimit, 3520, 1216);
        *(_QWORD *)(StatusReg + 80) = v64;
        *(_QWORD *)"ter ipa pm\n" = v65;
        if ( !v65 )
        {
LABEL_84:
          v66 = printk(&unk_3E3F71, "ipa_pm_init");
          v67 = ipa3_get_ipc_logbuf(v66);
          if ( v67 )
          {
            v68 = ipa3_get_ipc_logbuf(v67);
            v67 = ipc_log_string(v68, "ipa_pm %s:%d :kzalloc err.\n", "ipa_pm_init", 647);
          }
          v69 = ipa3_get_ipc_logbuf_low(v67);
          if ( v69 )
          {
            v70 = ipa3_get_ipc_logbuf_low(v69);
            ipc_log_string(v70, "ipa_pm %s:%d :kzalloc err.\n", "ipa_pm_init", 647);
          }
          return 4294967284LL;
        }
        goto LABEL_10;
      }
      if ( v17 == 64 )
        v18 = 64;
      else
        v18 = v17 + 1;
      if ( v18 >= 0x41 )
        goto LABEL_83;
      v19 = (_DWORD *)(v12 + 96 * v13);
      v20 = sized_strscpy(v19, v16);
      v21 = ipa3_get_ipc_logbuf(v20);
      if ( v21 )
      {
        v22 = ipa3_get_ipc_logbuf(v21);
        v21 = ipc_log_string(v22, "ipa_pm %s:%d Usecase: %s\n", "ipa_pm_init", 676, *v15);
      }
      v23 = ipa3_get_ipc_logbuf_low(v21);
      if ( v23 )
      {
        v24 = ipa3_get_ipc_logbuf_low(v23);
        v23 = ipc_log_string(v24, "ipa_pm %s:%d Usecase: %s\n", "ipa_pm_init", 676, *v15);
      }
      v25 = 0;
      while ( *(_BYTE *)(v14 + v25) == 44 )
      {
        ++v19[16];
LABEL_32:
        if ( ++v25 == 64 )
          goto LABEL_35;
      }
      if ( *(_BYTE *)(v14 + v25) )
        goto LABEL_32;
LABEL_35:
      ++v19[16];
      v26 = ipa3_get_ipc_logbuf(v23);
      if ( v26 )
      {
        v27 = ipa3_get_ipc_logbuf(v26);
        v26 = ipc_log_string(v27, "ipa_pm %s:%d Pending: %d\n", "ipa_pm_init", 688, v19[16]);
      }
      v9 = ipa3_get_ipc_logbuf_low(v26);
      if ( v9 )
      {
        v28 = ipa3_get_ipc_logbuf_low(v9);
        v9 = ipc_log_string(v28, "ipa_pm %s:%d Pending: %d\n", "ipa_pm_init", 688, v19[16]);
      }
      if ( (int)a1[5] >= 1 )
      {
        v19[19] = *((_DWORD *)v15 + 2);
        if ( (int)a1[5] >= 2 )
        {
          v19[20] = *((_DWORD *)v15 + 3);
          if ( (int)a1[5] >= 3 )
          {
            v19[21] = *((_DWORD *)v15 + 4);
            if ( (int)a1[5] >= 4 )
            {
              v19[22] = *((_DWORD *)v15 + 5);
              if ( (int)a1[5] >= 5 )
              {
                v19[23] = *((_DWORD *)v15 + 6);
                if ( (int)a1[5] > 5 )
                {
LABEL_45:
                  __break(0x5512u);
                  break;
                }
              }
            }
          }
        }
      }
      ++v13;
      v14 += 96;
    }
    while ( v13 < (int)a1[46] );
  }
  v29 = ipa3_get_ipc_logbuf(v9);
  if ( v29 )
  {
    v30 = ipa3_get_ipc_logbuf(v29);
    v29 = ipc_log_string(v30, "ipa_pm %s:%d initialization success", "ipa_pm_init", 697);
  }
  v31 = ipa3_get_ipc_logbuf_low(v29);
  if ( v31 )
  {
    v32 = ipa3_get_ipc_logbuf_low(v31);
    ipc_log_string(v32, "ipa_pm %s:%d initialization success", "ipa_pm_init", 697);
  }
  v33 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  if ( v33 )
  {
    v34 = ipa3_ctx;
    *(_QWORD *)(v33 + 16) = ipa_pm_ctx;
    strcpy((char *)(v33 + 24), "ipa_pm_ctx");
    *(_DWORD *)(v33 + 56) = 1216;
    v35 = (__int64 *)(v34 + 51408);
    v36 = *(_QWORD *)(v34 + 51408);
    if ( *(_QWORD *)(v36 + 8) == v34 + 51408 && (__int64 *)v33 != v35 && v36 != v33 )
    {
      *(_QWORD *)(v36 + 8) = v33;
      *(_QWORD *)v33 = v36;
      *(_QWORD *)(v33 + 8) = v35;
      *v35 = v33;
      return 0;
    }
    _list_add_valid_or_report(v33, v35);
  }
  return 0;
}
