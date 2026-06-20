__int64 __fastcall cam_soc_util_release_platform_resource(__int64 a1)
{
  __int64 v1; // x21
  const char *v2; // x22
  __int64 v3; // x25
  __int64 v4; // x19
  const void *v5; // x20
  int v6; // w8
  unsigned __int64 v7; // x20
  __int64 *v8; // x26
  int v9; // w8
  int v11; // w8
  char v12; // w0

  if ( !a1 || (v4 = a1, !*(_QWORD *)(a1 + 8)) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_release_platform_resource",
      4633,
      "Invalid parameter");
    return 4294967274LL;
  }
  v5 = *(const void **)(a1 + 3192);
  if ( v5 )
  {
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_unregister_mmrm_client",
        965,
        "MMRM UnRegister handle=%pK",
        *(const void **)(a1 + 3192));
    a1 = mmrm_client_deregister(v5);
    if ( (_DWORD)a1 )
      a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             1,
             "cam_soc_util_unregister_mmrm_client",
             972,
             "Failed in deregister handle=%pK, rc %d",
             v5,
             a1);
    *(_QWORD *)(v4 + 3192) = 0;
  }
  v6 = *(_DWORD *)(v4 + 868);
  v7 = (unsigned int)(v6 - 1);
  if ( v6 - 1 >= 0 )
  {
    v3 = v4 + 2664;
    v1 = (__int64)"cam_soc_util_release_platform_resource";
    v2 = "%s handle is NULL skip put";
    v8 = (__int64 *)(v4 + 8LL * (unsigned int)v7 + 1128);
    do
    {
      v9 = *(_DWORD *)(v4 + 2792);
      if ( (v9 & (1 << v7)) != 0 )
      {
        if ( v7 >= 0x20 )
          goto LABEL_55;
        LOBYTE(a1) = cam_soc_util_clk_wrapper_unregister_entry(*(_DWORD *)(v3 + 4 * v7), (const char **)v4);
      }
      v9 = *(_DWORD *)(v4 + 3568);
      if ( (v9 & (1 << v7)) != 0 )
      {
        if ( v7 > 0x1F )
          goto LABEL_55;
        cam_soc_util_clk_aggregate_unregister_entry(*(unsigned int *)(v3 + 4 * v7), v4, v7);
      }
      else if ( v7 > 0x1F )
      {
        goto LABEL_55;
      }
      a1 = *v8;
      if ( *v8 )
      {
        a1 = cam_wrapper_clk_put(a1);
        *v8 = 0;
      }
      else if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 0x20000,
               4,
               "cam_soc_util_release_platform_resource",
               4657,
               "%s handle is NULL skip put",
               (const char *)*(v8 - 32));
      }
      --v7;
      --v8;
    }
    while ( v7 != -1 );
  }
  v9 = *(_DWORD *)(v4 + 488);
  v7 = (unsigned int)(v9 - 1);
  if ( v9 - 1 >= 0 )
  {
    v1 = 8LL * (unsigned int)(v9 - 1);
    while ( (unsigned int)v7 <= 9 )
    {
      v2 = (const char *)(v4 + v1);
      a1 = *(_QWORD *)(v4 + v1 + 744);
      if ( a1 )
      {
        a1 = cam_wrapper_regulator_put(a1);
        *((_QWORD *)v2 + 93) = 0;
      }
      v1 -= 8;
      if ( v1 == -8 )
        goto LABEL_32;
    }
    goto LABEL_55;
  }
LABEL_32:
  v11 = *(_DWORD *)(v4 + 480);
  v7 = (unsigned int)(v11 - 1);
  if ( v11 - 1 >= 0 )
  {
    v9 = 24;
    v1 = 24LL * (unsigned int)v7;
    while ( (unsigned int)v7 <= 7 )
    {
      v2 = (const char *)(v4 + v1);
      a1 = iounmap(*(_QWORD *)(v4 + v1 + 288));
      v1 -= 24;
      *((_QWORD *)v2 + 36) = 0;
      *((_QWORD *)v2 + 38) = 0;
      if ( v1 == -24 )
        goto LABEL_36;
    }
    goto LABEL_55;
  }
LABEL_36:
  v9 = *(_DWORD *)(v4 + 104);
  LODWORD(v3) = v9 - 1;
  if ( v9 - 1 >= 0 )
  {
    if ( (unsigned int)v3 <= 1 )
    {
      v7 = v4 + 80;
      v2 = (const char *)(v4 + 64);
      v1 = v4 + 40;
      if ( *(int *)(v4 + 80 + 4LL * (unsigned int)v3) < 1 )
      {
LABEL_44:
        if ( (_DWORD)v3 == 1 && *(int *)v7 >= 1 )
        {
          if ( (cam_presil_mode_enabled(a1) & 1) != 0 && **(_QWORD **)(v4 + 224) >> 24 == 8 )
          {
            v12 = cam_presil_unsubscribe_device_irq(**(unsigned int **)v2);
            if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x8000000,
                4,
                "cam_soc_util_release_platform_resource",
                4689,
                "UnSubscribe IRQ: Ret=%d NUM=%d Name=%s",
                v12 & 1,
                **(_QWORD **)v2,
                *(const char **)v1);
          }
          disable_irq(*(unsigned int *)v7);
        }
        goto LABEL_52;
      }
      if ( (((__int64 (*)(void))cam_presil_mode_enabled)() & 1) == 0
        || **(_QWORD **)(v4 + 224) >> 24 != 8
        || (LOBYTE(a1) = cam_presil_unsubscribe_device_irq(**(unsigned int **)&v2[8 * (unsigned int)v3]),
            v9 = debug_mdl,
            (debug_mdl & 0x8000000) == 0)
        || debug_priority )
      {
LABEL_43:
        a1 = disable_irq(*(unsigned int *)(v7 + 4LL * (unsigned int)v3));
        goto LABEL_44;
      }
LABEL_56:
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v9 & 0x8000000,
        4,
        "cam_soc_util_release_platform_resource",
        4689,
        "UnSubscribe IRQ: Ret=%d NUM=%d Name=%s",
        a1 & 1,
        **(_QWORD **)&v2[8 * (unsigned int)v3],
        *(const char **)(v1 + 8LL * (unsigned int)v3));
      goto LABEL_43;
    }
LABEL_55:
    __break(0x5512u);
    goto LABEL_56;
  }
LABEL_52:
  if ( *(_QWORD *)(v4 + 3216) )
    devm_pinctrl_put();
  cam_soc_util_request_gpio_table(v4, 0);
  *(_QWORD *)(v4 + 3272) = 0;
  return 0;
}
