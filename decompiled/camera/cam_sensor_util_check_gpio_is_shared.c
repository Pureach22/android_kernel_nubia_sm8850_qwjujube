__int64 __fastcall cam_sensor_util_check_gpio_is_shared(__int64 a1)
{
  __int64 v1; // x8
  const void *v2; // x6
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 3208);
  if ( !v1 )
  {
    result = 0;
    if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
      return result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_check_gpio_is_shared",
      1417,
      "No GPIO data");
    return 0;
  }
  if ( !*(_BYTE *)(v1 + 8) )
  {
    result = 0;
    if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
      return result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_check_gpio_is_shared",
      1422,
      "No GPIO entry");
    return 0;
  }
  v2 = *(const void **)(v1 + 16);
  if ( !v2 || !*(_BYTE *)(v1 + 24) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_check_gpio_is_shared",
      1431,
      "invalid gpio_tbl %pK / size %d",
      v2,
      *(unsigned __int8 *)(v1 + 24));
    return 0;
  }
  if ( (cam_res_mgr_util_check_if_gpio_is_shared(*(_QWORD *)(v1 + 16), *(unsigned __int8 *)(v1 + 24)) & 1) != 0 )
    return 1;
  result = 0;
  if ( (debug_mdl & 0x800000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_check_gpio_is_shared",
      1440,
      "dev: %s don't have shared gpio resources",
      *(const char **)(a1 + 24));
    return 0;
  }
  return result;
}
