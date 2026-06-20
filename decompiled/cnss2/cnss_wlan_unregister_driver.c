__int64 __fastcall cnss_wlan_unregister_driver(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x19
  __int64 timeout; // x0
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x7
  __int64 v10; // x8
  unsigned __int64 v11; // x8
  const char *v12; // x1
  __int16 v13; // w9
  const char *v14; // x8
  unsigned __int64 StatusReg; // x22
  const char *v17; // x1
  __int64 v18; // x7
  const char *v19; // x1
  __int64 v20; // x0
  unsigned int v21; // w20
  __int64 v22; // x0
  __int64 v23; // x7
  unsigned __int64 v24; // x22
  const char *v25; // x1
  __int64 v26; // x7
  const char *v27; // x1
  char v28; // [xsp+0h] [xbp+0h]
  char v29; // [xsp+0h] [xbp+0h]
  char v30; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(0, a2);
  if ( v2 )
  {
    v5 = v2;
    mutex_lock(v2 + 6424);
    if ( *(_QWORD *)(v5 + 528) == 62
      || (timeout = cnss_get_timeout(v5, 4),
          v7 = timeout,
          v8 = _msecs_to_jiffies(timeout),
          (unsigned int)wait_for_completion_timeout(v5 + 6312, v8)) )
    {
      if ( (*(_QWORD *)(v5 + 552) & 0x200) != 0 )
        goto LABEL_28;
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v17 = "soft_irq";
      }
      else
      {
        v17 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v17,
        "cnss_wlan_unregister_driver",
        3u,
        3u,
        "Timeout (%ums) waiting for driver power up to complete\n",
        v7,
        v9,
        v28);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v19 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v19 = "soft_irq";
      }
      else
      {
        v19 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v19,
        "cnss_wlan_unregister_driver",
        3u,
        3u,
        "ASSERT at line %d\n",
        4486,
        v18,
        v29);
      __break(0x800u);
      if ( (*(_QWORD *)(v5 + 552) & 0x200) != 0 )
        goto LABEL_28;
    }
    if ( (*(_QWORD *)(v5 + 552) & 0x800) == 0 )
    {
      v10 = *(_QWORD *)(v5 + 8);
      if ( !v10 || *(_DWORD *)(v5 + 16) || *(_DWORD *)(v10 + 24) == 62 || (*(_QWORD *)(v10 + 352) & 0x100) == 0 )
      {
LABEL_40:
        cnss_driver_event_post(v5, 8u, 5, 0);
        return mutex_unlock(v5 + 6424);
      }
    }
LABEL_28:
    *(_DWORD *)(v5 + 6648) = 0;
    v20 = cnss_get_timeout(v5, 6);
    v21 = v20;
    v22 = _msecs_to_jiffies(v20);
    if ( !(unsigned int)wait_for_completion_timeout(v5 + 6648, v22) )
    {
      v24 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else if ( (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
      {
        v25 = "soft_irq";
      }
      else
      {
        v25 = (const char *)(v24 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v25,
        "cnss_wlan_unregister_driver",
        3u,
        3u,
        "Timeout (%ums) waiting for recovery to complete\n",
        v21,
        v23,
        v28);
      if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
      {
        v27 = "irq";
      }
      else if ( (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
      {
        v27 = "soft_irq";
      }
      else
      {
        v27 = (const char *)(v24 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v27,
        "cnss_wlan_unregister_driver",
        3u,
        3u,
        "ASSERT at line %d\n",
        4502,
        v26,
        v30);
      __break(0x800u);
    }
    goto LABEL_40;
  }
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else
  {
    v13 = *(_DWORD *)(v11 + 16);
    v14 = (const char *)(v11 + 2320);
    if ( (v13 & 0xFF00) != 0 )
      v12 = "soft_irq";
    else
      v12 = v14;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v12,
           "cnss_wlan_unregister_driver",
           3u,
           3u,
           "plat_priv is NULL\n",
           v3,
           v4,
           v28);
}
