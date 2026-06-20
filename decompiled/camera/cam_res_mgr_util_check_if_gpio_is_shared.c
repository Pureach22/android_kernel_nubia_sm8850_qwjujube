__int64 __fastcall cam_res_mgr_util_check_if_gpio_is_shared(int *a1, unsigned __int8 a2)
{
  __int64 v3; // x24
  int v4; // w22
  int v5; // t1
  int v6; // w23
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  int v10; // w0
  __int64 result; // x0
  const char *v12; // x5
  __int64 v13; // x1
  __int64 v14; // x4

  if ( !cam_res )
  {
    result = 0;
    if ( (debug_mdl & 0x200000) == 0 || debug_priority )
      return result;
    v12 = "cam_res data is not avaialbe";
    v13 = debug_mdl & 0x200000;
    v14 = 558;
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v13,
      4,
      "cam_res_mgr_util_check_if_gpio_is_shared",
      v14,
      v12);
    return 0;
  }
  if ( *(_BYTE *)(cam_res + 200) != 1 )
  {
    result = 0;
    if ( (debug_mdl & 0x200000) == 0 || debug_priority )
      return result;
    v12 = "shared gpio support is not enabled";
    v13 = debug_mdl & 0x200000;
    v14 = 563;
    goto LABEL_17;
  }
  if ( !a2 )
    return 0;
  v3 = a2;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = *a1;
      a1 += 6;
      v4 = v5;
      v6 = cam_res_mgr_gpio_is_in_shared_gpio(v5);
      v10 = cam_res_mgr_gpio_is_in_shared_pctrl_gpio(v5, v7, v8, v9);
      if ( (v10 & 1) == 0 || (v6 & 1) == 0 )
        break;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000,
        2,
        "__cam_res_mgr_find_if_gpio_is_shared",
        428,
        "gpio: %u cannot be shared in both list",
        v4);
      if ( !--v3 )
        return 0;
    }
    if ( ((v10 | v6) & 1) != 0 )
      break;
    if ( !--v3 )
      return 0;
  }
  return 1;
}
