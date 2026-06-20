__int64 ipa3_rmnet_ll_init()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x22
  unsigned __int64 dir; // x0
  __int64 v4; // x1
  const char *v5; // x19
  unsigned __int64 file; // x0
  unsigned __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned __int64 v18; // x0
  _QWORD v19[5]; // [xsp+8h] [xbp-28h] BYREF

  v19[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset((char *)&v19[2] + 3, 0, 13);
  *(_QWORD *)((char *)&v19[1] + 3) = 0;
  if ( !ipa3_ctx )
  {
    printk(&unk_3C30BD, "ipa3_rmnet_ll_init");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_rmnet_ll_init", 240);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_rmnet_ll_init", 240);
    }
    goto LABEL_24;
  }
  if ( (unsigned int)ipa_get_ep_mapping(120) == -1 || (unsigned int)ipa_get_ep_mapping(121) == -1 )
  {
    printk(&unk_3E21AC, "ipa3_rmnet_ll_init");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d invalid low lat data endpoints\n", "ipa3_rmnet_ll_init", 247);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d invalid low lat data endpoints\n", "ipa3_rmnet_ll_init", 247);
    }
LABEL_24:
    result = 4294967274LL;
    goto LABEL_25;
  }
  rmnet_ll_ipa3_ctx = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 744);
  if ( rmnet_ll_ipa3_ctx )
  {
    strcpy((char *)v19, "rmnet_llwq");
    v0 = alloc_workqueue((const char *)v19, 74, 1);
    v1 = rmnet_ll_ipa3_ctx;
    *(_QWORD *)(rmnet_ll_ipa3_ctx + 736) = v0;
    if ( v0 )
    {
      *(_QWORD *)(v1 + 304) = 0;
      *(_QWORD *)(v1 + 312) = 0;
      *(_QWORD *)(v1 + 288) = 0;
      *(_QWORD *)(v1 + 296) = 0;
      *(_QWORD *)(v1 + 272) = 0;
      *(_QWORD *)(v1 + 280) = 0;
      *(_QWORD *)(v1 + 256) = 0;
      *(_QWORD *)(v1 + 264) = 0;
      *(_QWORD *)(v1 + 240) = 0;
      *(_QWORD *)(v1 + 248) = 0;
      *(_QWORD *)(v1 + 224) = 0;
      *(_QWORD *)(v1 + 232) = 0;
      *(_QWORD *)(v1 + 208) = 0;
      *(_QWORD *)(v1 + 216) = 0;
      *(_QWORD *)(v1 + 192) = 0;
      *(_QWORD *)(v1 + 200) = 0;
      *(_QWORD *)(v1 + 176) = 0;
      *(_QWORD *)(v1 + 184) = 0;
      *(_QWORD *)(v1 + 160) = 0;
      *(_QWORD *)(v1 + 168) = 0;
      *(_QWORD *)(v1 + 144) = 0;
      *(_QWORD *)(v1 + 152) = 0;
      *(_QWORD *)(v1 + 128) = 0;
      *(_QWORD *)(v1 + 136) = 0;
      *(_QWORD *)(v1 + 112) = 0;
      *(_QWORD *)(v1 + 120) = 0;
      *(_QWORD *)(v1 + 96) = 0;
      *(_QWORD *)(v1 + 104) = 0;
      *(_QWORD *)(v1 + 80) = 0;
      *(_QWORD *)(v1 + 88) = 0;
      *(_QWORD *)(v1 + 64) = 0;
      *(_QWORD *)(v1 + 72) = 0;
      *(_QWORD *)(v1 + 568) = 0;
      *(_QWORD *)(v1 + 560) = 0;
      *(_QWORD *)(v1 + 552) = 0;
      *(_QWORD *)(v1 + 544) = 0;
      *(_QWORD *)(v1 + 536) = 0;
      *(_QWORD *)(v1 + 528) = 0;
      *(_QWORD *)(v1 + 520) = 0;
      *(_QWORD *)(v1 + 504) = 0;
      *(_QWORD *)(v1 + 512) = 0;
      *(_QWORD *)(v1 + 488) = 0;
      *(_QWORD *)(v1 + 496) = 0;
      *(_QWORD *)(v1 + 472) = 0;
      *(_QWORD *)(v1 + 480) = 0;
      *(_QWORD *)(v1 + 456) = 0;
      *(_QWORD *)(v1 + 464) = 0;
      *(_QWORD *)(v1 + 440) = 0;
      *(_QWORD *)(v1 + 448) = 0;
      *(_QWORD *)(v1 + 424) = 0;
      *(_QWORD *)(v1 + 432) = 0;
      *(_QWORD *)(v1 + 408) = 0;
      *(_QWORD *)(v1 + 416) = 0;
      *(_QWORD *)(v1 + 392) = 0;
      *(_QWORD *)(v1 + 400) = 0;
      *(_QWORD *)(v1 + 376) = 0;
      *(_QWORD *)(v1 + 384) = 0;
      *(_QWORD *)(v1 + 360) = 0;
      *(_QWORD *)(v1 + 368) = 0;
      *(_QWORD *)(v1 + 344) = 0;
      *(_QWORD *)(v1 + 352) = 0;
      *(_QWORD *)(v1 + 328) = 0;
      *(_QWORD *)(v1 + 336) = 0;
      *(_QWORD *)(v1 + 320) = 0;
      *(_QWORD *)(v1 + 648) = v1 + 648;
      *(_QWORD *)(v1 + 656) = v1 + 648;
      *(_QWORD *)(v1 + 664) = 0;
      *(_DWORD *)(v1 + 56) = 0;
      _mutex_init(v1 + 688, "&rmnet_ll_ipa3_ctx->lock", &ipa3_rmnet_ll_init___key);
      v2 = rmnet_ll_ipa3_ctx;
      *(_DWORD *)(rmnet_ll_ipa3_ctx + 584) = 0;
      *(_BYTE *)(v2 + 60) = 0;
      *(_DWORD *)(v2 + 644) = 64;
      dir = debugfs_create_dir("rmnet_ll_ipa", 0);
      *(_QWORD *)(v2 + 680) = dir;
      if ( dir > 0xFFFFFFFFFFFFF000LL )
      {
        printk(&unk_3ED4CC, v4);
        result = 0;
      }
      else
      {
        v5 = "stats";
        file = debugfs_create_file("stats", 292, dir, 0, &unk_1E4A00);
        if ( file )
        {
          if ( file <= 0xFFFFFFFFFFFFF000LL )
          {
            v5 = "free_credit_threshld";
            v7 = debugfs_create_file("free_credit_threshld", 436, *(_QWORD *)(v2 + 680), 0, &unk_1E4B20);
            if ( v7 )
            {
              if ( v7 < 0xFFFFFFFFFFFFF001LL )
                goto LABEL_11;
            }
          }
        }
        printk(&unk_3E09D4, "rmnet_ll_ipa3_debugfs_init");
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v16 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v16 )
          {
            ipc_log_string(
              v16,
              "ipa %s:%d fail to create file for debug_fs %s\n",
              "rmnet_ll_ipa3_debugfs_init",
              220,
              v5);
            v15 = ipa3_ctx;
          }
          v17 = *(_QWORD *)(v15 + 34160);
          if ( v17 )
            ipc_log_string(
              v17,
              "ipa %s:%d fail to create file for debug_fs %s\n",
              "rmnet_ll_ipa3_debugfs_init",
              220,
              v5);
        }
        v18 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 680);
        if ( v18 > 0xFFFFFFFFFFFFF000LL )
        {
LABEL_11:
          result = 0;
        }
        else
        {
          debugfs_remove(v18);
          result = 0;
          *(_QWORD *)(rmnet_ll_ipa3_ctx + 680) = 0;
        }
      }
    }
    else
    {
      kfree(v1);
      rmnet_ll_ipa3_ctx = 0;
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
