__int64 __fastcall cnss_send_subsys_restart_level_msg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  unsigned int v11; // w19
  unsigned __int64 v12; // x22
  char v13; // w19
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int64 v17; // x0
  __int64 v18; // x21
  unsigned int v19; // w0
  unsigned int v20; // w0
  __int64 v21; // x7
  const char *v22; // x6
  const char *v23; // x1
  const char *v24; // x1
  __int64 v25; // x7
  const char *v27; // x1
  char v28; // [xsp+0h] [xbp-60h]
  char v29; // [xsp+0h] [xbp-60h]
  char v30; // [xsp+0h] [xbp-60h]
  __int16 v31; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD v32[10]; // [xsp+10h] [xbp-50h] BYREF

  v32[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v31 = 1;
    if ( (*(_QWORD *)(a1 + 552) & 4) == 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_send_subsys_restart_level_msg",
        7u,
        7u,
        "Can't send pcss cmd before fw ready\n",
        a7,
        a8,
        v28);
LABEL_30:
      v11 = 0;
      goto LABEL_31;
    }
    v12 = _ReadStatusReg(SP_EL0);
    v13 = *(_BYTE *)(a1 + 545);
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_send_subsys_restart_level_msg",
      7u,
      7u,
      "Sending pcss recovery status: %d\n",
      *(unsigned __int8 *)(a1 + 545),
      a8,
      v28);
    v17 = *(unsigned int *)(a1 + 6696);
    HIBYTE(v31) = v13;
    v18 = _msecs_to_jiffies(v17);
    memset(v32, 0, 72);
    v19 = qmi_txn_init(a1 + 856, v32, &wlfw_subsys_restart_level_resp_msg_v01_ei);
    if ( (v19 & 0x80000000) != 0 )
    {
      v11 = v19;
      v22 = "Qmi fail: fail to init txn,";
    }
    else
    {
      v11 = qmi_send_request(a1 + 856, 0, v32, 85, 4, &wlfw_subsys_restart_level_req_msg_v01_ei, &v31);
      if ( (v11 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v32);
        v22 = "Qmi fail: fail to send req,";
      }
      else
      {
        v20 = qmi_txn_wait(v32, v18);
        if ( (v20 & 0x80000000) == 0 )
        {
          if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
          {
            v23 = "irq";
          }
          else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
          {
            v23 = "soft_irq";
          }
          else
          {
            v23 = (const char *)(v12 + 2320);
          }
          cnss_debug_ipc_log_print(cnss_ipc_log_context, v23, "qmi_send_wait", 7u, 7u, "req %x success\n", 85, v21, v29);
          goto LABEL_30;
        }
        v11 = v20;
        v22 = "Qmi fail: wait timeout,";
      }
    }
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
    {
      v24 = "soft_irq";
    }
    else
    {
      v24 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "qmi_send_wait",
      3u,
      3u,
      "%s req %x, ret %d\n",
      (__int64)v22,
      85,
      v11);
    if ( (v11 & 0x80000000) == 0 )
      goto LABEL_30;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v27 = "irq";
    }
    else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
    {
      v27 = "soft_irq";
    }
    else
    {
      v27 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v27,
      "cnss_send_subsys_restart_level_msg",
      3u,
      3u,
      "pcss recovery setting failed with ret %d\n",
      v11,
      v25,
      v30);
  }
  else
  {
    v11 = -19;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v11;
}
