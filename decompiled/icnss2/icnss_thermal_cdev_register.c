__int64 __fastcall icnss_thermal_cdev_register(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x22
  __int64 v6; // x19
  const char **node_by_name; // x21
  unsigned __int64 v8; // x0
  __int64 v9; // x2
  __int64 *v10; // x1
  unsigned int v11; // w20
  _QWORD v13[2]; // [xsp+0h] [xbp-20h] BYREF
  int v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v14 = 0;
  v13[0] = 0;
  v13[1] = 0;
  v6 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 56);
  if ( v6 )
  {
    *(_DWORD *)(v6 + 16) = a3;
    *(_QWORD *)(v6 + 32) = a2;
    snprintf((char *)v13, 0x14u, "icnss_cdev%d", a3);
    node_by_name = (const char **)of_find_node_by_name(0, v13);
    if ( node_by_name
      || (snprintf((char *)v13, 0x14u, "qcom,icnss_cdev%d", a3),
          (node_by_name = (const char **)of_find_node_by_name(0, v13)) != nullptr) )
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2: tcdev node->name=%s\n", *node_by_name);
      if ( of_find_property(node_by_name, "#cooling-cells", 0) )
      {
        v8 = thermal_of_cooling_device_register(node_by_name, v13, v6, icnss_cooling_ops);
        *(_QWORD *)(v6 + 48) = v8;
        if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
        {
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2: Cooling device registered for cdev id %d",
            *(_DWORD *)(v6 + 16));
          v9 = *(_QWORD *)(v5 + 5528);
          v10 = (__int64 *)(v5 + 5528);
          if ( *(_QWORD *)(v9 + 8) != v5 + 5528 || (__int64 *)v6 == v10 || v9 == v6 )
          {
            _list_add_valid_or_report(v6, v10);
            v11 = 0;
          }
          else
          {
            v11 = 0;
            *(_QWORD *)(v9 + 8) = v6;
            *(_QWORD *)v6 = v9;
            *(_QWORD *)(v6 + 8) = v10;
            *v10 = v6;
          }
        }
        else
        {
          v11 = v8;
          printk(
            "%sicnss2: Cooling device register failed: %d, for cdev id %d\n",
            byte_130B32,
            v8,
            *(_DWORD *)(v6 + 16));
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2: Cooling device register failed: %d, for cdev id %d\n",
            (const char *)&unk_12DBF3,
            v11,
            *(_DWORD *)(v6 + 16));
        }
      }
      else
      {
        ipc_log_string(icnss_ipc_log_context, "icnss2: Cooling device registration not supported");
        v11 = -95;
      }
    }
    else
    {
      printk("%sicnss2: Failed to get cooling device node\n", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to get cooling device node\n", (const char *)&unk_12DBF3);
      v11 = -22;
    }
  }
  else
  {
    v11 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
