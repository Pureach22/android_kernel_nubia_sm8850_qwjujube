__int64 __fastcall cnss_thermal_cdev_register(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x22
  __int64 v11; // x6
  __int64 v12; // x7
  __int64 v13; // x19
  __int64 *node_by_name; // x0
  __int64 v15; // x6
  __int64 v16; // x7
  unsigned __int64 StatusReg; // x21
  int v18; // w9
  __int64 *v19; // x20
  const char *v20; // x1
  unsigned __int64 v21; // x8
  const char *v22; // x1
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  unsigned int v26; // w20
  __int64 v27; // x6
  __int64 v28; // x7
  unsigned __int64 v29; // x0
  __int64 v30; // x7
  const char *v31; // x1
  const char *v32; // x1
  const char *v33; // x1
  __int64 v34; // x2
  __int64 *v35; // x1
  unsigned __int64 v36; // x8
  const char *v37; // x1
  __int16 v38; // w9
  const char *v39; // x8
  _QWORD v41[2]; // [xsp+0h] [xbp-20h] BYREF
  int v42; // [xsp+10h] [xbp-10h]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = plat_env;
  v42 = 0;
  v41[0] = 0;
  v41[1] = 0;
  if ( plat_env )
  {
    v13 = _kmalloc_cache_noprof(of_get_property, 3520, 56);
    if ( v13 )
    {
      *(_DWORD *)(v13 + 16) = a3;
      *(_QWORD *)(v13 + 32) = a2;
      snprintf((char *)v41, 0x14u, "qcom,cnss_cdev%d", a3);
      node_by_name = (__int64 *)of_find_node_by_name(0, v41);
      StatusReg = _ReadStatusReg(SP_EL0);
      v18 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
      if ( node_by_name )
      {
        v19 = node_by_name;
        if ( v18 )
        {
          v20 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v20 = "soft_irq";
        }
        else
        {
          v20 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v20,
          "cnss_thermal_cdev_register",
          7u,
          7u,
          "tcdev node->name=%s\n",
          *node_by_name,
          v16,
          v41[0]);
        if ( of_find_property(v19, "#cooling-cells", 0) )
        {
          v29 = thermal_of_cooling_device_register(v19, v41, v13, cnss_cooling_ops);
          v26 = v29;
          *(_QWORD *)(v13 + 48) = v29;
          if ( v29 && v29 < 0xFFFFFFFFFFFFF001LL )
          {
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
              "cnss_thermal_cdev_register",
              7u,
              7u,
              "Cooling device registered for cdev id %d",
              *(unsigned int *)(v13 + 16),
              v30,
              v41[0]);
            mutex_lock(v8 + 592);
            v34 = *(_QWORD *)(v8 + 576);
            v35 = (__int64 *)(v8 + 576);
            if ( *(_QWORD *)(v34 + 8) != v8 + 576 || (__int64 *)v13 == v35 || v34 == v13 )
            {
              _list_add_valid_or_report(v13, v35);
            }
            else
            {
              *(_QWORD *)(v34 + 8) = v13;
              *(_QWORD *)v13 = v34;
              *(_QWORD *)(v13 + 8) = v35;
              *v35 = v13;
            }
            mutex_unlock(v8 + 592);
            v26 = 0;
          }
          else
          {
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
              "cnss_thermal_cdev_register",
              3u,
              3u,
              "Cooling device register failed: %d, for cdev id %d\n",
              (unsigned int)v29,
              *(unsigned int *)(v13 + 16),
              v41[0]);
            kfree(v13);
          }
        }
        else
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v32 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v32 = "soft_irq";
          }
          else
          {
            v32 = (const char *)(StatusReg + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v32,
            "cnss_thermal_cdev_register",
            7u,
            7u,
            "Cooling device registration not supported",
            v27,
            v28,
            v41[0]);
          kfree(v13);
          v26 = -95;
        }
      }
      else
      {
        if ( v18 )
        {
          v23 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v23 = "soft_irq";
        }
        else
        {
          v23 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v23,
          "cnss_thermal_cdev_register",
          3u,
          3u,
          "Failed to get cooling device node\n",
          v15,
          v16,
          v41[0]);
        kfree(v13);
        v26 = -22;
      }
    }
    else
    {
      v36 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v36 + 16) & 0xF0000) != 0 )
      {
        v37 = "irq";
      }
      else
      {
        v38 = *(_DWORD *)(v36 + 16);
        v39 = (const char *)(v36 + 2320);
        if ( (v38 & 0xFF00) != 0 )
          v37 = "soft_irq";
        else
          v37 = v39;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v37,
        "cnss_thermal_cdev_register",
        3u,
        3u,
        "Failed to allocate cnss_tcdev object!\n",
        v11,
        v12,
        v41[0]);
      v26 = -12;
    }
  }
  else
  {
    v21 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
    {
      v22 = "irq";
    }
    else
    {
      v24 = *(_DWORD *)(v21 + 16);
      v25 = (const char *)(v21 + 2320);
      if ( (v24 & 0xFF00) != 0 )
        v22 = "soft_irq";
      else
        v22 = v25;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v22,
      "cnss_thermal_cdev_register",
      3u,
      3u,
      "Platform driver is not initialized!\n",
      a7,
      a8,
      v41[0]);
    v26 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return v26;
}
