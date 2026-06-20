__int64 __fastcall smmu_proxy_unmap(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int memparcel_hdl; // w0
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w20
  void *v8; // x0
  int v9; // w25
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  mutex_lock(&sender_mutex);
  v2 = _kmalloc_cache_noprof(mutex_unlock, 3520, 240);
  v3 = v2;
  if ( !v2 )
  {
    printk(&unk_7A79, "smmu_proxy_unmap");
    v7 = -12;
    goto LABEL_25;
  }
  memparcel_hdl = mem_buf_dma_buf_get_memparcel_hdl(a1, v2 + 8);
  if ( memparcel_hdl )
  {
    v7 = memparcel_hdl;
    printk(&unk_76B0, "smmu_proxy_unmap");
  }
  else
  {
    v5 = msgq_hdl;
    *(_QWORD *)v3 = 0xC00000002LL;
    v6 = gh_msgq_send(v5, v3, 12, 0);
    if ( (v6 & 0x80000000) != 0 )
    {
      v7 = v6;
      v8 = &unk_75E8;
      goto LABEL_23;
    }
    v7 = gh_msgq_recv(msgq_hdl, v3, 12, v12, 0);
    if ( (v7 & 0x80000000) != 0 )
    {
      v9 = -10;
      while ( !__CFADD__(v9++, 1) )
      {
        if ( (unsigned int)__ratelimit(&smmu_proxy_unmap__rs_7, "smmu_proxy_unmap") )
          printk(&unk_7A9B, "smmu_proxy_unmap");
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        _const_udelay(4295000);
        v7 = gh_msgq_recv(msgq_hdl, v3, 12, v12, 0);
        if ( (v7 & 0x80000000) == 0 )
          goto LABEL_5;
      }
      if ( !(unsigned int)__ratelimit(&smmu_proxy_unmap__rs, "smmu_proxy_unmap") )
        goto LABEL_24;
      v8 = &unk_7970;
      goto LABEL_23;
    }
LABEL_5:
    if ( v12[0] != 12 )
    {
      if ( (unsigned int)__ratelimit(&smmu_proxy_unmap__rs_9, "smmu_proxy_unmap") )
        printk(&unk_7616, "smmu_proxy_unmap");
      v7 = -22;
      goto LABEL_24;
    }
    if ( *(_DWORD *)(v3 + 8) )
    {
      printk(&unk_7912, "smmu_proxy_unmap");
      v7 = -22;
    }
    if ( *(_DWORD *)v3 != 3 )
    {
      v8 = &unk_7821;
LABEL_23:
      printk(v8, "smmu_proxy_unmap");
    }
  }
LABEL_24:
  kfree(v3);
LABEL_25:
  mutex_unlock(&sender_mutex);
  _ReadStatusReg(SP_EL0);
  return v7;
}
