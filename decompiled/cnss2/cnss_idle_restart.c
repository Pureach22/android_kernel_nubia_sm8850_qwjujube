__int64 __fastcall cnss_idle_restart(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x19
  int v7; // w0
  __int64 v8; // x6
  __int64 v9; // x7
  unsigned __int64 v10; // x23
  int v11; // w9
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  const char *v15; // x1
  __int64 v16; // x6
  __int64 v17; // x7
  int v18; // w0
  __int64 v19; // x6
  __int64 v20; // x7
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned int v25; // w20
  const char *v26; // x1
  int qmi_timeout; // w21
  __int64 v28; // x0
  int v29; // w0
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  int v33; // w20
  const char *v34; // x1
  const char *v35; // x1
  const char *v36; // x1
  const char *v37; // x1
  __int64 v38; // x1
  __int64 v39; // x7
  const char *v40; // x1
  unsigned __int64 v47; // x11
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]

  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v22 = *(_DWORD *)(StatusReg + 16);
      v23 = (const char *)(StatusReg + 2320);
      if ( (v22 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v23;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_idle_restart",
      3u,
      3u,
      "plat_priv is NULL\n",
      v4,
      v5,
      vars0);
    return 4294967277LL;
  }
  v6 = v3;
  v7 = mutex_trylock(v3 + 6424);
  v10 = _ReadStatusReg(SP_EL0);
  v11 = *(_DWORD *)(v10 + 16) & 0xF0000;
  if ( !v7 )
  {
    if ( v11 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_idle_restart",
      7u,
      7u,
      "Another driver operation is in progress, ignore idle restart\n",
      v8,
      v9,
      vars0);
    return 4294967280LL;
  }
  if ( v11 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(v10 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_idle_restart",
    7u,
    7u,
    "Doing idle restart\n",
    v8,
    v9,
    vars0);
  *(_DWORD *)(v6 + 6312) = 0;
  if ( (*(_QWORD *)(v6 + 552) & 0x10000) != 0 )
  {
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_idle_restart",
      7u,
      7u,
      "Reboot or shutdown is in progress, ignore idle restart\n",
      v16,
      v17,
      vars0a);
    goto LABEL_31;
  }
  v18 = cnss_driver_event_post(v6, 0xDu, 3, 0);
  if ( v18 )
  {
    if ( v18 != -4 )
    {
LABEL_32:
      v25 = v18;
      mutex_unlock(v6 + 6424);
      return v25;
    }
    if ( *(_QWORD *)(v6 + 528) == 62 )
    {
      v18 = -4;
      goto LABEL_32;
    }
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v26 = "soft_irq";
    }
    else
    {
      v26 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v26,
      "cnss_idle_restart",
      3u,
      3u,
      "Idle restart has been interrupted but device power up is still in progress",
      v19,
      v20,
      vars0a);
  }
  if ( *(_QWORD *)(v6 + 528) == 62 )
  {
    v18 = cnss_bus_call_driver_probe(v6);
    goto LABEL_32;
  }
  qmi_timeout = cnss_get_qmi_timeout(v6);
  v28 = _msecs_to_jiffies((unsigned int)(qmi_timeout + 90000));
  v29 = wait_for_completion_timeout(v6 + 6312, v28);
  v32 = *(_DWORD *)(v6 + 7568);
  if ( v32 )
  {
    _X9 = (unsigned __int64 *)(v6 + 552);
    __asm { PRFM            #0x11, [X9] }
    do
      v47 = __ldxr(_X9);
    while ( __stxr(v47 & 0xFFFFFFFFFFFFFFBFLL, _X9) );
    v33 = v32;
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v34 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v34 = "soft_irq";
    }
    else
    {
      v34 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v34,
      "cnss_idle_restart",
      7u,
      7u,
      "Power up error:%d, exiting\n",
      *(unsigned int *)(v6 + 7568),
      v31,
      vars0a);
    v18 = v33;
    goto LABEL_32;
  }
  if ( !v29 )
  {
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v36 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v36 = "soft_irq";
    }
    else
    {
      v36 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v36,
      "cnss_idle_restart",
      3u,
      3u,
      "fatal: Timeout (%ums) waiting for idle restart to complete\n",
      (unsigned int)(qmi_timeout + 90000),
      v31,
      vars0a);
    cnss_power_down(a1, v38);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v40 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v40 = "soft_irq";
    }
    else
    {
      v40 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v40,
      "cnss_idle_restart",
      3u,
      3u,
      "ASSERT at line %d\n",
      1776,
      v39,
      vars0b);
    __break(0x800u);
    v18 = -110;
    goto LABEL_32;
  }
  if ( (*(_QWORD *)(v6 + 552) & 0x10000) != 0 )
  {
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v37 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v37 = "soft_irq";
    }
    else
    {
      v37 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v37,
      "cnss_idle_restart",
      7u,
      7u,
      "Reboot or shutdown is in progress, ignore idle restart\n",
      v30,
      v31,
      vars0a);
    timer_delete((timer_t)(v6 + 6272));
LABEL_31:
    v18 = -22;
    goto LABEL_32;
  }
  if ( (*(_QWORD *)(v6 + 6680) & 0x200) != 0 )
  {
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v35 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v35 = "soft_irq";
    }
    else
    {
      v35 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v35,
      "cnss_idle_restart",
      7u,
      7u,
      "DRV is disabled\n",
      v30,
      v31,
      vars0a);
    cnss_bus_disable_mhi_satellite_cfg(v6);
  }
  mutex_unlock(v6 + 6424);
  return 0;
}
