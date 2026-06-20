__int64 __fastcall cnss_wlfw_send_pcie_gen_speed_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 v9; // x6
  unsigned __int64 StatusReg; // x21
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  unsigned int v14; // w19
  __int16 v15; // w9
  const char *v16; // x8
  __int64 v18; // x23
  unsigned int v19; // w0
  __int64 v20; // x7
  __int64 v21; // x0
  const char *v22; // x1
  __int64 v23; // x0
  const char *v24; // x1
  const char *v25; // x5
  char v27; // [xsp+0h] [xbp-60h]
  char v28; // [xsp+0h] [xbp-60h]
  _QWORD v29[9]; // [xsp+8h] [xbp-58h] BYREF
  int v30; // [xsp+50h] [xbp-10h]
  int v31; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+58h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( a1 )
  {
    v8 = a1 + 4096;
    v9 = *(unsigned __int8 *)(a1 + 7536);
    memset(v29, 0, sizeof(v29));
    if ( (_DWORD)v9 && (*(_BYTE *)(a1 + 7512) & 1) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v11 = "soft_irq";
      }
      else
      {
        v11 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v11,
        "cnss_wlfw_send_pcie_gen_speed_sync",
        7u,
        7u,
        "Sending PCIE Gen speed: %d state: 0x%lx\n",
        v9,
        *(_QWORD *)(a1 + 552),
        v27);
      v31 = *(unsigned __int8 *)(v8 + 3440);
      v18 = a1;
      v19 = qmi_txn_init(a1 + 856, v29, &wlfw_pcie_gen_switch_resp_msg_v01_ei);
      if ( (v19 & 0x80000000) != 0 )
      {
        v14 = v19;
        v23 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(StatusReg + 2320);
        }
        v25 = "Failed to initialize txn for PCIE speed switch err: %d\n";
      }
      else
      {
        v14 = qmi_send_request(a1 + 856, 0, v29, 83, 7, &wlfw_pcie_gen_switch_req_msg_v01_ei, &v31);
        if ( (v14 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v29);
          v23 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v24 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v24 = "soft_irq";
          }
          else
          {
            v24 = (const char *)(StatusReg + 2320);
          }
          v25 = "Failed to send PCIE speed switch, err: %d\n";
        }
        else
        {
          v21 = _msecs_to_jiffies(*(unsigned int *)(v18 + 6696));
          v14 = qmi_txn_wait(v29, v21);
          if ( (v14 & 0x80000000) == 0 )
          {
            if ( (_WORD)v30 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v22 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v22 = "soft_irq";
              }
              else
              {
                v22 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v22,
                "cnss_wlfw_send_pcie_gen_speed_sync",
                3u,
                3u,
                "PCIE Gen Switch req failed, Speed: %d, result: %d, err: %d\n",
                *(unsigned __int8 *)(v8 + 3440),
                (unsigned __int16)v30,
                SBYTE2(v30));
              v14 = -(unsigned __int16)v30;
            }
            goto LABEL_45;
          }
          v23 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v24 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v24 = "soft_irq";
          }
          else
          {
            v24 = (const char *)(StatusReg + 2320);
          }
          v25 = "Failed to wait for PCIE Gen switch resp, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v23, v24, "cnss_wlfw_send_pcie_gen_speed_sync", 3u, 3u, v25, v14, v20, v28);
LABEL_45:
      *(_BYTE *)(v8 + 3440) = 0;
      goto LABEL_46;
    }
    v12 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v12 + 16);
      v16 = (const char *)(v12 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_wlfw_send_pcie_gen_speed_sync",
      7u,
      7u,
      "PCIE Gen speed not setup\n",
      v9,
      a8,
      v27);
    v14 = 0;
  }
  else
  {
    v14 = -19;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v14;
}
