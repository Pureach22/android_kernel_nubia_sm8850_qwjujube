__int64 __fastcall cnss_wlan_reg_driver_work(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x21
  __int64 v9; // x20
  unsigned __int64 v10; // x8
  __int64 v11; // x0
  const char *v12; // x1
  __int64 v13; // x19
  unsigned int timeout; // w0
  __int64 v15; // x7
  unsigned __int64 v16; // x9
  unsigned int v17; // w20
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  const char *v21; // x5
  unsigned int v22; // w3
  unsigned int v23; // w4
  __int64 v24; // x6
  __int64 v25; // x7
  unsigned __int64 v26; // x22
  const char *v27; // x1
  __int16 v28; // w10
  const char *v29; // x9
  __int64 v30; // x0
  __int64 v31; // x7
  const char *v32; // x1
  unsigned __int64 StatusReg; // x8
  __int16 v34; // w9
  const char *v35; // x8
  char v36; // [xsp+0h] [xbp+0h]
  char v37; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(result - 712);
  if ( (*(_QWORD *)(result - 168) & 0x1000000) != 0 )
    return result;
  v9 = result - 720;
  if ( (*(_QWORD *)(result - 168) & 0x20000) != 0 )
  {
LABEL_33:
    if ( (*(_QWORD *)(result - 168) & 0x10000) == 0 )
    {
      *(_DWORD *)(result + 5592) = 0;
      return cnss_driver_event_post(v9, 7u, 5, *(_QWORD *)(v8 + 40));
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v34 = *(_DWORD *)(StatusReg + 16);
      v35 = (const char *)(StatusReg + 2320);
      if ( (v34 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v35;
    }
    v21 = "Reboot/Shutdown is in progress, ignore register driver\n";
    v22 = 7;
    v23 = 7;
    return cnss_debug_ipc_log_print(v11, v12, "cnss_wlan_reg_driver_work", v22, v23, v21, a7, a8, v36);
  }
  if ( *(_BYTE *)(result + 6856) )
  {
    v10 = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(v10 + 16);
      v20 = (const char *)(v10 + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v20;
    }
    v21 = "Ignore calibration timeout in charger mode\n";
    v22 = 3;
    v23 = 3;
    return cnss_debug_ipc_log_print(v11, v12, "cnss_wlan_reg_driver_work", v22, v23, v21, a7, a8, v36);
  }
  v13 = result;
  if ( (*(_QWORD *)(result - 168) & 8) == 0 )
  {
    timeout = cnss_get_timeout(result - 720, 3);
    v16 = _ReadStatusReg(SP_EL0);
    v17 = timeout;
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v28 = *(_DWORD *)(v16 + 16);
      v29 = (const char *)(v16 + 2320);
      if ( (v28 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v29;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_wlan_reg_driver_work",
      7u,
      7u,
      "File system not ready to start calibration. Wait for %ds..\n",
      timeout / 0x3E8uLL,
      v15,
      v36);
    v30 = _msecs_to_jiffies(v17);
    return queue_delayed_work_on(32, system_wq, v13, v30);
  }
  timer_delete((timer_t)(result + 5552));
  if ( (*(_QWORD *)(v13 - 168) & 8) != 0
    && (*(_QWORD *)(v13 - 168) & 0x10000) == 0
    && (*(_QWORD *)(v13 - 168) & 0x200) == 0 )
  {
    v26 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v26 + 16) & 0xF0000) != 0 )
    {
      v27 = "irq";
    }
    else if ( (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
    {
      v27 = "soft_irq";
    }
    else
    {
      v27 = (const char *)(v26 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v27,
      "cnss_wlan_reg_driver_work",
      3u,
      3u,
      "Timeout waiting for calibration to complete\n",
      v24,
      v25,
      v36);
    if ( (*(_DWORD *)(v26 + 16) & 0xF0000) != 0 )
    {
      v32 = "irq";
    }
    else if ( (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
    {
      v32 = "soft_irq";
    }
    else
    {
      v32 = (const char *)(v26 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v32,
      "cnss_wlan_reg_driver_work",
      3u,
      3u,
      "ASSERT at line %d\n",
      4325,
      v31,
      v37);
    __break(0x800u);
  }
  result = _kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( result )
  {
    *(_DWORD *)result = 1;
    cnss_driver_event_post(v9, 6u, 0, result);
    result = v13;
    goto LABEL_33;
  }
  return result;
}
