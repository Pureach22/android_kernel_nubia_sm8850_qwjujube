__int64 __fastcall fastrpc_cb_probe(_QWORD *a1)
{
  const char **v1; // x19
  __int64 v3; // x20
  unsigned __int64 current_channel_ctx; // x0
  unsigned int v5; // w24
  unsigned __int64 v6; // x23
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x24
  __int64 v11; // x11
  _DWORD *v12; // x10
  __int64 v13; // x25
  int v14; // w8
  __int64 property; // x0
  unsigned int v16; // w8
  __int64 v17; // x22
  int v18; // w8
  __int64 v19; // x8
  int v20; // w9
  int v21; // w22
  __int64 v22; // x8
  char *v23; // x28
  __int64 v24; // x1
  unsigned int v25; // w0
  unsigned __int64 file; // x0
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  int variable_u32_array; // w0
  _QWORD *v31; // x0
  _QWORD *v32; // x21
  __int64 v33; // x1
  __int64 v34; // x0
  const void *v35; // x0
  unsigned int sgtable_attrs; // w0
  __int64 domain_for_dev; // x0
  const char *v38; // x2
  __int64 v39; // x23
  unsigned __int64 v40; // x0
  unsigned __int64 v41; // x25
  unsigned int v42; // w0
  _QWORD *v43; // [xsp+8h] [xbp-58h]
  _DWORD *v44; // [xsp+10h] [xbp-50h]
  __int64 v45; // [xsp+18h] [xbp-48h]
  __int64 v46; // [xsp+20h] [xbp-40h] BYREF
  __int64 v47; // [xsp+28h] [xbp-38h]
  int v48; // [xsp+30h] [xbp-30h] BYREF
  int v49; // [xsp+34h] [xbp-2Ch] BYREF
  __int64 v50; // [xsp+38h] [xbp-28h] BYREF
  __int64 v51; // [xsp+40h] [xbp-20h]
  __int64 v52; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v53[2]; // [xsp+50h] [xbp-10h] BYREF

  v1 = (const char **)(a1 + 2);
  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = qword_27538;
  v49 = 0;
  v48 = 0;
  v52 = 0;
  v53[0] = 0;
  v50 = 0;
  v51 = 0;
  v46 = 0;
  v47 = 0;
  current_channel_ctx = get_current_channel_ctx(a1 + 2);
  v5 = -22;
  if ( !current_channel_ctx )
    goto LABEL_5;
  v6 = current_channel_ctx;
  if ( current_channel_ctx > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_5;
  of_property_read_variable_u32_array(a1[95], "qcom,nsessions", &v49, 1, 0);
  if ( of_get_property(a1[95], "pd-type", 0) )
  {
    v5 = of_property_read_variable_u32_array(a1[95], "pd-type", &v48, 1, 0);
    if ( (v5 & 0x80000000) != 0 )
      goto LABEL_5;
    *(_BYTE *)(v6 + 64132) = 1;
  }
  v8 = raw_spin_lock_irqsave(v6 + 51600);
  v9 = *(unsigned int *)(v6 + 4);
  v10 = v8;
  if ( (int)v9 > 49 )
  {
    dev_err(v1, "too many sessions\n");
    raw_spin_unlock_irqrestore(v6 + 51600, v10);
    v5 = -28;
    goto LABEL_5;
  }
  v45 = v8;
  if ( (int)v9 < 1 )
    goto LABEL_18;
  if ( (unsigned int)(v48 - 11) <= 0xFFFFFFFD )
  {
    *(_DWORD *)(v6 + 4) = v9 + 1;
LABEL_19:
    v13 = v6 + (v9 << 10) + 176;
    goto LABEL_20;
  }
  v11 = 0;
  v12 = (_DWORD *)(v6 + 1184);
  while ( 1 )
  {
    if ( v11 == 50 )
      goto LABEL_75;
    if ( *v12 == v48 )
      break;
    ++v11;
    v12 += 256;
    if ( v9 == v11 )
      goto LABEL_18;
  }
  v13 = (__int64)(v12 - 252);
  *(_BYTE *)(v6 + 64176) = 1;
  if ( v12 == dword_3F0 )
  {
LABEL_18:
    *(_DWORD *)(v6 + 4) = v9 + 1;
    if ( (unsigned int)v9 > 0x32 )
      goto LABEL_75;
    goto LABEL_19;
  }
LABEL_20:
  if ( !*(_DWORD *)(v13 + 1016) )
  {
    v14 = v48;
    *(_DWORD *)(v13 + 1020) = 0;
    *(_DWORD *)(v13 + 1008) = v14;
  }
  property = of_find_property(a1[95], "qcom,secure-context-bank", 0);
  v16 = *(_DWORD *)(v13 + 1016);
  *(_BYTE *)(v13 + 1012) = property != 0;
  *(_DWORD *)(v13 + 1016) = v16 + 1;
  if ( v16 > 7 )
LABEL_75:
    __break(0x5512u);
  v17 = v13 + 144LL * v16;
  *(_BYTE *)(v17 + 12) = 1;
  *(_QWORD *)v17 = v1;
  *(_QWORD *)(v17 + 128) = v13;
  *(_DWORD *)(v17 + 136) = 32;
  _mutex_init(v17 + 16, "&smmucb->map_mutex", &fastrpc_cb_probe___key);
  of_property_read_variable_u32_array(a1[95], "ubs", v17 + 136, 1, 0);
  if ( *(_DWORD *)(v6 + 64240) )
    v18 = 56;
  else
    v18 = *(_DWORD *)(v17 + 136);
  *(_DWORD *)(v17 + 140) = v18;
  if ( (of_property_read_variable_u32_array(a1[95], "reg", v17 + 8, 1, 0) & 0x80000000) != 0 )
    dev_info(v1, "FastRPC Session ID not specified in DT\n");
  v44 = (_DWORD *)(v17 + 136);
  if ( (of_property_read_variable_u64_array(a1[95], "alloc-size-range", &v50, 2, 0) & 0x80000000) == 0 )
  {
    *(_QWORD *)(v17 + 112) = v50;
    v19 = v51;
LABEL_32:
    *(_QWORD *)(v17 + 120) = v19;
    goto LABEL_33;
  }
  if ( (of_property_read_variable_u32_array(a1[95], "alloc-size-range", &v52, 2, 0) & 0x80000000) == 0 )
  {
    *(_QWORD *)(v17 + 112) = (unsigned int)v52;
    v19 = HIDWORD(v52);
    goto LABEL_32;
  }
LABEL_33:
  v43 = (_QWORD *)v17;
  v20 = v49;
  *(_QWORD *)(v17 + 104) = ~(-1LL << *(_DWORD *)(v17 + 136));
  a1[21] = v17;
  if ( v20 >= 1 )
  {
    *(_BYTE *)(v13 + 1013) = 1;
    if ( v20 != 1 )
    {
      v21 = 1;
      do
      {
        v22 = *(unsigned int *)(v6 + 4);
        if ( (int)v22 > 49 )
          break;
        *(_DWORD *)(v6 + 4) = v22 + 1;
        if ( (unsigned int)v22 > 0x32 )
          goto LABEL_75;
        v23 = (char *)(v6 + 176 + (v22 << 10));
        memcpy(v23, (const void *)v13, 0x400u);
        _mutex_init(v23 + 16, "&dup_sess->smmucb[DEFAULT_SMMU_IDX].map_mutex", &fastrpc_cb_probe___key_535);
        ++v21;
      }
      while ( v21 < v49 );
    }
  }
  raw_spin_unlock_irqrestore(v6 + 51600, v45);
  if ( !of_get_property(a1[95], "qrtr-gen-pool", 0) )
    goto LABEL_40;
  variable_u32_array = of_property_read_variable_u32_array(a1[95], "frpc-gen-addr-pool", v53, 2, 0);
  if ( (variable_u32_array & 0x80000000) == 0 )
  {
    v43[10] = SLODWORD(v53[0]);
    v43[11] = SHIDWORD(v53[0]);
    v31 = (_QWORD *)_kmalloc_cache_noprof(_usecs_to_jiffies, 3520, 224);
    v32 = v31;
    if ( !v31 || (unsigned __int64)v31 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v1, "allocation failed for size 0x%zx\n", 0xE0u);
      v5 = -12;
      goto LABEL_5;
    }
    v31[16] = v31 + 16;
    v31[17] = v31 + 16;
    *v31 = v31;
    v31[1] = v31;
    _mutex_init(v31 + 10, "&buf->lock", &fastrpc_cb_probe___key_542);
    v33 = SHIDWORD(v53[0]);
    v32[8] = 0;
    v32[6] = 0;
    v32[9] = v33;
    v34 = *v43;
    v32[18] = 0;
    v32[4] = v34;
    v35 = (const void *)dma_alloc_attrs();
    v32[6] = v35;
    if ( v35 && (unsigned __int64)v35 < 0xFFFFFFFFFFFFF001LL )
    {
      sgtable_attrs = dma_get_sgtable_attrs(*v43, &v46, v35, v32[8], v32[9], 0);
      if ( sgtable_attrs )
      {
        v5 = sgtable_attrs;
        dev_err(v1, "dma_get_sgtable_attrs failed with err %d", sgtable_attrs);
      }
      else
      {
        domain_for_dev = iommu_get_domain_for_dev(*v43);
        if ( domain_for_dev )
        {
          v39 = domain_for_dev;
          v5 = iommu_map_sg(domain_for_dev, SLODWORD(v53[0]), v46, (unsigned int)v47, 7, 3264);
          if ( (v5 & 0x80000000) != 0 )
          {
            dev_err(v1, "iommu_map_sg failed with err %d", v5);
          }
          else
          {
            v40 = devm_gen_pool_create(*v43, 0, 0xFFFFFFFFLL, 0);
            v41 = v40;
            if ( v40 < 0xFFFFFFFFFFFFF001LL )
            {
              v42 = gen_pool_add_owner(v40, v32[6], v32[8], v32[9], 0xFFFFFFFFLL, 0);
              if ( !v42 )
              {
                v43[8] = v41;
                v43[9] = v32;
                dev_err(v1, "fastrpc_cb_probe qrtr-gen-pool end\n");
LABEL_40:
                if ( *v44 == 64 )
                  v24 = -1;
                else
                  v24 = ~(-1LL << *v44);
                v25 = dma_set_mask(v1, v24);
                if ( v25 )
                {
                  v5 = v25;
                  dev_err(v1, "32-bit DMA enable failed\n");
                }
                else
                {
                  if ( v3 && !qword_27540 )
                  {
                    file = debugfs_create_file("global", 420, v3, 0, &fastrpc_debugfs_fops);
                    if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
                    {
                      printk(&unk_24B81, _ReadStatusReg(SP_EL0) + 2320, "fastrpc_cb_probe", v27, v28, v29);
                      file = 0;
                    }
                    qword_27540 = file;
                  }
                  dev_info(v1, "Successfully added %s", *v1);
                  v5 = 0;
                }
                goto LABEL_5;
              }
              v5 = v42;
              dev_err(v1, "gen_pool_add_virt failed with err %d", v42);
              gen_pool_destroy(v41);
            }
            else
            {
              dev_err(v1, "devm_gen_pool_create failed with err %d", v40);
              v5 = v41;
            }
            iommu_unmap(v39, v43[10], v43[11]);
          }
        }
        else
        {
          dev_err(v1, "iommu_get_domain_for_dev failed ");
          v5 = 0;
        }
      }
      dma_free_attrs(*v43, v32[9], v32[6], v32[8] & ~(-1LL << *((_DWORD *)v43 + 35)), 0);
    }
    else
    {
      dev_err(v1, "dma_alloc failed for size 0x%llx, returned %pK\n", v32[9], v35);
      v5 = -105;
    }
    kfree(v32);
    goto LABEL_5;
  }
  v38 = (const char *)a1[16];
  v5 = variable_u32_array & (variable_u32_array >> 31);
  if ( !v38 )
    v38 = *v1;
  dev_err(v1, "Error: parsing frpc-gen-addr-pool arguments failed for %s with err %d\n", v38, v5);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v5;
}
