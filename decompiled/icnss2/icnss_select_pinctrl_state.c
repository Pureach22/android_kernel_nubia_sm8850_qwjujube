__int64 __fastcall icnss_select_pinctrl_state(_QWORD *a1, char a2)
{
  unsigned __int64 v3; // x1
  __int64 result; // x0
  _QWORD *v5; // x20
  unsigned int v6; // w0
  const char *v7; // x19
  unsigned __int64 v8; // x1
  __int64 v9; // x0
  int raw_value; // w0
  __int64 v11; // x22
  __int64 v12; // x0
  int v13; // w0
  const char *v14; // x20
  unsigned int v15; // w19

  if ( !a1 )
  {
    printk("%splat_priv is NULL!\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%splat_priv is NULL!\n", (const char *)&unk_12DBF3);
    return 4294967277LL;
  }
  if ( (a2 & 1) != 0 )
  {
    v3 = a1[33];
    result = 0;
    if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = a1;
      v6 = pinctrl_select_state(a1[31], v3);
      if ( !v6 )
      {
        v7 = "Assert";
LABEL_11:
        v9 = gpio_to_desc(*((unsigned int *)v5 + 70));
        raw_value = gpiod_get_raw_value(v9);
        printk("%sWLAN_EN Value: %d\n", byte_13289B, raw_value);
        v11 = icnss_ipc_log_context;
        v12 = gpio_to_desc(*((unsigned int *)v5 + 70));
        v13 = gpiod_get_raw_value(v12);
        ipc_log_string(v11, "%sWLAN_EN Value: %d\n", (const char *)&unk_12DBF3, v13);
        printk("%s%s WLAN_EN GPIO successfully\n", byte_13289B, v7);
        ipc_log_string(icnss_ipc_log_context, "%s%s WLAN_EN GPIO successfully\n", (const char *)&unk_12DBF3, v7);
        return 0;
      }
      v14 = "%sFailed to select wlan_en active state, err = %d\n";
LABEL_15:
      v15 = v6;
      printk(v14, byte_130B32, v6);
      ipc_log_string(icnss_ipc_log_context, v14, &unk_12DBF3, v15);
      return v15;
    }
  }
  else
  {
    v8 = a1[34];
    result = 0;
    if ( v8 && v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = a1;
      v6 = pinctrl_select_state(a1[31], v8);
      if ( !v6 )
      {
        v7 = "De-assert";
        goto LABEL_11;
      }
      v14 = "%sFailed to select wlan_en sleep state, err = %d\n";
      goto LABEL_15;
    }
  }
  return result;
}
