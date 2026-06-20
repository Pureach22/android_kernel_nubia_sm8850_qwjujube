__int64 __fastcall cnss_xdump_wl_over_bt_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned __int64 v9; // x8
  const char *v10; // x1
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  unsigned __int64 v13; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int64 result; // x0
  __int16 v18; // w9
  const char *v19; // x8
  unsigned __int64 v20; // x8
  const char *v21; // x1
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v24; // x8
  const char *v25; // x1
  __int16 v26; // w9
  const char *v27; // x8
  __int64 v29; // x6
  __int64 v30; // x7
  unsigned __int64 v31; // x8
  const char *v32; // x1
  __int16 v33; // w9
  const char *v34; // x8
  __int16 v35; // w9
  const char *v36; // x8
  char v37; // [xsp+0h] [xbp-20h]

  v8 = a1 + 4096;
  if ( *(_BYTE *)(a1 + 7955) )
  {
    if ( (*(_QWORD *)(a1 + 552) & 0x10000) != 0 || (*(_QWORD *)(a1 + 552) & 0x40000) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v12 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v12 = "soft_irq";
        else
          v12 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v12,
        "cnss_xdump_wl_over_bt_req",
        6u,
        6u,
        "Skip in reboot/panic\n",
        a7,
        a8,
        v37);
      return 4294967280LL;
    }
    else if ( (*(_QWORD *)(a1 + 552) & 4) != 0 )
    {
      if ( *(_BYTE *)(a1 + 7958) )
      {
        v20 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
        {
          v21 = "irq";
        }
        else
        {
          v26 = *(_DWORD *)(v20 + 16);
          v27 = (const char *)(v20 + 2320);
          if ( (v26 & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = v27;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_xdump_wl_over_bt_req",
          6u,
          6u,
          "Collect BT dump over WLAN is in progress\n",
          a7,
          a8,
          v37);
        return 4294967274LL;
      }
      else if ( *(_BYTE *)(a1 + 7957) )
      {
        v24 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
        {
          v25 = "irq";
        }
        else
        {
          v33 = *(_DWORD *)(v24 + 16);
          v34 = (const char *)(v24 + 2320);
          if ( (v33 & 0xFF00) != 0 )
            v25 = "soft_irq";
          else
            v25 = v34;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v25,
          "cnss_xdump_wl_over_bt_req",
          6u,
          6u,
          "Collect WLAN dump over BT is in progress\n",
          a7,
          a8,
          v37);
        return 4294967182LL;
      }
      else
      {
        *(_DWORD *)(a1 + 7960) = 0;
        *(_BYTE *)(a1 + 7957) = 1;
        result = cnss_genl_send_xdump_wl_over_bt_req();
        if ( !(_DWORD)result )
        {
          result = wait_for_completion_timeout(a1 + 7960, 5000);
          if ( !(_DWORD)result )
          {
            v31 = _ReadStatusReg(SP_EL0);
            if ( (*(_DWORD *)(v31 + 16) & 0xF0000) != 0 )
            {
              v32 = "irq";
            }
            else
            {
              v35 = *(_DWORD *)(v31 + 16);
              v36 = (const char *)(v31 + 2320);
              if ( (v35 & 0xFF00) != 0 )
                v32 = "soft_irq";
              else
                v32 = v36;
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v32,
              "cnss_xdump_wl_over_bt_req",
              3u,
              3u,
              "Timeout waiting for xdump complete\n",
              v29,
              v30,
              v37);
            result = 0;
          }
        }
        *(_BYTE *)(v8 + 3861) = 0;
      }
    }
    else
    {
      v9 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v22 = *(_DWORD *)(v9 + 16);
        v23 = (const char *)(v9 + 2320);
        if ( (v22 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v23;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_xdump_wl_over_bt_req",
        6u,
        6u,
        "FW not ready\n",
        a7,
        a8,
        v37);
      return 4294967277LL;
    }
  }
  else
  {
    v13 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(v13 + 16);
      v19 = (const char *)(v13 + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v19;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_xdump_wl_over_bt_req",
      6u,
      6u,
      "XDUMP: wl_over_bt NOT enabled, bt_cap(%d: %d) wl_cap(%d: %d) user_config(%d: %d)\n",
      *(_BYTE *)(a1 + 7954) & 1,
      (*(unsigned __int8 *)(a1 + 7954) >> 1) & 1,
      *(_BYTE *)(a1 + 7953) & 1);
    return 4294967201LL;
  }
  return result;
}
