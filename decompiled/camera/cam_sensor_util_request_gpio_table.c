__int64 __fastcall cam_sensor_util_request_gpio_table(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x24
  _QWORD *v9; // x27
  int v10; // w28
  __int64 result; // x0
  __int64 v12; // x22
  const char **i; // x23
  unsigned int v14; // w0
  unsigned int v15; // w21

  v2 = *(_QWORD *)(a1 + 3208);
  if ( !v2 )
  {
    result = 0;
    if ( (debug_mdl & 0x800000000LL) == 0 || debug_priority )
      return result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000000LL,
      4,
      "cam_sensor_util_request_gpio_table",
      1355,
      "No GPIO data");
    return 0;
  }
  if ( !*(_BYTE *)(v2 + 8) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_request_gpio_table",
      1360,
      "No GPIO entry");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(v2 + 16);
  v4 = *(unsigned __int8 *)(v2 + 24);
  if ( !v3 || !*(_BYTE *)(v2 + 24) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000000LL,
      1,
      "cam_sensor_util_request_gpio_table",
      1369,
      "invalid gpio_tbl %pK / size %d",
      *(const void **)(v2 + 16),
      v4);
    return 4294967274LL;
  }
  v6 = debug_mdl;
  v7 = debug_priority;
  v8 = 0;
  v9 = (_QWORD *)(v3 + 8);
  do
  {
    if ( (v6 & 0x800000000LL) != 0 && !v7 )
    {
      v10 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v6 & 0x800000000LL,
        4,
        "cam_sensor_util_request_gpio_table",
        1376,
        "%s%d, i: %d, gpio %d dir %lld",
        *(const char **)(a1 + 24),
        *(_DWORD *)(a1 + 20),
        v8,
        *((_DWORD *)v9 - 2),
        *v9);
      v6 = debug_mdl;
      v7 = debug_priority;
      a2 = v10;
    }
    ++v8;
    v9 += 3;
  }
  while ( v4 != v8 );
  if ( !a2 )
  {
    cam_res_mgr_gpio_free_arry(*(_QWORD *)(a1 + 8), v3, v4);
    return 0;
  }
  v12 = 0;
  for ( i = (const char **)(v3 + 16); ; i += 3 )
  {
    v14 = cam_res_mgr_gpio_request(*(_QWORD *)(a1 + 8), *((unsigned int *)i - 4), *(i - 1), *i);
    if ( v14 )
      break;
    if ( v4 == ++v12 )
      return 0;
  }
  v15 = v14;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x800000000LL,
    1,
    "cam_sensor_util_request_gpio_table",
    1391,
    "gpio %d:%s request fails",
    *((_DWORD *)i - 4),
    *i);
  if ( v12 )
    cam_res_mgr_gpio_free_arry(*(_QWORD *)(a1 + 8), v3, v12);
  return v15;
}
