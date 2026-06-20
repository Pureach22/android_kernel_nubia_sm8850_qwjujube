__int64 __fastcall smmu_proxy_switch_sid(__int64 a1, unsigned int a2)
{
  __int64 v4; // x19
  __int64 v5; // x0
  unsigned int variable_u32_array; // w0
  __int64 v7; // x2
  __int64 v8; // x0
  unsigned int v9; // w0
  unsigned int v10; // w21
  void *v11; // x0
  int v13; // w26
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  mutex_lock(&sender_mutex);
  v4 = _kmalloc_cache_noprof(mutex_unlock, 3520, 240);
  if ( !v4 )
  {
    printk(&unk_7A79, "smmu_proxy_switch_sid");
    v10 = -12;
    goto LABEL_14;
  }
  v5 = *(_QWORD *)(a1 + 744);
  *(_QWORD *)v4 = 0x1000000005LL;
  variable_u32_array = of_property_read_variable_u32_array(v5, "qti,smmu-proxy-cb-id", v4 + 8, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v10 = variable_u32_array;
    dev_err(a1, "%s: Err reading 'qti,smmu-proxy-cb-id' rc: %d\n", "smmu_proxy_switch_sid", variable_u32_array);
    goto LABEL_13;
  }
  if ( a2 <= 1 )
  {
    v7 = *(unsigned int *)(v4 + 4);
    v8 = msgq_hdl;
    *(_DWORD *)(v4 + 12) = a2;
    v9 = gh_msgq_send(v8, v4, v7, 0);
    if ( (v9 & 0x80000000) != 0 )
    {
      v10 = v9;
      v11 = &unk_7649;
    }
    else
    {
      v10 = gh_msgq_recv(msgq_hdl, v4, 12, v15, 0);
      if ( (v10 & 0x80000000) == 0 )
      {
LABEL_6:
        if ( v15[0] == 12 )
        {
          if ( *(_DWORD *)(v4 + 8) )
          {
            printk(&unk_7763, "smmu_proxy_switch_sid");
            v10 = -22;
          }
          if ( *(_DWORD *)v4 == 6 )
            goto LABEL_13;
          v11 = &unk_76DD;
          goto LABEL_25;
        }
        if ( (unsigned int)__ratelimit(&smmu_proxy_switch_sid__rs_20, "smmu_proxy_switch_sid") )
        {
          printk(&unk_7B53, "smmu_proxy_switch_sid");
          v10 = -22;
          goto LABEL_13;
        }
        goto LABEL_12;
      }
      v13 = -10;
      while ( !__CFADD__(v13++, 1) )
      {
        if ( (unsigned int)__ratelimit(&smmu_proxy_switch_sid__rs_18, "smmu_proxy_switch_sid") )
          printk(&unk_7A40, "smmu_proxy_switch_sid");
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
        v10 = gh_msgq_recv(msgq_hdl, v4, 12, v15, 0);
        if ( (v10 & 0x80000000) == 0 )
          goto LABEL_6;
      }
      if ( !(unsigned int)__ratelimit(&smmu_proxy_switch_sid__rs, "smmu_proxy_switch_sid") )
        goto LABEL_13;
      v11 = &unk_7B21;
    }
LABEL_25:
    printk(v11, "smmu_proxy_switch_sid");
    goto LABEL_13;
  }
LABEL_12:
  v10 = -22;
LABEL_13:
  kfree(v4);
LABEL_14:
  mutex_unlock(&sender_mutex);
  _ReadStatusReg(SP_EL0);
  return v10;
}
