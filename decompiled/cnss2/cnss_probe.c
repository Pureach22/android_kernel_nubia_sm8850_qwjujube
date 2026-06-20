__int64 __fastcall cnss_probe(__int64 a1)
{
  __int64 matched; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  const char *v8; // x1
  unsigned __int64 v9; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  __int64 result; // x0
  unsigned __int64 v14; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  const char *v18; // x5
  _QWORD *v19; // x0
  __int64 v20; // x19
  __int64 v21; // x0
  __int64 v22; // x7
  __int64 v23; // x6
  __int16 v24; // w9
  const char *v25; // x8
  char **v26; // x26
  unsigned __int64 v27; // x28
  const char *v28; // x1
  char v29; // w8
  bool v30; // w8
  __int64 v31; // x9
  __int64 property; // x0
  int v33; // w8
  unsigned int wlan_sw_ctrl; // w0
  __int64 v35; // x7
  unsigned int v36; // w19
  const char *v37; // x1
  __int64 v38; // x0
  unsigned __int8 raw_value; // w0
  __int64 v40; // x7
  const char *v41; // x1
  __int64 v42; // x7
  unsigned int v43; // w8
  unsigned int resources; // w21
  const char *v45; // x1
  int v46; // w23
  __int64 next_available_child; // x0
  const char **v48; // x21
  char **v49; // x27
  int v50; // w0
  __int64 v51; // x6
  __int64 v52; // x7
  int v53; // w26
  unsigned int v54; // w22
  __int64 v55; // x8
  __int64 v56; // x9
  __int64 v57; // x0
  __int64 v58; // x0
  const char *v59; // x1
  const char *v60; // x1
  int variable_u32_array; // w0
  __int64 v62; // x7
  const char *v63; // x1
  const char *v64; // x1
  int bus_type; // w0
  __int64 v66; // x8
  bool v67; // zf
  char v68; // w8
  __int64 v69; // x6
  __int64 v70; // x7
  int v71; // w21
  const char *v72; // x1
  __int64 v73; // x0
  const char *v74; // x5
  __int64 v75; // x6
  __int64 v76; // x7
  unsigned int v77; // w0
  const char *v78; // x1
  char v79; // [xsp+0h] [xbp-20h]
  char v80; // [xsp+0h] [xbp-20h]
  char v81; // [xsp+0h] [xbp-20h]
  int v82; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v83; // [xsp+18h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  matched = of_match_device(&_mod_of__cnss_of_match_table_device_table, a1 + 16);
  if ( matched )
  {
    v5 = *(_QWORD *)(matched + 192);
    if ( v5 )
    {
      if ( *(_QWORD *)(v5 + 24) == 0xFFFF )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v7 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v8 = "irq";
        }
        else
        {
          v16 = *(_DWORD *)(StatusReg + 16);
          v17 = (const char *)(StatusReg + 2320);
          if ( (v16 & 0xFF00) != 0 )
            v8 = "soft_irq";
          else
            v8 = v17;
        }
        v18 = "cnss direct link device probed!\n";
LABEL_19:
        cnss_debug_ipc_log_print(v7, v8, "cnss_probe", 6u, 6u, v18, v3, v4, v79);
        result = 0;
        goto LABEL_120;
      }
      if ( plat_env )
      {
        v14 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
        {
          v15 = "irq";
        }
        else
        {
          v24 = *(_DWORD *)(v14 + 16);
          v25 = (const char *)(v14 + 2320);
          if ( (v24 & 0xFF00) != 0 )
            v15 = "soft_irq";
          else
            v15 = v25;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v15,
          "cnss_probe",
          3u,
          3u,
          "Driver is already initialized!\n",
          v3,
          v4,
          v79);
        result = 4294967279LL;
        goto LABEL_120;
      }
      v19 = (_QWORD *)devm_kmalloc(a1 + 16, 8008, 3520);
      if ( !v19 )
      {
        result = 4294967284LL;
        goto LABEL_120;
      }
      *v19 = a1;
      v20 = (__int64)v19;
      v19[972] = 0;
      v21 = *(_QWORD *)(a1 + 760);
      *(_QWORD *)(v20 + 528) = *(_QWORD *)(v5 + 24);
      if ( of_find_property(v21, "qcom,converged-dt", 0) )
        v23 = 1;
      else
        v23 = 2 * (unsigned int)(of_find_property(*(_QWORD *)(*(_QWORD *)v20 + 760LL), "qcom,multi-wlan-exchg", 0) != 0);
      *(_DWORD *)(v20 + 7736) = v23;
      v26 = &off_5B000;
      v27 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
      {
        v28 = "irq";
      }
      else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
      {
        v28 = "soft_irq";
      }
      else
      {
        v28 = (const char *)(v27 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v28,
        "cnss_probe",
        7u,
        7u,
        "Probing platform driver from dt type: %d\n",
        v23,
        v22,
        v79);
      v29 = *(_BYTE *)(v20 + 7953);
      *(_DWORD *)(v20 + 7960) = 0;
      *(_BYTE *)(v20 + 7953) = v29 | 6;
      _init_swait_queue_head(v20 + 7968, "&x->wait", &init_completion___key);
      v30 = of_find_property(*(_QWORD *)(*(_QWORD *)v20 + 760LL), "qcom,converged-dt", 0)
         || of_find_property(*(_QWORD *)(*(_QWORD *)v20 + 760LL), "qcom,same-dt-multi-dev", 0)
         || of_find_property(*(_QWORD *)(*(_QWORD *)v20 + 760LL), "qcom,multi-wlan-exchg", 0) != 0;
      v31 = *(_QWORD *)v20;
      *(_BYTE *)(v20 + 6514) = v30;
      property = of_find_property(*(_QWORD *)(v31 + 760), "firmware-managed-resources", 0);
      v33 = *(_DWORD *)(v20 + 7736);
      *(_BYTE *)(v20 + 7880) = property != 0;
      if ( v33 == 1 )
      {
        v82 = 0;
        wlan_sw_ctrl = cnss_get_wlan_sw_ctrl(v20);
        if ( wlan_sw_ctrl )
        {
          v36 = wlan_sw_ctrl;
          if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
          {
            v37 = "irq";
          }
          else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
          {
            v37 = "soft_irq";
          }
          else
          {
            v37 = (const char *)(v27 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v37,
            "cnss_get_dev_cfg_node",
            7u,
            7u,
            "Failed to parse wlan_sw_ctrl gpio, error:%d",
            wlan_sw_ctrl,
            v35,
            v80);
          v43 = v36;
        }
        else
        {
          v38 = gpio_to_desc(*(unsigned int *)(v20 + 128));
          raw_value = gpiod_get_raw_value(v38);
          if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
          {
            v41 = "irq";
          }
          else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
          {
            v41 = "soft_irq";
          }
          else
          {
            v41 = (const char *)(v27 + 2320);
          }
          v46 = raw_value;
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v41,
            "cnss_get_dev_cfg_node",
            7u,
            7u,
            "Value of Device Identifier GPIO: %d\n",
            raw_value,
            v40,
            v80);
          next_available_child = of_get_next_available_child(*(_QWORD *)(*(_QWORD *)v20 + 760LL), 0);
          if ( next_available_child )
          {
            v48 = (const char **)next_available_child;
            while ( 1 )
            {
              v49 = v26;
              if ( !strcmp(*v48, "chip_cfg") )
                break;
LABEL_59:
              v48 = (const char **)of_get_next_available_child(*(_QWORD *)(*(_QWORD *)v20 + 760LL), v48);
              v43 = -22;
              v26 = v49;
              if ( !v48 )
                goto LABEL_48;
            }
            v50 = of_property_count_elems_of_size(v48, "supported-ids", 4);
            if ( v50 < 1 )
            {
              v58 = (__int64)v26[490];
              if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
              {
                v59 = "irq";
              }
              else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
              {
                v59 = "soft_irq";
              }
              else
              {
                v59 = (const char *)(v27 + 2320);
              }
              v74 = "Device id is NOT set\n";
            }
            else
            {
              v53 = v50;
              v54 = 0;
              while ( !(unsigned int)of_property_read_u32_index(v48, "supported-ids", v54, &v82) )
              {
                if ( v46 && v82 == 4355 )
                {
                  v55 = *(_QWORD *)v20;
                  v56 = 4355;
                  v57 = 1;
                  goto LABEL_74;
                }
                if ( !v46 && v82 == 4359 )
                {
                  v55 = *(_QWORD *)v20;
                  v56 = 4359;
                  v57 = 0;
LABEL_74:
                  *(_QWORD *)(v55 + 760) = v48;
                  *(_QWORD *)(v20 + 528) = v56;
                  cnss_utils_update_device_type(v57);
                  v26 = v49;
                  if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
                  {
                    v60 = "irq";
                  }
                  else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
                  {
                    v60 = "soft_irq";
                  }
                  else
                  {
                    v60 = (const char *)(v27 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    (__int64)v49[490],
                    v60,
                    "cnss_get_dev_cfg_node",
                    7u,
                    7u,
                    "got node[%s@%d] for device[0x%x]\n",
                    (__int64)*v48,
                    v54,
                    v82);
                  goto LABEL_80;
                }
                if ( v53 == ++v54 )
                  goto LABEL_59;
              }
              v58 = (__int64)v49[490];
              v26 = v49;
              if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
              {
                v59 = "irq";
              }
              else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
              {
                v59 = "soft_irq";
              }
              else
              {
                v59 = (const char *)(v27 + 2320);
              }
              v74 = "Failed to read supported ids\n";
            }
            cnss_debug_ipc_log_print(v58, v59, "cnss_get_dev_cfg_node", 3u, 3u, v74, v51, v52, v81);
            v43 = -22;
          }
          else
          {
            v43 = -22;
          }
        }
LABEL_48:
        resources = v43;
        if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
        {
          v45 = "irq";
        }
        else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
        {
          v45 = "soft_irq";
        }
        else
        {
          v45 = (const char *)(v27 + 2320);
        }
        cnss_debug_ipc_log_print(
          (__int64)v26[490],
          v45,
          "cnss_probe",
          3u,
          3u,
          "Failed to get device cfg node, err = %d\n",
          v43,
          v42,
          v81);
        goto LABEL_119;
      }
LABEL_80:
      if ( (cnss_probe_prealloc_initialized & 1) == 0 )
      {
        cnss_initialize_prealloc_pool(*(_QWORD *)(v20 + 528));
        cnss_probe_prealloc_initialized = 1;
      }
      variable_u32_array = of_property_read_variable_u32_array(
                             *(_QWORD *)(*(_QWORD *)v20 + 760LL),
                             "qcom,wlan-rc-num",
                             v20 + 520,
                             1,
                             0);
      if ( variable_u32_array < 0 )
      {
        if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
        {
          v63 = "irq";
        }
        else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
        {
          v63 = "soft_irq";
        }
        else
        {
          v63 = (const char *)(v27 + 2320);
        }
        cnss_debug_ipc_log_print(
          (__int64)v26[490],
          v63,
          "cnss_probe",
          3u,
          3u,
          "Failed to find PCIe RC number, err = %d\n",
          variable_u32_array & (unsigned int)(variable_u32_array >> 31),
          v62,
          v80);
      }
      if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
      {
        v64 = "irq";
      }
      else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
      {
        v64 = "soft_irq";
      }
      else
      {
        v64 = (const char *)(v27 + 2320);
      }
      cnss_debug_ipc_log_print(
        (__int64)v26[490],
        v64,
        "cnss_probe",
        7u,
        7u,
        "rc_num=%d\n",
        *(unsigned int *)(v20 + 520),
        v62,
        v80);
      bus_type = cnss_get_bus_type(v20);
      v66 = *(_QWORD *)v20;
      *(_DWORD *)(v20 + 16) = bus_type;
      v67 = of_find_property(*(_QWORD *)(v66 + 760), "use-nv-mac", 0) == 0;
      plat_env = v20;
      *(_QWORD *)(a1 + 168) = v20;
      strcpy((char *)(v20 + 7784), "wlan");
      v68 = !v67;
      *(_BYTE *)(v20 + 7490) = v68;
      *(_QWORD *)(v20 + 24) = v20 + 24;
      *(_QWORD *)(v20 + 32) = v20 + 24;
      *(_QWORD *)(v20 + 40) = v20 + 40;
      *(_QWORD *)(v20 + 48) = v20 + 40;
      cnss_get_pm_domain_info(v20);
      cnss_get_wlaon_pwr_ctrl_info(v20);
      cnss_power_misc_params_init(v20);
      cnss_get_tcs_info(v20);
      cnss_get_cpr_info(v20);
      cnss_get_wlan_tsf_gpio_info(v20);
      cnss_aop_interface_init(v20);
      cnss_init_control_params(v20);
      cnss_get_cpumask_for_wlan_txrx_intr(v20);
      cnss_pm_notifier_init(v20);
      resources = cnss_get_resources(v20);
      if ( resources )
      {
LABEL_118:
        cnss_pm_notifier_deinit(v20);
        cnss_aop_interface_deinit(v20);
        *(_QWORD *)(a1 + 168) = 0;
LABEL_119:
        plat_env = 0;
        result = resources;
        goto LABEL_120;
      }
      if ( *(_QWORD *)(v20 + 528) == 4366 )
      {
        v71 = *(_DWORD *)(v20 + 112);
        if ( v71 >= 1 )
        {
          if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
          {
            v72 = "irq";
          }
          else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
          {
            v72 = "soft_irq";
          }
          else
          {
            v72 = (const char *)(v27 + 2320);
          }
          cnss_debug_ipc_log_print((__int64)v26[490], v72, "cnss_probe", 3u, 3u, "Disabling BT_EN", v69, v70, v79);
          v73 = gpio_to_desc((unsigned int)v71);
          gpiod_direction_output_raw(v73, 0);
        }
      }
      resources = cnss_register_bus_scale(v20);
      if ( resources )
      {
LABEL_117:
        cnss_put_resources(v20);
        goto LABEL_118;
      }
      resources = cnss_event_work_init(v20);
      if ( resources )
      {
LABEL_116:
        cnss_unregister_bus_scale(v20);
        goto LABEL_117;
      }
      resources = cnss_create_sysfs(v20);
      if ( resources )
      {
LABEL_115:
        destroy_workqueue(*(_QWORD *)(v20 + 680));
        goto LABEL_116;
      }
      resources = cnss_dms_init(v20);
      if ( resources )
      {
LABEL_114:
        cnss_remove_sysfs(v20);
        goto LABEL_115;
      }
      resources = cnss_debugfs_create(v20);
      if ( resources )
      {
LABEL_113:
        cnss_cancel_dms_work(v20);
        cnss_dms_deinit(v20);
        goto LABEL_114;
      }
      resources = cnss_misc_init(v20);
      if ( resources )
      {
LABEL_112:
        cnss_debugfs_destroy(v20);
        goto LABEL_113;
      }
      cnss_wlan_hw_disable_check(v20);
      if ( (*(_QWORD *)(v20 + 552) & 0x1000000) != 0 )
      {
        if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
        {
          v78 = "irq";
        }
        else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
        {
          v78 = "soft_irq";
        }
        else
        {
          v78 = (const char *)(v27 + 2320);
        }
        cnss_debug_ipc_log_print(
          (__int64)v26[490],
          v78,
          "cnss_probe",
          6u,
          6u,
          "WLAN HW Disabled. Defer PCI enumeration\n",
          v75,
          v76,
          v79);
      }
      else
      {
        v77 = cnss_wlan_device_init(v20);
        if ( v77 )
        {
          resources = v77;
          cnss_misc_deinit(v20);
          goto LABEL_112;
        }
      }
      cnss_register_coex_service(v20);
      cnss_register_ims_service(v20);
      _mutex_init(v20 + 592, "&plat_priv->tcdev_lock", &cnss_probe___key);
      *(_QWORD *)(v20 + 576) = v20 + 576;
      *(_QWORD *)(v20 + 584) = v20 + 576;
      v7 = (__int64)v26[490];
      if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
      {
        v8 = "irq";
      }
      else if ( (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
      {
        v8 = "soft_irq";
      }
      else
      {
        v8 = (const char *)(v27 + 2320);
      }
      v18 = "Platform driver probed successfully.\n";
      goto LABEL_19;
    }
  }
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v11 = *(_DWORD *)(v9 + 16);
    v12 = (const char *)(v9 + 2320);
    if ( (v11 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v12;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_probe",
    3u,
    3u,
    "Failed to find of match device!\n",
    v3,
    v4,
    v79);
  result = 4294967277LL;
LABEL_120:
  _ReadStatusReg(SP_EL0);
  return result;
}
