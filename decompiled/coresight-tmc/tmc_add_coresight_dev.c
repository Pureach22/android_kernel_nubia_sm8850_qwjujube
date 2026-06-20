__int64 __fastcall tmc_add_coresight_dev(__int64 *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x19
  unsigned int *platform_data; // x22
  unsigned __int64 v9; // x21
  __int64 property; // x0
  unsigned int v11; // w0
  int v12; // w8
  unsigned int v13; // w21
  int v14; // w9
  unsigned int v15; // w10
  __int64 v16; // x0
  int v17; // w8
  int v18; // w0
  int v19; // w8
  int v20; // w0
  int v21; // w0
  int v22; // w19
  unsigned __int64 v23; // x0
  int v24; // w9
  __int64 *v25; // x8
  void *v26; // x0
  __int64 (__fastcall ***v27)(); // x9
  unsigned __int64 v28; // x0
  __int64 v29; // x26
  __int64 v30; // x9
  int v31; // w23
  int v32; // w24
  int v33; // w25
  __int64 v34; // x2
  __int64 v35; // x3
  __int64 v36; // x4
  __int64 v37; // x5
  __int64 v38; // x6
  __int64 v39; // x7
  unsigned int v40; // w9
  __int64 v41; // x8
  _QWORD *v42; // x8
  __int64 v43; // x8
  unsigned int v44; // w22
  unsigned __int64 v45; // x0
  int v46; // w8
  __int64 v47; // x21
  int v48; // w22
  unsigned int v49; // w8
  unsigned __int64 v50; // t2
  int v51; // w0
  unsigned __int64 v52; // x19
  __int64 v54; // [xsp+0h] [xbp-60h] BYREF
  __int64 v55; // [xsp+8h] [xbp-58h] BYREF
  __int64 (__fastcall ***v56)(); // [xsp+10h] [xbp-50h]
  unsigned int *v57; // [xsp+18h] [xbp-48h]
  __int64 *v58; // [xsp+20h] [xbp-40h]
  _UNKNOWN **v59; // [xsp+28h] [xbp-38h]
  __int64 v60; // [xsp+30h] [xbp-30h]
  __int64 v61; // [xsp+38h] [xbp-28h]
  unsigned int *v62; // [xsp+40h] [xbp-20h]
  __int64 v63; // [xsp+48h] [xbp-18h]
  unsigned int v64; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v65; // [xsp+58h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1[19];
  v62 = nullptr;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = nullptr;
  v59 = nullptr;
  v56 = nullptr;
  v57 = nullptr;
  v54 = 0;
  v55 = 0;
  if ( !v6 )
  {
    LODWORD(platform_data) = -12;
    goto LABEL_79;
  }
  platform_data = (unsigned int *)devm_ioremap_resource(a1, a2, a3, a4, a5, a6);
  if ( (unsigned __int64)platform_data >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_79;
  v9 = devm_clk_get(a1, "atclk");
  *(_QWORD *)(v6 + 360) = v9;
  if ( v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    property = of_find_property(a1[93], "qcom,atclk-dependence", 0);
    v9 = *(_QWORD *)(v6 + 360);
    if ( property )
    {
      dev_err(a1, "get atclk fail %ld\n", *(_QWORD *)(v6 + 360));
      LODWORD(platform_data) = *(_DWORD *)(v6 + 360);
      goto LABEL_79;
    }
  }
  if ( v9 <= 0xFFFFFFFFFFFFF000LL )
  {
    v20 = clk_prepare(v9);
    if ( !v20 )
    {
      v21 = clk_enable(v9);
      if ( !v21 )
        goto LABEL_8;
      v22 = v21;
      clk_unprepare(v9);
      v20 = v22;
    }
    if ( v20 == -110 )
      LODWORD(platform_data) = -517;
    else
      LODWORD(platform_data) = v20;
    goto LABEL_79;
  }
LABEL_8:
  *(_QWORD *)(v6 + 8) = platform_data;
  LOBYTE(v61) = 1;
  *(_DWORD *)((char *)&v61 + 1) = 0;
  HIDWORD(v61) = 0;
  v62 = platform_data;
  v63 = 0;
  *(_DWORD *)(v6 + 104) = 0;
  _mutex_init(v6 + 152, "&drvdata->mem_lock", &tmc_add_coresight_dev___key);
  v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(v6 + 8) + 4040LL));
  v12 = (unsigned __int8)v11 >> 6;
  v13 = v11;
  v14 = 0;
  v15 = ((v11 >> 8) & 7) - 2;
  *(_DWORD *)(v6 + 140) = v12;
  if ( v15 <= 3 )
    v14 = dword_109B4[v15];
  *(_DWORD *)(v6 + 144) = v14;
  *(_DWORD *)(v6 + 108) = -1;
  *(_DWORD *)(v6 + 208) = 3;
  if ( v12 == 1 )
  {
    *(_DWORD *)(v6 + 332) = 1;
    v16 = a1[94];
    v64 = 0;
    if ( (unsigned int)fwnode_property_read_u32_array(v16, "arm,buffer-size", &v64, 1) )
      v17 = 0x100000;
    else
      v17 = v64;
    v64 = 0;
    *(_DWORD *)(v6 + 132) = v17;
    v18 = fwnode_property_read_u32_array(a1[94], "arm,max-burst-size", &v64, 1);
    v19 = v64;
    if ( v64 >= 0xF )
      v19 = 15;
    if ( v18 )
      v19 = 15;
    *(_DWORD *)(v6 + 136) = v19;
  }
  else
  {
    *(_DWORD *)(v6 + 132) = 4 * readl_relaxed((unsigned int *)(*(_QWORD *)(v6 + 8) + 4LL));
  }
  if ( !(unsigned int)of_get_coresight_csr_name(a1[93], v6 + 320) )
  {
    v23 = coresight_csr_get(*(_QWORD *)(v6 + 320));
    *(_QWORD *)(v6 + 312) = v23;
    if ( v23 > 0xFFFFFFFFFFFFF000LL )
    {
      LODWORD(platform_data) = -517;
      goto LABEL_76;
    }
  }
  v24 = *(_DWORD *)(v6 + 140);
  v58 = a1;
  *(_BYTE *)(v6 + 344) = 0;
  if ( v24 == 2 )
  {
    v25 = &v55;
    v26 = &etf_devs;
    v59 = &coresight_etf_groups;
    v27 = tmc_etf_cs_ops;
    v54 = 0x200000002LL;
LABEL_34:
    v56 = v27;
    *(_DWORD *)v25 = 2;
    goto LABEL_35;
  }
  if ( v24 != 1 )
  {
    if ( v24 )
    {
      printk(&unk_FBFC, v60);
      LODWORD(platform_data) = -22;
      goto LABEL_76;
    }
    v25 = (__int64 *)((char *)&v54 + 4);
    v59 = &coresight_etf_groups;
    v26 = &etb_devs;
    LODWORD(v54) = 0;
    v27 = &tmc_etb_cs_ops;
    goto LABEL_34;
  }
  v29 = a1[19];
  v59 = &coresight_etr_groups;
  v56 = &tmc_etr_cs_ops;
  v30 = *(_QWORD *)(v29 + 8);
  v54 = 0x300000000LL;
  if ( (~(unsigned int)readl_relaxed((unsigned int *)(v30 + 4024)) & 3) != 0 )
  {
    LODWORD(platform_data) = -13;
    goto LABEL_76;
  }
  v31 = readl_relaxed(platform_data + 1016);
  v32 = readl_relaxed(platform_data + 1017);
  v33 = readl_relaxed(platform_data + 1018);
  readl_relaxed(platform_data + 1019);
  v40 = (v31 | (v32 << 8) | (v33 << 16)) & 0xFFFFF;
  LODWORD(v41) = 0;
  if ( v40 > 0xBB9E8 )
  {
    if ( v40 == 768489 )
    {
      v42 = &unk_10338;
    }
    else
    {
      if ( v40 != 768490 )
        goto LABEL_58;
      v42 = &unk_10348;
    }
  }
  else if ( v40 == 768353 )
  {
    v42 = &_mod_amba__tmc_ids_device_table;
  }
  else
  {
    if ( v40 != 768488 )
      goto LABEL_58;
    v42 = &unk_10328;
  }
  v41 = v42[1];
  if ( v41 )
    LODWORD(v41) = *(_DWORD *)(v41 + 16);
LABEL_58:
  if ( *(_DWORD *)(v29 + 204) )
    __break(0x800u);
  v44 = v13;
  *(_DWORD *)(v29 + 204) = v41;
  if ( (v13 & 0x1000000) == 0 )
  {
    v45 = a1[94];
    if ( v45 )
    {
      if ( v45 <= 0xFFFFFFFFFFFFF000LL
        && *(_UNKNOWN **)(v45 + 8) == &of_fwnode_ops
        && (fwnode_property_present(v45, "arm,scatter-gather", v34, v35, v36, v37, v38, v39, v54, v55) & 1) != 0 )
      {
        *(_DWORD *)(v29 + 204) |= 1u;
      }
    }
  }
  v46 = (v13 >> 17) & 0x7F;
  v47 = 0xFFFFFFFFFFLL;
  if ( (*(_QWORD *)&v44 & 0x10000LL) != 0 )
    v48 = v46;
  else
    v48 = 0;
  HIDWORD(v50) = v48 - 32;
  LODWORD(v50) = v48 - 32;
  v49 = v50 >> 2;
  if ( v49 <= 5 && v49 != 1 )
  {
    dev_info(a1, "Detected dma mask %dbits\n", v48);
    if ( v48 == 64 )
      v47 = -1;
    else
      v47 = ~(-1LL << v48);
  }
  v51 = dma_set_mask(a1, v47);
  if ( v51 )
  {
    LODWORD(platform_data) = v51;
    dev_err(a1, "Failed to setup DMA mask: %d\n", v51);
    goto LABEL_76;
  }
  dma_set_coherent_mask(a1, v47);
  *(_QWORD *)(v6 + 216) = 0x1000000400000000LL;
  *(_QWORD *)(v6 + 224) = 0;
  *(_QWORD *)(v6 + 232) = 0;
  _mutex_init(v6 + 240, "&drvdata->idr_mutex", &tmc_add_coresight_dev___key_9);
  *(_QWORD *)(v6 + 304) = byte_cntr_init(a1, v6);
  LODWORD(platform_data) = tmc_etr_usb_init(a1, v6);
  if ( !(_DWORD)platform_data )
  {
    v26 = &etr_devs;
LABEL_35:
    v60 = coresight_alloc_device_name(v26, a1);
    if ( v60 )
    {
      platform_data = (unsigned int *)coresight_get_platform_data(a1);
      if ( (unsigned __int64)platform_data <= 0xFFFFFFFFFFFFF000LL
        && (a1[18] = (__int64)platform_data,
            v57 = platform_data,
            v28 = coresight_register(&v54),
            LODWORD(platform_data) = v28,
            *(_QWORD *)(v6 + 16) = v28,
            v28 <= 0xFFFFFFFFFFFFF000LL) )
      {
        v43 = v60;
        *(_DWORD *)(v6 + 24) = 255;
        *(_QWORD *)(v6 + 32) = v43;
        *(_QWORD *)(v6 + 40) = &tmc_fops;
        LODWORD(platform_data) = misc_register();
        if ( !(_DWORD)platform_data )
        {
          *(_BYTE *)(v6 + 408) = 1;
          _pm_runtime_idle(a1, 4);
          goto LABEL_79;
        }
        coresight_unregister(*(_QWORD *)(v6 + 16));
      }
      else if ( !(_DWORD)platform_data )
      {
        goto LABEL_79;
      }
    }
    else
    {
      LODWORD(platform_data) = -12;
    }
  }
LABEL_76:
  v52 = *(_QWORD *)(v6 + 360);
  if ( v52 && v52 <= 0xFFFFFFFFFFFFF000LL )
  {
    clk_disable(v52);
    clk_unprepare(v52);
  }
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)platform_data;
}
