__int64 __fastcall coex_antenna_switch_to_mdm_send_sync_msg(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x23
  const char *v10; // x1
  unsigned int v11; // w22
  _QWORD *v12; // x19
  unsigned __int16 *v13; // x20
  unsigned int v14; // w0
  __int64 v15; // x7
  __int64 v16; // x0
  unsigned int v17; // w0
  const char *v18; // x1
  __int64 v19; // x0
  const char *v20; // x1
  const char *v21; // x5
  _QWORD v23[10]; // [xsp+0h] [xbp-50h] BYREF

  v23[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v23, 0, 72);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v10 = "soft_irq";
    }
    else
    {
      v10 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "coex_antenna_switch_to_mdm_send_sync_msg",
      7u,
      7u,
      "Sending coex antenna switch_to_mdm\n",
      a7,
      a8,
      v23[0]);
    v12 = (_QWORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 8);
    if ( v12 )
    {
      v13 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v13 )
      {
        v11 = -12;
        goto LABEL_43;
      }
      *v12 = *(_QWORD *)(a1 + 6744);
      v14 = qmi_txn_init(a1 + 6760, v23, &coex_antenna_switch_to_mdm_resp_msg_v01_ei);
      if ( (v14 & 0x80000000) != 0 )
      {
        v11 = v14;
        v19 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
        v21 = "Fail to init txn for coex antenna switch_to_mdm resp %d\n";
      }
      else
      {
        v11 = qmi_send_request(a1 + 6760, 0, v23, 66, 11, &coex_antenna_switch_to_mdm_req_msg_v01_ei, v12);
        if ( (v11 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v23);
          v19 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
          v21 = "Fail to send coex antenna switch_to_mdm req %d\n";
        }
        else
        {
          v16 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v17 = qmi_txn_wait(v23, v16);
          if ( (v17 & 0x80000000) == 0 )
          {
            if ( *v13 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v18 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v18 = "soft_irq";
              }
              else
              {
                v18 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v18,
                "coex_antenna_switch_to_mdm_send_sync_msg",
                3u,
                3u,
                "Coex antenna switch_to_mdm request rejected, result:%d error:%d\n",
                *v13,
                v13[1],
                v23[0]);
              v11 = -*v13;
            }
            else
            {
              v11 = 0;
            }
            goto LABEL_40;
          }
          v11 = v17;
          v19 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
          v21 = "Coex antenna switch_to_mdm resp wait failed with ret %d\n";
        }
      }
      cnss_debug_ipc_log_print(v19, v20, "coex_antenna_switch_to_mdm_send_sync_msg", 3u, 3u, v21, v11, v15, v23[0]);
LABEL_40:
      kfree(v13);
LABEL_43:
      kfree(v12);
      goto LABEL_44;
    }
    v11 = -12;
  }
  else
  {
    v11 = -19;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v11;
}
