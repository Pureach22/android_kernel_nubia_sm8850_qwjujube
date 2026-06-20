__int64 __fastcall dp_parser_gpio(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x24
  char **v6; // x25
  unsigned __int64 StatusReg; // x26
  const char *v8; // x23
  __int64 named_gpio; // x0
  __int64 v10; // x28
  size_t v11; // x0
  unsigned __int64 v12; // x2
  __int64 ipc_log_context; // x0
  __int64 v15; // x0

  v1 = *a1;
  v3 = *(_QWORD *)(*a1 + 760);
  if ( of_find_property(v3, "qcom,dp-gpio-aux-switch", 0) )
    *((_BYTE *)a1 + 732) = 1;
  v4 = devm_kmalloc(v1 + 16, 280, 3520);
  a1[5] = v4;
  if ( !v4 )
    return 4294967284LL;
  v5 = 0;
  v6 = dp_parser_gpio_dp_gpios;
  StatusReg = _ReadStatusReg(SP_EL0);
  *((_DWORD *)a1 + 8) = 7;
  while ( 1 )
  {
    v8 = *v6;
    named_gpio = of_get_named_gpio(v3, *v6, 0);
    *(_DWORD *)(a1[5] + v5) = named_gpio;
    v10 = a1[5];
    if ( (*(_DWORD *)(v10 + v5) & 0x80000000) != 0 )
    {
      ipc_log_context = get_ipc_log_context(named_gpio);
      ipc_log_string(ipc_log_context, "[d][%-4d]%s gpio not specified\n", *(_DWORD *)(StatusReg + 1800), v8);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s gpio not specified\n", *(_DWORD *)(StatusReg + 1800), v8);
      *((_BYTE *)a1 + 732) = 0;
      goto LABEL_6;
    }
    v11 = strnlen(v8, 0x20u);
    if ( v11 == -1 )
      break;
    if ( v11 == 32 )
      v12 = 32;
    else
      v12 = v11 + 1;
    if ( v12 >= 0x21 )
      goto LABEL_20;
    sized_strscpy(v10 + v5 + 8, v8);
    *(_DWORD *)(a1[5] + v5 + 4) = 0;
LABEL_6:
    v5 += 40;
    ++v6;
    if ( v5 == 280 )
      return 0;
  }
  _fortify_panic(2, -1, 0);
LABEL_20:
  v15 = _fortify_panic(7, 32, v12);
  return dp_parser_catalog(v15);
}
