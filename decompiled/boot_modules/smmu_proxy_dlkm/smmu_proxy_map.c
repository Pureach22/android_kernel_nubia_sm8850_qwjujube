__int64 __fastcall smmu_proxy_map(__int64 a1, _DWORD *a2, __int64 a3)
{
  __int64 result; // x0
  int v7; // w24
  int v8; // w23
  __int64 v9; // x19
  unsigned int memparcel_hdl; // w0
  __int16 v11; // w8
  char v12; // w9
  char v13; // w9
  unsigned int variable_u32_array; // w0
  __int64 v15; // x0
  __int64 v16; // x2
  unsigned int v17; // w0
  __int64 v18; // x26
  int i; // w25
  unsigned int v20; // w0
  unsigned int v21; // w26
  unsigned int v22; // w27
  unsigned int v23; // w0
  void *v24; // x0
  void *v25; // x0
  void *v26; // x8
  unsigned int v27; // w2
  __int64 v28; // [xsp+8h] [xbp-58h] BYREF
  _QWORD *v29; // [xsp+10h] [xbp-50h]
  __int64 *v30; // [xsp+18h] [xbp-48h]
  __int64 v31; // [xsp+20h] [xbp-40h]
  __int64 v32; // [xsp+28h] [xbp-38h]
  __int64 v33; // [xsp+30h] [xbp-30h] BYREF
  __int64 v34; // [xsp+38h] [xbp-28h]
  __int64 v35; // [xsp+40h] [xbp-20h] BYREF
  __int64 v36; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v37[2]; // [xsp+50h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v34 = 0;
  v37[0] = 0x310000002DLL;
  v35 = 0;
  v36 = 0x600000006LL;
  v31 = 0;
  v32 = 0;
  v29 = nullptr;
  v30 = nullptr;
  v28 = 0;
  result = smmu_proxy_get_csf_version(&v33);
  if ( (_DWORD)result )
    goto LABEL_44;
  v7 = v34;
  if ( (_DWORD)v34 == 1 )
    v8 = 2;
  else
    v8 = 1;
  mutex_lock(&sender_mutex);
  v9 = _kmalloc_cache_noprof(mutex_unlock, 3520, 240);
  if ( !v9 )
  {
    v22 = -12;
    goto LABEL_43;
  }
  if ( (mem_buf_dma_buf_exclusive_owner(a3) & 1) != 0 )
  {
    v29 = v37;
    v30 = &v36;
    LODWORD(v28) = v8;
    memparcel_hdl = mem_buf_lend(a3, &v28);
    if ( memparcel_hdl )
    {
      v26 = &unk_77D4;
      goto LABEL_37;
    }
  }
  v11 = v37[0];
  v12 = v36;
  *(_DWORD *)(v9 + 16) = v8;
  *(_WORD *)(v9 + 20) = v11;
  *(_BYTE *)(v9 + 22) = v12;
  if ( v7 == 1 )
  {
    v13 = BYTE4(v36);
    *(_WORD *)(v9 + 24) = WORD2(v37[0]);
    *(_BYTE *)(v9 + 26) = v13;
  }
  memparcel_hdl = mem_buf_dma_buf_get_memparcel_hdl(a3, v9 + 8);
  if ( memparcel_hdl )
  {
    v26 = &unk_76B0;
LABEL_37:
    v27 = memparcel_hdl;
    v24 = v26;
    v22 = v27;
LABEL_38:
    printk(v24, "smmu_proxy_map");
    goto LABEL_39;
  }
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qti,smmu-proxy-cb-id", v9 + 12, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v22 = variable_u32_array;
    dev_err(a1, "%s: Err reading 'qti,smmu-proxy-cb-id' rc: %d\n", "smmu_proxy_map", variable_u32_array);
    goto LABEL_39;
  }
  v15 = msgq_hdl;
  v16 = (unsigned int)(4 * v8 + 20);
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = v16;
  v17 = gh_msgq_send(v15, v9, v16, 0);
  if ( (v17 & 0x80000000) != 0 )
  {
    v22 = v17;
    printk(&unk_75E8, "smmu_proxy_map");
    goto LABEL_39;
  }
  v18 = 0;
  for ( i = -9; ; ++i )
  {
    v20 = gh_msgq_recv(msgq_hdl, v9, 28, &v35, v18);
    if ( (v20 & 0x80000000) != 0 )
      goto LABEL_19;
    if ( v35 != 28 )
    {
      if ( !(unsigned int)__ratelimit(&smmu_proxy_map__rs, "smmu_proxy_map") )
      {
LABEL_32:
        v22 = -22;
        goto LABEL_39;
      }
      v25 = &unk_7A0F;
LABEL_41:
      printk(v25, "smmu_proxy_map");
      v22 = -22;
      goto LABEL_39;
    }
    if ( *(_DWORD *)(v9 + 8) )
    {
      if ( !(unsigned int)__ratelimit(&smmu_proxy_map__rs_27, "smmu_proxy_map") )
        goto LABEL_32;
      v25 = &unk_7792;
      goto LABEL_41;
    }
    if ( *(_DWORD *)v9 == 1 )
    {
      v23 = mem_buf_dma_buf_set_destructor(a3, smmu_proxy_unmap, a3);
      if ( !v23 )
      {
        v22 = 0;
        *(_QWORD *)(*(_QWORD *)a2 + 16LL) = *(_QWORD *)(v9 + 12);
        *(_DWORD *)(*(_QWORD *)a2 + 24LL) = *(_QWORD *)(v9 + 20);
        a2[2] = 1;
        goto LABEL_39;
      }
      v22 = v23;
      if ( !(unsigned int)__ratelimit(&smmu_proxy_map__rs_31, "smmu_proxy_map") )
        goto LABEL_39;
      v24 = &unk_79D0;
      goto LABEL_38;
    }
    v21 = v20;
    printk(&unk_7821, "smmu_proxy_map");
    v20 = v21;
    v18 = 0x100000000LL;
LABEL_19:
    v22 = v20;
    if ( !i )
      break;
    if ( (unsigned int)__ratelimit(&smmu_proxy_map__rs_30, "smmu_proxy_map") )
      printk(&unk_7A9B, "smmu_proxy_map");
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
  }
  if ( (unsigned int)__ratelimit(&smmu_proxy_map__rs_29, "smmu_proxy_map") )
    printk(&unk_7970, "smmu_proxy_map");
LABEL_39:
  kfree(v9);
LABEL_43:
  mutex_unlock(&sender_mutex);
  result = v22;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
