__int64 __fastcall cnss_pci_probe(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w20
  __int64 plat_priv_by_rc_num; // x0
  unsigned __int64 StatusReg; // x27
  __int64 v7; // x19
  const char *v8; // x1
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 v11; // x0
  __int64 *v12; // x20
  __int64 v13; // x8
  _BYTE *v14; // x24
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x8
  __int64 next_available_child; // x0
  __int64 v19; // x7
  const char **v20; // x22
  const char *v21; // x1
  __int64 result; // x0
  int v23; // w0
  int v24; // w26
  unsigned int v25; // w25
  char v26; // w8
  __int64 v27; // x0
  const char *v28; // x1
  const char *v29; // x1
  const char *v30; // x5
  const char *v31; // x1
  __int64 v32; // x7
  const char *v33; // x1
  __int64 v34; // x22
  unsigned int v35; // w0
  __int64 v36; // x7
  const char *v37; // x1
  const char *v38; // x1
  __int64 v39; // x22
  const char *v40; // x23
  __int64 name; // x0
  __int64 v42; // x7
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v45; // x3
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  unsigned int inited; // w22
  __int64 v51; // x1
  __int64 v52; // x2
  __int64 v53; // x3
  __int64 v54; // x4
  __int64 v55; // x5
  __int64 v56; // x6
  __int64 v57; // x7
  unsigned int v58; // w0
  __int64 v59; // x7
  const char *v60; // x1
  int v61; // w0
  __int64 v62; // x7
  int v63; // w21
  __int64 v64; // x6
  __int64 v65; // x3
  __int64 v66; // x4
  __int64 v67; // x5
  __int64 v68; // x6
  __int64 v69; // x7
  __int64 v70; // x3
  __int64 v71; // x4
  __int64 v72; // x5
  __int64 v73; // x6
  __int64 v74; // x7
  const char *v75; // x1
  unsigned __int64 v82; // x9
  char v83; // [xsp+0h] [xbp-20h]
  char v84; // [xsp+0h] [xbp-20h]
  int v85; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v86; // [xsp+18h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 252LL);
  plat_priv_by_rc_num = cnss_get_plat_priv_by_rc_num(v4, (__int64)a2);
  StatusReg = _ReadStatusReg(SP_EL0);
  v7 = plat_priv_by_rc_num;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v8 = "soft_irq";
  }
  else
  {
    v8 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v8,
    "cnss_pci_probe",
    7u,
    7u,
    "PCI is probing, vendor ID: 0x%x, device ID: 0x%x rc_num %d\n",
    *a2,
    *(unsigned __int16 *)(a1 + 62),
    v4);
  if ( v7 )
  {
    v11 = devm_kmalloc(a1 + 200, 736, 3520);
    if ( v11 )
    {
      v12 = (__int64 *)v11;
      *(_QWORD *)v11 = a1;
      *(_QWORD *)(v11 + 8) = v7;
      *(_BYTE *)(v11 + 48) = 1;
      v13 = *(unsigned __int16 *)(a1 + 62);
      *(_QWORD *)(v11 + 16) = a2;
      *(_DWORD *)(v11 + 24) = v13;
      v14 = (_BYTE *)(v7 + 4096);
      *(_QWORD *)(a1 + 352) = v11;
      *(_QWORD *)(v7 + 8) = v11;
      *(_QWORD *)(v7 + 528) = v13;
      _mutex_init(v11 + 600, "&pci_priv->bus_lock", &cnss_pci_probe___key);
      if ( *(_BYTE *)(v7 + 7489) )
        *(_QWORD *)(a1 + 792) = &cnss_pm_domain;
      if ( *(_DWORD *)(v7 + 7736) == 2 )
      {
        v17 = *(_QWORD *)(v7 + 528);
        v85 = 0;
        if ( v17 )
        {
          next_available_child = of_get_next_available_child(*(_QWORD *)(*(_QWORD *)v7 + 760LL), 0);
          if ( !next_available_child )
          {
LABEL_44:
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v31 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v31 = "soft_irq";
            }
            else
            {
              v31 = (const char *)(StatusReg + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v31,
              "cnss_pci_probe",
              3u,
              3u,
              "Failed to get device cfg node, err = %d\n",
              4294967274LL,
              v19,
              v83);
            result = 4294967274LL;
            goto LABEL_100;
          }
          v20 = (const char **)next_available_child;
          while ( strcmp(*v20, "chip_cfg") )
          {
LABEL_17:
            v20 = (const char **)of_get_next_available_child(*(_QWORD *)(*(_QWORD *)v7 + 760LL), v20);
            if ( !v20 )
              goto LABEL_44;
          }
          v23 = of_property_count_elems_of_size(v20, "supported-ids", 4);
          if ( v23 < 1 )
          {
            v27 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v28 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v28 = "soft_irq";
            }
            else
            {
              v28 = (const char *)(StatusReg + 2320);
            }
            v30 = "Device id is NOT set\n";
          }
          else
          {
            v24 = v23;
            v25 = 0;
            while ( !(unsigned int)of_property_read_u32_index(v20, "supported-ids", v25, &v85) )
            {
              v26 = v85;
              if ( *(_QWORD *)(v7 + 528) == v85 )
              {
                *(_QWORD *)(v7 + 7776) = v20;
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                {
                  v29 = "irq";
                }
                else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  v29 = "soft_irq";
                }
                else
                {
                  v29 = (const char *)(StatusReg + 2320);
                }
                v14 = (_BYTE *)(v7 + 4096);
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v29,
                  "cnss_pci_get_dev_cfg_node",
                  7u,
                  7u,
                  "got node[%s@%d] for device[0x%x]\n",
                  (__int64)*v20,
                  v25,
                  v26);
                goto LABEL_54;
              }
              if ( v24 == ++v25 )
                goto LABEL_17;
            }
            v27 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v28 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v28 = "soft_irq";
            }
            else
            {
              v28 = (const char *)(StatusReg + 2320);
            }
            v30 = "Failed to read supported ids\n";
          }
        }
        else
        {
          v27 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v28 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v28 = "soft_irq";
          }
          else
          {
            v28 = (const char *)(StatusReg + 2320);
          }
          v30 = "Invalid device id\n";
        }
        cnss_debug_ipc_log_print(v27, v28, "cnss_pci_get_dev_cfg_node", 3u, 3u, v30, v15, v16, v83);
        goto LABEL_44;
      }
LABEL_54:
      cnss_get_bwscal_info(v7);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v33 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v33 = "soft_irq";
      }
      else
      {
        v33 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v33,
        "cnss_pci_probe",
        7u,
        7u,
        "no_bwscale: %d\n",
        (unsigned __int8)v14[3744],
        v32,
        v83);
      cnss_get_sleep_clk_supported((_BYTE *)v7);
      result = cnss_dev_specific_power_on(v7);
      if ( (result & 0x80000000) != 0 )
        goto LABEL_100;
      v34 = *v12;
      v35 = of_reserved_mem_device_init_by_idx(*v12 + 200, *(_QWORD *)(*v12 + 944), 0);
      if ( v35 )
      {
        if ( v35 == -22 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v37 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v37 = "soft_irq";
          }
          else
          {
            v37 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_long_context,
            v37,
            "cnss_pci_of_reserved_mem_device_init",
            7u,
            7u,
            "Ignore, no specific reserved-memory assigned\n",
            v35,
            v36,
            v84);
        }
        else
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v38 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v38 = "soft_irq";
          }
          else
          {
            v38 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v38,
            "cnss_pci_of_reserved_mem_device_init",
            3u,
            3u,
            "Failed to init reserved mem device, err = %d\n",
            v35,
            v36,
            v84);
        }
      }
      if ( *(_QWORD *)(v34 + 904) )
      {
        v39 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v40 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v40 = "soft_irq";
        }
        else
        {
          v40 = (const char *)(StatusReg + 2320);
        }
        name = cma_get_name();
        cnss_debug_ipc_log_print(
          v39,
          v40,
          "cnss_pci_of_reserved_mem_device_init",
          7u,
          7u,
          "CMA area is %s\n",
          name,
          v42,
          v84);
      }
      result = cnss_register_subsys(v7);
      if ( (_DWORD)result )
        goto LABEL_100;
      inited = cnss_register_ramdump((__int64 *)v7, v43, v44, v45, v46, v47, v48, v49);
      if ( inited )
      {
LABEL_99:
        cnss_unregister_subsys(v7);
        result = inited;
LABEL_100:
        *(_QWORD *)(v7 + 8) = 0;
        goto LABEL_101;
      }
      inited = cnss_pci_init_smmu(v12);
      if ( inited )
      {
LABEL_98:
        cnss_unregister_ramdump((_QWORD *)v7, v51, v52, v53, v54, v55, v56, v57);
        goto LABEL_99;
      }
      cnss_pci_update_drv_supported(v12);
      cnss_update_supported_link_info(v12);
      *((_DWORD *)v12 + 92) = 0;
      _init_swait_queue_head(v12 + 47, "&x->wait", &init_completion___key_0);
      v58 = cnss_reg_pci_event(v12);
      if ( v58 )
      {
        inited = v58;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v60 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v60 = "soft_irq";
        }
        else
        {
          v60 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v60,
          "cnss_pci_probe",
          3u,
          3u,
          "Failed to register PCI event, err = %d\n",
          v58,
          v59,
          v84);
        goto LABEL_97;
      }
      inited = cnss_pci_enable_bus(v12);
      if ( inited )
      {
LABEL_92:
        cnss_dereg_pci_event(v12);
LABEL_97:
        v12[33] = 0;
        goto LABEL_98;
      }
      v61 = cnss_pci_enable_msi(v12);
      if ( v61 )
      {
LABEL_91:
        inited = v61;
        cnss_pci_disable_bus(v12);
        goto LABEL_92;
      }
      v61 = cnss_pci_register_mhi(v12);
      if ( v61 )
      {
LABEL_107:
        if ( *((_DWORD *)v12 + 6) != 62 )
        {
          v63 = v61;
          pci_free_irq_vectors(*v12);
          v61 = v63;
        }
        goto LABEL_91;
      }
      v64 = *(unsigned __int16 *)(a1 + 62);
      if ( (unsigned int)(v64 - 4352) <= 0x12 && ((1 << *(_WORD *)(a1 + 62)) & 0x6448F) != 0 )
      {
        if ( (cnss_is_dual_wlan_enabled() & 1) != 0 && (v14[3708] & 1) != 0 || (cnss_is_dual_wlan_enabled() & 1) == 0 )
          cnss_pci_set_wlaon_pwr_ctrl((__int64)v12, 0, 0, v65, v66, v67, v68, v69);
        init_timer_key(v12 + 50, cnss_dev_rddm_timeout_hdlr, 0, 0, 0);
        init_timer_key(v12 + 56, cnss_boot_debug_timeout_hdlr, 0, 0, 0);
        v12[61] = 0xFFFFFFFE00000LL;
        v12[62] = (__int64)(v12 + 62);
        v12[63] = (__int64)(v12 + 62);
        v12[64] = (__int64)cnss_pci_time_sync_work_hdlr;
        init_timer_key(v12 + 65, &delayed_work_timer_fn, 0x200000, 0, 0);
        cnss_pci_get_link_status(v12);
        cnss_pci_set_wlaon_pwr_ctrl((__int64)v12, 1, 0, v70, v71, v72, v73, v74);
      }
      else
      {
        if ( (_DWORD)v64 != 62 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v75 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v75 = "soft_irq";
          }
          else
          {
            v75 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v75,
            "cnss_pci_probe",
            3u,
            3u,
            "Unknown PCI device found: 0x%x\n",
            v64,
            v62,
            v84);
          cnss_pci_unregister_mhi(v12);
          v61 = -19;
          goto LABEL_107;
        }
        pci_read_config_word(a1, 8, (char *)v12 + 28);
      }
      cnss_pci_config_regs(v12);
      if ( ((cnss_is_dual_wlan_enabled() & 1) == 0 || v14[3708] == 1) && (v14[3784] & 1) == 0 )
        cnss_pci_suspend_pwroff(a1);
      _X8 = (unsigned __int64 *)(v7 + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v82 = __ldxr(_X8);
      while ( __stxr(v82 | 0x400000, _X8) );
      result = 0;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_pci_probe",
      3u,
      3u,
      "Find match plat_priv with rc number failure\n",
      v9,
      v10,
      v83);
    result = 4294967277LL;
  }
LABEL_101:
  _ReadStatusReg(SP_EL0);
  return result;
}
