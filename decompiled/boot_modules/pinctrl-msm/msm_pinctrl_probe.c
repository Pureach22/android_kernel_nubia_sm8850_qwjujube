unsigned __int64 __fastcall msm_pinctrl_probe(_QWORD *a1, __int64 a2)
{
  __int64 *v2; // x22
  __int64 v5; // x0
  __int64 **v6; // x19
  int is_compatible; // w0
  _QWORD *v8; // x8
  unsigned __int64 result; // x0
  __int64 *v10; // x8
  int v11; // w24
  __int64 v12; // x26
  int v13; // w25
  __int64 *v14; // x8
  __int64 *v15; // x9
  unsigned __int64 v16; // x0
  __int64 *v17; // x8
  unsigned int v18; // w10
  __int64 *v19; // x9
  __int64 *v20; // x10
  __int64 v21; // x0
  __int64 matching_fwspec; // x0
  __int64 *v23; // x11
  unsigned int v24; // w8
  unsigned __int64 v25; // x11
  unsigned __int64 v26; // x12
  __int64 v27; // x11
  unsigned __int64 v34; // x13
  __int64 *v35; // x0
  __int64 v36; // x0
  __int64 *v37; // x8
  __int64 *v38; // x0
  unsigned __int64 v39; // x8
  __int64 *v40; // x0
  __int64 v41; // x1
  __int64 v42; // x0
  int v43; // w0
  __int64 v44; // x25
  __int64 v45; // x22
  __int64 v46; // x26
  __int64 v47; // x27
  unsigned int irq; // w24
  unsigned int v49; // w8
  int v50; // w22
  int u16_array; // w0
  __int64 *v52; // x21
  __int64 v53; // x26
  unsigned int v54; // w25
  __int64 v55; // x27
  int v56; // w8
  int *v57; // x8
  __int64 v58; // x1
  unsigned int v59; // w23
  __int64 mapping_affinity; // x0
  unsigned int v61; // w24
  __int64 irq_data; // x0
  __int64 v63; // x24
  __int64 data; // x23
  __int64 v65; // x0
  __int64 v66; // x9
  __int64 v67; // x24
  __int64 v68; // x28
  int v69; // w0
  unsigned __int64 v70; // x19
  unsigned __int64 v71; // x20
  _QWORD *resource_byname; // [xsp+0h] [xbp-60h] BYREF
  __int64 v73; // [xsp+8h] [xbp-58h] BYREF
  __int64 v74; // [xsp+10h] [xbp-50h]
  __int64 v75; // [xsp+18h] [xbp-48h]
  __int64 v76; // [xsp+20h] [xbp-40h]
  __int64 v77; // [xsp+28h] [xbp-38h]
  __int64 v78; // [xsp+30h] [xbp-30h]
  __int64 v79; // [xsp+38h] [xbp-28h]
  __int64 v80; // [xsp+40h] [xbp-20h]
  __int64 v81; // [xsp+48h] [xbp-18h]
  __int64 v82; // [xsp+50h] [xbp-10h]
  __int64 v83; // [xsp+58h] [xbp-8h]

  v2 = a1 + 2;
  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  resource_byname = nullptr;
  v5 = devm_kmalloc(a1 + 2, 1048, 3520);
  msm_pinctrl_data = v5;
  if ( !v5 )
    goto LABEL_53;
  v6 = (__int64 **)v5;
  *(_BYTE *)(v5 + 1040) = 0;
  *(_QWORD *)v5 = v2;
  *(_QWORD *)(v5 + 968) = a2;
  memcpy((void *)(v5 + 16), &msm_gpio_template, 0x270u);
  is_compatible = of_device_is_compatible(a1[95], "qcom,ipq8064-pinctrl");
  v8 = *(_QWORD **)(a2 + 56);
  *((_DWORD *)v6 + 191) = 0;
  *((_BYTE *)v6 + 760) = is_compatible != 0;
  if ( !v8 )
    goto LABEL_13;
  if ( *(_DWORD *)(a2 + 64) )
  {
    resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, *v8);
    result = devm_ioremap_resource(v2, resource_byname);
    v6[122] = (__int64 *)result;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_54;
    if ( *(_DWORD *)(a2 + 64) >= 2u )
    {
      resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, *(_QWORD *)(*(_QWORD *)(a2 + 56) + 8LL));
      result = devm_ioremap_resource(v2, resource_byname);
      v6[123] = (__int64 *)result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_54;
      if ( *(_DWORD *)(a2 + 64) >= 3u )
      {
        resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, *(_QWORD *)(*(_QWORD *)(a2 + 56) + 16LL));
        result = devm_ioremap_resource(v2, resource_byname);
        v6[124] = (__int64 *)result;
        if ( result > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_54;
        if ( *(_DWORD *)(a2 + 64) >= 4u )
        {
          resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, *(_QWORD *)(*(_QWORD *)(a2 + 56) + 24LL));
          result = devm_ioremap_resource(v2, resource_byname);
          v6[125] = (__int64 *)result;
          if ( result > 0xFFFFFFFFFFFFF000LL )
            goto LABEL_54;
          if ( *(_DWORD *)(a2 + 64) >= 5u )
          {
            resource_byname = (_QWORD *)platform_get_resource_byname(a1, 512, *(_QWORD *)(*(_QWORD *)(a2 + 56) + 32LL));
            devm_ioremap_resource(v2, resource_byname);
            __break(0x5512u);
LABEL_13:
            result = devm_platform_get_and_ioremap_resource(a1, 0, &resource_byname);
            v6[122] = (__int64 *)result;
            if ( result >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_54;
            *((_DWORD *)v6 + 252) = *resource_byname;
          }
        }
      }
    }
  }
  v10 = v6[121];
  v11 = *((_DWORD *)v10 + 6);
  if ( v11 )
  {
    v12 = v10[2];
    v13 = 0;
    while ( strcmp(*(const char **)(v12 + 24LL * v13), "ps_hold") )
    {
      if ( v11 == ++v13 )
        goto LABEL_23;
    }
    v6[91] = (__int64 *)msm_ps_hold_restart;
    *((_DWORD *)v6 + 186) = 128;
    if ( (unsigned int)register_restart_handler(v6 + 91) )
      dev_err(*v6, "failed to setup restart handler.\n");
    poweroff_pctrl = (__int64)v6;
    pm_power_off = msm_ps_hold_poweroff;
  }
LABEL_23:
  result = platform_get_irq(a1, 0);
  *((_DWORD *)v6 + 188) = result;
  if ( (result & 0x80000000) == 0 )
  {
    v6[83] = (__int64 *)msm_pinctrl_ops;
    v14 = (__int64 *)a1[16];
    v6[84] = (__int64 *)&msm_pinmux_ops;
    v6[86] = (__int64 *)&_this_module;
    v6[85] = (__int64 *)&msm_pinconf_ops;
    if ( !v14 )
      v14 = (__int64 *)*v2;
    v15 = v6[121];
    v6[80] = v14;
    v6[81] = (__int64 *)*v15;
    LODWORD(v15) = *((_DWORD *)v15 + 2);
    *((_DWORD *)v6 + 174) = 3;
    *((_DWORD *)v6 + 164) = (_DWORD)v15;
    v6[88] = (__int64 *)&msm_gpio_bindings;
    v16 = devm_pinctrl_register(v2, v6 + 80, v6);
    v6[1] = (__int64 *)v16;
    if ( v16 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v2, "Couldn't register pinctrl driver\n");
      result = *((unsigned int *)v6 + 2);
      goto LABEL_54;
    }
    v17 = v6[121];
    v18 = *((_DWORD *)v17 + 11);
    if ( v18 >= 0x12D )
    {
      __break(0x800u);
      result = 4294967274LL;
      goto LABEL_54;
    }
    v19 = *v6;
    *((_WORD *)v6 + 94) = v18;
    *((_DWORD *)v6 + 46) = -1;
    v20 = (__int64 *)v19[14];
    if ( !v20 )
      v20 = (__int64 *)*v19;
    v6[2] = v20;
    v6[4] = v19;
    v6[6] = (__int64 *)&_this_module;
    if ( !v17[9] )
    {
      v50 = of_property_count_elems_of_size(v19[93], "qcom,gpios-reserved", 4);
      u16_array = device_property_read_u16_array(*v6, "gpios", 0, 0);
      if ( v50 >= 1 && u16_array >= 1 )
      {
        dev_warn(*v6, "qcom,gpios-reserved and gpios are both defined. Only one should be used.\n");
      }
      else if ( v50 <= 0 && u16_array < 1 )
      {
LABEL_32:
        v21 = (*v6)[93];
        v81 = 0;
        v82 = 0;
        v79 = 0;
        v80 = 0;
        v77 = 0;
        v78 = 0;
        v75 = 0;
        v76 = 0;
        v73 = 0;
        v74 = 0;
        if ( !(unsigned int)_of_parse_phandle_with_args(v21, "wakeup-parent", 0, 0, 0, &v73) && v73 )
        {
          v81 = 0;
          v82 = 0;
          v79 = 0;
          v80 = 0;
          v77 = 0;
          v78 = 0;
          v75 = 0;
          v76 = 0;
          v73 += 24;
          v74 = 0;
          matching_fwspec = irq_find_matching_fwspec(&v73, 9);
          v6[41] = (__int64 *)matching_fwspec;
          if ( !matching_fwspec )
          {
            result = 4294966779LL;
            goto LABEL_54;
          }
          v6[42] = (__int64 *)msm_gpio_wakeirq;
          if ( (*(_BYTE *)(matching_fwspec + 42) & 1) != 0 )
          {
            v23 = v6[121];
            if ( *((_DWORD *)v23 + 22) )
            {
              v24 = 0;
              do
              {
                v25 = *(unsigned int *)(v23[10] + 8LL * (int)v24);
                v26 = v25 >> 6;
                v27 = 1LL << v25;
                _X12 = (unsigned __int64 *)&v6[v26 + 106];
                __asm { PRFM            #0x11, [X12] }
                do
                  v34 = __ldxr(_X12);
                while ( __stxr(v34 | v27, _X12) );
                v23 = v6[121];
                ++v24;
              }
              while ( v24 < *((_DWORD *)v23 + 22) );
            }
          }
        }
        v35 = *v6;
        v6[38] = (__int64 *)&msm_gpio_irq_chip;
        v6[59] = (__int64 *)msm_gpio_irq_handler;
        v36 = _dev_fwnode(v35);
        v37 = *v6;
        v6[40] = (__int64 *)v36;
        *((_DWORD *)v6 + 122) = 1;
        v38 = (__int64 *)devm_kmalloc(v37, 4, 3520);
        v6[62] = v38;
        if ( v38 )
        {
          *(_DWORD *)v38 = *((_DWORD *)v6 + 188);
          *((_DWORD *)v6 + 112) = 0;
          v6[55] = (__int64 *)&handle_bad_irq;
          v39 = (unsigned int)gpiochip_add_data_with_key(v6 + 2, v6, 0, 0);
          v40 = *v6;
          if ( (_DWORD)v39 )
          {
            v70 = v39;
            dev_err(v40, "Failed register gpiochip\n");
            result = v70;
          }
          else
          {
            if ( of_find_property(v40[93], "gpio-ranges", 0) )
              goto LABEL_49;
            v41 = (*v6)[14];
            if ( !v41 )
              v41 = **v6;
            v42 = gpiochip_add_pin_range(v6 + 2, v41, 0, 0, *((unsigned __int16 *)v6 + 94));
            if ( (_DWORD)v42 )
            {
              v71 = v42;
              dev_err(*v6, "Failed to add pin range\n");
              gpiochip_remove(v6 + 2);
              result = v71;
            }
            else
            {
LABEL_49:
              v43 = platform_irq_count(a1);
              if ( v43 <= 1 )
              {
                v49 = *((_DWORD *)v6 + 189);
              }
              else
              {
                v44 = (unsigned int)v43;
                v45 = 1;
                v46 = 12;
                do
                {
                  v47 = *(_QWORD *)(a2 + 144);
                  irq = platform_get_irq(a1, (unsigned int)v45);
                  *(_DWORD *)(v47 + v46) = irq;
                  _irq_set_handler();
                  irq_set_irq_type(irq, 1);
                  ++v45;
                  v46 += 8;
                  v49 = *((_DWORD *)v6 + 189) + 1;
                  *((_DWORD *)v6 + 189) = v49;
                }
                while ( v44 != v45 );
              }
              if ( v49 )
              {
                v52 = v6[39];
                v53 = 8LL * v49;
                v54 = 0;
                v55 = v49 - 1LL;
                do
                {
                  v57 = (int *)(v6[121][18] + v53);
                  v58 = *v57;
                  if ( (_DWORD)v58 != -1 )
                  {
                    v59 = v57[1];
                    mapping_affinity = irq_create_mapping_affinity(v52, v58, 0);
                    v61 = mapping_affinity;
                    irq_set_parent(mapping_affinity, v59);
                    irq_set_chip_data(v61, v6 + 2);
                    irq_set_chip_and_handler_name(v61, &msm_gpio_irq_chip, 0, 0);
                    irq_data = irq_get_irq_data(v61);
                    if ( irq_data )
                    {
                      v63 = irq_data;
                      irq_set_handler_data(v59, irq_data);
                      data = gpiochip_get_data(*(_QWORD *)(v63 + 48));
                      v65 = raw_spin_lock_irqsave(data + 764);
                      v66 = *(_QWORD *)(v63 + 8);
                      v67 = v65;
                      v68 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112 * v66;
                      writel_relaxed(
                        (unsigned __int8)v66,
                        (unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v68 + 84) >> 5) & 3LL))
                                       + *(unsigned int *)(v68 + 80)
                                       + v54));
                      v69 = readl(
                              *(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v68 + 84) >> 5) & 3LL))
                            + *(unsigned int *)(v68 + 68));
                      writel(
                        v69 | (unsigned int)(1LL << (*(_QWORD *)(v68 + 92) >> 52)),
                        *(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v68 + 84) >> 5) & 3LL)) + *(unsigned int *)(v68 + 68));
                      raw_spin_unlock_irqrestore(data + 764, v67);
                    }
                  }
                  v56 = v55--;
                  v54 += 4;
                  v53 -= 8;
                }
                while ( v56 );
              }
              pinctrl_msm_log_mask = 0;
              a1[21] = v6;
              register_syscore_ops(&msm_pinctrl_pm_ops);
              result = register_pm_notifier(&pinctrl_notif_block);
              if ( !(_DWORD)result )
              {
                gpio_status_debug_init((__int64)(v6 + 2));
                tracepoint_probe_register(&_tracepoint_suspend_resume, clk_debug_suspend_trace_probe, 0);
                printk(&unk_D490, "msm_pinctrl_probe");
                gpio_sleep_status_info = _kmalloc_large_noprof(30000, 3264);
                memset((void *)gpio_sleep_status_info, 0, 0xCC0u);
                result = 0;
              }
            }
          }
          goto LABEL_54;
        }
LABEL_53:
        result = 4294967284LL;
        goto LABEL_54;
      }
    }
    v6[19] = (__int64 *)msm_gpio_init_valid_mask;
    goto LABEL_32;
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
