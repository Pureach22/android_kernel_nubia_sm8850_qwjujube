__int64 ipa3_rmnet_ctl_init()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  _QWORD v10[5]; // [xsp+8h] [xbp-28h] BYREF

  v10[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset((char *)&v10[1] + 4, 0, 20);
  if ( !ipa3_ctx )
  {
    printk(&unk_3C30BD, "ipa3_rmnet_ctl_init");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_rmnet_ctl_init", 85);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d ipa3_ctx was not initialized\n", "ipa3_rmnet_ctl_init", 85);
    }
    goto LABEL_19;
  }
  if ( (unsigned int)ipa_get_ep_mapping(104) == -1 || (unsigned int)ipa_get_ep_mapping(105) == -1 )
  {
    printk(&unk_3BC28C, "ipa3_rmnet_ctl_init");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d invalid low lat endpoints\n", "ipa3_rmnet_ctl_init", 92);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d invalid low lat endpoints\n", "ipa3_rmnet_ctl_init", 92);
    }
LABEL_19:
    result = 4294967274LL;
    goto LABEL_20;
  }
  rmnet_ctl_ipa3_ctx = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 728);
  if ( rmnet_ctl_ipa3_ctx )
  {
    strcpy((char *)v10, "rmnet_ctlwq");
    v0 = alloc_workqueue((const char *)v10, 74, 1);
    v1 = rmnet_ctl_ipa3_ctx;
    *(_QWORD *)(rmnet_ctl_ipa3_ctx + 720) = v0;
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
      *(_QWORD *)(v1 + 640) = v1 + 640;
      *(_QWORD *)(v1 + 648) = v1 + 640;
      *(_QWORD *)(v1 + 656) = 0;
      *(_DWORD *)(v1 + 56) = 0;
      _mutex_init(v1 + 672, "&rmnet_ctl_ipa3_ctx->lock", &ipa3_rmnet_ctl_init___key);
      v2 = rmnet_ctl_ipa3_ctx;
      result = 0;
      *(_DWORD *)(rmnet_ctl_ipa3_ctx + 584) = 0;
      *(_BYTE *)(v2 + 60) = 0;
    }
    else
    {
      kfree(v1);
      rmnet_ctl_ipa3_ctx = 0;
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
