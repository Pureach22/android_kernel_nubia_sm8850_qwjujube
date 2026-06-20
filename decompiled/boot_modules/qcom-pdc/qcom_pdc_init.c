__int64 __fastcall qcom_pdc_init(__int64 a1, __int64 a2)
{
  __int64 v3; // x28
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 matching_fwspec; // x0
  unsigned int v8; // w8
  int u32_index; // w0
  __int64 v10; // x0
  __int64 v11; // x26
  int v12; // w22
  char v13; // w9
  _DWORD *v14; // x8
  __int64 v15; // x21
  unsigned int v16; // w22
  __int64 v17; // x28
  int v18; // w0
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w8
  __int64 v22; // x3
  __int64 hierarchy; // x0
  __int64 v24; // x8
  __int64 property; // x8
  __int64 v26; // x0
  _QWORD *v27; // x9
  __int64 v28; // x10
  __int64 v29; // x0
  unsigned int v30; // w20
  __int64 v31; // [xsp+8h] [xbp-C8h]
  __int64 v32; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v33; // [xsp+18h] [xbp-B8h]
  __int64 v34; // [xsp+20h] [xbp-B0h]
  __int64 v35; // [xsp+28h] [xbp-A8h]
  __int64 v36; // [xsp+30h] [xbp-A0h]
  __int64 v37; // [xsp+38h] [xbp-98h]
  __int64 v38; // [xsp+40h] [xbp-90h]
  __int64 v39; // [xsp+48h] [xbp-88h]
  __int64 v40; // [xsp+50h] [xbp-80h]
  __int64 v41; // [xsp+58h] [xbp-78h]
  __int64 v42; // [xsp+60h] [xbp-70h]
  __int64 v43; // [xsp+68h] [xbp-68h]
  __int64 v44; // [xsp+70h] [xbp-60h] BYREF
  __int64 v45; // [xsp+78h] [xbp-58h]
  __int64 v46; // [xsp+80h] [xbp-50h]
  __int64 v47; // [xsp+88h] [xbp-48h]
  __int64 v48; // [xsp+90h] [xbp-40h]
  __int64 v49; // [xsp+98h] [xbp-38h]
  __int64 v50; // [xsp+A0h] [xbp-30h]
  __int64 v51; // [xsp+A8h] [xbp-28h]
  __int64 v52; // [xsp+B0h] [xbp-20h]
  __int64 v53; // [xsp+B8h] [xbp-18h]
  __int64 v54; // [xsp+C0h] [xbp-10h]

  v3 = a1;
  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( !(unsigned int)of_address_to_resource(a1, 0, &v32) )
  {
    if ( !((unsigned __int64)(v33 - v32 + 1) >> 16) )
      printk(&unk_7052, v3);
    v5 = ((__int64 (*)(void))ioremap_prot)();
    pdc_base = v5;
    if ( !v5 )
    {
      printk(&unk_7154, v3);
      result = 4294967290LL;
      goto LABEL_47;
    }
    pdc_version = readl_relaxed(v5 + 4096);
    if ( a2 )
      v6 = a2 + 24;
    else
      v6 = 0;
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = v6;
    v45 = 0;
    matching_fwspec = irq_find_matching_fwspec(&v44, 1);
    if ( !matching_fwspec )
    {
      v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      v48 = 0;
      v49 = 0;
      v46 = 0;
      v47 = 0;
      v44 = v6;
      v45 = 0;
      matching_fwspec = irq_find_matching_fwspec(&v44, 0);
      if ( !matching_fwspec )
      {
        printk(&unk_6FF8, v3);
        v30 = -6;
        goto LABEL_46;
      }
    }
    v31 = matching_fwspec;
    v8 = of_property_count_elems_of_size(v3, "qcom,pdc-ranges", 4);
    u32_index = -22;
    if ( (int)v8 >= 1 && !(v8 % 3) )
    {
      pdc_region_cnt = v8 / 3;
      v10 = _kmalloc_noprof(12LL * (v8 / 3), 3520);
      pdc_region = v10;
      if ( v10 )
      {
        if ( pdc_region_cnt >= 1 )
        {
          v11 = 0;
          do
          {
            v12 = 3 * v11;
            u32_index = of_property_read_u32_index(v3, "qcom,pdc-ranges", (unsigned int)(3 * v11), v10 + 12 * v11);
            if ( u32_index )
              goto LABEL_45;
            u32_index = of_property_read_u32_index(
                          v3,
                          "qcom,pdc-ranges",
                          (unsigned int)(v12 + 1),
                          pdc_region + 12 * v11 + 4);
            if ( u32_index )
              goto LABEL_45;
            u32_index = of_property_read_u32_index(
                          v3,
                          "qcom,pdc-ranges",
                          (unsigned int)(v12 + 2),
                          pdc_region + 12 * v11 + 8);
            if ( u32_index )
              goto LABEL_45;
            v10 = pdc_region;
            v14 = (_DWORD *)(pdc_region + 12 * v11);
            if ( v14[2] )
            {
              v15 = v3;
              v16 = 0;
              do
              {
                v21 = v16 + *v14;
                if ( (unsigned int)pdc_version >> 9 > 0x180 )
                {
                  v17 = 4LL * v21;
                  v18 = readl_relaxed(pdc_base + v17 + 272);
                  v19 = 272;
                  v20 = v18 & 0xFFFFFFF7;
                }
                else
                {
                  v17 = 4LL * (unsigned int)((int)v21 / 32);
                  v20 = (unsigned int)readl_relaxed(pdc_base + v17 + 16) & ~(unsigned int)(1LL << (v21 - (v13 & 0xE0)));
                  v19 = 16;
                }
                writel_relaxed(v20, pdc_base + v19 + v17);
                v10 = pdc_region;
                v14 = (_DWORD *)(pdc_region + 12 * v11);
                ++v16;
              }
              while ( v16 < v14[2] );
              v3 = v15;
            }
          }
          while ( ++v11 < pdc_region_cnt );
        }
        if ( (unsigned int)of_address_to_resource(v3, 1, &v32) )
          goto LABEL_28;
        spi_cfg = _kmalloc_cache_noprof(kfree, 3520, 24);
        if ( spi_cfg )
        {
          property = of_find_property(v3, "qcom,scm-spi-cfg", 0);
          v26 = v32;
          v27 = (_QWORD *)spi_cfg;
          v28 = v33 - v32;
          *(_BYTE *)(spi_cfg + 16) = property != 0;
          v27[1] = v28 + 1;
          if ( property )
          {
            *v27 = v26;
LABEL_28:
            if ( v3 )
              v22 = v3 + 24;
            else
              v22 = 0;
            hierarchy = irq_domain_create_hierarchy(v31, 0x10000, 256, v22, &qcom_pdc_ops, 0);
            if ( hierarchy )
            {
              irq_domain_update_bus_token(hierarchy, 9);
              v24 = ipc_log_context_create(2, "pdc", 0);
              result = 0;
              pdc_ipc_log = v24;
              goto LABEL_47;
            }
            printk(&unk_70F5, v3);
            if ( spi_cfg && *(_QWORD *)spi_cfg )
              ((void (*)(void))iounmap)();
            goto LABEL_42;
          }
          v29 = ioremap_prot(v26);
          *(_QWORD *)spi_cfg = v29;
          if ( v29 )
            goto LABEL_28;
        }
LABEL_42:
        v30 = -12;
LABEL_46:
        kfree(spi_cfg);
        kfree(pdc_region);
        iounmap(pdc_base);
        result = v30;
        goto LABEL_47;
      }
      u32_index = -12;
      pdc_region_cnt = 0;
    }
LABEL_45:
    v30 = u32_index;
    printk(&unk_7024, v3);
    goto LABEL_46;
  }
  result = 4294967274LL;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
