__int64 __fastcall cam_soc_util_regulator_disable(
        __int64 a1,
        const char *a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 result; // x0
  unsigned int v11; // w0
  const char *v12; // x5
  unsigned int v13; // w20
  __int64 v14; // x4

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_regulator_disable",
      3891,
      "Invalid NULL parameter");
    return 4294967274LL;
  }
  result = cam_wrapper_regulator_is_enabled();
  if ( (result & 0x80000000) != 0 )
  {
    v12 = "%s regulator_is_enabled failed";
    v13 = result;
    v14 = 3897;
    goto LABEL_8;
  }
  if ( (_DWORD)result )
  {
    v11 = cam_wrapper_regulator_disable(a1, a2);
    if ( v11 )
    {
      v12 = "%s regulator disable failed";
      v13 = v11;
      v14 = 3906;
LABEL_8:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_regulator_disable",
        v14,
        v12,
        a2);
      return v13;
    }
    if ( a6 < 0x15 )
    {
      if ( a6 )
        usleep_range_state(1000 * a6, 1000 * a6 + 1000, 2);
    }
    else
    {
      msleep(a6);
    }
    if ( (int)cam_wrapper_regulator_count_voltages(a1, a2) >= 1 )
    {
      cam_wrapper_regulator_set_load(a1, 0);
      cam_wrapper_regulator_set_voltage(a1, 0, a4, a2);
    }
    return 0;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_regulator_disable",
      3900,
      "%s regulator already disabled",
      a2);
    return 0;
  }
  return result;
}
