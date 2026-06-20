_QWORD *__fastcall qce_open(__int64 a1, int *a2)
{
  _QWORD *v4; // x19
  __int64 v5; // x2
  __int64 v6; // x0
  _BOOL4 v7; // w9
  __int64 v8; // x0
  bool v9; // w9
  __int64 v10; // x0
  bool v11; // w9
  __int64 v12; // x0
  bool v13; // w9
  __int64 v14; // x0
  bool v15; // w9
  __int64 v16; // x0
  bool v17; // w9
  __int64 v18; // x0
  bool v19; // w9
  __int64 v20; // x0
  bool v21; // w9
  __int64 v22; // x0
  bool v23; // w9
  __int64 v24; // x0
  bool v25; // w9
  __int64 v26; // x0
  bool v27; // w9
  __int64 v28; // x0
  __int64 property; // x0
  __int64 v30; // x2
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x0
  __int64 v34; // x2
  __int64 v35; // x2
  __int64 v36; // x2
  __int64 v37; // x2
  __int64 v38; // x2
  bool v39; // w9
  __int64 v40; // x0
  __int64 v41; // x0
  int v42; // w12
  int v43; // w9
  int v44; // w8
  int v45; // w12
  int v46; // w11
  int v47; // w10
  int v48; // w8
  int v49; // w9
  int v50; // w11
  int v51; // w12
  _QWORD *resource_byname; // x0
  __int64 v53; // x2
  int v54; // w9
  __int64 v55; // x2
  __int64 v56; // x0
  __int64 v57; // x2
  __int64 v58; // x0
  __int64 v59; // x2
  int irq_byname; // w0
  int irq; // w0
  __int64 v62; // x2
  int v63; // w0
  __int64 v64; // x2
  int v65; // w8
  __int64 v66; // x21
  _DWORD *v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x2
  __int64 v72; // x0
  __int64 v73; // x0
  unsigned __int64 v74; // x0
  __int64 v75; // x2
  unsigned int v76; // w0
  void *v77; // x0
  unsigned __int64 v78; // x0
  __int64 v79; // x2
  unsigned __int64 v80; // x0
  __int64 v81; // x2
  unsigned __int64 v82; // x0
  __int64 v83; // x2
  int v84; // w0
  int v85; // w21
  int v86; // w0
  __int64 v87; // x2
  __int64 v89; // x8
  int v90; // w10
  unsigned int v91; // w21

  v4 = (_QWORD *)_kmalloc_large_noprof(70312, 3520);
  if ( v4 )
  {
    *v4 = a1 + 16;
    mutex_lock(&qce_iomap_mutex);
    v6 = *(_QWORD *)(a1 + 760);
    if ( !v6 )
    {
      *a2 = -22;
      printk(&unk_1547F, "qce_open", v5);
LABEL_82:
      mutex_unlock(&qce_iomap_mutex);
      kfree(v4);
      return nullptr;
    }
    v7 = of_find_property(v6, "qcom,ce-hw-shared", 0) != 0;
    v8 = *(_QWORD *)(a1 + 760);
    *((_DWORD *)v4 + 15) = v7;
    v9 = of_find_property(v8, "qcom,ce-hw-key", 0) != 0;
    v10 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 69) = v9;
    v11 = of_find_property(v10, "qcom,use-sw-aes-cbc-ecb-ctr-algo", 0) != 0;
    v12 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 136) = v11;
    v13 = of_find_property(v12, "qcom,use-sw-aead-algo", 0) != 0;
    v14 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 137) = v13;
    v15 = of_find_property(v14, "qcom,use-sw-aes-xts-algo", 0) != 0;
    v16 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 138) = v15;
    v17 = of_find_property(v16, "qcom,use-sw-ahash-algo", 0) != 0;
    v18 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 139) = v17;
    v19 = of_find_property(v18, "qcom,use-sw-hmac-algo", 0) != 0;
    v20 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 140) = v19;
    v21 = of_find_property(v20, "qcom,use-sw-aes-ccm-algo", 0) != 0;
    v22 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 141) = v21;
    v23 = of_find_property(v22, "qcom,clk-mgmt-sus-res", 0) != 0;
    v24 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 70) = v23;
    v25 = of_find_property(v24, "qcom,support-core-clk-only", 0) != 0;
    v26 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 71) = v25;
    v27 = of_find_property(v26, "qcom,request-bw-before-clk", 0) != 0;
    v28 = *(_QWORD *)(a1 + 760);
    *((_BYTE *)v4 + 72) = v27;
    property = of_find_property(v28, "qcom,use-key-index", 0);
    *((_BYTE *)v4 + 73) = property != 0;
    if ( property )
    {
      printk(&unk_151AC, "__qce_get_device_tree_data", v30);
      *((_BYTE *)v4 + 70253) = 1;
    }
    else
    {
      printk(&unk_15A30, "__qce_get_device_tree_data", v30);
    }
    v31 = *(_QWORD *)(a1 + 760);
    *(_QWORD *)((char *)v4 + 324) = 0;
    *(_QWORD *)((char *)v4 + 332) = 0;
    *(_QWORD *)((char *)v4 + 316) = 0;
    *((_BYTE *)v4 + 70250) = 1;
    if ( (of_property_read_variable_u32_array(v31, "qcom,bam-pipe-pair", (char *)v4 + 316, 1, 0) & 0x80000000) != 0 )
    {
      printk(&unk_15DEB, "__qce_get_device_tree_data", v32);
      *((_BYTE *)v4 + 70250) = 0;
      *((_DWORD *)v4 + 79) = 2;
    }
    if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,offload-ops-support", 0) )
    {
      v33 = *(_QWORD *)(a1 + 760);
      *((_BYTE *)v4 + 70251) = 1;
      if ( (of_property_read_variable_u32_array(v33, "qcom,bam-pipe-offload-cpb-hlos", v4 + 42, 1, 0) & 0x80000000) != 0 )
      {
        v77 = &unk_150C5;
        goto LABEL_66;
      }
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,bam-pipe-offload-hlos-hlos", v4 + 40, 1, 0)
          & 0x80000000) != 0 )
      {
        v77 = &unk_14C71;
        goto LABEL_66;
      }
      if ( (of_property_read_variable_u32_array(
              *(_QWORD *)(a1 + 760),
              "qcom,bam-pipe-offload-hlos-hlos-1",
              (char *)v4 + 324,
              1,
              0)
          & 0x80000000) != 0 )
        printk(&unk_154B6, "__qce_get_device_tree_data", v35);
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,bam-pipe-offload-hlos-cpb", v4 + 41, 1, 0)
          & 0x80000000) != 0 )
      {
        v77 = &unk_1617F;
        goto LABEL_66;
      }
      if ( (of_property_read_variable_u32_array(
              *(_QWORD *)(a1 + 760),
              "qcom,bam-pipe-offload-hlos-cpb-1",
              (char *)v4 + 332,
              1,
              0)
          & 0x80000000) != 0 )
        printk(&unk_14DCD, "__qce_get_device_tree_data", v36);
    }
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ce-device", v4 + 38, 1, 0) & 0x80000000) != 0 )
    {
      v77 = &unk_14E8E;
    }
    else
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ce-hw-instance", (char *)v4 + 308, 1, 0)
          & 0x80000000) == 0 )
      {
        if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,bam-ee", v4 + 39, 1, 0) & 0x80000000) != 0 )
        {
          printk(&unk_1524E, "__qce_get_device_tree_data", v37);
          *((_DWORD *)v4 + 78) = 1;
        }
        if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,ce-opp-freq", (char *)v4 + 132, 1, 0)
            & 0x80000000) != 0 )
        {
          printk(&unk_165D3, "__qce_get_device_tree_data", v38);
          *((_DWORD *)v4 + 33) = 100000000;
        }
        if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,smmu-s1-enable", 0) )
          *((_BYTE *)v4 + 70248) = 1;
        v39 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,no-clock-support", 0) != 0;
        v40 = *(_QWORD *)(a1 + 760);
        *((_BYTE *)v4 + 70249) = v39;
        v41 = of_find_property(v40, "qcom,no-clk-gating", 0);
        v42 = 2 * *((_DWORD *)v4 + 79);
        v43 = v42 | 1;
        v44 = 2 * *((_DWORD *)v4 + 80);
        *((_BYTE *)v4 + 70252) = v41 != 0;
        *((_DWORD *)v4 + 91) = v42;
        v45 = *((_DWORD *)v4 + 81);
        v46 = v44 | 1;
        *((_DWORD *)v4 + 85) = v43;
        v47 = *((_DWORD *)v4 + 82);
        *((_DWORD *)v4 + 92) = v44;
        v48 = 2 * v45;
        v49 = (2 * v45) | 1;
        *((_DWORD *)v4 + 86) = v46;
        v50 = *((_DWORD *)v4 + 83);
        v51 = *((_DWORD *)v4 + 84);
        *((_DWORD *)v4 + 93) = v48;
        *((_DWORD *)v4 + 87) = v49;
        *((_DWORD *)v4 + 94) = 2 * v47;
        *((_DWORD *)v4 + 88) = (2 * v47) | 1;
        *((_DWORD *)v4 + 95) = 2 * v50;
        *((_DWORD *)v4 + 89) = (2 * v50) | 1;
        *((_DWORD *)v4 + 96) = 2 * v51;
        *((_DWORD *)v4 + 90) = (2 * v51) | 1;
        resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, "crypto-base");
        if ( !resource_byname )
        {
          printk(&unk_15A77, "__qce_get_device_tree_data", v53);
          *a2 = -19;
          goto LABEL_82;
        }
        v54 = arm64_use_ng_mappings;
        *((_DWORD *)v4 + 22) = *resource_byname;
        if ( v54 )
          v55 = 0x68000000000F13LL;
        else
          v55 = 0x68000000000713LL;
        v56 = ioremap_prot(*resource_byname, resource_byname[1] - *resource_byname + 1LL, v55);
        v4[10] = v56;
        if ( !v56 )
        {
          printk(&unk_15104, "__qce_get_device_tree_data", v57);
          *a2 = -12;
          goto LABEL_82;
        }
        v58 = platform_get_resource_byname(a1, 512, "crypto-bam-base");
        if ( v58 )
        {
          *((_DWORD *)v4 + 13) = *(_QWORD *)v58;
          *((_DWORD *)v4 + 14) = *(_DWORD *)(v58 + 8) - *(_DWORD *)v58 + 1;
          irq_byname = platform_get_irq_byname(a1, "bam-irq");
          *((_DWORD *)v4 + 72) = irq_byname;
          if ( (irq_byname & 0x80000000) == 0
            || (irq = platform_get_irq(a1, 0), *((_DWORD *)v4 + 72) = irq, (irq & 0x80000000) == 0) )
          {
            v63 = platform_get_irq_byname(a1, "core-irq");
            *((_DWORD *)v4 + 16) = v63;
            *((_BYTE *)v4 + 70261) = 1;
            if ( v63 < 0 )
            {
              printk(&unk_16622, "__qce_get_device_tree_data", v64);
              *((_BYTE *)v4 + 70261) = 0;
            }
            v65 = *((unsigned __int8 *)v4 + 70248);
            *a2 = 0;
            if ( v65 == 1 )
            {
              v66 = *v4;
              v67 = *(_DWORD **)(*v4 + 672LL);
              if ( !v67 )
              {
                v67 = (_DWORD *)devm_kmalloc(*v4, 16, 3520);
                *(_QWORD *)(v66 + 672) = v67;
                if ( !v67 )
                {
                  *a2 = -5;
                  goto LABEL_82;
                }
              }
              *v67 = -1;
              v68 = *(_QWORD *)(v66 + 672);
              if ( v68 )
                *(_QWORD *)(v68 + 8) = -1;
              else
                __break(0x800u);
            }
            *((_DWORD *)v4 + 656) = 0;
            *((_DWORD *)v4 + 2514) = 0;
            *((_DWORD *)v4 + 4372) = 0;
            *((_DWORD *)v4 + 6230) = 0;
            *((_DWORD *)v4 + 8088) = 0;
            *((_DWORD *)v4 + 9946) = 0;
            *((_DWORD *)v4 + 11804) = 0;
            *((_DWORD *)v4 + 13662) = 0;
            *((_DWORD *)v4 + 15520) = 0;
            v69 = *v4;
            *((_DWORD *)v4 + 17378) = 0;
            *((_DWORD *)v4 + 8) = 368640;
            v70 = dma_alloc_attrs(v69, 368640, v4 + 3, 3264, 0);
            v4[2] = v70;
            if ( !v70 )
            {
              *a2 = -12;
              printk(&unk_14F3A, "qce_open", v71);
LABEL_80:
              if ( v4[10] )
                iounmap();
              goto LABEL_82;
            }
            *((_DWORD *)v4 + 12) = 73728;
            v72 = _kmalloc_noprof(*((int *)v4 + 12), 3520);
            v4[5] = v72;
            if ( !v72 || (v73 = _kmalloc_cache_noprof(kfree, 3520, 64), (v4[8779] = v73) == 0) )
            {
LABEL_78:
              kfree(v4[8779]);
              kfree(v4[5]);
              v87 = v4[2];
              if ( v87 )
                dma_free_attrs(*v4, *((int *)v4 + 8), v87, v4[3], 0);
              goto LABEL_80;
            }
            if ( (*((_BYTE *)v4 + 70249) & 1) != 0 )
            {
LABEL_54:
              *a2 = 0;
              v84 = qce_enable_clk((__int64)v4);
              *a2 = v84;
              if ( !v84 )
              {
                if ( (unsigned int)probe_ce_engine(v4) )
                {
                  *a2 = -6;
                }
                else
                {
                  *a2 = 0;
                  tasklet_init(v4 + 8783, qce_core_irq_bottom_half, v4);
                  qce_core_irq_init(v4);
                  qce_init_ce_cfg_val(v4);
                  qce_parse_soc_revision(v4);
                  v86 = qce_sps_init(v4);
                  *a2 = v86;
                  if ( !v86 )
                  {
                    qce_setup_ce_sps_data(v4);
                    qce_disable_clk((__int64)v4);
                    setup_recovery_req(v4);
                    setup_dummy_req(v4);
                    *((_DWORD *)v4 + 17380) = 0;
                    *((_DWORD *)v4 + 17548) = 0;
                    init_timer_key(v4 + 8691, qce_multireq_timeout, 0, 0, 0);
                    v89 = jiffies;
                    v90 = qce_open_pcedev_no;
                    *((_DWORD *)v4 + 17549) = 0;
                    *((_DWORD *)v4 + 17379) = 0;
                    *((_DWORD *)v4 + 17550) = v90;
                    v4[8693] = v89 + 5;
                    qce_open_pcedev_no = v90 + 1;
                    qce_enable_clock_gating(v4);
                    mutex_unlock(&qce_iomap_mutex);
                    return v4;
                  }
                }
                qce_disable_clk((__int64)v4);
              }
              if ( (*((_BYTE *)v4 + 70249) & 1) == 0 )
              {
                if ( v4[15] )
                  clk_put();
                if ( v4[14] )
                  clk_put();
                if ( v4[13] )
                  clk_put();
                if ( v4[12] )
                  clk_put();
              }
              goto LABEL_78;
            }
            v74 = clk_get(*v4, "core_clk_src");
            v4[12] = v74;
            if ( v74 > 0xFFFFFFFFFFFFF000LL )
            {
              if ( *((_BYTE *)v4 + 71) == 1 )
              {
                v91 = v74;
                v4[12] = 0;
                printk(&unk_154E5, "__qce_init_clk", v75);
LABEL_105:
                *a2 = v91;
                goto LABEL_78;
              }
              printk(&unk_163FE, "__qce_init_clk", v75);
              v4[12] = 0;
            }
            else if ( (v4[9] & 1) == 0 )
            {
              v76 = clk_set_rate();
              if ( v76 )
              {
                v91 = v76;
                printk(&unk_166E0, "__qce_init_clk", *((unsigned int *)v4 + 33) / 0xF4240uLL);
                if ( !v4[12] )
                  goto LABEL_104;
                goto LABEL_103;
              }
            }
            if ( *((_BYTE *)v4 + 71) == 1 )
            {
              v4[14] = 0;
              v4[15] = 0;
              v4[13] = 0;
              goto LABEL_54;
            }
            v78 = clk_get(*v4, "core_clk");
            v4[13] = v78;
            if ( v78 >= 0xFFFFFFFFFFFFF001LL )
            {
              v91 = v78;
              printk(&unk_14E17, "__qce_init_clk", v79);
              if ( !v4[12] )
                goto LABEL_104;
              goto LABEL_103;
            }
            v80 = clk_get(*v4, "iface_clk");
            v4[14] = v80;
            if ( v80 >= 0xFFFFFFFFFFFFF001LL )
            {
              v91 = v80;
              printk(&unk_159A9, "__qce_init_clk", v81);
              if ( !v4[13] )
                goto LABEL_102;
            }
            else
            {
              v82 = clk_get(*v4, "bus_clk");
              v4[15] = v82;
              if ( v82 < 0xFFFFFFFFFFFFF001LL )
                goto LABEL_54;
              v91 = v82;
              printk(&unk_16715, "__qce_init_clk", v83);
              if ( v4[14] )
              {
                clk_put();
                if ( !v4[13] )
                {
LABEL_102:
                  if ( !v4[12] )
                  {
LABEL_104:
                    printk(&unk_16073, "__qce_init_clk", v91);
                    goto LABEL_105;
                  }
LABEL_103:
                  clk_put();
                  goto LABEL_104;
                }
              }
              else if ( !v4[13] )
              {
                goto LABEL_102;
              }
            }
            clk_put();
            if ( !v4[12] )
              goto LABEL_104;
            goto LABEL_103;
          }
          printk(&unk_1538B, "__qce_get_device_tree_data", v62);
          if ( v4[37] )
            iounmap();
          v85 = -22;
        }
        else
        {
          printk(&unk_163D4, "__qce_get_device_tree_data", v59);
          v85 = -19;
        }
        if ( v4[10] )
          iounmap();
        *a2 = v85;
        goto LABEL_82;
      }
      v77 = &unk_14B3B;
    }
LABEL_66:
    printk(v77, "__qce_get_device_tree_data", v34);
    *a2 = -22;
    goto LABEL_82;
  }
  *a2 = -12;
  printk(&unk_15D19, "qce_open", 4294967284LL);
  return v4;
}
