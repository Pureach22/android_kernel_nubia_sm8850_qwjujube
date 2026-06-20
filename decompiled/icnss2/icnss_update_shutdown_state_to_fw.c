__int64 __fastcall icnss_update_shutdown_state_to_fw(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x20
  __int64 v6; // x0
  int raw_value; // w0
  __int64 v8; // x21
  __int64 v9; // x0
  int v10; // w0
  __int64 v11; // x19
  __int64 v12; // x0
  int v13; // w0
  int v14; // w20
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x21
  __int64 v18; // x0
  int v19; // w0
  unsigned __int64 v26; // x10

  if ( (*(_BYTE *)(a2 + 8) & 1) == 0 )
  {
    if ( *(_DWORD *)(result + 3272) )
    {
      *(_DWORD *)(result + 3272) = 0;
      if ( (*(_QWORD *)(result + 1832) & 0x200) == 0
        && (*(_QWORD *)(result + 1832) & 0x800) == 0
        && (*(_QWORD *)(result + 1832) & 0x20000) == 0
        && !*(_DWORD *)(result + 3276) )
      {
        v5 = result;
        v6 = gpio_to_desc(*(unsigned int *)(result + 280));
        raw_value = gpiod_get_raw_value(v6);
        printk("%sicnss2: WLAN_EN Value: %d\n", byte_13289B, raw_value);
        v8 = icnss_ipc_log_context;
        v9 = gpio_to_desc(*(unsigned int *)(v5 + 280));
        v10 = gpiod_get_raw_value(v9);
        ipc_log_string(v8, "%sicnss2: WLAN_EN Value: %d\n", (const char *)&unk_12DBF3, v10);
        icnss_driver_event_post(v5, 4u, 3, 0);
        v11 = v5;
        v12 = gpio_to_desc(*(unsigned int *)(v5 + 280));
        if ( (unsigned int)gpiod_get_raw_value(v12) )
        {
          v13 = icnss_select_pinctrl_state(v5, 0);
          if ( v13 )
          {
            v14 = v13;
            printk("%sicnss2: Failed to select pinctrl state, err = %d\n", byte_130B32, v13);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2: Failed to select pinctrl state, err = %d\n",
              (const char *)&unk_12DBF3,
              v14);
          }
        }
        v15 = gpio_to_desc(*(unsigned int *)(v11 + 280));
        v16 = gpiod_get_raw_value(v15);
        printk("%sicnss2: WLAN_EN Value: %d\n", byte_13289B, v16);
        v17 = icnss_ipc_log_context;
        v18 = gpio_to_desc(*(unsigned int *)(v11 + 280));
        v19 = gpiod_get_raw_value(v18);
        ipc_log_string(v17, "%sicnss2: WLAN_EN Value: %d\n", (const char *)&unk_12DBF3, v19);
        _X8 = (unsigned __int64 *)(v11 + 1832);
        __asm { PRFM            #0x11, [X8] }
        do
          v26 = __ldxr(_X8);
        while ( __stxr(v26 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        result = v11;
      }
    }
    if ( (*(_QWORD *)(result + 1832) & 0x20000) == 0
      || (v2 = result, v3 = wait_for_completion_timeout(result + 3088, 3750), result = v2, v3) )
    {
      result = wlfw_send_fw_shutdown_msg(result);
      if ( (result & 0x80000000) == 0 )
        return result;
LABEL_12:
      v4 = result;
      printk("%sicnss2: Fail to send FW shutdown Indication %d\n", byte_130B32, result);
      return ipc_log_string(
               icnss_ipc_log_context,
               "%sicnss2: Fail to send FW shutdown Indication %d\n",
               (const char *)&unk_12DBF3,
               v4);
    }
    printk("%sicnss2: FW block shutdown timeout\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: FW block shutdown timeout\n", (const char *)&unk_12DBF3);
    result = wlfw_send_fw_shutdown_msg(v2);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_12;
  }
  return result;
}
